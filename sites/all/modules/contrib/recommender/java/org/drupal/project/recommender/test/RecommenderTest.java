package org.drupal.project.recommender.test;

import org.drupal.project.async_command.*;
import org.drupal.project.recommender.RecommenderApp;
import org.junit.Test;

import java.sql.SQLException;

import static junit.framework.Assert.assertTrue;

public class RecommenderTest {

    @Test
    public void testPingMe() throws SQLException {
        // create a pingme command.
        // attention: this drupal connection is the one Drush is using. could be different from the one in the drupalConnection created earlier
        String output = DrupalUtils.executeDrush("async-command", "recommender", "PingMe", "From UnitTest", "string1=Hello");
        System.out.println("Drush output: " + output);

        DrupalConnection drupalConnection = DrupalConnection.create();
        drupalConnection.connect();
        Long id = DrupalUtils.getLong(drupalConnection.queryValue("SELECT max(id) FROM {async_command}"));
        RecommenderApp drupalApp = new RecommenderApp(drupalConnection);
        drupalApp.run();

        // run() closes the drupal connection, so we recreate again.
        drupalConnection.connect(true);
        assertTrue(output.trim().endsWith(id.toString()));
        CommandRecord record = drupalConnection.retrieveCommandRecord(id);
        assertTrue(record.getStatus().equals(AsyncCommand.Status.SUCCESS));
        assertTrue(record.getMessage().endsWith("Hello"));
    }

    @Test
    public void testRecommender() throws Throwable {
        DrupalConnection drupalConnection = DrupalConnection.create();
        drupalConnection.connect();

        // prepare test recommender app
        String params = "a:6:{s:9:\"algorithm\";s:9:\"item2item\";s:5:\"table\";s:32:\"{recommender_preference_staging}\";s:6:\"fields\";a:4:{i:0;s:10:\"source_eid\";i:1;s:10:\"target_eid\";i:2;s:5:\"score\";i:3;s:7:\"updated\";}s:11:\"entity_type\";a:2:{s:10:\"similarity\";a:2:{i:0;s:4:\"node\";i:1;s:4:\"node\";}s:10:\"prediction\";a:2:{i:0;s:5:\"users\";i:1;s:4:\"node\";}}s:11:\"performance\";s:6:\"memory\";s:10:\"preference\";s:5:\"score\";}";
        drupalConnection.update("DELETE FROM {recommender_app} WHERE name='unittest'");
        long appId = drupalConnection.insertAutoIncrement("INSERT INTO {recommender_app}(name, title, params) VALUES (?, ?, ?)", "unittest", "UnitTest Recommender", params);

        drupalConnection.update("TRUNCATE TABLE {recommender_preference_staging}");
        BatchUploader insert = new BatchUploader("InsertGroupLens", drupalConnection.getConnection(), drupalConnection.d("INSERT INTO {recommender_preference_staging}(source_eid, target_eid, score) VALUES (?, ?, ?)"));
        insert.start();
        insert.put(1,1,1);
        insert.put(1,2,5);
        insert.put(1,4,2);
        insert.put(1,5,4);
        insert.put(2,1,4);
        insert.put(2,2,2);
        insert.put(2,4,5);
        insert.put(2,5,1);
        insert.put(2,6,2);
        insert.put(3,1,2);
        insert.put(3,2,4);
        insert.put(3,3,3);
        insert.put(3,6,5);
        insert.put(4,1,2);
        insert.put(4,2,4);
        insert.put(4,4,5);
        insert.put(4,5,1);
        insert.accomplish();

        DrupalUtils.executeDrush("recommender", "unittest", "From UnitTest");
        RecommenderApp drupalApp = new RecommenderApp(drupalConnection);
        drupalApp.run();

        // run() closes the drupal connection, so we recreate again.
        drupalConnection.connect(true);
        long similarity = DrupalUtils.getLong(drupalConnection.queryValue("SELECT count(*) FROM {recommender_similarity} WHERE app_id=?", appId));
        assertTrue(similarity > 0);
        long prediction = DrupalUtils.getLong(drupalConnection.queryValue("SELECT count(*) FROM {recommender_prediction} WHERE app_id=?", appId));
        assertTrue(prediction > 0);

        assertTrue(4 < (Float) drupalConnection.queryValue("SELECT score FROM {recommender_prediction} WHERE app_id=? AND source_eid=1 AND target_eid=6", appId));
        // item-itme similarity.
        //assertTrue(-0.5 > (Float) drupalConnection.queryValue("SELECT score FROM {recommender_similarity} WHERE app_id=? AND source_eid=4 AND target_eid=5", appId));
        DrupalUtils.executeDrush("eval", "recommender_app_unregister('unittest');");
    }

}

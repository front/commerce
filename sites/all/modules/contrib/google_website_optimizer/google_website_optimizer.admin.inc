<?php

/**
 * @file
 * Easily insert the nessesary javascript code for your Google Website Optimizer tests.
 */

/**
 * Controller for google_website_optimizer tests.
 */
function google_website_optimizer_admin_overview() {
  $output = '';

  $tests = google_website_optimizer_test_load();
  if ($tests) {
    $variables['header'] = array(t('Test'), t('Status'), t('Operations'));
    foreach ($tests as $test) {
      if ($test->test_status == 1) {
	    $test_status = t('Published');
	  }
	  else {
		$test_status = t('Not published');  
	  }
      $variables['rows'][] = array(array('data' => check_plain($test->name), 'valign' => 'top'), array('data' => $test_status, 'valign' => 'top'), array('data' => l(t('edit'), 'admin/config/content/google_website_optimizer/edit/'. $test->test_id) .' '. l(t('delete'), 'admin/config/content/google_website_optimizer/delete/'. $test->test_id), 'valign' => 'top'));
    }

    $output .= theme('table', $variables);
    $output .= '<p>'. l(t('Add new test'), 'admin/config/content/google_website_optimizer/add') .'</p>';
  }
  else {
    drupal_set_message(t('No tests found. Click here to <a href="!create-test-url">create a new test</a>.', array('!create-test-url' => url('admin/config/content/google_website_optimizer/add'))));
  }

  return $output;
}

/**
 * Return an HTML form for test configuration.
 */
function google_website_optimizer_admin_form($form, $form_state, $test_id = NULL) {
  if (isset($test_id)) {
    if (isset($form_state['values'])) {
      $edit = $form_state['values'];
    }
    else {
      $edit = google_website_optimizer_test_load($test_id);
    }
    $form['test_id'] = array(
      '#type' => 'hidden',
      '#value' => $edit->test_id,
    );
    $btn = t('Update test');
  }
  else {
    $btn = t('Create test');
    $edit->name = NULL;
	  $edit->test_status = 1;
    $edit->test_page_path = NULL;
    $edit->control_tracking_script = NULL;
    $edit->variation_page_path = NULL;
    $edit->variation_tracking_script = NULL;
    $edit->conversion_page_path = NULL;
    $edit->conversion_script = NULL;
    $edit->excluded_ips = NULL;
	  $edit->customvarslot = 0;
	  $edit->test_page_title = NULL;
	  $edit->test_page_language = LANGUAGE_NONE;
  }
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Test name'),
    '#default_value' => $edit->name,
    '#size' => 40,
    '#maxlength' => 128,
    '#description' => t('Enter a name for this test. This should correspond to the name of your test in Google Website Optimizer to make it easy to identify.'),
    '#required' => TRUE,
  );

  $form['test_status'] = array(
    '#type' => 'checkbox',
	'#title' => t('Published'),
	'#default_value' => $edit->test_status,
	'#description' => t('Select whether the experiment should be running or not.'),
  );

  $form['testing_page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Testing Page'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['testing_page']['test_page_path'] = array(
    '#type' => 'textarea',
    '#title' => t('Testing Page'),
    '#default_value' => $edit->test_page_path,
    '#description' => t("Enter one page per line as Drupal paths (e.g. <em>node/1</em> or <em>blog/some-article</em>). The '*' character is a wildcard."),
    '#required' => TRUE,
  );

  // get list og languages
  $languages = language_list('enabled');

  // create array of options
  $options[LANGUAGE_NONE] = t('All');
  foreach($languages[1] as $code => $item){
    $options[$code] = $item->name;
  }

  $form['testing_page']['test_page_language'] = array(
    '#type' => 'select',
	'#title' => t('Testing pages\' language'),
	'#default_value' => $edit->test_page_language,
	'#options' => $options,
    '#description' => t("Select the language you want to test. Useful if you want to test only on certain language. E.g. Select multiple nodes with asterisk (<em>node/*</em>) ang select a language to test all nodes of this language."),
    '#required' => TRUE,
  );

  // if there is only one language (two defined options e.g. und & en) make language input hidden
  if(count($options) < 3){
    $form['testing_page']['test_page_language']['#type'] = 'hidden';
  }

  $form['testing_page']['control_tracking_script'] = array(
    '#type' => 'textarea',
    '#title' => t('Control and Tracking Script'),
    '#default_value' => $edit->control_tracking_script,
    '#description' => t("Enter the control and tracking script provided by Google Website Optimizer. In order for the IP Exclusion filter to work, you have to paste exactly as given by Google. Specifically, the &lt;!-- Google Website Optimizer Control Script --&gt; and &lt;!-- End of Google Website Optimizer Control Script --&gt; comment tags should be there."),
    '#required' => TRUE,
  );

  $form['variation_pages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Variation pages (for A/B tests only)'),
    '#collapsible' => TRUE,
    '#collapsed' => $edit->variation_page_path == '',
  );

  $form['variation_pages']['variation_page_path'] = array(
    '#type' => 'textarea',
    '#title' => t('Variation Pages'),
    '#default_value' => $edit->variation_page_path,
    '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard."),
  );

  $form['variation_pages']['variation_tracking_script'] = array(
    '#type' => 'textarea',
    '#title' => t('Variation Tracking Script'),
    '#default_value' => $edit->variation_tracking_script,
    '#description' => t("Enter the variation tracking script provided by Google Website Optimizer."),
  );

  $form['conversion_page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Conversion Page'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['conversion_page']['conversion_page_path'] = array(
    '#type' => 'textarea',
    '#title' => t('Conversion Page(s)'),
    '#default_value' => $edit->conversion_page_path,
    '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard."),
    '#required' => TRUE,
  );

  $form['conversion_page']['conversion_script'] = array(
    '#type' => 'textarea',
    '#title' => t('Conversion Script'),
    '#default_value' => $edit->conversion_script,
    '#description' => t("Enter the conversion script provided by Google Website Optimizer."),
    '#required' => TRUE,
  );

  $form['other_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['other_settings']['excluded_ips'] = array(
    '#type' => 'textarea',
    '#title' => t('Excluded IP\'s'),
    '#default_value' => $edit->excluded_ips,
    '#description' => t("Enter one IP per line. These IP's will be able to see variations served by Google Website Optimizer, but they won't be tracked. <strong>IP filtering works only for logged in users</strong>."),
    '#required' => FALSE,
  );

  $form['other_settings']['customvarslot'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom Variable Slot'),
    '#default_value' => $edit->customvarslot,
    '#size' => 10,
    '#maxlength' => 1,
    '#description' => t('Enter a number from 1-5 for the custom variable slot to be used for Google Analytics Integration. If 0, no custom variable will be set. This is not IP filtered. Add your own IP filters in Google Analytics.'),
    '#required' => TRUE,
  );

  $form['other_settings']['test_page_title'] = array(
    '#type' => 'checkbox',
	'#title' => t('Test page title'),
	'#default_value' => $edit->test_page_title,
	'#description' => t('If you want to have the page title as a tested section, check this box. The proper tags will be added to the page title so you can add variations for it in Google Website Optimizer.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $btn
  );

  return $form;
}

/**
 * Save a test to the database.
 */
function google_website_optimizer_admin_form_submit($form, &$form_state) {
  if (isset($form_state['values']['test_id'])) { //It's an existing test
    drupal_write_record('google_website_optimizer', $form_state['values'], 'test_id');
    drupal_set_message(t('Test updated.'));
  } 
  else { //It's a new test
    drupal_write_record('google_website_optimizer', $form_state['values']);
    drupal_set_message(t('Test created.'));
  }
  $form_state['redirect'] = 'admin/config/content/google_website_optimizer';
}

/**
 * Test removal confirmation.
 */
function google_website_optimizer_delete_confirm($form, $form_state, $test_id) {
  $test = google_website_optimizer_test_load($test_id);

  $form['test_id'] = array(
    '#type' => 'value',
    '#value' => $test_id,
  );

  return confirm_form($form, t('Are you sure you want to delete test @name?', array('@name' => $test->name)), 'admin/config/content/google_website_optimizer', NULL, t('Delete test'));
}

/**
 * Submit delete confirm - remove a test from the database.
 */
function google_website_optimizer_delete_confirm_submit($form, &$form_state) {
  db_delete('google_website_optimizer')
    ->condition('test_id', $form_state['values']['test_id'])
    ->execute();
  drupal_set_message(t('Test removed.'));
  $form_state['redirect'] = 'admin/config/content/google_website_optimizer';
}

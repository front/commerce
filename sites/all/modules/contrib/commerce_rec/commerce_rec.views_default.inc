<?php
/**
 * @file commerce_rec.views.inc
 * Default views definitions for product recommendations
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_rec_views_default_views() {
  return array(
    'commerce_rec_similar_products' => recommender_default_view_template(
      'commerce_rec_similar_products',
      'Commerce Products Recommender: similar products',
      'Display on a product page "users who have ordered this product also ordered"',
      'recommender_similarity',
      'commerce_product',
      'title',
      'commerce_product',
      'commerce_rec'
    ),
    'commerce_rec_personal_recommendations' => recommender_default_view_template(
      'commerce_rec_personal_recommendations',
      'Commerce Products Recommender: personal recommendations',
      'Recommend to the current user other products this user might be interested based on the users purchasing history',
      'recommender_prediction',
      'commerce_product',
      'title',
      'current_user',
      'commerce_rec'
    ),
  );
}

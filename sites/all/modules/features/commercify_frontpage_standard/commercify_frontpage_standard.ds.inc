<?php
/**
 * @file
 * commercify_frontpage_standard.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function commercify_frontpage_standard_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|produktvisning|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'produktvisning';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'dynamic_field_forfatter' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:6:{s:5:"label";s:5:"title";s:9:"formatter";s:29:"taxonomy_term_reference_plain";s:18:"formatter_settings";a:0:{}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:25:"node:field_product_author";}',
        'load_terms' => 1,
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|produktvisning|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|produktvisning|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'produktvisning';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|produktvisning|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function commercify_frontpage_standard_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|produktvisning|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'produktvisning';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'product:field_product_image',
        1 => 'title',
        2 => 'field_product_author',
        3 => 'product:commerce_price',
        4 => 'field_display_product',
      ),
    ),
    'fields' => array(
      'product:field_product_image' => 'ds_content',
      'title' => 'ds_content',
      'field_product_author' => 'ds_content',
      'product:commerce_price' => 'ds_content',
      'field_display_product' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|produktvisning|teaser'] = $ds_layout;

  return $export;
}

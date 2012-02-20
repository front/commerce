<?php
/**
 * @file
 * commercify_frontpage_standard.ds.inc
 */

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
      ),
    ),
    'fields' => array(
      'product:field_product_image' => 'ds_content',
      'title' => 'ds_content',
      'field_product_author' => 'ds_content',
      'product:commerce_price' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|produktvisning|teaser'] = $ds_layout;

  return $export;
}

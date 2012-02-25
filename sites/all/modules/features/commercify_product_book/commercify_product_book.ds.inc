<?php
/**
 * @file
 * commercify_product_book.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function commercify_product_book_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|produktvisning|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'produktvisning';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'product:field_product_image',
      ),
      'right' => array(
        0 => 'title',
        1 => 'product:commerce_price',
        2 => 'dynamic_field_forfatter',
        3 => 'field_product_description',
        4 => 'group_cart',
        5 => 'field_product_author',
        6 => 'field_display_product',
      ),
    ),
    'fields' => array(
      'product:field_product_image' => 'left',
      'title' => 'right',
      'product:commerce_price' => 'right',
      'dynamic_field_forfatter' => 'right',
      'field_product_description' => 'right',
      'group_cart' => 'right',
      'field_product_author' => 'right',
      'field_display_product' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|produktvisning|default'] = $ds_layout;

  return $export;
}

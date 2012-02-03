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
  $ds_layout->layout = 'panels-threecol_25_50_25_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'top' => array(
        0 => 'title',
      ),
      'left' => array(
        0 => 'field_product_image',
      ),
      'middle' => array(
        0 => 'field_product_author',
        1 => 'field_product_description',
      ),
      'right' => array(
        0 => 'product:field_product_price_before',
        1 => 'product:commerce_price',
        2 => 'product:field_product_weight',
        3 => 'product:commerce_stock',
        4 => 'product:field_product_dimension',
        5 => 'field_display_product',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'field_product_image' => 'left',
      'field_product_author' => 'middle',
      'field_product_description' => 'middle',
      'product:field_product_price_before' => 'right',
      'product:commerce_price' => 'right',
      'product:field_product_weight' => 'right',
      'product:commerce_stock' => 'right',
      'product:field_product_dimension' => 'right',
      'field_display_product' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|produktvisning|default'] = $ds_layout;

  return $export;
}

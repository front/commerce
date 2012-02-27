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
        1 => 'dynamic_field_forfatter',
        2 => 'group_cart',
        3 => 'product:commerce_price',
        4 => 'group_details',
        5 => 'product:field_product_language',
        6 => 'field_display_product',
        7 => 'product:field_product_pages',
        8 => 'product:field_product_isbn',
        9 => 'product:field_product_detail_year',
        10 => 'field_product_description',
        11 => 'field_product_author',
      ),
    ),
    'fields' => array(
      'product:field_product_image' => 'left',
      'title' => 'right',
      'dynamic_field_forfatter' => 'right',
      'group_cart' => 'right',
      'product:commerce_price' => 'right',
      'group_details' => 'right',
      'product:field_product_language' => 'right',
      'field_display_product' => 'right',
      'product:field_product_pages' => 'right',
      'product:field_product_isbn' => 'right',
      'product:field_product_detail_year' => 'right',
      'field_product_description' => 'right',
      'field_product_author' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|produktvisning|default'] = $ds_layout;

  return $export;
}

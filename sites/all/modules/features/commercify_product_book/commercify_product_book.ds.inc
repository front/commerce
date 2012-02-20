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
  $ds_layout->layout = 'panels-twocol_bricks';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_above' => array(
        0 => 'product:field_product_image',
        1 => 'group_details',
        2 => 'product:field_product_detail_year',
        3 => 'product:field_product_pages',
        4 => 'product:field_product_language',
      ),
      'right_above' => array(
        0 => 'title',
        1 => 'product:field_product_author',
        2 => 'group_cart',
        3 => 'field_product_description',
        4 => 'product:commerce_price',
        5 => 'field_display_product',
      ),
    ),
    'fields' => array(
      'product:field_product_image' => 'left_above',
      'group_details' => 'left_above',
      'title' => 'right_above',
      'product:field_product_detail_year' => 'left_above',
      'product:field_product_author' => 'right_above',
      'product:field_product_pages' => 'left_above',
      'group_cart' => 'right_above',
      'product:field_product_language' => 'left_above',
      'field_product_description' => 'right_above',
      'product:commerce_price' => 'right_above',
      'field_display_product' => 'right_above',
    ),
    'classes' => array(),
  );
  $export['node|produktvisning|default'] = $ds_layout;

  return $export;
}

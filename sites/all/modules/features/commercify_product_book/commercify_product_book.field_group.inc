<?php
/**
 * @file
 * commercify_product_book.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function commercify_product_book_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cart|node|produktvisning|default';
  $field_group->group_name = 'group_cart';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'produktvisning';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Price & Cart',
    'weight' => '3',
    'children' => array(
      0 => 'field_display_product',
      1 => 'product:commerce_price',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Price & Cart',
      'instance_settings' => array(
        'classes' => 'price-cart',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_cart|node|produktvisning|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_design|node|produktvisning|form';
  $field_group->group_name = 'group_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'produktvisning';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Design',
    'weight' => '3',
    'children' => array(
      0 => 'field_product_special_css',
      1 => 'field_product_sub_header',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_design|node|produktvisning|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|commerce_product|publication|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Detaljer',
    'weight' => '8',
    'children' => array(
      0 => 'field_product_description',
      1 => 'field_product_detail_publisher',
      2 => 'field_product_language',
      3 => 'field_product_series_num',
      4 => 'field_product_detail_year',
      5 => 'field_product_pages',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_details|commerce_product|publication|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|produktvisning|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'produktvisning';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Small details',
    'weight' => '4',
    'children' => array(
      0 => 'product:field_product_language',
      1 => 'product:field_product_isbn',
      2 => 'product:field_product_detail_year',
      3 => 'product:field_product_pages',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Small details',
      'instance_settings' => array(
        'classes' => 'book-details',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details|node|produktvisning|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_info|commerce_product|publication|form';
  $field_group->group_name = 'group_product_info';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Produkt',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_product_info|commerce_product|publication|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_price|commerce_product|publication|form';
  $field_group->group_name = 'group_product_price';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pris',
    'weight' => '5',
    'children' => array(
      0 => 'commerce_price',
      1 => 'field_product_price_before',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_product_price|commerce_product|publication|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_stock|commerce_product|publication|form';
  $field_group->group_name = 'group_product_stock';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stock',
    'weight' => '9',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_product_stock|commerce_product|publication|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product|node|produktvisning|form';
  $field_group->group_name = 'group_product';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'produktvisning';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Produkt',
    'weight' => '2',
    'children' => array(
      0 => 'field_product_image',
      1 => 'field_product_description',
      2 => 'field_product_author',
      3 => 'field_product_category_main',
      4 => 'field_product_price_before',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Produkt',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_product|node|produktvisning|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stock|commerce_product|publication|form';
  $field_group->group_name = 'group_stock';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lager',
    'weight' => '6',
    'children' => array(
      0 => 'field_product_weight',
      1 => 'field_product_dimension',
      2 => 'commerce_stock',
      3 => 'field_product_stock_min',
      4 => 'field_product_stock_warning',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stock|commerce_product|publication|form'] = $field_group;

  return $export;
}

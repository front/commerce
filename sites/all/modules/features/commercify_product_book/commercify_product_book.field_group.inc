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
  $field_group->identifier = 'group_details|commerce_product|publication|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Detaljer',
    'weight' => '5',
    'children' => array(
      0 => 'field_product_description',
      1 => 'field_product_detail_year',
      2 => 'field_product_detail_publisher',
      3 => 'field_product_pages',
      4 => 'field_product_language',
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
  $field_group->identifier = 'group_product_info|commerce_product|publication|form';
  $field_group->group_name = 'group_product_info';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Produkt',
    'weight' => '4',
    'children' => array(
      0 => 'field_product_weight',
      1 => 'field_product_dimension',
      2 => 'field_product_author',
      3 => 'field_product_series_num',
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
    'weight' => '6',
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
    'weight' => '7',
    'children' => array(
      0 => 'commerce_stock',
      1 => 'field_product_stock_min',
      2 => 'field_product_stock_warning',
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
    'weight' => '3',
    'children' => array(
      0 => 'field_product_image',
      1 => 'field_product_description',
      2 => 'field_product_author',
      3 => 'field_product_genre',
      4 => 'field_product_category_main',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
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
    'weight' => '4',
    'children' => array(
      0 => 'commerce_stock',
      1 => 'field_product_stock_min',
      2 => 'field_product_stock_warning',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
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

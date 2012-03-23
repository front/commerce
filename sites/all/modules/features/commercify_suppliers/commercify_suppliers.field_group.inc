<?php
/**
 * @file
 * commercify_suppliers.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function commercify_suppliers_field_group_info() {
  $export = array();

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
    'weight' => '2',
    'children' => array(
      0 => 'field_product_weight',
      1 => 'field_product_dimension',
      2 => 'commerce_stock',
      3 => 'field_product_stock_min',
      4 => 'field_product_stock_warning',
      5 => 'field_product_supplier',
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

<?php
/**
 * @file
 * commercify_admin_overview.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function commercify_admin_overview_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'commerce_order|commerce_order|default';
  $ds_fieldsetting->entity_type = 'commerce_order';
  $ds_fieldsetting->bundle = 'commerce_order';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'commercify_change_order_state' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['commerce_order|commerce_order|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function commercify_admin_overview_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass;
  $ds_field->api_version = 1;
  $ds_field->field = 'commercify_change_order_state';
  $ds_field->label = 'Commercify: Change order state';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'commerce_order' => 'commerce_order',
  );
  $ds_field->properties = array(
    'block' => 'commercify|order-state-modify',
    'block_render' => '3',
  );
  $export['commercify_change_order_state'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function commercify_admin_overview_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'commerce_order|commerce_order|default';
  $ds_layout->entity_type = 'commerce_order';
  $ds_layout->bundle = 'commerce_order';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-twocol_bricks';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'top' => array(
        0 => 'commercify_change_order_state',
        1 => 'commerce_line_items',
        2 => 'commerce_order_total',
      ),
      'left_above' => array(
        0 => 'commerce_customer_shipping',
        1 => 'commerce_customer_billing',
      ),
      'right_above' => array(
        0 => 'field_order_customer_comment',
      ),
    ),
    'fields' => array(
      'commercify_change_order_state' => 'top',
      'commerce_line_items' => 'top',
      'commerce_order_total' => 'top',
      'commerce_customer_shipping' => 'left_above',
      'commerce_customer_billing' => 'left_above',
      'field_order_customer_comment' => 'right_above',
    ),
    'classes' => array(),
  );
  $export['commerce_order|commerce_order|default'] = $ds_layout;

  return $export;
}

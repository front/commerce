<?php
/**
 * @file
 * commercify_admin_overview.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function commercify_admin_overview_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_order_tos|commerce_order|commerce_order|form';
  $field_group->group_name = 'group_order_tos';
  $field_group->entity_type = 'commerce_order';
  $field_group->bundle = 'commerce_order';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Leveringsvilkår',
    'weight' => '8',
    'children' => array(
      0 => 'field_order_tos',
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
  $export['group_order_tos|commerce_order|commerce_order|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_comments|commerce_order|commerce_order|form';
  $field_group->group_name = 'group_user_comments';
  $field_group->entity_type = 'commerce_order';
  $field_group->bundle = 'commerce_order';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kommentarer',
    'weight' => '5',
    'children' => array(
      0 => 'field_order_customer_comment',
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
  $export['group_user_comments|commerce_order|commerce_order|form'] = $field_group;

  return $export;
}

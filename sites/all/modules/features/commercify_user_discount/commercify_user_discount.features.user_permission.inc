<?php
/**
 * @file
 * commercify_user_discount.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commercify_user_discount_user_default_permissions() {
  $permissions = array();

  // Exported permission: create field_user_discount
  $permissions['create field_user_discount'] = array(
    'name' => 'create field_user_discount',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_discount
  $permissions['edit field_user_discount'] = array(
    'name' => 'edit field_user_discount',
    'roles' => array(
      0 => 'administrator',
      1 => 'selger',
      2 => 'store-admin',
      3 => 'superselger',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_discount
  $permissions['edit own field_user_discount'] = array(
    'name' => 'edit own field_user_discount',
    'roles' => array(
      0 => 'administrator',
      1 => 'selger',
      2 => 'store-admin',
      3 => 'superselger',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_discount
  $permissions['view field_user_discount'] = array(
    'name' => 'view field_user_discount',
    'roles' => array(
      0 => 'administrator',
      1 => 'selger',
      2 => 'store-admin',
      3 => 'superselger',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_discount
  $permissions['view own field_user_discount'] = array(
    'name' => 'view own field_user_discount',
    'roles' => array(),
  );

  return $permissions;
}

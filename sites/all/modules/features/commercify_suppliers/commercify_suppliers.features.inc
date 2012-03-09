<?php
/**
 * @file
 * commercify_suppliers.features.inc
 */

/**
 * Implements hook_views_api().
 */
function commercify_suppliers_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function commercify_suppliers_node_info() {
  $items = array(
    'supplier' => array(
      'name' => t('Leverandør'),
      'base' => 'node_content',
      'description' => t('A supplier of goods, referenced to from products'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

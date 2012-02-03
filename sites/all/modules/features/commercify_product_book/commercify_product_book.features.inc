<?php
/**
 * @file
 * commercify_product_book.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function commercify_product_book_commerce_product_default_types() {
  $items = array(
    'publication' => array(
      'type' => 'publication',
      'name' => 'Publikasjon',
      'description' => 'En publikasjon.',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function commercify_product_book_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function commercify_product_book_node_info() {
  $items = array(
    'produktvisning' => array(
      'name' => t('Produktvisning'),
      'base' => 'node_content',
      'description' => t('Standardvisning av produkter.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

<?php
/**
 * @file
 * commercify_banners.features.inc
 */

/**
 * Implements hook_node_info().
 */
function commercify_banners_node_info() {
  $items = array(
    'banners' => array(
      'name' => t('Bannere'),
      'base' => 'node_content',
      'description' => t('Bannere for bruk i produktpromotering.'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => '',
    ),
  );
  return $items;
}

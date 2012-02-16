<?php
/**
 * @file
 * commercify_product_book.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function commercify_product_book_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-produkter
  $menus['menu-produkter'] = array(
    'menu_name' => 'menu-produkter',
    'title' => 'Produkter',
    'description' => 'Produktene vi har i vårt assortement',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Produktene vi har i vårt assortement');
  t('Produkter');


  return $menus;
}

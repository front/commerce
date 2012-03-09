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

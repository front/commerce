<?php
/**
 * @file
 * commercify_order_maps.features.inc
 */

/**
 * Implements hook_views_api().
 */
function commercify_order_maps_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

<?php
/**
 * @file
 * commercify_taxonomy_pages.features.inc
 */

/**
 * Implements hook_views_api().
 */
function commercify_taxonomy_pages_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

<?php

/**
 * Override of theme('breadcrumb').
 */
function cube_commerce_breadcrumb($vars) {
  $output = '';

  foreach ($vars['breadcrumb'] as $key => $item) {
    $vars['breadcrumb'][$key] = htmlspecialchars_decode($item);
  }

  // Add current page onto the end.
  if (!drupal_is_front_page()) {
    $item = menu_get_item();
    $end = end($vars['breadcrumb']);
    if ($end && strip_tags($end) !== $item['title']) {
      $vars['breadcrumb'][] = "<strong>" . check_plain($item['title']) . "</strong>";
    }
  }

  // Optional: Add the site name to the front of the stack.
  if (!empty($vars['prepend'])) {
    $site_name = empty($vars['breadcrumb']) ? "<strong>" . check_plain(variable_get('site_name', '')) . "</strong>" : l(variable_get('site_name', ''), '<front>', array('purl' => array('disabled' => TRUE)));
    array_unshift($vars['breadcrumb'], $site_name);
  }

  $depth = 0;
  foreach ($vars['breadcrumb'] as $link) {
    $output .= "<span class='breadcrumb-link breadcrumb-depth-{$depth}'>{$link}</span>";
    $depth++;
  }
  return $output;
}

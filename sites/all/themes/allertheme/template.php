<?php

/**
 * Override or insert variables into the html templates.
 * Replace 'allertheme' with your themes name, i.e. mytheme_preprocess_html()
 */
function allertheme_preprocess_html(&$vars) {
  $ie_files = array(
    'IE' => 'ie.css',
  );
  load_subtheme_ie_styles($ie_files, 'allertheme');

  $http_header = drupal_get_http_header();
  if (isset($http_header['status'])) {
    $status = drupal_clean_css_identifier($http_header['status']);
    $vars['classes_array'][] = 'page-' . strtolower($status);
  }
}

/**
 * Implements hook_css_alter().
 */
function allertheme_css_alter(&$css) {
  // Remove AT Commerce responsive css
  $at_commerce_path = drupal_get_path('theme', 'at_commerce');
  unset($css[$at_commerce_path . '/css/at_commerce.responsive.style.css']);
  unset($css[$at_commerce_path . '/css/at_commerce.responsive.gpanels.css']);
  unset($css[$at_commerce_path . '/css/ie-6.css']);
  unset($css[$at_commerce_path . '/css/ie-lte-7.css']);
  unset($css[$at_commerce_path . '/css/ie-8.css']);
  unset($css[$at_commerce_path . '/css/ie-lte-9.css']);
}

/**
 * Implements hook_js_alter().
 */
function allertheme_js_alter(&$js) {
  // Remove hardcoded setting from superfish menu.
  foreach ($js as $key => $value) {
    if ($value['type'] == 'inline') {
      if (preg_match('/#superfish/i', $value['data'])) {
        $js[$key]['data'] = str_replace('extraWidth: 1', 'extraWidth: 0', $value['data']);
      }
    }
  }
}

/**
 * Preprocess variables for page.tpl.php
 */
function allertheme_preprocess_page(&$vars) {
  // Hide breacrumb on frontpage
  if ($vars['is_front']) {
    $vars['breadcrumb'] = FALSE;
  }
}

/**
 * Theme callback: display prices in a table.
 *
 * From commerce_price_savings_formatter module.
 */
function allertheme_commerce_price_savings_formatter_formatter($vars) {
  // Build an array of table rows based on the prices passed in.
  $rows = array();

  // exit if no prices
  if (empty($vars['prices'])) {
    return '';
  }

  // store prices count
  $prices_count = count($vars['prices']);

  // move price to 1st position
  if (isset($vars['prices']['price'])) {
    $vars['prices'] = array('price' => $vars['prices']['price']) + $vars['prices'];
  }

  // build rows
  foreach ($vars['prices'] as $key => $value) {
    switch ($key) {
      case 'list':
        $label = t('List price');
        break;

      case 'price':
        $label = t('Price:');
        break;

      case 'savings':
        $label = t('You save');
        break;
    }

    $rows[] = array(
      'data' => array(
        array('data' => $label, 'class' => array('price-label')),
        array('data' => $value, 'class' => array('price-amount')),
      ),
      'class' => array('commerce-price-savings-formatter-' . $key),
    );
  }

  return theme('table', array('rows' => $rows, 'attributes' => array('class' => array('commerce-price-savings-formatter-prices', 'commerce-price-savings-formatter-prices-count-' . $prices_count))));
}

/**
 * Implements hook_form_alter().
 */
function allertheme_form_alter(&$form, &$form_state, $form_id) {
  // TODO: move this to a custom module and make title context aware
  if ($form_id == 'search_api_page_search_form_search_page') {
    if (isset($form['keys_1'])) {
      $form['keys_1']['#attributes']['#title'] = $form['keys_1']['#attributes']['placeholder'] = t('Search for book or author');
    }
  }
  elseif ($form_id == 'search_api_page_search_form') {
    if (isset($form['form']['keys_1'])) {
      $form['form']['keys_1']['#attributes']['placeholder'] = $form['form']['keys_1']['#title'];
      $form['form']['keys_1']['#title'] = '';
    }
  }
}

function allertheme_preprocess_commerce_line_item_summary(&$vars) {
  if (empty($vars['links'])) {
    $vars['quantity_raw'] = l($vars['quantity_raw'], 'cart');
    $vars['quantity_label'] = l($vars['quantity_label'], 'cart');
  }
}

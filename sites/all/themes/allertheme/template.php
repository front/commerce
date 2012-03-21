<?php

/**
 * Override or insert variables into the html templates.
 * Replace 'allertheme' with your themes name, i.e. mytheme_preprocess_html()
 */
function allertheme_preprocess_html(&$vars) {
 /**
  * Load IE specific stylesheets
  * AT automates adding IE stylesheets, simply add to the array using
  * the conditional comment as the key and the stylesheet name as the value.
  *
  * See our online help: http://adaptivethemes.com/documentation/working-with-internet-explorer
  *
  * For example to add a stylesheet for IE8 only use:
  *
  *  'IE 8' => 'ie-8.css',
  *
  * Your IE CSS file must be in the /css/ directory in your subtheme.
  */
  /* -- Delete this line to add a conditional stylesheet for IE 7 or less.
  $ie_files = array(
    'lte IE 7' => 'ie-lte-7.css',
  );
  load_subtheme_ie_styles($ie_files, 'allertheme'); // Replace 'allertheme' with your themes name
  // */

}

/**
 * Implements hook_css_alter().
 */
function allertheme_css_alter(&$css) {
  // Remove AT Commerce responsive css
  unset($css[drupal_get_path('theme', 'at_commerce') . '/css/at_commerce.responsive.style.css']);
  unset($css[drupal_get_path('theme', 'at_commerce') . '/css/at_commerce.responsive.gpanels.css']);
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

<?php

/**
 * Views for commerce orders for report displays.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_reports_views_default_views() {

  $view = new view;
  $view->name = 'order_report';
  $view->description = 'Display a list of orders for the store admin.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Order Report';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Grafiske oversikter';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['style_plugin'] = 'jump_menu';
  $handler->display->display_options['style_options']['hide'] = 1;
  $handler->display->display_options['style_options']['path'] = 'order_id';
  $handler->display->display_options['style_options']['choose'] = '- Ordrer inkludert i denne statistikken -';
  $handler->display->display_options['style_options']['default_value'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Commerce Order: Product Quantities by Month */
  $handler->display->display_options['footer']['products_qty_monthly_line']['id'] = 'products_qty_monthly_line';
  $handler->display->display_options['footer']['products_qty_monthly_line']['table'] = 'commerce_order';
  $handler->display->display_options['footer']['products_qty_monthly_line']['field'] = 'products_qty_monthly_line';
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['alter_text'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['make_link'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['absolute'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['external'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['nl2br'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['word_boundary'] = 1;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['ellipsis'] = 1;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['strip_tags'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['trim'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['alter']['html'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['element_label_colon'] = 1;
  $handler->display->display_options['footer']['products_qty_monthly_line']['element_default_classes'] = 1;
  $handler->display->display_options['footer']['products_qty_monthly_line']['hide_empty'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['empty_zero'] = 0;
  $handler->display->display_options['footer']['products_qty_monthly_line']['hide_alter_empty'] = 1;
  /* Footer: Commerce Order: Product Sales by Month */
  $handler->display->display_options['footer']['products_sales_monthly_bar']['id'] = 'products_sales_monthly_bar';
  $handler->display->display_options['footer']['products_sales_monthly_bar']['table'] = 'commerce_order';
  $handler->display->display_options['footer']['products_sales_monthly_bar']['field'] = 'products_sales_monthly_bar';
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['alter_text'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['make_link'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['absolute'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['external'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['nl2br'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['word_boundary'] = 1;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['ellipsis'] = 1;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['strip_tags'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['trim'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['alter']['html'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['element_label_colon'] = 1;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['element_default_classes'] = 1;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['hide_empty'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['empty_zero'] = 0;
  $handler->display->display_options['footer']['products_sales_monthly_bar']['hide_alter_empty'] = 1;
  /* Footer: Commerce Order: Product Sales Percentages */
  $handler->display->display_options['footer']['products_percent_monthly_pie']['id'] = 'products_percent_monthly_pie';
  $handler->display->display_options['footer']['products_percent_monthly_pie']['table'] = 'commerce_order';
  $handler->display->display_options['footer']['products_percent_monthly_pie']['field'] = 'products_percent_monthly_pie';
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['alter_text'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['make_link'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['absolute'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['external'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['nl2br'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['word_boundary'] = 1;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['ellipsis'] = 1;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['strip_tags'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['trim'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['alter']['html'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['element_label_colon'] = 1;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['element_default_classes'] = 1;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['hide_empty'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['empty_zero'] = 0;
  $handler->display->display_options['footer']['products_percent_monthly_pie']['hide_alter_empty'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'No orders for this time period';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  $handler->display->display_options['empty']['text']['tokenize'] = 0;
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['required'] = 0;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Ordre #';
  $handler->display->display_options['fields']['order_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['order_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['order_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['order_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['order_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['order_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['order_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['order_number']['hide_alter_empty'] = 0;
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Dato opprettet';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Ordretotal';
  $handler->display->display_options['fields']['commerce_order_total']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['empty_zero'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
      'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_order_total']['field_api_classes'] = 0;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Ordrestatus';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['text'] = 'admin/commerce/orders/[order_id]';
  $handler->display->display_options['fields']['order_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['order_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['order_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['order_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['order_id']['hide_alter_empty'] = 1;
  /* Sort criterion: Commerce Order: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Dato';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
      'cart' => 'cart',
      'checkout' => 'checkout',
  );
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Order state';
  $handler->display->display_options['filters']['state']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['reduce'] = 0;
  /* Filter criterion: Commerce Order: Created date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Opprettet mellom';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['created']['expose']['multiple'] = FALSE;

  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['path'] = 'admin/commerce/overview/orders/graphs';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Grafisk oversikt';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Reports';
  $handler->display->display_options['tab_options']['description'] = 'Manage orders in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['order_report'] = array(
      t('Defaults'),
      t('Grafiske oversikter'),
      t('more'),
      t('Apply'),
      t('Reset'),
      t('Sort by'),
      t('Asc'),
      t('Desc'),
      t('Items per page'),
      t('- All -'),
      t('Offset'),
      t('Product Quantities by Month'),
      t('Product Sales by Month'),
      t('Product Sales Percentages'),
      t('No orders for this time period'),
      t('Order owner'),
      t('Customer profile'),
      t('Ordre #'),
      t('Dato opprettet'),
      t('Ordretotal'),
      t('Ordrestatus'),
      t('Order ID'),
      t('admin/commerce/orders/[order_id]'),
      t('Dato'),
      t('Order state'),
      t('Opprettet mellom'),
      t('Admin page'),
  );


  $views[$view->name] = $view;

  return $views;
}

<?php
/**
 * @file
 * commercify_order_maps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function commercify_order_maps_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'c_dashboard_map_overview';
  $view->description = '';
  $view->tag = 'ip_geoloc';
  $view->base_table = 'commerce_order';
  $view->human_name = 'C Dashboard Map Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Order Locations';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'tableipmapd';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = 'Posisjonene på dette kartet er ikke eksakte.';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['required'] = 1;
  /* Field: IP geolocations: IP address */
  $handler->display->display_options['fields']['ip_address']['id'] = 'ip_address';
  $handler->display->display_options['fields']['ip_address']['table'] = 'ip_geoloc';
  $handler->display->display_options['fields']['ip_address']['field'] = 'ip_address';
  $handler->display->display_options['fields']['ip_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['ip_address']['alter']['text'] = 'IP: [ip_address]';
  $handler->display->display_options['fields']['ip_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ip_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ip_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ip_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ip_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ip_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ip_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ip_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ip_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ip_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ip_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ip_address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ip_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ip_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ip_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ip_address']['hide_alter_empty'] = 1;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['order_number']['alter']['text'] = 'Order #[order_number]';
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
  $handler->display->display_options['fields']['order_number']['hide_alter_empty'] = 1;
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Order placed: [created]';
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
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Commerce Order: Order state */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['state']['alter']['text'] = 'Order state: [state]';
  $handler->display->display_options['fields']['state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['state']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['state']['hide_alter_empty'] = 1;
  /* Field: IP geolocations: Address */
  $handler->display->display_options['fields']['formatted_address']['id'] = 'formatted_address';
  $handler->display->display_options['fields']['formatted_address']['table'] = 'ip_geoloc';
  $handler->display->display_options['fields']['formatted_address']['field'] = 'formatted_address';
  $handler->display->display_options['fields']['formatted_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['formatted_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['formatted_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['formatted_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['formatted_address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['formatted_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['formatted_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['formatted_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['formatted_address']['hide_alter_empty'] = 1;
  /* Field: IP geolocations: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'ip_geoloc';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['latitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['latitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['latitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['latitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['latitude']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['latitude']['format_plural'] = 0;
  /* Field: IP geolocations: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'ip_geoloc';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['longitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['longitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['longitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['longitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['longitude']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['longitude']['format_plural'] = 0;
  /* Sort criterion: Commerce Order: Order ID */
  $handler->display->display_options['sorts']['order_id']['id'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['order_id']['field'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['order'] = 'DESC';
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'checkout' => 'checkout',
    'pending' => 'pending',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Ordrestatus';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['state']['expose']['reduce'] = 0;
  /* Filter criterion: Commerce Order: Created date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '<=';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Fra DD-MM-ÅÅÅÅ';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['multiple'] = FALSE;
  /* Filter criterion: Commerce Order: Created date */
  $handler->display->display_options['filters']['created_1']['id'] = 'created_1';
  $handler->display->display_options['filters']['created_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['created_1']['field'] = 'created';
  $handler->display->display_options['filters']['created_1']['operator'] = '<=';
  $handler->display->display_options['filters']['created_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created_1']['expose']['operator_id'] = 'created_1_op';
  $handler->display->display_options['filters']['created_1']['expose']['label'] = 'Til DD-MM-ÅÅÅÅ';
  $handler->display->display_options['filters']['created_1']['expose']['operator'] = 'created_1_op';
  $handler->display->display_options['filters']['created_1']['expose']['identifier'] = 'created_1';
  $handler->display->display_options['filters']['created_1']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/overview/ip-map';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Kart';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $translatables['c_dashboard_map_overview'] = array(
    t('Master'),
    t('Order Locations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Posisjonene på dette kartet er ikke eksakte.'),
    t('Customer profile'),
    t('IP address'),
    t('IP: [ip_address]'),
    t('Order number'),
    t('Order #[order_number]'),
    t('Created date'),
    t('Order placed: [created]'),
    t('Order state'),
    t('Order state: [state]'),
    t('Address'),
    t('Latitude'),
    t('.'),
    t(','),
    t('Longitude'),
    t('Ordrestatus'),
    t('Fra DD-MM-ÅÅÅÅ'),
    t('Til DD-MM-ÅÅÅÅ'),
    t('Page'),
    t('Content pane'),
    t('View panes'),
  );
  $export['c_dashboard_map_overview'] = $view;

  return $export;
}

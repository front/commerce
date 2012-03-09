<?php
/**
 * @file
 * commercify_suppliers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function commercify_suppliers_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'c_dashboard_suppliers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'C Dashboard Suppliers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Leverandører';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Kontaktperson */
  $handler->display->display_options['fields']['field_supplier_contact']['id'] = 'field_supplier_contact';
  $handler->display->display_options['fields']['field_supplier_contact']['table'] = 'field_data_field_supplier_contact';
  $handler->display->display_options['fields']['field_supplier_contact']['field'] = 'field_supplier_contact';
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_supplier_contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_supplier_contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_supplier_contact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_supplier_contact']['field_api_classes'] = 0;
  /* Field: Content: Telefon */
  $handler->display->display_options['fields']['field_supplier_phone']['id'] = 'field_supplier_phone';
  $handler->display->display_options['fields']['field_supplier_phone']['table'] = 'field_data_field_supplier_phone';
  $handler->display->display_options['fields']['field_supplier_phone']['field'] = 'field_supplier_phone';
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_supplier_phone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_supplier_phone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_supplier_phone']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_supplier_phone']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'supplier' => 'supplier',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Navn';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/overview/suppliers/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Leverandører';
  $handler->display->display_options['menu']['description'] = 'Liste over leverandører';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Leverandører';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['c_dashboard_suppliers'] = array(
    t('Master'),
    t('Leverandører'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Kontaktperson'),
    t('Telefon'),
    t('Navn'),
    t('Page'),
  );
  $export['c_dashboard_suppliers'] = $view;

  return $export;
}

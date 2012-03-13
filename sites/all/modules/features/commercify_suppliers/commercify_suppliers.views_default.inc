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
  $view->human_name = 'C-admin Suppliers';
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
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
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
  $handler->display->display_options['path'] = 'admin/commerce/overview/suppliers';
  $handler->display->display_options['menu']['type'] = 'tab';
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

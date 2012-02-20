<?php

/*
 * @file 
 * 
 * Rules config.
 * Triggers the order export.
 */

/**
 * Implementation of hook_trigger_info().
 */
function commerce_mc_rules_action_info() {
  $actions = array();

  $actions['commerce_mc_order_process'] = array(
      'type' => 'commerce_order',
      'group' => t('Commerce Mediaconnect'),
      'label' => t('Process an order'),
      'parameter' => array(
          'commerce_order' => array(
              'type' => 'commerce_order',
              'label' => t('Order potentially containing line items with MC SKU field'),
              'save' => TRUE
          ),
      ),
      'callbacks' => array(
          'execute' => 'commerce_mc_process_order',
      ),
  );
//  $actions['commerce_mc_product_import'] = array(
//      'type' => 'commerce_order',
//      'group' => t('Commerce Mediaconnect'),
//      'label' => t('Import & update existing products'),
//      'parameter' => array(
//          'commerce_order' => array(
//              'type' => 'commerce_order',
//              'label' => t('Order containing referenced nodes'),
//              'save' => TRUE
//          ),
//      ),
//      'callbacks' => array(
//          'execute' => 'commerce_mc_product_import',
//      ),
//  );
//
//  $actions['commerce_mc_product_update'] = array(
//      'type' => 'commerce_order',
//      'group' => t('Commerce Mediaconnect'),
//      'label' => t('Update single Mediaconnect product'),
//      'parameter' => array(
//          'commerce_product' => array(
//              'type' => 'commerce_product',
//              'label' => t('Product'),
//          ),
//      ),
//      'callbacks' => array(
//          'execute' => 'commerce_mc_product_update',
//      ),
//  );
  return $actions;
}

/**
 * Implements hook_rules_event_info().
 */
function commerce_mc_rules_event_info() {
  $events = array();
//
//  $events['smb_order_admin_expand'] = array(
//      'label' => t('After the form is submitted'),
//      'group' => t('Commerce Order'),
//      'variables' => array(
//          'commerce_order' => array(
//              'type' => 'commerce_order',
//              'label' => t('An order with line items'),
//          ),
//      ),
//      'access callback' => 'rules_node_admin_access',
//  );
  return $events;
}


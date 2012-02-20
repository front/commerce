<?php

/*
 * @file
 * Default rules for Commerce Mediaconnect integration.
 *
 * Provides a basic rules config that fires a sending of an order at
 * checkout complete.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_mc_default_rules_configuration() {
  $items = array();
  $items['commerce_nodecopy_process'] = entity_import('rules_config', '{ "rules_mediaconnect_process_order" : {
    "LABEL" : "Mediaconnect: Process order",
    "PLUGIN" : "reaction rule",
    "REQUIRES" : [ "commerce_mc", "commerce_checkout" ],
    "ON" : [ "commerce_checkout_complete" ],
    "DO" : [
      { "commerce_mc_order_process" : { "commerce_order" : [ "commerce_order" ] } }
    ]
  }
}');
  return $items;
}
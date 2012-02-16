<?php
/**
 * @file
 * commercify_user_discount.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commercify_user_discount_default_rules_configuration() {
  $items = array();
  $items['rules_discount_set_user_discount'] = entity_import('rules_config', '{ "rules_discount_set_user_discount" : {
      "LABEL" : "Discount: Set user discount",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "User", "type" : "user" },
        "percent" : { "label" : "Percent", "type" : "integer" }
      },
      "ACTION SET" : [
        { "data_set" : { "data" : [ "user:field-user-discount" ], "value" : [ "percent" ] } }
      ]
    }
  }');
  return $items;
}

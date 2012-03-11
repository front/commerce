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
  $items['rules_commercify_discount_on_user_entity'] = entity_import('rules_config', '{ "rules_commercify_discount_on_user_entity" : {
      "LABEL" : "Commercify: Discount % on user entity",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : [ "commerce_product_calculate_sell_price" ],
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:order:owner" ],
            "field" : "field_user_discount"
          }
        },
        { "NOT data_is_empty" : { "data" : [ "commerce-line-item:order:owner:field-user-discount" ] } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:order:owner:field-user-discount" ],
              "op" : "-",
              "input_2" : "100"
            },
            "PROVIDE" : { "result" : { "remainingpercent" : "remainingpercent" } }
          }
        },
        { "data_calc" : {
            "USING" : { "input_1" : [ "remainingpercent" ], "op" : "\\/", "input_2" : "-1" },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_divide" : {
            "commerce_line_item" : [ "commerce-line-item" ],
            "amount" : "100",
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_multiply" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
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

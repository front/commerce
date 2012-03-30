<?php
/**
 * @file
 * commercify_admin_overview.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commercify_admin_overview_default_rules_configuration() {
  $items = array();
  $items['rules_admin_redirect'] = entity_import('rules_config', '{ "rules_admin_redirect" : {
      "LABEL" : "Login: Redirect to sales administration",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Commerce admin" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_login" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "4" : "4", "3" : "3", "5" : "5", "6" : "6" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "admin\\/commerce\\/overview" } } ]
    }
  }');
  $items['rules_commercify_move_to_cancelled'] = entity_import('rules_config', '{ "rules_commercify_move_to_cancelled" : {
      "LABEL" : "Commercify: Move to Cancelled",
      "PLUGIN" : "action set",
      "TAGS" : [ "Commerce" ],
      "REQUIRES" : [ "commerce_order", "rules" ],
      "USES VARIABLES" : { "order" : { "label" : "Commerce order", "type" : "commerce_order" } },
      "ACTION SET" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "order" ], "order_status" : "canceled" } },
        { "drupal_message" : {
            "message" : "MERK: Ordrene du valgte er n\\u00e5 kansellert. Varene trekkes fra varelager n\\u00e5r de er betalt, men de legges ikke tilbake automatisk. Dette m\\u00e5 gj\\u00f8res manuelt.",
            "type" : "warning",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  $items['rules_commercify_move_to_completed'] = entity_import('rules_config', '{ "rules_commercify_move_to_completed" : {
      "LABEL" : "Commercify: Move to Completed",
      "PLUGIN" : "action set",
      "TAGS" : [ "Commerce" ],
      "REQUIRES" : [ "commerce_order" ],
      "USES VARIABLES" : { "order" : { "label" : "Commerce order", "type" : "commerce_order" } },
      "ACTION SET" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "order" ], "order_status" : "completed" } }
      ]
    }
  }');
  $items['rules_commercify_move_to_processing'] = entity_import('rules_config', '{ "rules_commercify_move_to_processing" : {
      "LABEL" : "Commercify: Move to Processing",
      "PLUGIN" : "action set",
      "TAGS" : [ "Commerce" ],
      "REQUIRES" : [ "commerce_order" ],
      "USES VARIABLES" : { "order" : { "label" : "Commerce order", "type" : "commerce_order" } },
      "ACTION SET" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "order" ], "order_status" : "processing" } }
      ]
    }
  }');
  return $items;
}

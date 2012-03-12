<?php
/**
 * @file
 * commercify_emails.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commercify_emails_default_rules_configuration() {
  $items = array();
  $items['rules_commercify_order_status_changed'] = entity_import('rules_config', '{ "rules_commercify_order_status_changed" : {
      "LABEL" : "Commercify: Order status changed",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : [ "commerce_order_presave" ],
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "commerce-order:status" ],
            "value" : [ "commerce-order-unchanged:status" ]
          }
        },
        { "NOT user_has_role" : {
            "account" : [ "commerce-order:owner" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        },
        { "NOT data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "cart" } },
        { "NOT data_is" : { "data" : [ "commerce-order-unchanged:state" ], "value" : "checkout" } }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "En mail har blitt sendt til kunden med oppdatert status.",
            "repeat" : 0
          }
        },
        { "mail" : {
            "to" : "[commerce-order:mail]",
            "subject" : "Din ordre [commerce-order:order-id] hos [site:name]",
            "message" : "Hei!\\r\\n\\r\\nDin ordre nummer [commerce-order:order-id] hos oss n\\u00e5 har f\\u00e5tt ny status:\\r\\n\\r\\nGammel status: [commerce-order-unchanged:status-title]\\r\\nNy status: [commerce-order:status-title]\\r\\n\\r\\nDu kan til enhver tid se din ordre som innlogget p\\u00e5:\\r\\n[site:url]\\/user\\/[commerce-order:uid]\\/orders\\/[commerce-order:order-id] .\\r\\n\\r\\nMed vennlig hilsen,\\r\\n[site:name]\\r\\n[site:url]",
            "from" : "kundeservice@allerbok.no"
          }
        }
      ]
    }
  }');
  return $items;
}

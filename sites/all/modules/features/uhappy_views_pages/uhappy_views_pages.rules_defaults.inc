<?php
/**
 * @file
 * uhappy_views_pages.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function uhappy_views_pages_default_rules_configuration() {
  $items = array();
  $items['rules_send_e_mail'] = entity_import('rules_config', '{ "rules_send_e_mail" : {
      "LABEL" : "Send e-mail",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Uhappy" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--order" : { "bundle" : "order" } },
      "DO" : [
        { "mail" : {
            "to" : "ag@peytz.dk",
            "subject" : "New Order for [node:title] was submitted",
            "message" : "hi new node was created",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}

<?php

/**
 * Implementation of hook_views_plugins().
 */
function views_ipmap_views_plugins() {
  return array(
    'style' => array(
      'tableipmapd' => array(
        'title' => t('Ip-mapping'),
        'help' => t('Displays a IP map.'),
        'handler' => 'views_ipmap_plugin_style_tableipmapd',
        //'parent' => 'table',
        'theme' => 'views_ipmap_views_tableipmapd',
/*         'theme path' => drupal_get_path('module', 'views_ipmap') . '/theme', */
        'uses row plugin' => FALSE,
        'uses row class' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-table',
      ),
    ),
  );
}

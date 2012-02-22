<?php

/**
 * Style plugin to render each item as a row in a table.
 *
 * @ingroup views_style_plugins
 */
class views_ipmap_plugin_style_tableipmapd extends views_plugin_style {

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    //$form['#theme'] = 'views_ipmap_plugin_style_tableipmapd';
    $form['map_options'] = array(
      '#type' => 'textfield',
      '#size' => 120,
      '#title' => t('Map options'),
      '#default_value' => variable_get('ip_geoloc_map_of_view_options', IP_GEOLOC_RECENT_VISITORS_MAP_OPTIONS),
      '#description' => t("The default %default_options produces a world map zoomed in to level 2. A list of map options can be found <a href='!google_map_docs'>here</a>. Remember to separate options with comma's, not semi-colons, and make sure your quotes match.", array('%default_options' => IP_GEOLOC_RECENT_VISITORS_MAP_OPTIONS,
        '!google_map_docs' => DOC_GOOGLE_MAP_OPTIONS))
    );
  }

  function render() {

    if (isset($this->view->live_preview) && $this->view->live_preview) {
      return t('IPmap is incompatible with live preview.');
    }

    $view = $this->view;
    $locations = array();
    foreach ($view->result as $row) {
      if (!empty($row->ip_geoloc_latitude) && !empty($row->ip_geoloc_longitude)) {
        $locations[] = array(
          'latitude' => $row->ip_geoloc_latitude,
          'longitude' => $row->ip_geoloc_longitude,
          'balloonText' => 'test',
        );
      }
    }
    if (empty($locations)) {
      return t("Ingen markører tilgjengelige.");
    }
    $map_style = "height:500px";
    //$map_options = '{"mapTypeId":"terrain", "disableDefaultUI":true, "zoom":7,  "zoomControl":false}';
    $map_options = variable_get('ip_geoloc_recent_map_of_view_options', IP_GEOLOC_RECENT_VISITORS_MAP_OPTIONS);
    return ip_geoloc_output_map_multi_locations($locations, 'ip-geoloc-block-map-of-view', drupal_json_decode($map_options), $map_style);
  }

}

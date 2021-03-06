<?php

/**
 * @file
 * Preprocess functions for Views RSS: Core Elements module.
 */

/**
 * Preprocess function for channel <title> element.
 */
function views_rss_core_preprocess_channel_title(&$variables) {
  $view_title = $variables['view']->get_title();
  $variables['value'] = ($view_title) ? $view_title : variable_get('sitename', t('Drupal'));
}

/**
 * Preprocess function for channel <description> element.
 */
function views_rss_core_preprocess_channel_description(&$variables) {
  $variables['value'] = ($variables['value']) ? $variables['value'] : variable_get('site_slogan', '');
}

/**
 * Preprocess function for channel <link> element.
 */
function views_rss_core_preprocess_channel_link(&$variables) {
  $variables['value'] = url('<front>', array('absolute' => TRUE));
}

/**
 * Preprocess function for channel <atom:link> element.
 */
function views_rss_core_preprocess_channel_atom_link(&$variables) {
  $url_options = array('absolute' => TRUE);
  $input = $variables['view']->get_exposed_input();
  if ($input) {
    $url_options['query'] = $input;
  }
  $url = url($variables['view']->get_url(), $url_options);

  $variables['value'] = array(
    'arguments' => array(
      'rel' => 'self',
      'href' => $url,
    ),
  );
}

/**
 * Preprocess function for channel <image> element.
 */
function views_rss_core_preprocess_channel_image(&$variables) {
  if (!empty($variables['value'])) {
    $path = $variables['value'];
    // Get value of channel <title> element from its preprocess function.
    views_rss_core_preprocess_channel_title($variables);
    $title = $variables['value'];
    // Get value of channel <title> element from its preprocess function.
    views_rss_core_preprocess_channel_link($variables);
    $link = $variables['value'];
    // Create subelements array.
    $subelements = array(
      'url' => array(
        'element' => 'url',
        'value' => file_create_url($path),
      ),
      'title' => array(
        'element' => 'title',
        'value' => $title,
      ),
      'link' => array(
        'element' => 'link',
        'value' => $link,
      ),
    );
    // Try to get image description from website's mission.
    $site_slogan = variable_get('site_slogan', '');
    if (!empty($site_slogan)) {
      $subelements['description'] = array(
        'element' => 'description',
        'value' => $site_slogan,
      );
    }
    // Get image width and height.
    $image = image_load($path);
    if (!empty($image)) {
      $subelements['width'] = array(
        'element' => 'width',
        'value' => $image->info['width'],
      );
      $subelements['height'] = array(
        'element' => 'height',
        'value' => $image->info['height'],
      );
    }
    // Assign generated subelements array back to $variables.
    $variables['value'] = array(
      'subelements' => $subelements,
    );
  }
}

/**
 * Preprocess function for item <pubDate> and <lastBuildDate> elements.
 *
 * It will return values for date element providing that original Views query
 * was modified appropriately by views_rss_core_views_query_alter() by adding
 * new fields to SELECT clause retrieving object creation (for <pubDate>)
 * or modification timestamp (for <lastBuildDate>).
 */
function views_rss_core_preprocess_channel_date(&$variables) {
  if (count($variables['view']->result) > 0) {
    $max_date = 0;
    foreach ($variables['view']->result as $row) {
      if (isset($row->{strtolower($variables['element'])}) && $row->{strtolower($variables['element'])} > $max_date) {
        $max_date = $row->{strtolower($variables['element'])};
      }
    }
    if ($max_date) {
      $variables['value'] = date('r', $max_date);
    }
  }
}

/**
 * Preprocess function for channel and item <skipHours> and <skipDays> elements.
 */
function views_rss_core_preprocess_channel_skip(&$variables) {
  if (!empty($variables['value'])) {
    $element = array(
      'element' => $variables['element'],
      'subelements' => array(),
    );
    foreach (explode(',', strip_tags($variables['value'])) as $skip_value) {
      $element['subelements'][] = array(
        'element' => ($variables['element'] == 'skipHours') ? 'hour' : 'day',
        'value' => trim($skip_value),
      );
    }
    $variables['value'] = $element;
  }
}

/**
 * Preprocess function for channel <cloud> element.
 */
function views_rss_core_preprocess_channel_cloud(&$variables) {
  if ($variables['value']) {
    if ($url = parse_url($variables['value'])) {
      $variables['value'] = array(
        'arguments' => array(
          'domain' => $url['host'],
          'port' => $url['port'],
          'path' => $url['path'],
          'registerProcedure' => $url['fragment'],
          'protocol' => $url['scheme'],
        ),
      );
    }
  }
}

/**
 * Preprocess function for channel and item <category> element.
 */
function views_rss_core_preprocess_category(&$variables) {
  if (!empty($variables['value'])) {
    $elements = array();
    $categories = explode(',', $variables['value']);
    foreach ($categories as $category) {
      $elements[] = array(
        'element' => $variables['element'],
        'value' => trim($category),
      );
    }
    $variables['value'] = array('elements' => $elements);
  }
}

/**
 * Preprocess function for item <guid> element.
 */
function views_rss_core_preprocess_item_guid(&$variables) {
  if ($variables['value']) {
    $value = array(
      'value' => $variables['value'],
      'arguments' => array(
        'isPermaLink' => 'false',
      ),
    );
    if ((!isset($variables['item']['views_rss_core']['link']) || empty($variables['item']['views_rss_core']['link'])) && valid_url($value['value'], TRUE)) {
      $value['arguments']['isPermaLink'] = 'true';
    }
    $variables['value'] = $value;
  }
}

/**
 * Preprocess function for channel <source> element.
 */
function views_rss_core_preprocess_item_source(&$variables) {
  $url_options = array('absolute' => TRUE);
  $input = $variables['view']->get_exposed_input();
  if ($input) {
    $url_options['query'] = $input;
  }
  $url = url($variables['view']->get_url(), $url_options);

  $variables['value'] = array(
    'value' => $variables['view']->get_title(),
    'arguments' => array(
      'url' => $url,
    ),
  );
}

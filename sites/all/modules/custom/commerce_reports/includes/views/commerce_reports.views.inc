<?php

/**
 * Provide commerce reports related Views integration.
 */

/**
 * Implements hook_views_data_alter().
 */
function commerce_reports_views_data_alter(&$data) {
  
  $data['commerce_order']['products_qty_monthly_line'] = array(
    'area' => array(
      'title' => t('Product Quantities by Month'),
      'help' => t('Display line chart for different product quantities sold'),
      'handler' => 'commerce_reports_handler_field_products_qty_monthly_line',
    ),
  );
  
  $data['commerce_order']['products_sales_monthly_bar'] = array(
    'area' => array(
      'title' => t('Product Sales by Month'),
      'help' => t('Display bar chart for product sales'),
      'handler' => 'commerce_reports_handler_field_products_sales_monthly_bar',
    ),
  );
  
  $data['commerce_order']['products_percent_monthly_pie'] = array(
    'area' => array(
      'title' => t('Product Sales Percentages'),
      'help' => t('Display pie chart for product sales percentages'),
      'handler' => 'commerce_reports_handler_field_products_percent_pie',
    ),
  );
  
}

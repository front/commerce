<?php

/**
 * Field handler to present a link to an order.
 */
class commerce_reports_handler_field_products_sales_monthly_bar extends views_handler_field {
  function construct() {
    parent::construct();

    //$this->additional_fields['order_id'] = 'order_id';
  }

  //function option_definition() {
  //  $options = parent::option_definition();
  //
  //  //$options['text'] = array('default' => '', 'translatable' => TRUE);
  //
  //  return $options;
  //}

  //function options_form(&$form, &$form_state) {
  //  parent::options_form($form, $form_state);
  //
  //  //$form['text'] = array(
  //  //  '#type' => 'textfield',
  //  //  '#title' => t('Text to display'),
  //  //  '#default_value' => $this->options['text'],
  //  //);
  //}

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    
    $view = views_get_current_view();
    $view->execute();
    
    //ob_start();
    //print '<pre>';
    //print_r($view->result);
    //print '</pre>';
    //$var = ob_get_clean();
    //return $var;
    
    //$total =0;
    //foreach ( $view->result as $k=> $v ) {
    //    print $k.'<br />';
    //}
    //print_r($view);
    
    $data = __prepare_commerce_reports_products_sales_monthly_bar_data($view->result);

    return theme('commerce_reports_products_sales_monthly_bar', array('data' => $data));
  }
}
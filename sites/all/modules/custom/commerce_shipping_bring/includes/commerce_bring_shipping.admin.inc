<?php

/**
 * Form callback: builds the settings form.
 */
function commerce_shipping_bring_settings_form($form, &$form_state) {
    
  $form['commerce_shipping_bring_rate_currency_code'] = array(
    '#type' => 'select',
    '#title' => t('Currency'),
    '#options' => commerce_currency_code_options_list(),
    '#default_value' => variable_get('commerce_shipping_bring_rate_currency_code', commerce_default_currency()),
  );

  $form['commerce_shipping_bring_zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t('The Shop zipcode'),
    '#default_value' => variable_get('commerce_shipping_bring_zipcode', ''),
    '#required' => TRUE,
  	'#size' => 10,
  );  
  
  $form['services'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enable Bring shipping services'), 
		'#collapsible' => TRUE,
  ); 
  
  // Get an array of service elements.
  $package_services = commerce_shipping_bring_available_services();

  $form['services']['commerce_shipping_bring_services'] = array(
    '#type' => 'checkboxes',    
    '#options' => $package_services,
    '#default_value' => variable_get('commerce_shipping_bring_services', array()),
  );
    
  return system_settings_form($form);
}
<?php

/**
 * Mapping settings
 */
function commerce_mc_settings_form() {
  $form = array();
  $form['info'] = array(
      '#type' => 'markup',
      '#markup' => t('Nothing here yet.'),
  );

  return system_settings_form($form);
}

/**
 * Structure settings.
 * Line item & order settings are 2 separate arrays.
 */
function commerce_mc_settings_mapping_form() {  
  $form = array();
  $order_settings = variable_get('commerce_mc_order', array());
  $line_settings = variable_get('commerce_mc_lines', array());
  dpm($order_settings);
  dpm($line_settings);
  // If first startup, load defaults.
  if (empty($order_settings)) {
    $order_settings = commerce_mc_default_settings();
  }

  $form['commerce_mc_orderid'] = array(
      '#type' => 'textfield',
      '#title' => t('Internal order ID'),
      '#default_value' => variable_get('commerce_mc_orderid', '123'),
      '#description' => t('What we want to get back as identifier. DOC: <order> elementer KAN ha EN, og kun EN attributt; externalOrderId. Dette attributtet kan settes av klienten og vil i så fall være tilstede i responsen slik at klienten kan skille mellom de forskjellige <order> elementene ved tolkning av responsen for å finne status på hver ordre.'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
  );

  $form['commerce_mc_order'] = array(
      '#type' => 'fieldset',
      '#title' => t('Order mapping'),
      '#tree' => true,
  );
  $form['commerce_mc_order']['order_test'] = array(
      '#type' => 'textfield',
      '#title' => t('Test settings on order'),
      '#default_value' => $order_settings['order_test'],
      '#description' => t('Test this setting by entering an order ID for test.'),
  );

  $form['commerce_mc_order']['orderTime'] = array(
      '#type' => 'textfield',
      '#title' => t('Order Time'),
      '#default_value' => $order_settings['orderTime'],
      '#description' => t('Tidsstempel på når ordren ble registrert (ordretidspunkt i det eksterne ordresystemet/ webshop/etc).'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
  );

  $form['commerce_mc_order']['marketingCouponCode'] = array(
      '#type' => 'textfield',
      '#title' => t('Marketing Coupon Code'),
      '#default_value' => $order_settings['marketingCouponCode'],
      '#description' => t('Static marketing coupon code. This field is used to populate \'marketingCouponCode\' in the order header.'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
  );

  $form['commerce_mc_order']['marketingCouponno'] = array(
      '#type' => 'textfield',
      '#title' => t('Marketing Coupon Number'),
      '#default_value' => $order_settings['marketingCouponno'],
      '#description' => t('Static marketing coupon number. This field is used to populate \'marketingCouponno\' in the order header.'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
  );

  $form['commerce_mc_order']['paymentMethod'] = array(
      '#type' => 'select',
      '#title' => t('Payment types'),
      '#default_value' => $order_settings['paymentMethod'],
      '#description' => t(''),
      '#options' => array(
          'creditcard' => t('Credit card'),
          'prepaid' => t('Prepaid (no card info exchange)'),
          'prepaidCreditcard' => t('Prepaid with credit card'),
      ),
      '#required' => TRUE,
  );

  $form['commerce_mc_order']['mspContractId'] = array(
      '#type' => 'textfield',
      '#title' => t('MSP Contract ID'),
      '#default_value' => $order_settings['mspContractId'],
      '#description' => t('Merchant service provider contract id (betalingsformidler kontrakt id). Benyttes ved kredittkortsbetalt ordre (paymentMethod = creditcard). Identifikasjon/avtalenummer til avtale med betalingsformidler. Benyttes for avstemming av kredittkortsbetalte ordre.'),
      '#required' => FALSE,
  );
  $form['commerce_mc_order']['mspTransactionId'] = array(
      '#type' => 'textfield',
      '#title' => t('MSP Transaction ID'),
      '#default_value' => $order_settings['mspTransactionId'],
      '#description' => t('Merchant service provider transaction id (betalingsformidler transaksjonsid). Benyttes ved kredittkortsbetalt ordre (paymentMethod = creditcard). Transaksjonsid ved forhåndsbetalt ordre. Typisk transaksjonsid mottatt fra betalingsformidler. Benyttes for avstemming av kredittkortsbetalt ordre.'),
      '#required' => FALSE,
  );

  $form['commerce_mc_order']['totalInclVat'] = array(
      '#type' => 'textfield',
      '#title' => t('Total Incl VAT mapping. (Might need to program this)'),
      '#default_value' => $order_settings['totalInclVat'],
      '#description' => t('Total order sum including VAT. Ordresum angis alltid inklusiv eventuell MVA; det er ikke eget felt for MVA. Grunnen til dette er at i henhold til regnskapsloven er det forlagets ansvar å beregne riktig MVA selv om den som registrerer ordren har fortalt kunden noe feil..'),
      '#required' => FALSE,
  );

  // Available tokens only order
  $order_token_types = array(
      'commerce-order' => 'commerce-order'
  );
  // Set up the tokenization
  if (module_exists('token')) {
    $form['commerce_mc_order']['order_token_tree'] = array(
        '#theme' => 'token_tree',
        '#token_types' => $order_token_types,
    );
  }

  $form['commerce_mc_lines'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#title' => t('Line item mapping'),
      '#tree' => TRUE,
  );

  $form['commerce_mc_lines']['productSpecType'] = array(
      '#type' => 'radios',
      '#title' => t('The product Spec type.'),
      '#default_value' => $line_settings['productSpecType'],
      '#options' => array(
          'product' => t('Product'),
          'coupon' => t('Coupon'),
      ),
      '#required' => TRUE,
  );

  $form['commerce_mc_lines']['productSpecCode'] = array(
      '#type' => 'textfield',
      '#title' => t('Product spec code'),
      '#default_value' => $line_settings['productSpecCode'],
      '#description' => t('Se productSpecType for spesifikasjon av dette elementet.'),
      '#states' => array(
          'visible' => array(
              ':input[name="productSpecType"]' => array('value' => 'coupon'),
          ),
          'invisible' => array(
              ':input[name="productSpecType"]' => array('value' => 'product'),
          ),
      ),
  );
  $form['commerce_mc_lines']['productSpecNo'] = array(
      '#type' => 'textfield',
      '#title' => t('Product spec No'),
      '#default_value' => $line_settings['productSpecNo'],
      '#description' => t('Se productSpecType for spesifikasjon av dette elementet.'),
      '#required' => FALSE,
      '#states' => array(
          'visible' => array(
              ':input[name="productSpecType"]' => array('value' => 'coupon'),
          ),
          'invisible' => array(
              ':input[name="productSpecType"]' => array('value' => 'product'),
          ),
      ),
  );
  $form['commerce_mc_lines']['quantity'] = array(
      '#type' => 'textfield',
      '#title' => t('Product quantity'),
      '#default_value' => $line_settings['quantity'],
      '#description' => t('Se productSpecType for spesifikasjon av dette elementet.'),
      '#required' => FALSE,
      '#suffix' => token_replace
  );

  $form['commerce_mc_lines']['unitPrice'] = array(
      '#type' => 'textfield',
      '#title' => t('Unit price'),
      '#default_value' => $line_settings['unitPrice'],
      '#description' => t('Enhetspris inkl. MVA.'),
      '#required' => FALSE,
  );
  
  
  

  // Available tokens only order
  $line_item_token_types = array(
      'commerce-line-item' => 'commerce-line-item'
  );
  // Set up the tokenization
  if (module_exists('token')) {
    $form['commerce_mc_lines']['line_item_token_tree'] = array(
        '#theme' => 'token_tree',
        '#token_types' => $line_item_token_types,
    );
  }


  // Now everythin's in commerce_mc_map.
  return system_settings_form($form);
}

function commerce_mc_login_form() {
  $form = array();
  $form['commerce_mc_uname'] = array(
      '#type' => 'textfield',
      '#title' => t('Mediaconnect username'),
      '#default_value' => variable_get('commerce_mc_uname'),
      '#description' => t('The username you want to connect to MediaConnect with.'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
  );

  $form['commerce_mc_pass'] = array(
      '#type' => 'textfield',
      '#title' => t('Mediaconnect pass'),
      '#default_value' => variable_get('commerce_mc_pass'),
      '#description' => t('The password you want to connect to MediaConnect with.'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
  );
  return system_settings_form($form);
}

/**
 * Default settings for the configurations
 * @todo replace these with token texts (where not constants).
 * @return type 
 */
function commerce_mc_default_order_settings() {
  return array(
      'order' => array(
          'order_test' => 1,
          'orderTime' => '[current-date:custom:Y-m-d\TH:i:s]',
          'marketingCouponcode' => 'TESTKUPONG',
          'marketingCouponno' => '1234',
          'paymentMethod' => 'prepaid',
          'totalInclVat' => '625.00',
      ),
      'lines' => array(
          'productSpecType' => 'product',
          'orderProduct' => 'BOK',
          'quantity' => '1',
          'unitPrice' => '625.00',
      ),
      'payer' => array(
          'firstName' => 'Mikke',
          'lastName' => 'Mus',
          'street' => 'Andeveien',
          'postalCode' => '0975',
          'postalPlace' => 'Oslo',
          'countryCode' => 'NO',
      )
  );
}

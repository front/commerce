<?php

/**
 * Mapping settings
 */
function commerce_mc_order_form($form, &$form_state, $order) {
    $form = array();
    $form['info'] = array(
        '#type' => 'markup',
        '#markup' => t('Nothing here yet.') . dpm(commerce_product_load(5)) . dpm($order) . commerce_mc_process_order($order) . dpm(variable_get('commerce_mc_order')),
    );

    return $form;
}
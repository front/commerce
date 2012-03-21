<?php

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function allertheme_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL) {
  // Remove tablets and mobile settings.
  unset($form['at']['tablet']);
  unset($form['at']['smartphone']);
}

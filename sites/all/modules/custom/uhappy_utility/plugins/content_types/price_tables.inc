<?php
/**
 * @file
 * Displays a header bar.
 */

$plugin = array(
  'title' => t('Price tables'),
  // 'description' => t('Horizontal bar for headers.'),
  'category' => array('Uhappy', -10),
  'single' => TRUE,
  'key' => 'price_table',
  // 'defaults' => array(
  //   'header_title' => '',
  //   'description' => '',
  //   'back_link_name' => '',
  //   'back_link_url' => ''
  // ),
  'edit form' => 'price_table_content_type_edit_form',
  'render callback' => 'price_table_content_type_render',
  'all contexts' => TRUE,
);

/* --- HOOKS ---------------------------------------------------------------- */
/**
 * Output function for the 'custom teaser' content type. Outputs a custom
 * based on the module and delta supplied in the configuration.
 */
function price_table_content_type_render($subtype, $conf, $args, $contexts) {
  $block          = new stdClass();
  $block->content = '';
  $content = array();

  if ($args[0]) $node = node_load($args[0]);

  if (!empty($node->field_price_for_1_person)) {
    $content['price_for_1'] = $node->field_price_for_1_person['und'][0]['value'];
  }

  if (!empty($node->field_price_for_2_person)) {
    $content['price_for_2'] = $node->field_price_for_2_person['und'][0]['value'];
  }

  $block->content = theme('price_table', $content);

  return $block;
}

/**
 * Callback to provide administrative info. In this case we'll render the
 * content as long as it's not PHP, which is too risky to render here.
 */
function price_table_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title   = check_plain($conf['pane_header_title']) ? check_plain($conf['pane_header_title']) : '';
  $block->content = '';

  // if ($conf['pane_header_description']) {
  //   $block->content = t('Description') . ': ' . $conf['pane_header_description'];
  // }

  return $block;
}

/**
 * Callback to provide the teaser title of the custom teaser content.
 */
function price_table_content_type_admin_title($subtype, $conf) {
  $output = t('Header Pane');
  $title = !empty($conf['pane_header_title']) ? $conf['pane_header_title'] : '';

  if ($title) {
    $output = t('Header Pane: @title', array('@title' => $title));
  }

  return $output;
}

/**
 * Returns an edit form for the custom teaser type.
 */
function price_table_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  // $form['fieldset'] = array(
  //   '#type' => 'fieldset',
  //   '#title' => t('Header Pane settings'),
  //   '#weight' => 1,
  //   '#collapsed' => FALSE,
  // );
  // $form['fieldset']['pane_header_title'] = array(
  //   '#type' => 'textfield',
  //   '#default_value' => isset($conf['pane_header_title']) ? $conf['pane_header_title'] : '',
  //   '#title' => t('Pane Header title'),
  // );
  // $form['fieldset']['pane_header_description'] = array(
  //   '#type' => 'text_format',
  //   '#title' => t('Pane header description'),
  //   '#default_value' => isset($conf['pane_header_description']) ? $conf['pane_header_description']['value'] : '',
  //   '#rows' => 10,
  //   '#base_type' => 'textarea',
  //   '#format' => 'plain_text'
  // );
  // $form['back_link_fieldset'] = array(
  //   '#type' => 'fieldset',
  //   '#title' => t('Back Link'),
  //   '#weight' => 1,
  //   '#collapsed' => TRUE,
  //   '#collapsible' => TRUE
  // );
  // $form['back_link_fieldset']['back_link_name'] = array(
  //   '#type' => 'textfield',
  //   '#default_value' => isset($conf['back_link_name']) ? $conf['back_link_name'] : '',
  //   '#title' => t('Back link name'),
  // );
  // $form['back_link_fieldset']['back_link_url'] = array(
  //   '#type' => 'textfield',
  //   '#default_value' => isset($conf['back_link_url']) ? $conf['back_link_url'] : '',
  //   '#title' => t('Back link URL'),
  // );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function sty_site_header_pane_content_type_edit_form_submit(&$form, &$form_state) {
  //save config values
  if (isset($form_state['values'])) {
    $form_state['conf'] = $form_state['values'];
  }
}

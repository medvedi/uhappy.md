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

  // Include the CTools tools that we need.
  ctools_include('ajax');
  ctools_include('modal');
  // The view has two fields, title (not linked and no styles added), and NID (again,
  // no style added. They are available here as $vars['fields']->title and
  // $vars['fields']->nid.
  $name = $node->title;
  // Create a path for the url that is like our hook_menu() declaration above.
  $href = 'order/nojs/' . $node->nid;
  // Here's the ctools function that generates the trigger inside the link
  // ctools_modal_text_button($text, $dest, $alt, $class = '')
  // http://api.drupalize.me/api/drupal/function/ctools_modal_text_button/7
  // IMPORTANT: Include ctools-modal-[your declared style name] as a class so
  // Ctools knows what Javascript settings to use in generating the modal:
  $content['ctools_link'] = ctools_modal_text_button($name, $href, t('View node content for @name', array('@name' => $name)), 'ctools-modal-uhappy-modal-style');

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

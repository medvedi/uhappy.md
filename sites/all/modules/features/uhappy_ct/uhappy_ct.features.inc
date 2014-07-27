<?php
/**
 * @file
 * uhappy_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhappy_ct_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function uhappy_ct_image_default_styles() {
  $styles = array();

  // Exported image style: gallery.
  $styles['gallery'] = array(
    'name' => 'gallery',
    'label' => 'gallery',
    'effects' => array(
      3 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 282,
          'height' => 147,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function uhappy_ct_node_info() {
  $items = array(
    'order' => array(
      'name' => t('Order'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'scenario' => array(
      'name' => t('Scenario'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'slider' => array(
      'name' => t('Slider'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

<?php

/**
 * Page alter.
 */
function uhappy_theme_page_alter($page) {
  $mobileoptimized = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' =>  'MobileOptimized',
      'content' =>  'width'
    )
  );
  $handheldfriendly = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' =>  'HandheldFriendly',
      'content' =>  'true'
    )
  );
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' =>  'viewport',
      'content' =>  'width=device-width, initial-scale=1'
    )
  );
  drupal_add_html_head($mobileoptimized, 'MobileOptimized');
  drupal_add_html_head($handheldfriendly, 'HandheldFriendly');
  drupal_add_html_head($viewport, 'viewport');
}

/**
 * Preprocess variables for html.tpl.php
 */
function uhappy_theme_preprocess_html(&$variables) {
  /**
   * Add IE8 Support
   */
  drupal_add_css(path_to_theme() . '/css/ie8.css', array('group' => CSS_THEME, 'browsers' => array('IE' => '(lt IE 9)', '!IE' => FALSE), 'preprocess' => FALSE));

  /**
   * Add Javascript for enable/disable Bootstrap 3 Javascript
   */
  if (theme_get_setting('bootstrap_js_include', 'bootstrap_business')) {
    drupal_add_js(drupal_get_path('theme', 'bootstrap_business') . '/bootstrap/js/bootstrap.min.js');
  }
  //EOF:Javascript

  /**
   * Add Javascript for enable/disable scrollTop action
   */
  if (theme_get_setting('scrolltop_display', 'bootstrap_business')) {

    drupal_add_js('jQuery(document).ready(function($) {
		$(window).scroll(function() {
			if($(this).scrollTop() != 0) {
				$("#toTop").fadeIn();
			} else {
				$("#toTop").fadeOut();
			}
		});

		$("#toTop").click(function() {
			$("body,html").animate({scrollTop:0},800);
		});

		});',
      array('type' => 'inline', 'scope' => 'header'));
  }
  //EOF:Javascript

  // Add fredSel on all pages.
  $carouFredSel_path = libraries_get_path('carouFredSel');
  if (!empty($carouFredSel_path)) {
    drupal_add_js($carouFredSel_path . '/jquery.carouFredSel-6.2.1-packed.js');
  }

  // Add touchSwipe on all pages.
  $touchSwipe_path = libraries_get_path('touchSwipe');
  if (!empty($touchSwipe_path)) {
    drupal_add_js($touchSwipe_path . '/jquery.touchSwipe.js');
  }

  // Add chosen on all pages.
  $chosen_path = libraries_get_path('chosen');
  if (!empty($chosen_path)) {
    drupal_add_js($chosen_path . '/chosen.jquery.js');
  }

  // Add imagesloaded on all pages.
  $imagesloaded_path = libraries_get_path('imagesloaded');
  if (!empty($imagesloaded_path)) {
    drupal_add_js($imagesloaded_path . '/imagesloaded.pkgd.js');
  }

}

/**
 * Override or insert variables into the html template.
 */
function uhappy_theme_process_html(&$vars) {
  // Hook into color.module
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}

/**
 * Override or insert variables into the page template.
 */
function uhappy_theme_process_page(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }

  // Define new variables for site_phone && site_phone_description.
  $site_phone = variable_get('site_phone', '');
  $site_phone_description = variable_get('site_phone_description', '');
  $variables['page']['navigation']['site_phone']['#markup'] = '<div class="site-phone"> <span class="phone">' . $site_phone . '</span><span class="description">' . $site_phone_description . '</span></div>';
}

/**
 * Preprocess variables for block.tpl.php
 */
function uhappy_theme_preprocess_block(&$variables) {
  $variables['classes_array'][]='clearfix';
}

/**
 * Override theme_breadrumb().
 *
 * Print breadcrumbs as a list, with separators.
 */
function uhappy_theme_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    $breadcrumb[] = drupal_get_title();
    $breadcrumbs = '<ol class="breadcrumb">';

    $count = count($breadcrumb) - 1;
    foreach ($breadcrumb as $key => $value) {
      $breadcrumbs .= '<li>' . $value . '</li>';
    }
    $breadcrumbs .= '</ol>';

    return $breadcrumbs;
  }
}

/**
 * Search block form alter.
 */
function uhappy_theme_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    unset($form['search_block_form']['#title']);
    $form['search_block_form']['#title_display'] = 'invisible';
    $form_default = t('Search this website...');
    $form['search_block_form']['#default_value'] = $form_default;

    $form['actions']['submit']['#attributes']['value'][] = '';

    $form['search_block_form']['#attributes'] = array('onblur' => "if (this.value == '') {this.value = '{$form_default}';}", 'onfocus' => "if (this.value == '{$form_default}') {this.value = '';}" );
  }
}

function uhappy_theme_js_alter(&$javascript) {
  // Swap out ctools modal js to use a local version.
  $jsPath = '/sites/all/themes/uhappy_theme/js/modal.js';
  $javascript['sites/all/modules/contrib/ctools/js/modal.js']['data'] = $jsPath;
}

drupal_add_js('/sites/all/themes/uhappy_theme/js/main.js');

function uhappy_theme_preprocess_node(&$variables) {
  if ($variables['view_mode'] == 'full') {

    $name = t('Order');
    // Create a path for the url that is like our hook_menu() declaration above.
    $href = 'order/nojs/' . $variables['nid'];
    $variables['order_link'] = ctools_modal_text_button($name, $href, t('View node content for @name', array('@name' => $name)), 'ctools-modal-uhappy-modal-style');

    // Define new variables for site_phone && site_phone_description.
    $site_phone = variable_get('site_phone', '');
    $site_phone_description = variable_get('site_phone_description', '');
    $variables['site_phone'] = $site_phone;
    $variables['site_phone_description'] = $site_phone_description;
  }
}

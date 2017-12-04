<?php
/**
 * @file
 * controls load theme.
 */
// Split funtions and stuff into seperate files for eaiser house keeping.
$theme_path = drupal_get_path('theme', 'gavias_mdeal');
global $theme_root, $parent_root;
$theme_root = base_path() . path_to_theme();
$parent_root = base_path() . drupal_get_path('theme', 'gavias_mdeal');
include_once $theme_path . '/includes/template.functions.php';
include_once $theme_path . '/includes/functions.php';
include_once $theme_path . '/includes/dynamic_style.php';

/**
 * Assign theme hook suggestions for custom templates and pass color theme setting
 */  
function gavias_mdeal_preprocess_page(&$vars, $hook) {
  if (isset($vars['node'])) {
    $suggest = "page__node__{$vars['node']->type}";
    $vars['theme_hook_suggestions'][] = $suggest;
  }
  
  if (arg(0) == 'taxonomy' && arg(1) == 'term' ){
    $term = taxonomy_term_load(arg(2));
    $vars['theme_hook_suggestions'][] = 'page--taxonomy--vocabulary--' . $term->vid;
  }

  if($panel_page = page_manager_get_current_page()) {
    // Add a generic suggestion for all panel pages.
    $vars['theme_hook_suggestions'][] = 'page__panel';
    // Add the panel page machine name to the template suggestions.
    $vars['theme_hook_suggestions'][] = 'page__' . $panel_page['name'];
    // Add a body class for good measure.
    $body_classes[] = 'page-panel';
  }

  $alias = drupal_get_path_alias($_GET['q']);
  if ($alias != $_GET['q']) {
    $vars['theme_hook_suggestions'][] = 'page__'. str_replace('-', '_', $alias);     
  }
}

/**
 * Override or insert variables into the html template.
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
function gavias_mdeal_preprocess_html(&$vars) {

  global $theme, $base_url;
  global $parent_root;
  $skin = theme_get_setting('theme_skin');
  drupal_add_css(drupal_get_path('theme', 'gavias_mdeal') . '/css/' . ($skin ? ('skins/' . $skin . '/') : '' ) . 'template.css', array('group' => CSS_DEFAULT, 'type' => 'file'));
  drupal_add_css(drupal_get_path('theme', 'gavias_mdeal') . '/css/' . ($skin ? ('skins/' . $skin . '/') : '' ) . 'bootstrap.css', array('group' => CSS_DEFAULT, 'type' => 'file'));
 
  $viewport = array(
     '#type' => 'html_tag',
     '#tag' => 'meta',
     '#attributes' => array(
       'name' => 'viewport',
       'content' =>  'width=device-width, initial-scale=1, maximum-scale=1',
     ),
     '#weight' => 1,
   );

    $background_image = array(
     '#type' => 'markup',
     '#markup' => "<style type='text/css'>body {background-image:url(".$parent_root."/images/patterns/".theme_get_setting('background_select').".png);}</style> ",
     '#weight' => 2,
   );

   $background_color = array(
     '#type' => 'markup',
     '#markup' => "<style type='text/css'>body {background-color: #".theme_get_setting('body_background_color')." !important;}</style> ",
     '#weight' => 3,
   );
   
   drupal_add_html_head( $viewport, 'viewport');

   if ( theme_get_setting('site_layout') == "boxed") {
     drupal_add_html_head( $background_image, 'background_image');
   }

   if (theme_get_setting('body_background') == "custom_background_color") {
     drupal_add_html_head( $background_color, 'background_color');
   }
   // Add boxed class if layout is set that way.
   if (theme_get_setting('site_layout') == 'boxed'){
     $vars['classes_array'][] = 'boxed';
   }

   if(theme_get_setting('preloader') == '1'){
      $vars['classes_array'][] = 'js-preloader';
   }else{
      $vars['classes_array'][] = 'not-preloader';
   }
}

function gavias_mdeal_process_html(&$vars) {
  $vars['head_scripts'] = drupal_get_js('head_scripts');
}

function gavias_mdeal_form_comment_form_alter(&$form, &$form_state) {
    $form['author']['homepage']['#access'] = FALSE;
}


/**
 * Implements hook_preprocess_region().
 */ 
function gavias_mdeal_preprocess_region(&$variables) {
  global $theme;
  static $wells;
  if (!isset($wells)) {
    foreach (system_region_list($theme) as $name => $title) {
      $wells[$name] = theme_get_setting('gavias_mdeal_region_well-' . $name);
    }
  }
  switch ($variables['region']) {
    case 'content':
      $variables['theme_hook_suggestions'][] = 'region__no_wrapper';
      break;
    case 'help':
      $variables['content'] = _gavias_mdeal_icon('question-sign') . $variables['content'];
      $variables['classes_array'][] = 'alert';
      $variables['classes_array'][] = 'alert-info';
      break;
  }
  if (!empty($wells[$variables['region']])) {
    $variables['classes_array'][] = $wells[$variables['region']];
  }
}

/**
*  Implements theme_css_alter().
*/
function gavias_mdeal_css_alter(&$css) {
  if (theme_get_setting('rtl') == 1) {
    unset($css[drupal_get_path('theme', 'gavias_mdeal') . '/css/bootstrap.css']);
  }
  // Remove defaults.css file.
    unset($css[drupal_get_path('module', 'system') . '/defaults.css']);
    unset($css[drupal_get_path('module', 'system') . '/system.css']);
    unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
    unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
    unset($css[drupal_get_path('module', 'user') . '/user.css']);
    // .. etc..
}


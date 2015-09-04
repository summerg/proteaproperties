<?php
/**
 * @file
 * Panel style for the Gavias theme.
 */

/**
 * Implementation of hook_panels_style_info().
 */
function gavias_panels_gavias_panels_block_style_panels_styles() {
    return array(
        'title' => t('Gavias Panel Block style'),
        'description' => t('Panel Block style for the Gavias theme.'),
        'render pane' => 'gavias_panels_block_style_render_pane',
        'render region' => 'gavias_panels_block_style_render_region',
        'pane settings form' => 'gavias_panels_block_style_settings_form',
        'hook theme' => array(
            'gavias_panels_block' => array(
              'variables' => array('content' => NULL),
              'path' => drupal_get_path('module', 'gavias_panels') . '/templates',
              'template' => 'gavias-panels-block',
            ),
          ),
    );
}

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_gavias_panels_block_style_render_region($vars) {
    return implode($vars['panes']);
}

/**
 * Form callback.
 */
function gavias_panels_block_style_settings_form($settings) {
    /* Wrapper ID*/
    $form['wrapper_id'] = array(
        '#type' => 'textfield',
        '#title' => t('Wrapper ID'),
        '#description' => t('The class to provide on the wrapper, outside the pane.'),
        '#default_value' => (isset($settings['wrapper_id'])) ? $settings['wrapper_id'] : ''
    );
    /* Wrapper Classes*/
    $form['wrapper_classes'] = array(
        '#type' => 'textfield',
        '#title' => t('Wrapper Classes'),
        '#description' => t('The class to provide on the wrapper, outside the pane.'),
        '#default_value' => (isset($settings['wrapper_classes'])) ? $settings['wrapper_classes'] : ''
    );

    // background position
    $form['animation']= array(
        '#type' => 'select',
        '#title' => t('Animation'),
        '#options' => array(
            ''      => '-- None --',
            'bounce' => 'bounce',
            'flash' => 'flash',
            'pulse' => 'pulse',
            'rubberBand' => 'rubberBand',
            'shake' => 'shake',
            'swing' => 'swing',
            'tada' => 'tada',
            'wobble' => 'wobble',
            'jello' => 'jello',
            'bounceIn' => 'bounceIn',
            'bounceInDown' => 'bounceInDown',
            'bounceInLeft' => 'bounceInLeft',
            'bounceInRight' => 'bounceInRight',
            'bounceInUp' => 'bounceInUp',
            'fadeIn' => 'fadeIn',
            'fadeInDown' => 'fadeInDown',
            'fadeInDownBig' => 'fadeInDownBig',
            'fadeInLeft' => 'fadeInLeft',
            'fadeInLeftBig' => 'fadeInLeftBig',
            'fadeInRight' => 'fadeInRight',
            'fadeInRightBig' => 'fadeInRightBig',
            'fadeInUp' => 'fadeInUp',
            'fadeInUpBig' => 'fadeInUpBig',
            'flip' => 'flip',
            'flipInX' => 'flipInX',
            'flipInY' => 'flipInY',
            'flipOutX' => 'flipOutX',
            'flipOutY' => 'flipOutY',
            'lightSpeedIn' => 'lightSpeedIn',
            'rotateIn' => 'rotateIn',
            'rotateInDownLeft' => 'rotateInDownLeft',
            'rotateInDownRight' => 'rotateInDownRight',
            'rotateInUpLeft' => 'rotateInUpLeft',
            'rotateInUpRight' => 'rotateInUpRight',
            'slideInUp' => 'slideInUp',
            'slideInDown' => 'slideInDown',
            'slideInLeft' => 'slideInLeft',
            'slideInRight' => 'slideInRight',
            'zoomIn' => 'zoomIn',
            'zoomInDown' => 'zoomInDown',
            'zoomInLeft' => 'zoomInLeft',
            'zoomInRight' => 'zoomInRight',
            'zoomInUp' => 'zoomInUp',
            'rollIn' => 'rollIn',
        ),
        '#default_value' => (isset($settings['animation'])) ? $settings['animation'] : '',
    );

    /* Wrapper Classes*/
    $form['background_color'] = array(
        '#type' => 'textfield',
        '#title' => t('Background color (example: #f5f5f5)'),
        '#description' => t(''),
        '#default_value' => (isset($settings['background_color'])) ? $settings['background_color'] : ''
    );

    /* background image */
    $form['background_image'] = array(
        '#type' => 'media',
        '#tree' => TRUE,
        '#title' => t('Background image'),
        '#input' => TRUE,
        '#media_options' => array(
            'global' => array(
                'types' => array('image'), // Example: array('image', 'audio');
                'schemes' => array('http'), // Example: array('http', 'ftp', 'flickr');
            ),
        ),
        '#default_value' => array('fid' => (isset($settings['background_image'])) ? $settings['background_image'] : ''), // Change to your default value
    );

    /* background effects */
    $form['background_effects'] = array(
        '#type' => 'item',
        '#title' => t('Background effects'),
        '#prefix' => '<div class="gavias-pane-inline">',
        '#suffix' => '</div>',
    );

    // background repeat
    $form['background_effects']['background_repeat'] = array(
        '#type' => 'select',
        '#title' => t('Repeat'),
        '#options' => array(
            'inherit' => t('Inherit'),
            'repeat' => t('Repeat'),
            'repeat-x' => t('Repeat X'),
            'repeat-y' => t('Repeat Y'),
            'no-repeat' => t('No repeat'),
        ),
        '#default_value' => (isset($settings['background_effects']['background_repeat'])) ? $settings['background_effects']['background_repeat'] : 'inherit',
    );

    // background position
    $form['background_effects']['background_position'] = array(
        '#type' => 'select',
        '#title' => t('Position'),
        '#options' => array(
            'left top' => t('Left Top'),
            'left center' => t('Left Center'),
            'left bottom' => t('Left Bottom'),
            'center center' => t('Center Center'),
            'center top' => t('Center Top'),
            'center bottom' => t('Center Bottom'),
            'right top' => t('Right Top'),
            'right center' => t('Right Center'),
            'right bottom' => t('Right Bottom'),
        ),
        '#default_value' => (isset($settings['background_effects']['background_position'])) ? $settings['background_effects']['background_position'] : 'left top',
    );

    // background attachment
    $form['background_effects']['background_attachment'] = array(
        '#type' => 'select',
        '#title' => t('Attachment'),
        '#options' => array(
            'scroll' => t('Scroll'),
            'fixed' => t('Fixed'),
        ),
        '#default_value' => (isset($settings['background_effects']['background_attachment'])) ? $settings['background_effects']['background_attachment'] : 'scroll',
    );

    return $form;
}

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_gavias_panels_block_style_render_pane($vars) {
    $content = $vars['content'];
    $pane = $vars['pane'];
    $settings = $vars['settings'];
    $display = $vars['display'];
    $render = '';
    $wrap_open = '';
    $wrap_close = '';
    $css_bg = '';
    if (empty($content->content)) {
        return;
    }

    if (isset($pane->style['style']) && $pane->style['style'] == 'gavias_panels_block_style') {

        $vars['classes_array'][] = 'gavias-pane';

        // background
        $bg_attributes = array();
        if (!empty($settings['background_color']) || !empty($settings['background_image']['fid'])) {

            // background image
            if (!empty($settings['background_image']['fid']) && $settings['background_image']['fid'] != 0) {
                $file = file_load($settings['background_image']['fid']);
                $path_url = file_create_url($file->uri);
                $bg_attributes[] = 'url(' . $path_url . ')';
                $bg_attributes[] = $settings['background_effects']['background_repeat'];
                $bg_attributes[] = $settings['background_effects']['background_position'];
                $bg_attributes[] = $settings['background_effects']['background_attachment'];
            }

            // background color
            if (!empty($settings['background_color'])) {
                $bg_attributes[] = $settings['background_color'];
            }

            $css_bg = 'background: ' . implode(" ", $bg_attributes) . '; ';
        }
    }
    $wrapper_id = '';
    if(!empty($settings['wrapper_id'])) {
        $wrapper_id = $settings['wrapper_id'];
    }
    $wrapper_classes = '';
    if(!empty($settings['wrapper_classes'])) {
        $wrapper_classes = $settings['wrapper_classes'];
    }
    
    if(isset($settings['animation']) && !empty($settings['animation'])){
        $wrapper_classes = ' wow ' . $settings['animation'];
    }

    $output = '';
    if(!empty($wrapper_id) || !empty($wrapper_classes) || !empty($css_bg)) {
        $output .= '<div ';
        if(!empty($wrapper_id)) {
            $output .= ' id="'.$wrapper_id.'"';
        }
        if(!empty($wrapper_classes)) {
            $output .= ' class="'.$wrapper_classes.'"';
        }
        if(!empty($css_bg)) {
            $output .= ' style="'.$css_bg.'"';
        }
        $output .= ">";
    }
 
    $output .= theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));

    if(!empty($wrapper_id) || !empty($wrapper_classes) || !empty($css_bg)) {
        $output .= '</div>';
    }
   
    return $output;
}


<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Fullwidth'),
  'category' => t('Gavias Layout'),
  'icon' => 'fullwidth.png',
  'theme' => 'panels_fullwidth',
  'css' => 'fullwidth.css',
  'regions' => array(
      'main'    => 'Main Content'
  )
);

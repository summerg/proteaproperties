<?php
/**
 * @file
 * headquarters_events_pull.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function headquarters_events_pull_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_events:node/add/events.
  $menu_links['navigation_events:node/add/events'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/events',
    'router_path' => 'node/add/events',
    'link_title' => 'Events',
    'options' => array(
      'identifier' => 'navigation_events:node/add/events',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_xml-events-feed:node/add/xml-events-feed.
  $menu_links['navigation_xml-events-feed:node/add/xml-events-feed'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/xml-events-feed',
    'router_path' => 'node/add/xml-events-feed',
    'link_title' => 'XML Events Feed',
    'options' => array(
      'identifier' => 'navigation_xml-events-feed:node/add/xml-events-feed',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Events');
  t('XML Events Feed');

  return $menu_links;
}

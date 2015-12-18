<?php
/**
 * @file
 * headquarters_events_pull.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function headquarters_events_pull_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer xmlsitemap'.
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'xmlsitemap',
  );

  // Exported permission: 'clear headquarters_events feeds'.
  $permissions['clear headquarters_events feeds'] = array(
    'name' => 'clear headquarters_events feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'create xml_events_feed content'.
  $permissions['create xml_events_feed content'] = array(
    'name' => 'create xml_events_feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any xml_events_feed content'.
  $permissions['delete any xml_events_feed content'] = array(
    'name' => 'delete any xml_events_feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own xml_events_feed content'.
  $permissions['delete own xml_events_feed content'] = array(
    'name' => 'delete own xml_events_feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any xml_events_feed content'.
  $permissions['edit any xml_events_feed content'] = array(
    'name' => 'edit any xml_events_feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own xml_events_feed content'.
  $permissions['edit own xml_events_feed content'] = array(
    'name' => 'edit own xml_events_feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'import headquarters_events feeds'.
  $permissions['import headquarters_events feeds'] = array(
    'name' => 'import headquarters_events feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'tamper headquarters_events'.
  $permissions['tamper headquarters_events'] = array(
    'name' => 'tamper headquarters_events',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock headquarters_events feeds'.
  $permissions['unlock headquarters_events feeds'] = array(
    'name' => 'unlock headquarters_events feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  return $permissions;
}

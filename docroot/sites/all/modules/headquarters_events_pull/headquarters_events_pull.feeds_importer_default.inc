<?php
/**
 * @file
 * headquarters_events_pull.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function headquarters_events_pull_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'headquarters_events';
  $feeds_importer->config = array(
    'name' => 'Headquarters Events',
    'description' => 'Import the events from the Headquarters Site to appear on the Visit Seaport Page',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(),
        'rawXML' => array(),
        'context' => '',
        'exp' => array(
          'errors' => FALSE,
          'tidy' => FALSE,
          'debug' => array(),
          'tidy_encoding' => 'UTF8',
        ),
        'allow_override' => TRUE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'format' => 'full_html',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_post_image:uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_date:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_date:end',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'status',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_which_calendar',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_external_url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'events',
      ),
    ),
    'content_type' => 'xml_events_feed',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['headquarters_events'] = $feeds_importer;

  return $export;
}

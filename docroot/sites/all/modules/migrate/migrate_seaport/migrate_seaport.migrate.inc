<?php

/**
 * @file
 * Because the name of this file is the module name plus '.migrate.inc', when
 * hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded - thus, you don't need to implement your hook in the .module file.
 */

/*
 * You must implement hook_migrate_api(), setting the API level to 2, if you are
 * implementing any migration classes. As of Migrate 2.5, you should also
 * register your migration and handler classes explicitly here - the former
 * method of letting them get automatically registered on a cache clear will
 * break in certain environments (see http://drupal.org/node/1778952).
 */
function migrate_seaport_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'seaport' => array(
        'title' => t('Seaport Village Blog and Events Imports'),
      ),
    ),
    'migrations' => array(

      'Article' => array( 'class_name' => 'ArticleMigration' , 'group_name' => 'seaport', ),
      // 'News' => array( 'class_name' => 'NewsMigration' , 'group_name' => 'seaport', ),
      'Events' => array( 'class_name' => 'EventsMigration' , 'group_name' => 'seaport', ),
      'Businesses' => array(  'class_name' => 'BusinessMigration' , 'group_name' => 'seaport', ),


      // 'UserDB' => array('class_name' => 'UserDBMigration' ),
      // 'PostDB' => array('class_name' => 'PostDBMigration' ),
      // 'UserCB' => array('class_name' => 'UserCBMigration' ),
      // 'PostCB' => array('class_name' => 'PostCBMigration' ),


    ),
  );
  return $api;
}

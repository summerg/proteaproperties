<?php

abstract class SeaportMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    // With migrate_ui enabled, migration pages will indicate people involved in
    // the particular migration, with their role and contact info. We default the
    // list in the shared class; it can be overridden for specific migrations.
    $this->team = array(
      new MigrateTeamMember('Summer Greene', 'summer@1011i.com', t('Data Guru')),
    );

//    parent::__construct(MigrateGroup::getInstance('Articles, Events and Offers', array('default')));

    Database::addConnectionInfo('seaport', 'blog', array(
      'driver' => 'mysql',
      'database' => 'seaport20151006',
      'username' => 'summer',
      'password' => 'w1nacka',
      'host' => 'localhost',
      'prefix' => '',
    ));

  }


 static public function Slug($string)
  {
      return strtolower(trim(preg_replace('~[^0-9a-z]+~i', '-', html_entity_decode(preg_replace('~&([a-z]{1,2})(?:acute|cedil|circ|grave|lig|orn|ring|slash|th|tilde|uml);~i', '$1', htmlentities($string, ENT_QUOTES, 'UTF-8')), ENT_QUOTES, 'UTF-8')), '-'));
  }

  static public function truncateTitle($string,$length=250,$append=",") {
      $string = trim($string);

      if(strlen($string) > 240) {
        $string = wordwrap($string, $length);
        $string = explode("\n", $string, 2);
        $string = $string[0] . "...";
      }

      return $string;
  }

  static public function validDate($datetimestamp) {
      $date = new DateTime($datetimestamp);
      echo $date->format("U");

      if ($datetimestamp == "" || $datetimestamp == "0000-00-00 00:00:00"  || $date->getTimestamp() < now() ){
          return false;
      }

      return true;
  }
}
/*
* END BASE
*/


/*
* START BUSINESSES
*/
class BusinessMigration extends SeaportMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Move the Businesses');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'Business ID.',
          'alias' => 'l',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = Database::getConnection('blog', 'seaport')
      -> select('locations', 'l');
    $query -> fields('l', array( 'id', 'name', 'type', 'payment', 'address', 'phone', 'fax',
      'email', 'url', 'map_id', 'contact', 'description', 'excerpt', 'facebook', 'vip_deal', 'parking', 'slug' ))
     ->condition('type', "attraction%", "NOT LIKE");

//     $query ->range(0,5);

    // Passing the cache_counts option means the source count (shown in
    // drush migrate-status) will be cached - this can be very handy when
    // dealing with a slow source database.
    $this->source = new MigrateSourceSQL($query);

    // Set up our destination - nodes of type migrate_example_beer
    $this->destination = new MigrateDestinationNode('business');

    // MAPPED


    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('field_payment_methods', 'payment');
    $this->addFieldMapping('field_business_address', 'address');
    $this->addFieldMapping('field_business_phone', 'phone');
    $this->addFieldMapping('field_business_fax', 'fax');
    $this->addFieldMapping('field_e_mail', 'email');
    $this->addFieldMapping('field_business_website', 'url');
    $this->addFieldMapping('field_business_website:title', 'url');

    $this->addFieldMapping('field_business_suite:title', 'map_id');
    $this->addFieldMapping('field_business_suite', 'map_location');

    $this->addFieldMapping('field_contact', 'contact');
    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:summary', 'excerpt');
    $this->addFieldMapping('field_facebook_url', 'facebook');

    $this->addFieldMapping('field_facebook_url', 'facebook');
    $this->addFieldMapping('field_vip_deal', 'vip_deal');
    $this->addFieldMapping('field_business_nearest_parking', 'parking');
    $this->addFieldMapping('path', 'slug');
    $this->addFieldMapping('field_original_id', 'id');

    $this->addFieldMapping('promote')       ->defaultValue(false);
    $this->addFieldMapping('revision')        ->defaultValue(0);
    $this->addFieldMapping('pathauto')      ->defaultValue(false);
    $this->addFieldMapping('body:format')  ->defaultValue('full_html');
    $this->addFieldMapping('status')          ->defaultValue(1);
    $this->addFieldMapping('sticky', 'is_sticky')       ->defaultValue(false);
    $this->addFieldMapping('comment', 'allow_comments')       ->defaultValue(false);
    $this->addFieldMapping('uid')       ->defaultValue(1);
 //   $this->addFieldMapping('uid')       ->defaultValue(35);

    $this->addFieldMapping('field_business_tags', 'tags');
    $this->addFieldMapping('field_business_tags:create_term')->defaultValue(true);
    $this->addFieldMapping('field_business_tags:ignore_case')->defaultValue(true);



    $this->addUnmigratedDestinations(array('created', 'changed', 'log', 'language', 'tnid', 'translate',
      'revision_uid', 'is_new', 'field_business_tags:source_type'

    ));
  }

public function prepareRow($current_row) {
  $current_row->map_location = "sites/seaport/files/userfiles/files/headquarters-and-seaport-map.pdf";
  if ($current_row->type == "shopping") $current_row->tags[] = "Shops";
  if ($current_row->type == "restaurants") $current_row->tags[] = "Restaurants";
  $query = Database::getConnection('blog', 'seaport')
        -> select('tagging', 't');
      $query -> join('tag', 'tag', 'tag_id=tag.id');
      $query ->fields('tag', array('name'))
        ->condition('taggable_id', $current_row->id)
        ->condition('taggable_model', "Location");
      foreach ( $query->execute()->fetchAll() as $row){
        if ($row->name ) $current_row->tags[] = trim($row->name);
      }
echo print_R($current_row->tags). "\n";




    }
}

/*
* END ARTICLES
*/


class ArticleMigration extends SeaportMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Move the Blog Articles ');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'Blog ID.',
          'alias' => 'b',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = Database::getConnection('blog', 'seaport')
      -> select('a_blog_item', 'b');
    $query -> join('a_page', 'p', 'b.page_id = p.id');
    $query -> join('a_area', 'a', 'a.page_id = p.id');
    $query -> join('a_area_version', 'v', 'v.area_id = a.id');
    $query -> join('a_page_to_category', 'ptc', 'ptc.page_id = p.id');
    $query -> join('a_category', 'c', 'ptc.category_id = c.id');
    $query -> fields('b', array( 'id', 'author_id','page_id', 'title', 'slug', 'published_at'));
    $query -> fields('v', array( "updated_at" ));
    $query -> fields('c', array( "name" ));
    $query->addField('v', 'id', 'version_id');
    $query->addField('c', 'slug', 'cat_slug');
    $query ->where('a.latest_version = v.version');
    $query ->where('c.id in (1,2) ');
    $query ->condition('a.name', 'blog-body');
    //$query ->range(0,15);
//echo $query;

    // Passing the cache_counts option means the source count (shown in
    // drush migrate-status) will be cached - this can be very handy when
    // dealing with a slow source database.
    $this->source = new MigrateSourceSQL($query);

    // Set up our destination - nodes of type migrate_example_beer
    $this->destination = new MigrateDestinationNode('article');

    // MAPPED


    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('created', 'published_at');
    $this->addFieldMapping('changed', 'updated_at');
    $this->addFieldMapping('field_article_type', 'name') ;
    $this->addFieldMapping('path', 'slug');
    $this->addFieldMapping('field_original_id', 'original_id');
    $this->addFieldMapping('body', 'newbody');



    $this->addFieldMapping('promote')       ->defaultValue(false);
    $this->addFieldMapping('revision')        ->defaultValue(0);
    $this->addFieldMapping('pathauto')      ->defaultValue(false);
    $this->addFieldMapping('body:format')  ->defaultValue('full_html');
    $this->addFieldMapping('status')          ->defaultValue(1);
    $this->addFieldMapping('sticky', 'is_sticky')       ->defaultValue(false);
    $this->addFieldMapping('comment', 'allow_comments')       ->defaultValue(false);
 //   $this->addFieldMapping('uid')       ->defaultValue(1);
    $this->addFieldMapping('uid')       ->defaultValue(35);


    $this->addFieldMapping('field_article_tags', 'tags');
    $this->addFieldMapping('field_article_tags:create_term')->defaultValue(true);
    $this->addFieldMapping('field_article_tags:ignore_case')->defaultValue(true);


    // $this->addFieldMapping('body:summary', 'extract');

    //  $this->addFieldMapping('field_article_category', 'RelatedCategories');
    // $this->addFieldMapping('field_article_category:ignore_case')->defaultValue(true);

    //  $this->addFieldMapping('field_image', 'image_name'); // image is file name no path in example
    //  $this->addFieldMapping('field_image:source_dir', 'image_path');
    //  $this->addFieldMapping('field_image:alt', 'title');
    //  $this->addFieldMapping('field_image:destination_file', 'image_name');
//     $this->addFieldMapping('field_image:destination_dir')       ->defaultValue('');

     $this->addUnmigratedDestinations(array(

    ));
  }

public function prepareRow($current_row) {
      $published = strtotime($current_row->published_at);
      $current_row->slug = $current_row->cat_slug . "/". date("Y/m/d", $published) . "/" .$current_row->slug;
      $current_row->original_id = $current_row->id;

      $query = Database::getConnection('blog', 'seaport')
        -> select('a_area_version_slot', 'vs');
      $query -> join('a_slot', 's', '  slot_id  = s.id');
      $query ->fields('s', array('value'))
        ->condition('area_version_id', $current_row->version_id)
        ->orderBy("rank");
      foreach ( $query->execute()->fetchAll() as $row){
        if ($row->value ) $current_row->newbody .= trim($row->value) . "\n";
      }

      $query = Database::getConnection('blog', 'seaport')
        -> select('tagging', 't');
      $query -> join('tag', 'tag', 'tag_id=tag.id');
      $query ->fields('tag', array('name'))
        ->condition('taggable_id', $current_row->page_id);

      foreach ( $query->execute()->fetchAll() as $row){
        if ($row->name ) $current_row->tags[] = trim($row->name);
      }

   //    //print($current_row->slug . " - " . implode(", ", $current_row->RelatedCategories)) . "\n";

   //    $query = Database::getConnection('blog', 'georges')
   //      -> select('sf_tagging', 'tagging');
   //    $query -> join('sf_tag', 'tag', 'tag.id  = tagging.tag_id');
   //    $query ->fields('tag', array('Name'))
   //      ->condition('tagging.taggable_id', $current_row->id);
   //    foreach ( $query->execute()->fetchAll() as $row){
   //      if ($row->Name ) $current_row->newbody .= trim($row->Name);
   //    };
   //    //print($current_row->slug . " - " . implode(", ", $current_row->tags)) . "\n";

   //    $users = array ("Amy Grave" => 56, "April Johnson" => 44, "brian@1011i.com" => 18, "cody@1011i.com" => 2, "david@1011i.com" => 50, "esther@gacmail.net" => 49, "Fernando Fry" => 55, "Frankie Thaheld" => 43, "George Hauer" => 46, "George's at the Cove" => 52, "jeff@1011i.com" => 6, "joel@1011i.com" => 19, "Jonathan Bautista" => 54, "Joshua" => 58,  "kristine" => 45, "laura@gacmail.net" => 48, "Lori Sauer" => 57, "melissa@1011i.com" => 20, "monica@gacmail.net" => 47, "Sharon@georgesatthecove.com" => 51, "Stephen Kurpinsky" => 53, "tammy" => 41, "Trey Foshee" => 42);

   //    $query = Database::getConnection('blog', 'georges')
   //      -> select('sf_guard_user', 'users');
   //    $query ->fields('users', array('username'))
   //      ->condition('users.id', $current_row->author_id);
   //    foreach ( $query->execute()->fetchAll() as $row){
   //      if ($row->username ) $current_row->newauthor = $users[$row->username];
   //    };
   //    print($current_row->slug . " - " . $current_row->newauthor . "\n");


   //  if ($current_row->thumbnail != ""){
   //    $last_dot = strrpos( $current_row->ImageLoc , "." );
   //    $strlen = strlen($current_row->ImageLoc);
   //    $imagename = $current_row->thumbnail;

   //    $imagepath = trim("/var/www/html/georgesatthecove/site/web/uploads/blog/");;
   //    $file_headers = @get_headers($imagepath.$imagename);
   //    if($file_headers[0] != 'HTTP/1.1 404 Not Found') {
   //      $current_row->image_path = $imagepath ;
   //      $current_row->image_name =  $imagename;
   //      echo $imagepath . $imagename . "\n";
   //    }

   //  }
   // $Found = str_replace("/uploads/files/Blog/", "/sites/georgesatthecove.com/files/userfiles/images/blog/", $current_row->content);
   // $Found = str_replace("/uploads/files/", "/sites/georgesatthecove.com/files/userfiles/images/", $Found);

   //  if ($Found) {
   //    $current_row->newbody =  $Found;
   //   // echo $current_row->newbody ."\n\n";
   //  }


    }
}

/*
* END ARTICLES
*/




/*
* START EVENTS
*/
class EventsMigration extends SeaportMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Move the Events');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'Blog ID.',
          'alias' => 'b',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = Database::getConnection('blog', 'seaport')
      -> select('a_blog_item', 'b');
    $query -> join('a_page', 'p', 'b.page_id = p.id');
    $query -> join('a_area', 'a', 'a.page_id = p.id');
    $query -> join('a_area_version', 'v', 'v.area_id = a.id');
    $query -> join('a_page_to_category', 'ptc', 'ptc.page_id = p.id');
    $query -> join('a_category', 'c', 'ptc.category_id = c.id');
    $query -> fields('b', array( 'id', 'author_id','page_id', 'title', 'slug', 'published_at',
        'start_date', 'start_time', 'end_date', 'end_time', 'location'));
    $query -> fields('v', array( "updated_at" ));
    $query -> fields('c', array( "name" ));
    $query->addField('v', 'id', 'version_id');
    $query->addField('c', 'slug', 'cat_slug');
    $query ->where('a.latest_version = v.version');
    $query ->where('c.id in (3) ');
    $query ->condition('a.name', 'blog-body');
    $query ->condition('b.type', 'event');

    //$query ->range(0,15);
echo $query;

    // Passing the cache_counts option means the source count (shown in
    // drush migrate-status) will be cached - this can be very handy when
    // dealing with a slow source database.
    $this->source = new MigrateSourceSQL($query);

    // Set up our destination - nodes of type migrate_example_beer
    $this->destination = new MigrateDestinationNode('events');

    // MAPPED


    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('created', 'published_at');
    $this->addFieldMapping('changed', 'updated_at');
    $this->addFieldMapping('field_article_type', 'name') ;
    $this->addFieldMapping('path', 'newslug');
    $this->addFieldMapping('field_original_id', 'original_id');
    $this->addFieldMapping('body', 'newbody');
    $this->addFieldMapping('field_location', 'location');

    $this->addFieldMapping('field_date', 'start_date');
    $this->addFieldMapping('field_date:to', 'end_date');
    $this->addFieldMapping('field_date:timezone')       ->defaultValue("UTC");



//  'start_date', 'start_time', 'end_date', 'end_time', 'location'

    $this->addFieldMapping('promote')       ->defaultValue(false);
    $this->addFieldMapping('revision')        ->defaultValue(0);
    $this->addFieldMapping('pathauto')      ->defaultValue(false);
    $this->addFieldMapping('body:format')  ->defaultValue('full_html');
    $this->addFieldMapping('status')          ->defaultValue(1);
    $this->addFieldMapping('sticky', 'is_sticky')       ->defaultValue(false);
    $this->addFieldMapping('comment', 'allow_comments')       ->defaultValue(false);
//    $this->addFieldMapping('uid')       ->defaultValue(1);
    $this->addFieldMapping('uid')       ->defaultValue(35);


    $this->addFieldMapping('field_article_tags', 'tags');
    $this->addFieldMapping('field_article_tags:create_term')->defaultValue(true);
    $this->addFieldMapping('field_article_tags:ignore_case')->defaultValue(true);



     $this->addUnmigratedDestinations(array(

    ));
  }

public function prepareRow($current_row) {
      $current_row->original_id = $current_row->id;
      $published = strtotime($current_row->published_at);
      $current_row->newslug =  "events-calendar/". date("Y/m/d", $published) . "/" .$current_row->slug;
     // echo "\n\n".$current_row->newslug;




$original_datetime = $current_row->start_date . " " . $current_row->start_time;
$startzone=new DateTimeZone('America/Los_Angeles');
$datetime = new DateTime($current_row->start_date,$startzone );
$target_timezone = new DateTimeZone('UTC');
$datetime->setTimeZone($target_timezone);
$interval = new DateInterval('PT'. (3*60*60) .'S');
$datetime->add($interval);
$current_row->start_date = $current_row->start_date . " " . $current_row->start_time;
// echo "\nstart: ". $original_datetime . " UTC:" . $current_row->start_date; // echoes 04/01/2013 03:08 PM

$original_datetime = $current_row->end_date . " " . $current_row->end_time;
$original_timezone = new DateTimeZone('America/Los_Angeles');
$datetime = new DateTime($original_datetime, $original_timezone);
$target_timezone = new DateTimeZone('UTC');
$datetime->setTimeZone($target_timezone);
$interval = new DateInterval('PT'. (7*60*60) .'S');
$datetime->sub($interval);
$current_row->end_date = $current_row->end_date . " " . $current_row->end_time;
// echo "\nend: ". $original_datetime . " UTC:" . $current_row->end_date; // echoes 04/01/2013 03:08 PM


//  'start_date', 'start_time', 'end_date', 'end_time', 'location'


      $query = Database::getConnection('blog', 'seaport')
        -> select('a_area_version_slot', 'vs');
      $query -> join('a_slot', 's', '  slot_id  = s.id');
      $query ->fields('s', array('value'))
        ->condition('area_version_id', $current_row->version_id)
        ->orderBy("rank");
      foreach ( $query->execute()->fetchAll() as $row){
        if ($row->value ) $current_row->newbody .= trim($row->value) . "\n";
      }

      $query = Database::getConnection('blog', 'seaport')
        -> select('tagging', 't');
      $query -> join('tag', 'tag', 'tag_id=tag.id');
      $query ->fields('tag', array('name'))
        ->condition('taggable_id', $current_row->page_id);

      foreach ( $query->execute()->fetchAll() as $row){
        if ($row->name ) $current_row->tags[] = trim($row->name);
      }



    }
}

/*
* END Events
*/



/*
* END NEWS
*/



class NewsMigration extends SeaportMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Move the News Articles ');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'News ID.',
          'alias' => 'p',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = Database::getConnection('blog', 'seaport')
      -> select('a_page_to_category', 'ptc');
    $query -> join('a_page', 'p', 'ptc.page_id = p.id');
    $query -> join('a_area', 'a', 'a.page_id = p.id');
    $query -> join('a_area_version', 'v', 'v.area_id = a.id');
    $query -> fields('p', array( 'id', 'slug', 'published_at'));
    $query -> fields('v', array( "updated_at" ));
    $query->addField('v', 'id', 'version_id');
    $query ->where('a.latest_version = v.version');
    $query ->condition('a.name', 'title');
    $query ->where('ptc.category_id = 1');
    $query ->range(0,10);
   // echo $query;

//    $query ->condition('ptc.category_id', 'blog-body');
    //$query ->range(0,15);

    // Passing the cache_counts option means the source count (shown in
    // drush migrate-status) will be cached - this can be very handy when
    // dealing with a slow source database.
    $this->source = new MigrateSourceSQL($query);

    // Set up our destination - nodes of type migrate_example_beer
    $this->destination = new MigrateDestinationNode('article');

    // MAPPED


    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('created', 'published_at');
    $this->addFieldMapping('changed', 'updated_at');
    $this->addFieldMapping('field_article_type') ->defaultValue("News");
    $this->addFieldMapping('path', 'slug');
    $this->addFieldMapping('field_original_id', 'original_id');
    $this->addFieldMapping('body', 'newbody');



    $this->addFieldMapping('promote')       ->defaultValue(false);
    $this->addFieldMapping('revision')        ->defaultValue(0);
    $this->addFieldMapping('pathauto')      ->defaultValue(false);
    $this->addFieldMapping('body:format')  ->defaultValue('full_html');
    $this->addFieldMapping('status')          ->defaultValue(1);
    $this->addFieldMapping('sticky', 'is_sticky')       ->defaultValue(false);
    $this->addFieldMapping('comment', 'allow_comments')       ->defaultValue(false);
    $this->addFieldMapping('uid')       ->defaultValue(1);
//    $this->addFieldMapping('uid')       ->defaultValue(35);


    $this->addFieldMapping('field_article_tags', 'tags');
    $this->addFieldMapping('field_article_tags:create_term')->defaultValue(true);
    $this->addFieldMapping('field_article_tags:ignore_case')->defaultValue(true);


     $this->addUnmigratedDestinations(array(

    ));
  }

public function prepareRow($current_row) {
      $current_row->original_id = $current_row->id;

      $query = Database::getConnection('blog', 'seaport')
        -> select('a_redirect', 'r');
      $query ->fields('r', array('slug'))
        ->condition('page_id', $current_row->id);
      //echo $query . " - " . $current_row->id . "\n";
      foreach ( $query->execute()->fetchAll() as $row){
        if ($row->slug ) $current_row->slug = "news/". $row->slug;

      }
//      echo "\nher " .  $current_row->slug;


      $query = Database::getConnection('blog', 'seaport')
        -> select('a_area_version_slot', 'vs');
      $query -> join('a_slot', 's', '  slot_id  = s.id');
      $query ->fields('s', array('value'))
        ->condition('area_version_id', $current_row->version_id)
        ->orderBy("rank");
      foreach ( $query->execute()->fetchAll() as $row){
        if ($row->value ) $current_row->title .= trim($row->value) . "\n";
      }
   //   echo " - " .  $current_row->title;

      // $query = Database::getConnection('blog', 'seaport')
      //   -> select('a_area_version_slot', 'vs');
      // $query -> join('a_slot', 's', '  slot_id  = s.id');
      // $query ->fields('s', array('value'))
      //   ->condition('area_version_id', $current_row->version_id)
      //   ->orderBy("rank");
      // foreach ( $query->execute()->fetchAll() as $row){
      //   if ($row->value ) $current_row->newbody .= trim($row->value) . "\n";
      // }

      $query = Database::getConnection('blog', 'seaport')
        -> select('tagging', 't');
      $query -> join('tag', 'tag', 'tag_id=tag.id');
      $query ->fields('tag', array('name'))
        ->condition('taggable_id', $current_row->page_id);

      foreach ( $query->execute()->fetchAll() as $row){
        if ($row->name ) $current_row->tags[] = trim($row->name);
      }



    }
}

/*
* END NEWS
*/
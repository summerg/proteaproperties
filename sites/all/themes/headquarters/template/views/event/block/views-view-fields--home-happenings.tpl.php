<?php 
   $category = strtolower(preg_replace('/\s/', '', $fields['field_article_type']->content));
?>

<article class="view-home-blog-v2 col-lg-3 col-md-4 col-sm-6 isotope-item <?php echo strip_tags(str_replace(',', ' ', $category)); ?> grid ">      
  <div class="grid-inner col-inner">
    <div class="post-home">
        <!--<div class="entry-thumbnail text-center">[field_post_image] </div>-->
        <div class="meta">
               <div class="entry-date"><?php print $fields['field_date']->content; ?></div>
               <div class="entry-title"><h3><?php print $fields['title']->content; ?></h3></div>
              <div class="entry-body"><?php print $fields['body']->content; ?>
                  <div class="read-more"><div class="pull-right"><?php print $fields['view_node']->content; ?></div></div>
              </div>
         </div>
    </div>
  </div>
</article>
<?php
$post_format = "none";
?>

<?php if($teaser): ?>

<article id="node-<?php print $node->nid; ?>" class="node-teaser-display post-format-<?php echo $post_format ?> <?php print $classes; ?> post post-medium-image"<?php print $attributes; ?>>
   <div class="post-block">
    <div class="row row-post-single">
        <?php if (!empty($content['field_post_image'])): ?>
           <div class="col-sm-6">
              <?php if($post_format == 'gallery'){ ?>
                 <?php if(render($content['field_post_gallery'])){ ?>
                    <div class="post-image post-gallery">
                      <div class="carousel-gallery">
                          <?php if (render($content['field_post_gallery'])) : ?>
                             <?php print render($content['field_post_gallery']); ?>
                          <?php endif; ?>
                        </div>
                    </div>
                 <?php }else{ print render($content['field_post_image']); } ?>
              <?php }else{print render($content['field_post_image']);
              }
              ?>
           </div>
         <div class="col-sm-6">
         <?php else: ?>
          <div class="col-xs-12">
         <?php endif; ?>

          <div class="post-content">
            <div class="post-meta-wrap">
               <div class="post-title">
                 <?php print render($title_prefix); ?>
                    <h3 <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
                 <?php print render($title_suffix); ?>
               </div>
               <?php if (!$page && $teaser): ?>
                 <div class="post-meta">
                  <span class="post-date-blog"><?php print format_date($node->created, 'custom', 'M d, Y'); ?></span>
                </div>
              <?php endif; ?>
            </div>
              <div class="post-content-inner"<?php print $content_attributes; ?>>
                <?php
                  // Hide comments, tags, and links now so that we can render them later.
                  hide($content['taxonomy_forums']);
                  hide($content['comments']);
                  hide($content['links']);
                  hide($content['field_tags']);
                  hide($content['field_post_image']);
                  hide($content['field_post_gallery']);
                  hide($content['field_post_embed']);
                  hide($content['field_post_format']);
                  print render($content);
                ?>
              </div>
          </div>

      </div>
  </div>
  <div class="clearfix"></div>
</article>

<?php endif; ?>

<?php if(!$teaser): //Display node blog single ?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> post post-large blog-single-post"<?php print $attributes; ?>>
    <div class="text-center">
      <?php if($post_format == 'gallery'){ ?>
          <?php if(render($content['field_post_gallery'])){ ?>
            <div class="post-image post-gallery">
              <div>
                 <?php if (render($content['field_post_gallery'])) : ?>
                    <?php print render($content['field_post_gallery']); ?>
                 <?php endif; ?>
                </div>
            </div>
          <?php }else{ print render($content['field_post_image']); } ?>

          <?php }else{ print render($content['field_post_image']); } ?>
    </div>




  <div class="content-first">
     <?php if ($display_submitted): ?>
      <div class="post-date">
        <span class="day"><?php print format_date($node->created, 'custom', 'd'); ?></span>
        <span class="month"><?php print t(format_date($node->created, 'custom', 'M')); ?></span>
      </div>
    <?php endif; ?>
    <?php if ($display_submitted): ?>

        <div class="post-meta">
        <span class="post-meta-user"><i class="icon icon-user"></i> <?php print t('By'); ?> <?php print $name; ?> </span>
        <?php if (render($content['field_tags'])): ?>
          <span class="post-meta-tag"><i class="icon icon-tag"></i> <?php print render($content['field_tags']); ?> </span>
        <?php endif; ?>
        <?php if (render($content['field_term'])): ?>
          <span class="post-meta-tag"><i class="icon icon-tag"></i> <?php print render($content['field_term']); ?> </span>
        <?php endif; ?>

      </div>
      <div class="clearfix"></div>
    <?php endif; ?>
  </div>

  <div class="clearfix"></div>
  <div class="post-content">
    <div class="article_content"<?php print $content_attributes; ?>>
      <?php
        // Hide comments, tags, and links now so that we can render them later.
        hide($content['taxonomy_forums']);
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_tags']);
        hide($content['field_post_image']);
        hide($content['field_post_gallery']);
        hide($content['field_post_embed']);
        hide($content['field_post_format']);
        print render($content);
      ?>
    </div>


  <?php
    // Only display the wrapper div if there are links.
      $links = render($content['links']);
      if ($links):
    ?>
    <?php if (!$teaser): ?>
    <?php
      // No Comments Override
    /*
      <div class="link-wrapper">
        <?php print $links; ?>
      </div>
    */
    ?>

    <?php endif; ?>
  <?php endif; ?>

    <?php if( (!$teaser) AND (module_exists('profile2')) ): ?>

      <div class="post-block post-author clearfix">
      <h3><i class="icon icon-user"></i><?php print t('Author'); ?></h3>
      <div class="img-thumbnail">
        <?php
          if (!$user_picture) {
            echo '<img src="'.$parent_root.'/images/anon.png" alt="anon">';
          }
          else {
            print $user_picture;
          }
        ?>
      </div>
      <p><strong class="name"><?php print $name; ?> </strong></p>
        <?php if (isset($profile->field_bio['und'][0]['value'])): ?>
          <?php print ($profile->field_bio['und'][0]['value']); ?>
        <?php endif; ?>
    </div>
    <?php endif; ?>

  <?php
    // Remove the "Add new comment" link on the teaser page or if the comment
    // form is being displayed on the same page.
    if ($teaser || !empty($content['comments']['comment_form'])) {
      unset($content['links']['comment']['#links']['comment-add']);
    }
     print render($content['comments']); ?>




</article>
<!-- /node -->
<?php endif; ?>
<article class="view-home-blog-v2 col-lg-3 col-md-4 col-sm-6 col-xs-12 isotope-item grid ">
  <div class="grid-inner col-inner">
    <div class="post-home">
        <!--<div class="entry-thumbnail text-center">[field_post_image] </div>-->
        <div class="meta">
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>
    <?php print $field->content; ?>
  <?php print $field->wrapper_suffix; ?>
<?php endforeach; ?>
         </div>
    </div>
  </div>
</article>
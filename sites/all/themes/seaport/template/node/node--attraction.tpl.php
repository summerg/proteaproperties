<?php if($teaser): ?>

  <article class="col-sm-6 margin-bottom-30 isotope-item <?=$category?> grid ">
     <div class="grid-inner col-inner">
        <div class="views-field views-field-field-portfolio-image image text-center">
           <div class="field-content">
              <?php print render($content['field_attraction_image']); ?>
           </div>
        </div>
        <div class="view-item-body">
           <div class="views-field views-field-title">
              <h3><?php print $title; ?></h3>
           </div>
           <div class="views-field views-field-body">
              <?php print render($content['body']); ?>
              <?php print render($content['field_phone']); ?>
              <?php print render($content['field_business_suite']); ?>
              <?php print render($content['field_nearest_parking']); ?>
              <?php print render($content['field_attraction_website']); ?>
           </div>
        </div>
     </div>
  </article>

<?php endif; ?>

<?php if(!$teaser): //Display node blog single ?>

  <?php print render($content); ?>

<?php endif; ?>
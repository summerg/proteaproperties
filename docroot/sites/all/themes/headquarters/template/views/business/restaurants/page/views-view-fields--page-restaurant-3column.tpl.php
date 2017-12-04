<?php 
   $category = strtolower(preg_replace('/\s/', '', $fields['field_business_tags']->content));
?>

<article class="col-lg-4 col-md-4 col-sm-4 margin-bottom-30 isotope-item <?php echo strip_tags(str_replace(',', ' ', $category)); ?> grid ">      
   <div class="grid-inner col-inner">
      <div class="views-field views-field-field-portfolio-image image text-center">  
         <div class="field-content">
            <?php print $fields['field_business_image']->content; ?>
         </div> 
      </div>  
      <div class="view-item-body">
         <div class="views-field views-field-title"> 
            <h3><?php print $fields['title']->content; ?></h3>
         </div>  
         <div class="views-field views-field-body">        
            <?php print $fields['body']->content; ?>
            <?php print $fields['field_business_suite']->content; ?>
            <?php print $fields['field_business_address']->content; ?>
            <?php print $fields['field_business_nearest_parking']->content; ?>
            <?php print $fields['field_business_phone']->content; ?>
            <?php print $fields['field_business_fax']->content; ?>
            <?php print $fields['field_business_website']->content; ?>
         </div>

      </div>
   </div>
</article>
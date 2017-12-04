<?php 
   $category = strtolower(preg_replace('/\s/', '', $fields['field_portfolio_tags']->content));
?>

<article class="no-padding portfolio-v1 col-lg-3 col-md-3 col-sm-3 isotope-item <?php echo strip_tags(str_replace(',', ' ', $category)); ?> grid ">      
   <div class="grid-inner col-inner">
      <div class="views-field views-field-field-portfolio-image image text-center">  
         <div class="field-content">
            <?php print $fields['field_portfolio_image']->content; ?>
         </div> 
      </div>  
      <div class="view-item-body">
         <div class="views-field views-field-title"> 
            <?php print $fields['title']->content; ?>
         </div>  
         <div class="views-field views-field-tags">        
            <?php print $fields['field_portfolio_tags']->content; ?>
         </div>
         <div class="views-field views-field-body hidden">        
            <?php print $fields['body']->content; ?>
         </div>
      </div>
   </div>
</article>
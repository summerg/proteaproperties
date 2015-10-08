<article class="col-sm-6 margin-bottom-30 isotope-item views-field-performer">      
   <div class="grid-inner col-inner">
      <div class="views-field views-field-performer-image image text-center  pull-left">  
         <div class="field-content">
           <?php print $fields['field_attraction_image']->content; ?>
         </div> 
      </div>  
       <div class="views-field views-field-title"> 
          <h3><?php print $fields['title']->content; ?></h3>
       </div>  
       <div class="views-field views-field-body">        
          <?php print $fields['body']->content; ?>
       </div>
   </div>
</article>
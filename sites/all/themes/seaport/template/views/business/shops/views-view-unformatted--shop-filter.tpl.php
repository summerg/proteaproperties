<div class="text-center clearfix">
  <nav class="portfolio-filter center-block" style="max-width: 780px;">
    <ul class="nav nav-tabs">
       <li><a class="active btn btn-outline" href="#" data-filter="*"><span></span><?php print t('All'); ?></a></li>
       <?php $i=1; foreach ($rows as $id => $row): ?>
          <?php print $row; ?>
       <?php $i++; endforeach; ?>
    </ul>                    
  </nav> 
</div> 
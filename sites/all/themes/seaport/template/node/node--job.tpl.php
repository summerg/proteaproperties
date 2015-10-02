<?php if($teaser): ?>

  <div class="item panel panel-default">
    <div class="panel-heading">
      <h4 class="panel-title">
        <a data-parent="#job-accordion" data-toggle="collapse" class="collapsed" href="#<?=preg_replace("/[\s_]/", "-", preg_replace("/[\s-]+/", " ", preg_replace("/[^a-z0-9_\s-]/", "", strtolower($title))))?>"><span><?php print $title; ?></span><span class="pull-right"><?php print render($content['field_job_company']); ?></span></a>
      </h4>
    </div>
    <div id="<?=preg_replace("/[\s_]/", "-", preg_replace("/[\s-]+/", " ", preg_replace("/[^a-z0-9_\s-]/", "", strtolower($title))))?>" class="panel-collapse collapse">
      <div class="panel-body">
        <?php print render($content['body']); ?>
      </div>
    </div>
  </div>  

<?php endif; ?>



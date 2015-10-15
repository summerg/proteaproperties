<header class="visit-header text-center">
  <div class="visit-header-container">
    <div>
      <img alt="" src="sites/seaport/files/userfiles/images/visit/seaport-village-headquarters-logo.jpg" />
    </div>
    <div class="subtitle">
      <p class="text-left no-margin hidden">Over 80 Shops &amp; Restaurants Downtown on the Waterfront</p>
    </div>
  </div>
</header>

<section class="visit-main-body" style="height:450px;">
  <section class="half half-tl">
    <div class="half-centered text-center">
      <h2>Seaport Village</h2>
      <p class="caption hidden-xs"><span>The original, family-friendly waterfront destination for shopping and dining.</span></p>
      <div class="visit-button">
        <a class="btn btn-hero-outline" href="/">Visit Seaport Village</a>
      </div>
    </div>
  </section>

  <section class="half half-br">
    <div class="half-centered text-center">
      <h2>The Headquarters</h2>
      <p class="caption hidden-xs"><span>A restored waterfront icon, now home to exclusive shops and restaurants.</span></p>
      <div class="visit-button">
        <a class="btn btn-hero-outline" href="http://www.theheadquarters.com">Visit The Headquarters</a>
      </div>
    </div>
  </section>
</section>

<div class="gavias-main-page visit-main-page">
  <div role="main" class="main main-page">
    <?php if ($page['promotion']) { ?>
      <div class="promotion area no-margin">
        <div class="area-inner">
          <div class="row">
            <?php if ($page['promotion']) { ?>
              <div class="promotion-one col-xs-12">
                <?php print render($page['promotion']); ?>  
              </div>
            <?php } ?>
          </div>
        </div>  
      </div>
    <?php } ?>

    <?php if ($page['before_content']) { ?>
      <div class="before_content area">
        <div class="container">
          <div class="row">
            <?php print render($page['before_content']); ?>
          </div>
        </div>    
      </div>
    <?php } ?>

    <div id="content" class="content content-full">
      <div class="">
        <div class="content-main-inner">
          <div class="row">
            <?php if(isset($messages) && $messages){ ?>
              <div class="col-xs-12">
                <?php print $messages; ?>
              </div>  
            <?php } ?>

            <div id="page-main-content" class="main-content <?php if (($page['sidebar_right']) AND ($page['sidebar_left'])) {
                echo "col-xs-12 col-md-6 col-md-push-3 sb-r sb-l";
            } elseif (($page['sidebar_right']) OR ($page['sidebar_left'])) {
                if($page['sidebar_right']) echo "col-xs-12 col-md-9 sb-r";
                if($page['sidebar_left']) echo "col-xs-12 col-md-9 col-md-push-3 sb-l";
            } else {
                echo "col-md-12";
            } ?>">

              <div class="main-content-inner">
                <?php if ($tabs = render($tabs)): ?>
                    <div id="drupal_tabs" class="tabs ">
                        <?php print render($tabs); ?>
                    </div>
                <?php endif; ?>
                <?php print render($page['help']); ?>
                <?php if ($action_links): ?>
                    <ul class="action-links">
                        <?php print render($action_links); ?>
                    </ul>
                <?php endif; ?>

                <?php if ($page['content_top']) { ?>
                  <div class="content-top">
                    <?php print render($page['content_top']); ?>
                  </div>  
                <?php } ?>

                <?php if ($page['content']) { ?>
                  <div class="content-main">
                    <?php print render($page['content']); ?>
                  </div>  
                <?php } ?>

                <?php if ($page['content_bottom']) { ?>
                  <div class="content-bottom">
                    <?php print render($page['content_bottom']); ?>   
                  </div>  
                <?php } ?>
              </div>
            </div>  

            <?php if (($page['sidebar_left'])) : ?>
              <div class="col-md-3 col-sm-12 col-xs-12 <?php if($page['sidebar_right']) echo 'col-md-pull-6'; else echo 'col-md-pull-9'; ?>">
                <aside id="sidebar-left" class="sidebar sidebar-left">
                  <div class="sidebar-inner">
                    <?php print render($page['sidebar_left']); ?>
                  </div>  
                </aside>
              </div>
            <?php endif; ?>

            <?php if (($page['sidebar_right'])) : ?>
              <div class="col-lg-3 col-md-3 col-sm-12 col-xs-12">
                <aside id="sidebar-right" class="sidebar sidebar-right">
                  <div class="sidebar-inner">
                    <?php print render($page['sidebar_right']); ?>
                  </div>  
                </aside>
              </div>
            <?php endif; ?>
          </div>  
        </div>
      </div>
    </div>

    <?php if ($page['highlighted']) { ?>
      <div class="container">
        <div class="highlighted area">
          <?php print render($page['highlighted']); ?>
        </div>
      </div>  
    <?php } ?>

  </div>

   <footer id="footer" class="footer visit-footer"> 
     <div class="copyright">
        <div class="container">
           <div class="copyright-inner">
              <?php if($page['copyright']){
                 print render($page['copyright']);
              } ?>
           </div>   
        </div>   
     </div>
  </footer>

</div>
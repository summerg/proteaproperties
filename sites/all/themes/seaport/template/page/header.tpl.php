<?php if(theme_get_setting('preloader') == '1'): ?>
  <div id="jpreContent" >
      <div id="jprecontent-inner">
          <div class="preloader-wrapper active">
            <div class="spinner-layer spinner-blue-only">
              <div class="circle-clipper left">
                <div class="circle"></div>
              </div><div class="gap-patch">
                <div class="circle"></div>
              </div><div class="circle-clipper right">
                <div class="circle"></div>
              </div>
            </div>
          </div>  
      </div>
    </div>
<?php endif; ?>

   <div id="preheader">
        <span class="h5">Visit Seaport<span class="visible-sm-inline visible-md-inline visible-lg-inline">&mdash;San Diego&rsquo;s most exciting shopping, dining and entertainment &nbsp;</span></span>
        <a href="<?php print $front_page; ?>" class="btn btn-sm btn-default"><span class="visible-sm-inline visible-md-inline visible-lg-inline">Discover </span>Seaport Village</a> 
        <a href="http://www.theheadquarters.com" class="btn btn-sm btn-default active"><span class="visible-sm-inline visible-md-inline visible-lg-inline">Explore </span>The Headquarters at Seaport</a>
   </div>
   <header id="header" <?php if(theme_get_setting('sticky_menu') == 1){echo 'class="gv-fixonscroll"';} ?>>
      <?php if (isset($page['branding'])) : ?>
         <?php print render($page['branding']); ?>
      <?php endif; ?>
      <div class="header-main">
         <div class="container-fluid">
            <div class="header-main-inner">
               <div class="row">
                  <div class="col-md-3 col-xs-10 pull-left">
                     <?php if ($logo): ?>
                           <h1 class="logo">
                                 <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
                                       <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
                                 </a>
                           </h1>
                     <?php endif; ?>

                     <?php if ($site_name || $site_slogan): ?>
                           <div id="name-and-slogan"<?php if ($disable_site_name && $disable_site_slogan) {
                                 print ' class="hidden"';
                           } ?>>

                                 <?php if ($site_name): ?>
                                    <?php if ($title): ?>
                                          <div id="site-name"<?php if ($disable_site_name) {
                                                print ' class="hidden"';
                                          } ?>>
                                                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"
                                                    rel="home"><span><?php print $site_name; ?></span></a>
                                          </div>
                                    <?php else: /* Use h1 when the content title is empty */ ?>
                                          <h1 id="site-name"<?php if ($disable_site_name) {
                                                print ' class="hidden"';
                                          } ?>>
                                                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"
                                                    rel="home"><span><?php print $site_name; ?></span></a>
                                          </h1>
                                    <?php endif; ?>
                                 <?php endif; ?>

                                 <?php if ($site_slogan): ?>
                                    <div id="site-slogan"<?php if (($disable_site_slogan)) { print ' class="hidden"'; }
                                       if ((!$disable_site_slogan) AND ($disable_site_name)) { } ?>> <?php print $site_slogan; ?>
                                    </div>
                                 <?php endif; ?>

                           </div> <!-- /#name-and-slogan -->
                     <?php endif; ?>
                  </div>

                  <div class="col-md-9 col-xs-2 area-main-menu pull-right no-padding">
                  <?php if ($menu_bar = render($page['main_menu'])): print $menu_bar; endif; ?>
                  <?php if($page['search']){ ?>
                     <div class="search-region">
                        <?php print render($page['search']); ?>
                     </div>
                  <?php } ?>   
               </div>   
               </div> 
            </div>     
         </div>
      </div>   

   </header>

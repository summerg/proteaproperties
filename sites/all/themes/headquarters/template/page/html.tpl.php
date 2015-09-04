<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or
 *   'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see gavias_mdeal_preprocess_html()
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */

?>
<!DOCTYPE html>
<!--[if lt IE 7]> <html class="ie ie6" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?><?php if (theme_get_setting('rtl') == 1){ echo " rtl"; } ?>"> <![endif]-->
<!--[if IE 7]>    <html class="ie ie7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?><?php if (theme_get_setting('rtl') == 1){ echo " rtl"; } ?>"> <![endif]-->
<!--[if IE 8]>    <html class="ie ie8" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?><?php if (theme_get_setting('rtl') == 1){ echo " rtl"; } ?>"> <![endif]-->
<!--[if gt IE 8]> <!--> <html class="" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?><?php if (theme_get_setting('rtl') == 1){ echo " rtl"; } ?>"> <!--<![endif]-->

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
      <script src="https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script>
    <![endif]-->
  <?php print $head_scripts; ?>
  <?php gavias_user_css(); ?>  
  
  <link rel="shortcut icon" href="/sites/all/themes/headquarters/images/favicon.ico" type="image/x-icon" />
  <link rel="apple-touch-icon" href="/sites/all/themes/headquarters/images/apple-touch-icon.png" />
  <link rel="apple-touch-icon" sizes="57x57" href="/sites/all/themes/headquarters/images/apple-touch-icon-57x57.png" />
  <link rel="apple-touch-icon" sizes="72x72" href="/sites/all/themes/headquarters/images/apple-touch-icon-72x72.png" />
  <link rel="apple-touch-icon" sizes="76x76" href="/sites/all/themes/headquarters/images/apple-touch-icon-76x76.png" />
  <link rel="apple-touch-icon" sizes="114x114" href="/sites/all/themes/headquarters/images/apple-touch-icon-114x114.png" />
  <link rel="apple-touch-icon" sizes="120x120" href="/sites/all/themes/headquarters/images/apple-touch-icon-120x120.png" />
  <link rel="apple-touch-icon" sizes="144x144" href="/sites/all/themes/headquarters/images/apple-touch-icon-144x144.png" />
  <link rel="apple-touch-icon" sizes="152x152" href="/sites/all/themes/headquarters/images/apple-touch-icon-152x152.png" />
  <link rel="apple-touch-icon" sizes="180x180" href="/sites/all/themes/headquarters/images/apple-touch-icon-180x180.png" />
  
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
    
    <div id="fb-root"></div>
    <script>(function(d, s, id) {
      var js, fjs = d.getElementsByTagName(s)[0];
      if (d.getElementById(id)) return;
      js = d.createElement(s); js.id = id;
      js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.4&appId=216774645011748";
      fjs.parentNode.insertBefore(js, fjs);
    }(document, 'script', 'facebook-jssdk'));</script>

  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  
  <?php print $page_bottom; ?>
 
</body>

</html>

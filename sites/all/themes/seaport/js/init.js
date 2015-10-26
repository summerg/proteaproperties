jQuery(document).ready(function($){

    if(/iPad|iPhone|iPod/.test(navigator.userAgent) && !window.MSStream){
      document.querySelector('meta[name=viewport]')
        .setAttribute(
          'content', 
          'initial-scale=1.0001, minimum-scale=1.0001, maximum-scale=1.0001, user-scalable=no'
        );
    }
    
    // External Links and PDF's Open in New Window

    $('a[href^="https://"], a[href^="http://"]').not('.view-calendar a[href^="https://"], .view-calendar a[href^="http://"]').attr('target', '_blank');

    // Magnific Popup

    $('a[href$=".pdf"]').magnificPopup({
        disableOn: 700,
        type: 'iframe',
        mainClass: 'mfp-fade',
        removalDelay: 160,
        preloader: false,
        fixedContentPos: false
    });
    
    $(window).on('load resize', function(){
      $window = $(window);
      $('.visit-main-body').height(function(){
          return $window.height()-$(this).offset().top-110;   
      });
    });

    $('header [title]').removeAttr('title');

});
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

    var megaChild = ".level-1.mega.dropdown > a";

    $(megaChild).attr('aria-expanded','false');
    $(megaChild).click(function(){
      var $li = $(this).parent();
      $(this).parents('ul').children('li').not($li).removeClass('open');
      $li.toggleClass('open');
      if ($(this).attr('aria-expanded') == 'false') {
        $(megaChild).attr('aria-expanded', 'false');
        $(this).attr('aria-expanded', 'true');
      } else {
        $(megaChild).attr('aria-expanded', 'false');
      }
    });

    // Instagram Feed
      
      if($('.instafeed').length){
        jQuery.fn.spectragram.accessData = {
        accessToken:'489585525.5fd9bd4.3293869f36574e1cb10dcc58e9ea617f',
        clientID: '5fd9bd42193b4daa82eec6cde3df59ae'
        //accessToken: '1406933036.fedaafa.feec3d50f5194ce5b705a1f11a107e0b',
        //clientID: 'fedaafacf224447e8aef74872d3820a1'
      };
      $('.instafeed').each(function() {
          var feedID = $(this).attr('data-user-name');
          $(this).children('ul').spectragram('getUserFeed', {
              query: feedID,
              max: 12,
              size: 'small'
          });
        });
      }

    // Owl-Jumbo

    $(".owl-jumbo").owlCarousel({
      singleItem : true,
      autoPlay : 7000,
      slideSpeed:  300,
      navigation : true,
      pagination : false,
      addClassActive : true
    });

});

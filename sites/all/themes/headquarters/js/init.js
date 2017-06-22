jQuery(document).ready(function($){

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
  
  $('header [title]').removeAttr('title');


  // Web Access Mega

  var megaParent = ".level-1.mega.dropdown";
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
      accessToken: '549686280.24e1204.37f9c4c098e143dfaad3e4f027a9c9be',
      clientID: '24e1204232744fd9906d9b2bf7ff7b6c'
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

/*
onchange
if has dropdown and open aria-expanded="true"
*/

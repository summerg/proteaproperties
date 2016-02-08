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


});

/*
onchange
if has dropdown and open aria-expanded="true"
*/

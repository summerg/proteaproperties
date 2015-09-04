jQuery(document).ready(function($){

    // 

    var lineSystem={} 

    $(document).ready(function() {
      $('.poem').wraplines();
      var opts = $('.poem').data();
      
      $('.poem  span').addClass('extra');
      $('.poem').removeClass('init');
    });

    // External Links and PDF's Open in New Window

    $('a[href^="https://"], a[href^="http://"], a[href$=".pdf"').not('.view-calendar a[href^="https://"], .view-calendar a[href^="http://"]').attr('target', '_blank');

    // Magnific Popup

    $('a[href$=".pdf"').magnificPopup({
        disableOn: 700,
        type: 'iframe',
        mainClass: 'mfp-fade',
        removalDelay: 160,
        preloader: false,
        fixedContentPos: false
    });
    
});




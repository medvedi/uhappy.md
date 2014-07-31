(function ($) {

  'use strict';

  /**
   * A simple Drupal behavior example.
   */

  var modalPositionRecalculate = function(){
    var $modalHeight = $('#modalContent').height();
    var $windowHeight = $(window).height();
    var $top = ($windowHeight - $modalHeight)/2;

    if($modalHeight < $windowHeight){
      $('#modalContent').css('margin-top', $top);
    }
    else{
      $('#modalContent').css('margin-top', 0);
    }
  };

  var topCarouselPosition = function(){
    if($('#uhappyCarousel').length != 0){
      var $sliderHeight = $('.slider-wrapper').height();
      $('.carousel .container').css('height', $sliderHeight)
    }
  };

  Drupal.behaviors.sliderVideosAdd = {
    attach: function (context) {
      var $wrapper = $('.slider-wrapper ul', context);
      var $video = $('.embedded-video');
      $video.each(function(){
        $wrapper.prepend($video);
        $wrapper.find($video).wrap('<li class="video"></li>')
      })
    }
  };

  Drupal.behaviors.carouselNavigation = {
    attach: function (context) {
      $('<div class="carousel-navigation"><div id="carousel-left" class="nav-left"></div><div id="carousel-right" class="nav-right"></div></div>').insertAfter('.node-type-scenario .field-name-field-image-list .field-items');
    }
  };

  Drupal.behaviors.carousel = {
    attach: function (context) {

      $('#uhappyCarousel').imagesLoaded( function() {
        $('#uhappyCarousel', context).carousel({
          interval: 5000
        });
      });

      var $elementCarousel = $('.node-type-scenario .field-name-field-image-list .field-items');
      if($elementCarousel.length !== 0){
        $elementCarousel.imagesLoaded( function() {
          $elementCarousel.carouFredSel({
            direction : "left",
            responsive: true,
            height: 'variable',
            width :'variable',
            scroll : {
              items           : 1,
              easing          : "elastic",
              duration        : 1000,
              pauseOnHover    : true
            },
            items : {
              visible : {
                min : 1,
                max : 6
              },
              height: 'variable'
            },
            swipe       : {
              onTouch     : true,
              onMouse     : false
            },
            prev                : "#carousel-left",
            next                : "#carousel-right"
          });

          $elementCarousel.swipe({
            excludedElements: "button, input, select, textarea, .noSwipe",
            swipeLeft: function() {
              $elementCarousel.trigger('next', 1);
            },
            swipeRight: function() {
              $elementCarousel.trigger('prev', 1);
            }
          });
        });
      }
    }
  }

  Drupal.behaviors.chosenInit = {
    attach: function () {
      var $chosenElements = $(".ctools-modal-content select");
      $chosenElements.chosen();
    }
  };

  Drupal.behaviors.childrenRadioActive = {
    attach: function () {
      var $formRadio = $('.field-name-field-number-of-children .form-type-radio');
      $formRadio.find('input:checked').parent('.form-type-radio').addClass('active');
      $formRadio.find('label').click(function(){
        if (!$(this).parent().hasClass('active')){
          $(this).parent().addClass('active')
          $(this).parent().siblings().removeClass('active');
        }
      })
    }
  };

  Drupal.behaviors.modalPositionRecalculate = {
    attach: function () {
      $('#modalContent').ready(function(){
        modalPositionRecalculate();
        $(window).resize(function(){
          modalPositionRecalculate();
        })
      })
    }
  };

  Drupal.behaviors.onResizeFunctionsInit = {
    attach: function (context) {
      $('#uhappyCarousel', context).imagesLoaded( function() {
        topCarouselPosition();
        $(window).resize(function(){
          topCarouselPosition();
        })
      })
    }
  };

  Drupal.behaviors.throbberReplce = {
    attach: function () {
      $('.order')
        .ajaxStart(function(){
          $('#modalContent').hide();
          $('.main-throbber').show();
        })
        .ajaxStop(function(){
          $('#modalContent').show();
          $('.main-throbber').hide();
          modalPositionRecalculate()
        });
    }
  };

  Drupal.behaviors.bodyModalClass = {
    attach: function () {
      // beahvior: modalAddBodyClass
      $('a.ctools-use-modal').click(function(e){
        $('body').addClass('no-scroll');
      });
      $(window).keyup(function(e) {
        if( e.keyCode == 27 && $('body').hasClass('no-scroll') ) {
          $('body').removeClass('no-scroll');
        }
      });
      $('.ctools-modal-content .modal-header .close').click(function(){
        $('body').removeClass('no-scroll');
      });
    }
  };

})(jQuery);

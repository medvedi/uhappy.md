(function ($) {

  'use strict';

  /**
   * A simple Drupal behavior example.
   */

  Drupal.behaviors.carouselNavigation = {
    attach: function (context) {
      $('<div class="slider-navigation"><div class="nav-left"></div><div class="pager"></div><div class="nav-right"></div></div>').insertAfter('.slider-wrapper ul, .slider');
      $('<div class="carousel-navigation"><div class="nav-left"></div><div class="nav-right"></div></div>').insertAfter('.field-name-field-image-list .field-items, .carousel');
    }
  };

  Drupal.behaviors.carouFredSelInit = {
    attach: function (context) {
      // Using custom configuration
      var $elementCarousel = $('.field-name-field-image-list .field-items, .carousel');
      var $elementSlider = $('.slider-wrapper ul, .slider');

      if($elementCarousel.length !== 0){
//        $elementSlider.imagesLoaded( function() {
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
              onTouch     : true
            }
          });
//        });
      }

      if($elementSlider.length !== 0){
//        $elementSlider.imagesLoaded( function() {
          $elementSlider.carouFredSel({
            direction           : "left",
            responsive          : true,
            width: '100%',
            height: 'variable',
            items: {
              height: 'variable',
              visible: 1
            },
            pagination: ".pager",
            prev                : ".nav-left",
            next                : ".nav-right",
            scroll : {
              items           : 1,
              fx          : "fade",
              duration        : 1000,
              pauseOnHover    : false
            }
          });
//        });
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
      $('.field-name-field-number-of-children .form-type-radio label').click(function(){
        if (!$(this).parent().hasClass('active')){
          $(this).parent().addClass('active')
          $(this).parent().siblings().removeClass('active');
        }
      })
    }
  };

})(jQuery);

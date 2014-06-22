(function ($) {

  'use strict';

  /**
   * A simple Drupal behavior example.
   */

  Drupal.behaviors.carouselNavigation = {
    attach: function (context) {
      $('<div class="slider-navigation"><div id="slider-left" class="nav-left"></div><div class="pager"></div><div id="slider-right" class="nav-right"></div></div>').insertAfter('.slider-wrapper ul, .slider');
      $('<div class="carousel-navigation"><div id="carousel-left" class="nav-left"></div><div id="carousel-right" class="nav-right"></div></div>').insertAfter('.field-name-field-image-list .field-items, .carousel');
    }
  };

  Drupal.behaviors.carouFredSelInit = {
    attach: function (context) {
      // Using custom configuration
      var $elementCarousel = $('.field-name-field-image-list .field-items, .carousel');
      var $elementSlider = $('.slider-wrapper ul, .slider');

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

      if($elementSlider.length !== 0){
        $elementSlider.imagesLoaded( function() {
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
            prev                : "#slider-left",
            next                : "#slider-right",
            scroll : {
              items           : 1,
              fx          : "fade",
              duration        : 1000,
              pauseOnHover    : false
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
      $('.field-name-field-number-of-children .form-type-radio label').click(function(){
        if (!$(this).parent().hasClass('active')){
          $(this).parent().addClass('active')
          $(this).parent().siblings().removeClass('active');
        }
      })
    }
  };

})(jQuery);

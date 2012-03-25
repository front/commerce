/* Aller Theme */

(function($) {

    Drupal.behaviors.allerTheme = {
        attach: function(context, settings) {
            // Equalheights (grid)
            $(window).load(function () {
              // We wrap this to load event because webkit browsers
              // only calculate the image dimensions after load
              if ($('.pane-product-display-teasers-latest-products', context).length) {
                  var view = $('.pane-product-display-teasers-latest-products', context);

                  $('.views-row', view).each(function() {
                    // TODO: make this wrapper using fieldgroup on DS
                    // once the wireframe / design is closed
                      $('div.field:not(.field-name-field-display-product)', this).wrapAll('<div class="eq" />');
                  });
                  $('.eq', view).equalHeight();
              }

              if ($('.view-id-taxonomy_custom', context).length) {
                  var view = $('.view-id-taxonomy_custom', context);

                  $('.views-row', view).each(function() {
                    // TODO: make this wrapper using fieldgroup on DS
                    // once the wireframe / design is closed
                      $('div.field:not(.field-name-field-display-product)', this).wrapAll('<div class="eq" />');
                  });
                  $('.eq', view).equalHeight();
              }
            });

            // Placeholder support
            $('input.form-text, textarea').placeholder();
        }
    };

})(jQuery);
(function ($) {
    
    $(document).ready(function(){
        $('.commerce-reports-accordion header').click(function() {
            
            if ($(this).hasClass('active')) {
                $(this).removeClass('active');
                $(this).children('h2').children('a').text('+');
            }
            else {
                $(this).addClass('active');
                $(this).children('h2').children('a').text('-');
            }
            
            $(this).next().toggle('slow');
            return false;
        }).next().hide();
        $('.commerce-reports-accordion header').click();
    });
    

})(jQuery);


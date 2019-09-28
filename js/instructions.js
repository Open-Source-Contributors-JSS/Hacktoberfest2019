$(document).ready(function() {
  
  var content = $('.content');
  var currentItem = content.filter('.active');
  var steps = $('.card').filter('.steps');
  var inactive1 = $('.inactive-1');
  var inactive2 = $('.inactive-2');

  $('.button').click(function() {
      var nextItem = currentItem.next();
      var lastItem = content.last();
      var contentFirst = content.first();
    
      currentItem.removeClass('active');

      if (currentItem.is(lastItem)) {
          currentItem = contentFirst.addClass('active');
          currentItem.css({'right': '10%', 'opacity': '1'});
          $('.step').animate({width: '33%'});
          inactive1.animate({height: '8px', marginLeft:'20px', marginRight:'20px'}, 100);
          inactive2.animate({height: '8px', marginLeft:'10px', marginRight:'10px'}, 100);
        
      } else if (currentItem.is(contentFirst)) {
          currentItem.animate({opacity: 0}, 1000);
          currentItem = nextItem.addClass('active');
          $('.step').animate({width: '66%'});
          inactive2.animate({height: '0', marginLeft:'0px', marginRight:'0px'}, 100);
        
      } else {
          currentItem = nextItem.addClass('active');
          $('.step').animate({width: '100%'});
          inactive1.animate({height: '0', marginLeft:'0px', marginRight:'0px'}, 100);
      } 
  });

});
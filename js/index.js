document.addEventListener('DOMContentLoaded', () => {

  // Get all "navbar-burger" elements
  const $navbarBurgers = Array.prototype.slice.call(document.querySelectorAll('.navbar-burger'), 0);

  // Check if there are any navbar burgers
  if ($navbarBurgers.length > 0) {

    // Add a click event on each of them
    $navbarBurgers.forEach( el => {
      el.addEventListener('click', () => {

        // Get the target from the "data-target" attribute
        const target = el.dataset.target;
        const $target = document.getElementById(target);

        // Toggle the "is-active" class on both the "navbar-burger" and the "navbar-menu"
        el.classList.toggle('is-active');
        $target.classList.toggle('is-active');

      });
    });
  }
});

$(document).ready(function() {

  // Check for click events on the navbar burger icon
  $(".navbar-burger").click(function() {

    // Toggle the "is-active" class on both the "navbar-burger" and the "navbar-menu"
    $(".navbar-burger").toggleClass("is-active");
    $(".navbar-menu").toggleClass("is-active");

  });
});

// number count for stats, using jQuery animate
$('.counting').each(function() {  
  var $this = $(this),
      countTo = $this.attr('data-count');
  
  $({ countNum: $this.text()}).animate({
    countNum: countTo
  }, {

    duration: 3000,
    easing:'linear',
    step: function() {
      $this.text(Math.floor(this.countNum));
    },
    complete: function() {
      $this.text(this.countNum);
    }
  });   
});

const second = 1000,
      minute = second * 60,
      hour = minute * 60,
      day = hour * 24;

let countDown = new Date('Oct 31, 2019 00:00:00').getTime(),
    x = setInterval(function() {

      let now = new Date().getTime(),
          distance = countDown - now;

      document.getElementById('days').innerText = padWith(Math.floor(distance / (day)).toFixed(0)) + ' : ';
      document.getElementById('hours').innerText = padWith((Math.floor((distance % (day))) / (hour)).toFixed(0))+' : ';
      document.getElementById('minutes').innerText = padWith((Math.floor((distance % (hour))) / (minute)).toFixed(0))+' : ';
      document.getElementById('seconds').innerText = padWith((Math.floor((distance % (minute))) / second).toFixed(0));

      if (distance < 0) {
      clearInterval(x);
      
      }
    }, second)

// js for commands fetching
let url = './json-files/git-commands.json';
fetch(url)
  .then(data => data.json())
  .then(jsondata => console.log(jsondata))
  .catch(err => console.log(err));

/**
 * params
 * @initialValue  Object  The value that will be padded
 * @length        Number  Basically this method is used for padding datetime to 2 digits format, so given default value is 2
 * @padChar       String  '0' as the default value
 * @
 */
function padWith(initialValue, length = 2, padChar = '0') {
  return initialValue.toString().padStart(length, padChar);
}
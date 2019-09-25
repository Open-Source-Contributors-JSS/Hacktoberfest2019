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


//scroll reveal
window.sr = ScrollReveal();
        sr.reveal('.intro-text', {
          duration: 2000,
          origin:'top',
          distance:'300px'
        });
        sr.reveal('.intro-img', {
          duration: 2000,
          origin:'right',
          distance:'300px'
        });
        sr.reveal('.card-group', {
          duration: 2000,
          delay: 1000,
          origin:'bottom'
        });
        
        sr.reveal('.latest', {
          duration: 2000,
          delay:500,
          origin:'bottom',
          distance:'300px'
        });
        sr.reveal('.snip1', {
          duration: 3000,
          origin:'right',
          delay:500,
          distance:'300px'
        });
        sr.reveal('.snip2', {
          duration: 3000,
          origin:'left',
          delay:500,
          distance:'300px'
        });

        sr.reveal('.footer', {
          duration: 1000,
          origin:'bottom'
        });

        var isMobile = /iPhone|iPad|iPod|Android/i.test(navigator.userAgent);
        if (isMobile) {
          sr.reveal('.intro-img', {
            duration: 2000,
            origin:'bottom',
            distance:'300px'
          });
          sr.reveal('.footer', {
            duration: 500,
            origin:'bottom'
          });
        } 
'use strict'
let leftSection = document.getElementById('left-section');
let rightSection = document.getElementById('right-section');
let leftButton = document.getElementById('button-left');
let rightButton = document.getElementById('button-right');
let isLeftVisible = false;
let isRightVisible = false;

leftSection.addEventListener('mouseover', () => {
	window.isLeftVisible = true;
	document.getElementById('button-right').removeAttribute('hidden');
	document.getElementById('button-left').setAttribute('hidden', '');
});

rightSection.addEventListener('mouseover', () => {
	window.isRightVisible = true;
	document.getElementById('button-left').removeAttribute('hidden');
	document.getElementById('button-right').setAttribute('hidden', '');
});

leftButton.addEventListener('click', () => {
	if (window.isRightVisible) {
		Swal.fire({
		  'title': 'Congratulations!',
		  'text': 'You clicked the button!',
		  'type': 'success',
		  'confirmButtonText': 'Yeay!',
		  'onAfterClose': () => location.reload()
		});
		location.reload();
	} else {
		window.isRightVisible = false;
	}
});

rightButton.addEventListener('click', () => {
	if (window.isLeftVisible) {
		Swal.fire({
		  'title': 'Congratulations!',
		  'text': 'You clicked the button!',
		  'type': 'success',
		  'confirmButtonText': 'Yeay!',
		  'onAfterClose': () => location.reload()
		});
		location.reload();
	} else {
		window.isLeftVisible = false;
	}
});
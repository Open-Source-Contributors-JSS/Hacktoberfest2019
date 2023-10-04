const COUNTDOWN_FROM = new Date("10/31/2023").getTime();

const SECOND = 1000;
const MINUTE = SECOND * 60;
const HOUR = MINUTE * 60;
const DAY = HOUR * 24;

function updateCountdown() {
    const now = new Date().getTime();
    const distance = COUNTDOWN_FROM - now;

    const days = Math.floor(distance / DAY);
    const hours = Math.floor((distance % DAY) / HOUR);
    const minutes = Math.floor((distance % HOUR) / MINUTE);
    const seconds = Math.floor((distance % MINUTE) / SECOND);

    $("#days").text(days);
    $("#hours").text(hours);
    $("#minutes").text(minutes);
    $("#seconds").text(seconds);
}

setInterval(updateCountdown, 1000);
updateCountdown();


window.onload = startup;

function startup() {
    loop();
}

var canvas = document.querySelector("#canvas");
var context = canvas.getContext("2d");
var canvasPos = getPosition(canvas);

canvas.addEventListener("mousemove", setMousePosition, false);

var mouseX = 0;
var mouseY = 0;

function setMousePosition(e) {
    mouseX = e.clientX - canvasPos.x;
    mouseY = e.clientY - canvasPos.y;
}



//get position from canvas,the screen
function getPosition(el) {
    var xPosition = 0;
    var yPosition = 0;

    while (el) {
        xPosition += (el.offsetLeft - el.scrollLeft + el.clientLeft);
        yPosition += (el.offsetTop - el.scrollTop + el.clientTop);
        el = el.offsetParent;
    }
    return {
        x: xPosition,
        y: yPosition
    };
}


//the requestAnimationFrame updates screen and the clearRect erases older frame so new framecan be drawn
//if older frame isnt erased then the object will be drawn continuously like in Paint
function loop() {
    context.clearRect(0, 0, canvas.width, canvas.height);
    context.beginPath();
    context.arc(mouseX, mouseY, 50, 0, 2 * Math.PI, true);
    context.fillStyle = "#FF6A6A";
    context.fill();
    requestAnimationFrame(loop);
}
function TRex(x, y, radius) {

	this.x = x;
	this.y = y;

	this.yVelocity = 0;
	this.speed = 1;
	this.onGround = true;

	this.radius = radius; // size of circle
}

/**
	*	handle y values
	*/
TRex.prototype.update = function(platform) {

	var bottom = this.y + this.radius; // bottom pixel of circle
	var nextBottom = bottom + this.yVelocity; // calculate next frame's bottom

  if (bottom <= platform && nextBottom >= platform) { // next frame will be on platform

		this.yVelocity = 0; // reset velocity
		this.y = platform - this.radius; // don't go past platform
		this.onGround = true;
  } else if (platform - bottom > 1) { // nowhere near platform

		this.yVelocity += this.speed; // increase velocity
		this.onGround = false;
  }

	/* movement */
	this.y += this.yVelocity;
};

/**
	* make the dino jump
	*/
TRex.prototype.jump = function() {

	this.yVelocity = -(this.radius * 0.7); // jump
};

TRex.prototype.draw = function() {

  fill('#999999');
	stroke(255);
	strokeWeight(2);
  ellipse(this.x, this.y, this.radius * 2);
};



// By Prakhar Varshney https://github.com/prkhrv 

var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");
/*ctx.beginPath();
ctx.rect(20,40,50,50);
ctx.fillStyle="#FF0000";
ctx.fill();
ctx.closePath();

ctx.beginPath();
ctx.arc(240, 160, 20, 0, Math.PI*2);
ctx.fillStyle="green";
ctx.fill();
ctx.strokeStyle="black";
ctx.stroke();
ctx.closePath();*/

board = new Image();
board.src="board.jpg";

score=0;

paddleWidth=100;
paddleHeight=20;
paddleX=(canvas.width-paddleWidth)/2;

x=canvas.width/2;
y=canvas.height-30;
ballRadius=10;
dx=3;
dy=-3;

rightPressed=false;
leftPressed=false;

brickRowCount=8;
brickColumnCount=6;
brickWidth=80;
brickHeight=20;
brickPadding=10;
brickOffsetTop=30;
brickOffsetLeft=30;

var bricks = [];
for(c=0; c<brickColumnCount; c++) {
    bricks[c] = [];
    for(r=0; r<brickRowCount; r++) {
        bricks[c][r] = { x: 0, y: 0, status:1 };
    }
}

function drawBricks(){
for(c=0;c<brickColumnCount;c++){
	for(r=0;r<brickRowCount;r++){
		if(bricks[c][r].status==1){
		brickX=(c*(brickWidth+brickPadding))+brickOffsetLeft;
		brickY=(r*(brickHeight+brickPadding))+brickOffsetTop;
		bricks[c][r].x=brickX;
		bricks[c][r].y=brickY;
		ctx.beginPath();
		ctx.rect(brickX, brickY, brickWidth, brickHeight);
		ctx.fillStyle="#EEEEEE";
		ctx.fill();
		ctx.closePath();
		}
	}
}
}

function drawPaddle(){
	ctx.beginPath();
	ctx.rect(paddleX,canvas.height-paddleHeight, paddleWidth, paddleHeight);
	ctx.fillStyle="#05050D";
	ctx.fill();
	ctx.closePath();
	}

function drawBall(){
	ctx.beginPath();
	ctx.arc(x, y, ballRadius, 0, Math.PI*2);
	ctx.fillStyle="#011122";
	ctx.fill();
	ctx.closePath();
}

function drawScore(){
	ctx.font="16px Agency FB";
	ctx.fillStyle="#DDDD95";
	ctx.fillText("Score: "+ score, 8, 16);
}

function draw(){
	ctx.clearRect(0, 0, canvas.width, canvas.height)
	ctx.drawImage(board, 0, 0, 600, 600);
	drawBall();
	drawPaddle();
	drawBricks();
	drawScore();
	collisionDetection();

	x+=dx;
	y+=dy;

	if(y+dy<ballRadius){
		dy=-dy;
	}
	else if(y+dy>canvas.height-ballRadius-paddleHeight/2){
		if(x>paddleX && x<paddleX+paddleWidth){
			dy=-dy;
		}
		else {
		alert("GAME OVER! With a score of "+score);
		document.location.reload();
		}
	}
	
	if(x+dx>canvas.width-ballRadius || x+dx<ballRadius){
		dx=-dx;
	}

	if(rightPressed && paddleX<canvas.width-paddleWidth){
		paddleX+=5;
	}
	if(leftPressed && paddleX>0){
		paddleX-=5;
	}

	if(score==brickRowCount*brickColumnCount){
		alert("Congratulations, YOU WIN !");
		document.location.reaload();
	}

	requestAnimationFrame(draw);
}

document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);

function keyDownHandler(e){
	if(e.keyCode==39){
		rightPressed=true;
	}
	else if(e.keyCode==37){
		leftPressed=true;
	}
}
function keyUpHandler(e){
	if(e.keyCode==39){
		rightPressed=false;
	}
	else if(e.keyCode==37){
		leftPressed=false;
	}
}

function collisionDetection(){
	for(c=0;c<brickColumnCount;c++){
		for(r=0;r<brickRowCount;r++){
			var b=bricks[c][r];
			if(b.status==1){
			if(x>b.x && x<b.x+brickWidth && y>b.y && y<b.y+brickHeight){
				dy=-dy;
				b.status=0;score++;
			}
			}
		}
	}
}

draw();
//setInterval(draw, 10);

var score = 0;
var step =0;
var board = new Array();

$(document).ready(function(){
	newGame();
})

//游戏初始化
function newGame(){
	init();
	//初始化2048
	creatNumber();
	creatNumber();
	//随机生成两个数字
}

function init(){
	for(var i=0;i<4;i++)
	{
		for(var j=0;j<4;j++)
		{
			var bgceil=$('#ar_ceil-'+i+'-'+j);
			bgceil.css('top',gettop(i,j));
			bgceil.css('left',getleft(i,j));
		}
	}
	//使数组的全部置为零，为了后面判断操作
	for(let i=0;i<4;i++)
	{
		board[i] = new Array();
		for(let j=0;j<4;j++)
		{
			board[i][j]=0;
		}
	}
	//将所有置为0
	updatebgNumber();
	//更新界面
	score=0;
	step=0;
	$('#score').text(score);
	$('step').text(step);
	//将分数和步数置为零
}


function updatebgNumber(){
	$('#numberceil').remove();
	for(var i=0;i<4;i++)
	{
		for(var j=0;j<4;j++)
		{
			$('article').append('<div class="number_ceil" id="number_ceil-'+i+'-'+j+'"></div>');
			var numberceil=$('number_ceil-'+i+'-'+j);
			if(board[i][j]==0){
				numberceil.css('width','0');
				numberceil.css('height','0');
			}
			else{
				numberceil.css('width','170px');
				numberceil.css('height','100px');
				numberceil.css('top',gettop(i,j));
				numberceil.css('left',getleft(i,j));
				numberceil.css('background-color',getcolor(board[i][j]));
				numberceil.text(board[i][j]);
			}
		}
	}
}

function gettop(i,j){
	var top=20+i*140;
	return top+'px';
}
function getleft(i,j){
	var left=20+j*190;
	return left+'px';
}

function creatNumber(){
	if(nospace(board)){
		return false;
	}

	var randx=parseInt(Math.floor(Math.random()*4));
	var randy=parseInt(Math.floor(Math.random()*4));
	while(true){
		if(board[randx][randy]==0)
		{
			break;
		}
		var randx=parseInt(Math.floor(Math.random()*4));
		var randy=parseInt(Math.floor(Math.random()*4));
	}

	var randnumber=Math.random()>0.5?2:4;
	board[randx][randy]=randnumber;
	shownumberwithAnimation(randx,randy,randnumber);

	return true;
}
//棋盘上还有没有空间
function nospace(board){
	for(var i=0;i<4;i++)
	{
		for(var j=0;j<4;j++){
			if(board[i][j]==0)
			{
				return true;
			}
		}
	}
	return false;
}

function shownumberwithAnimation(i,j,n){
	var numberceil=$('number_ceil-'+i+'-'+j);
	numberceil.css('backgrand-color',getbgcolor(n));
	numberceil.css('width','170px');
	numberceil.css('height','100px');
	numberceil.text(n);
}


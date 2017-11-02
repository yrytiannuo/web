var score = 0;
var step =0;
var board = new Array();

$(document).ready(function(e){
	newGame();
});

//游戏初始化
function newGame(){
	init();
	//初始化2048
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
	score = 0;
	step =0;
	$('#score').val(score);
	$('#step').val(step);
	//将分数和步数置为零
}


function updatebgNumber(){
	$('#score').val(score);
	$('#step').val(step);
	$('.number_ceil').remove();
	for(var i=0;i<4;i++)
	{
		for(var j=0;j<4;j++)
		{
			$('#article').append('<div class="number_ceil" id="number_ceil-'+i+'-'+j+'"></div>');
			var numberceil=$('#number_ceil-'+i+'-'+j);
			if(board[i][j]==0){
				numberceil.css('width','0px');
				numberceil.css('height','0px');
				numberceil.css('top',gettop(i,j));
				numberceil.css('left',getleft(i,j));
			}
			else{
				numberceil.css('width','100px');
				numberceil.css('height','100px');
				numberceil.css('top',gettop(i,j));
				numberceil.css('left',getleft(i,j));
				numberceil.css('background-color',getnumcolor(board[i][j]));
				numberceil.text(board[i][j]);
			}
		}
	}
}

//随机位置创造随机的数字2或者4
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
		 randx=parseInt(Math.floor(Math.random()*4));
		 randy=parseInt(Math.floor(Math.random()*4));
	}

	var randnumber=Math.random()>0.5?2:4;
	board[randx][randy]=randnumber;
	shownumberwithAnimation(randx,randy,randnumber);

	return true;
}

$(document).keydown(function(event){
	switch (event.keyCode) {
    case 37://left
        if(moveLeft()){
            //setTimeout("generateOneNumber()",210);
            creatNumber();//每次新增一个数字就可能出现游戏结束
            isgameover();//300毫秒
        }
        break;
    case 38://up
        if(moveUp()){
            creatNumber();//每次新增一个数字就可能出现游戏结束
            isgameover();
        }
        break;
    case 39://right
        if(moveRight()){
            creatNumber();//每次新增一个数字就可能出现游戏结束
            isgameover();
        }
        break;
    case 40://down
        if(moveDown()){
            creatNumber();//每次新增一个数字就可能出现游戏结束
            isgameover();
        }
        break;

    }

});

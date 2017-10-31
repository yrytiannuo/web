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
	score=0;
	step=0;
	$('#score').text(score);
	$('#step').text(step);
	//将分数和步数置为零
}


function updatebgNumber(){
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
				numberceil.css('width','170px');
				numberceil.css('height','100px');
				numberceil.css('top',gettop(i,j));
				numberceil.css('left',getleft(i,j));
				numberceil.css('background-color',getnumcolor(board[i][j]));
				numberceil.text(board[i][j]);
			}
		}
	}
}
//获取top值
function gettop(i,j){
	var top=20+i*140;
	return top;
}
//获取left值
function getleft(i,j){
	var left=20+j*190;
	return left;
}
//获取不同的数字对应的背景颜色
function getnumcolor(n){
	    switch(n){
        case 2:
            return "#eee4da";
            break;
        case 4:
            return "#ede0c8";
            break;
        case 8:
            return "#f2b179";
            break;
        case 16:
            return "#f59563";
            break;
        case 32:
            return '#f67c5f';
            break;
        case 64:
            return "#f65e3b";
            break;
        case 128:
            return '#edcf72';
            break;
        case 256:
            return "#edcc61";
            break;
        case 512:
            return '#9c0';
            break;
        case 1024:
            return "#33b5e5";
            break;
        case 2048:
            return '#09c';
            break;
    }
    return "black";
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
function moveLeft(){//更多地细节信息
    //判断格子是否能够向左移动
    if( !canMoveLeft(board))
        return false;
    //真正的moveLeft函数//标准
    for(var i = 0;i<4;i++)
        for(var j = 1;j<4;j++){//第一列的数字不可能向左移动
            if(board[i][j] !=0){
                //(i,j)左侧的元素
                for(var k = 0;k<j;k++){
                    //落脚位置的是否为空 && 中间没有障碍物
                    if(board[i][k] == 0 && noBlockHorizontal(i , k, j, board)){
                        //move
                        showMoveAnimation(i, j,i,k);
                        board[i][k] = board[i][j];
                        board[i][j] = 0;
                        continue;
                    }
                    //落脚位置的数字和本来的数字相等 && 中间没有障碍物
                    else if(board[i][k] == board[i][j] && noBlockHorizontal(i , k, j, board)){
                        //move
                        showMoveAnimation(i, j,i,k);
                        //add
                        board[i][k] += board[i][j];
                        board[i][j] = 0;
                        
                        continue;
                    }
                }
            }
        }
    setTimeout("updatebgNumber()",200);
    return true;
}
function moveRight(){
	//判断是否能运动
	if(!canMoveRight(board))
	{
		return false;
	}
	//向右移的代码
	for(var i=0;i<4;i++)
	{
		for(var j=2;j>=0;j--)
		{
			if(board[i][j]!=0)
			{
				for(var k=3;k>j;k--)
				{
					if(board[i][k]==0&&noBlockHorizontal(i,j,k,board)){
						showMoveAnimation(i, j,i,k);
                        board[i][k] = board[i][j];
                        board[i][j] = 0;
                        continue;
					}
					else if(board[i][k] == board[i][j] && noBlockHorizontal(i , j, k, board)){
                        //move
                        showMoveAnimation(i, j,i,k);
                        //add
                        board[i][k] += board[i][j];
                        board[i][j] = 0;
                        
                        continue;
                    }
				}
			}
		}
	}
	setTimeout("updatebgNumber()",200);
    return true;
}
function moveUp(){
	//判断是否能运动
	if(!canMoveUp(board))
	{
		return false;
	}
	//向shang移的代码
	for(var j=0;j<4;j++)
	{
		for(var i=1;i<4;i++)
		{
			if(board[i][j]!=0)
			{
				for(var k=0;k<i;k++)
				{
					if(board[k][j]==0&&noBlockHorizontal1(j,k,i,board)){
						showMoveAnimation(i, j,k,j);
                        board[k][j] = board[i][j];
                        board[i][j] = 0;
                        continue;
					}
					else if(board[k][j] == board[i][j] && noBlockHorizontal1(j , k, i, board)){
                        //move
                        showMoveAnimation(i, j,k,j);
                        //add
                        board[k][j] += board[i][j];
                        board[i][j] = 0;
                        
                        continue;
                    }
				}
			}
		}
	}
	setTimeout("updatebgNumber()",200);
    return true;
}
function moveDown(){
	//判断是否能运动
	if(!canMoveDown(board))
	{
		return false;
	}
	//向shang移的代码
	for(var j=0;j<4;j++)
	{
		for(var i=2;i>=0;i--)
		{
			if(board[i][j]!=0)
			{
				for(var k=3;k>i;k--)
				{
					if(board[k][j]==0&&noBlockHorizontal1(j,k,i,board)){
						showMoveAnimation(i, j,k,j);
                        board[k][j] = board[i][j];
                        board[i][j] = 0;
                        continue;
					}
					else if(board[k][j] == board[i][j] && noBlockHorizontal1(j , k, i, board)){
                        //move
                        showMoveAnimation(i, j,k,j);
                        //add
                        board[k][j] += board[i][j];
                        board[i][j] = 0;
                        
                        continue;
                    }
				}
			}
		}
	}
	setTimeout("updatebgNumber()",200);
    return true;
}
function nomove(board){
    if(canMoveLeft(board)|| canMoveRight(board)||canMoveUp(board)||canMoveDown(board))
        return false;
    return true;
}
//判断是否能左移
function canMoveLeft( board ){
    for(var i = 0;i<4;i++)
        for(var j = 1;j<4;j++)
            if( board[i][j] !=0 )
                if( board[i][j-1] == 0 || board[i][j-1] == board[i][j])
                    return true;
                    
    return false;
}
//判断是否能右移
function canMoveRight(board){
	for(var i=0;i<4;i++)
		for(var j=2;j>=0;j--)
			if(board[i][j]!=0)
				if(board[i][j+1]==0||board[i][j+1]==board[i][j])
					return true;

	return false;
}
//判断是否能上移
function canMoveUp(board){
	for(var j=0;j<4;j++)
	{
		for(var i=1;i<4;i++)
		{
			if(board[i][j]!=0)
			{
				if(board[i-1][j]==0||board[i-1][j]==board[i][j])
				{
					return true;
				}
			}
		}
	}
	return false;
}
//判断是否能下移
function canMoveDown(board){
	for(var j=0;j<4;j++)
		for(var i=2;i>=0;i--)
			if(board[i][j]!=0)
				if(board[i+1][j]==0||board[i+1][j]==board[i][j])
					return true;


	return false;
}
function noBlockHorizontal(row, col1, col2, board){
    for(var i = col1 +1; i<col2; i++)
    {
    	if(board[row][i]!=0)
        {
            return false;
        }
    }     
    return true;
}
function noBlockHorizontal1(row, col1, col2, board){
    for(var i=col1+1;i<col2;i++)
    {
        if(board[i][row]!=0)
        {
            return false;
        }
    }
    return true;
}

//棋盘上还有没有空间
function nospace(board){
	for(var i=0;i<4;i++)
	{
		for(var j=0;j<4;j++){
			if(board[i][j]==0)
			{
				return false;
			}
		}
	}
	return true;
}
function shownumberwithAnimation(i,j,n){
	var numberceil=$('number_ceil-'+i+'-'+j);
	numberceil.css('backgrand-color',getnumcolor(n));
	// numberceil.css('width','170px');
	// numberceil.css('height','100px');
	// numberceil.css('top',gettop(i, j));
	// numberceil.css('left',getleft(i, j));
	numberceil.text(n);
	numberceil.animate({
        width : "170px",
        height : "100px",
        top : gettop(i, j),
        left : getleft(i, j)
    }, 50);
}
function showMoveAnimation(i, j, toi, toj){
    
    var numberCeil = $('#number_ceil-'+i +'-'+j);
    numberCeil.animate({
    	top:gettop(toi,toj),
    	left:getleft(toi,toj)
    },200);
}
//判断游戏结束
function isgameover(){
	if(nospace(board)&&nomove(board)){
		alert("gameover!");
	}
}


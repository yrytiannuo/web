function moveLeft(){//更多地细节信息
    //判断格子是否能够向左移动
    if( !canMoveLeft(board))
    {
        return false;
    }
    step+=1;
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
                        score+=board[i][j];
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
	step+=1;
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
                        score+=board[i][j];
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
	step+=1;
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
                        score+=board[i][j];
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
	step+=1;
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
                        score+=board[i][j];
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

function shownumberwithAnimation(i,j,n){
	var numberceil=$('number_ceil-'+i+'-'+j);
	numberceil.css('backgrand-color',getnumcolor(n));
	// numberceil.css('width','170px');
	// numberceil.css('height','100px');
	// numberceil.css('top',gettop(i, j));
	// numberceil.css('left',getleft(i, j));
	numberceil.text(n);
	numberceil.animate({
        width : "100px",
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


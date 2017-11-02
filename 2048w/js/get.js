//获取top值
function gettop(i,j){
	var top=20+i*110;
	return top;
}
//获取left值
function getleft(i,j){
	var left=20+j*110;
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

//能否上下左右移动
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
//判断两位置之间有没有其他障碍1
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
//判断两位置之间有没有其他障碍
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

//判断游戏结束
function isgameover(){
    if(nospace(board)&&nomove(board)){
        alert("gameover!");
    }
}

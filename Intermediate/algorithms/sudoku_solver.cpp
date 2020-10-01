#include<bits/stdc++.h>
using namespace std;
int board[4][4]={{1,3,0,4},{2,0,3,1},{0,1,0,2},{4,0,1,0}};
bool isRowsafe(int board[][4],int row,int num)
{

		for(int j=0;j<4;j++)
	 	 {
	 	 	if(board[row][j]==num)
	 	 		return false;
	 	 }
	 	 return true;
}
bool isColsafe(int board[][4],int col,int num)
{
	for(int j=0;j<4;j++)
	 	 {
	 	 	if(board[j][col]==num)
	 	 		return false;
	 	 }
	 	 return true;
}
bool isBoxsafe(int board[][4],int row,int col,int num)
{
	int r=row-row%2;
	int c=col-col%2;
	 for(int i=r;i<r+2;i++)
	 {
		for(int j=c;j<c+2;j++)
	 	 {
	 	 	if(board[i][j]==num)
	 	 		return false;
	 	 }
	 }
	 	 return true;
}
bool canwePlace(int board[][4],int row,int col,int num)
{
	if(!isRowsafe(board,row,num))
		return false;
	if(!isColsafe(board,col,num))
		return false;
	if(!isBoxsafe(board,row,col,num))
		return false;

	return true;
}

bool sudokuSolver(int board[][4])
{
	int row=-1;
	int col=-1;
	bool isEmpty=false;
	 for(int i=0;i<4;i++)
	 {
	 	 for(int j=0;j<4;j++)
	 	 {
	 	 	if(board[i][j]==0)
	 	 	{
	 	 		isEmpty=true;
	 	 		row=i;
	 	 		col=j;
	 	 		break;
	 	 	}
	 	 }
	 	 	if(isEmpty)
	 	 		break;
	 }
	 if(!isEmpty)
	 	return true;
	 for(int num=1; num<=4; num++)
	 {
	 	if(canwePlace(board, row, col, num))
	 	{
	 		board[row][col]=num;
	 		if(sudokuSolver(board))
	 		{
	 			return true;
	 		}
	 		board[row][col]=0;
	 	}
	 }
	 return false;
}

int main(){

        cout<<sudokuSolver(board)<<endl;
        for(int i=0;i<4;i++)
		 {
		 	 for(int j=0;j<4;j++)
		 	 {
		 	 	cout<<board[i][j]<<" ";
		 	 }
		 	 cout<<endl;
	 	}

       
return 0;
}
#include <stdio.h>

int main() {
	
	char direction='.';
	long long int score=0;
	int board[20][10];
	int cycle=0, next=0, check=0, rot=0, retry=0;
	int pl1=0, pl2=0, pl3=0, pl4=0;
	int pc1=0, pc2=0, pc3=0, pc4=0;
	
	system("tput reset");
	
	//Title Screen
	printf("\n					TTTTTTTTTTTTTTTTTTTTTTT                         tttt                              iiii                   \n					T:::::::::::::::::::::T                      ttt:::t                             i::::i                  \n					T:::::::::::::::::::::T                      t:::::t                              iiii                   \n					T:::::TT:::::::TT:::::T                      t:::::t                                                     \n					TTTTTT  T:::::T  TTTTTTeeeeeeeeeeee    ttttttt:::::ttttttt   rrrrr   rrrrrrrrr  iiiiiii     ssssssssss   \n					        T:::::T      ee::::::::::::ee  t:::::::::::::::::t   r::::rrr:::::::::r i:::::i   ss::::::::::s  \n					        T:::::T     e::::::eeeee:::::eet:::::::::::::::::t   r:::::::::::::::::r i::::i ss:::::::::::::s \n					        T:::::T    e::::::e     e:::::etttttt:::::::tttttt   rr::::::rrrrr::::::ri::::i s::::::ssss:::::s\n					        T:::::T    e:::::::eeeee::::::e      t:::::t          r:::::r     r:::::ri::::i  s:::::s  ssssss \n					        T:::::T    e:::::::::::::::::e       t:::::t          r:::::r     rrrrrrri::::i    s::::::s      \n					        T:::::T    e::::::eeeeeeeeeee        t:::::t          r:::::r            i::::i       s::::::s   \n					        T:::::T    e:::::::e                 t:::::t    ttttttr:::::r            i::::i ssssss   s:::::s \n					      TT:::::::TT  e::::::::e                t::::::tttt:::::tr:::::r           i::::::is:::::ssss::::::s\n					      T:::::::::T   e::::::::eeeeeeee        tt::::::::::::::tr:::::r           i::::::is::::::::::::::s \n					      T:::::::::T    ee:::::::::::::e          tt:::::::::::ttr:::::r           i::::::i s:::::::::::ss  \n					      TTTTTTTTTTT      eeeeeeeeeeeeee            ttttttttttt  rrrrrrr           iiiiiiii  sssssssssss    \n");
	
	printf("\n						`a` = Move a peca para a esquerda                       `d` = Move a peca para a direita\n");
	printf("						`s` = Move a peca para baixo                            `w` = Gira a peca\n\n");
	printf("										PRESSIONE ENTER PARA JOGAR!\n");
	
	scanf("%*c");
	system("tput reset");
	
	while(retry==0)
	{
	
		for(int i=0;i<20;i++)
		{ //spawn board
			for(int j=0;j<10;j++)
			{
				board[i][j]=0;
			}
		}
		
		direction='.';
		
		cycle=0;
		next=0;
		check=0;
		rot=0;
		retry=0;
		
		pl1=0;
		pl2=0;
		pl3=0;
		pl4=0;
		
		pc1=0;
		pc2=0;
		pc3=0;
		pc4=0;
		
		score=0;
		
		while(1)
		{
			if(cycle==0)
			{ //spawn square
				pl1=0;
				pl2=1;
				pl3=0;
				pl4=0;
				
				pc1=4;
				pc2=5;
				pc3=0;
				pc4=0;
				
				if(board[pl1][pc1]!=0 || board[pl1][pc2]!=0 || board[pl2][pc1]!=0 || board[pl2][pc2]!=0){break;}
				
				board[pl1][pc1]=1;
				board[pl1][pc2]=1;
				board[pl2][pc1]=1;
				board[pl2][pc2]=1;
				
				cycle++;
			}
			else if(cycle==2)
			{ //spawn s
				rot=0;
				pl1=0;
				pl2=1;
				pl3=0;
				pl4=0;
				
				pc1=3;
				pc2=4;
				pc3=5;
				pc4=0;
				
				if(board[pl1][pc2]!=0 || board[pl1][pc3]!=0 || board[pl2][pc1]!=0 || board[pl2][pc2]!=0){break;}
				
				board[pl1][pc2]=1;
				board[pl1][pc3]=1;
				board[pl2][pc1]=1;
				board[pl2][pc2]=1;
				
				cycle++;
			}
			else if(cycle==4)
			{ //spawn L
				rot=0;
				pl1=0;
				pl2=1;
				pl3=2;
				pl4=0;
				
				pc1=4;
				pc2=5;
				pc3=0;
				pc4=0;
				
				if(board[pl1][pc1]!=0 || board[pl2][pc1]!=0 || board[pl3][pc1]!=0 || board[pl3][pc2]!=0){break;}
				
				board[pl1][pc1]=1;
				board[pl2][pc1]=1;
				board[pl3][pc1]=1;
				board[pl3][pc2]=1;
				
				cycle++;
			}
			else if(cycle==6)
			{ //spawn T
				rot=0;
				pl1=0;
				pl2=1;
				pl3=0;
				pl4=0;
				
				pc1=3;
				pc2=4;
				pc3=5;
				pc4=0;
				
				if(board[pl1][pc1]!=0 || board[pl1][pc2]!=0 || board[pl1][pc3]!=0 || board[pl2][pc2]!=0){break;}
				
				board[pl1][pc1]=1;
				board[pl1][pc2]=1;
				board[pl1][pc3]=1;
				board[pl2][pc2]=1;
				
				cycle++;
			}
			else if(cycle==8)
			{ //spawn |
				rot=0;
				pl1=0;
				pl2=1;
				pl3=2;
				pl4=3;
				
				pc1=4;
				pc2=0;
				pc3=0;
				pc4=0;
				
				if(board[pl1][pc1]!=0 || board[pl2][pc1]!=0 || board[pl3][pc1]!=0 || board[pl4][pc1]!=0){break;}
				
				board[pl1][pc1]=1;
				board[pl2][pc1]=1;
				board[pl3][pc1]=1;
				board[pl4][pc1]=1;
				
				cycle++;
			}
			else if(cycle==10)
			{ //spawn |-
				rot=0;
				pl1=0;
				pl2=1;
				pl3=2;
				pl4=0;
				
				pc1=4;
				pc2=5;
				pc3=0;
				pc4=0;
				
				if(board[pl1][pc1]!=0 || board[pl1][pc2]!=0 || board[pl2][pc1]!=0 || board[pl3][pc1]!=0){break;}
				
				board[pl1][pc1]=1;
				board[pl1][pc2]=1;
				board[pl2][pc1]=1;
				board[pl3][pc1]=1;
				
				cycle++;
			}
			else if(cycle==12)
			{ //spawn z
				rot=0;
				pl1=0;
				pl2=1;
				pl3=0;
				pl4=0;
				
				pc1=3;
				pc2=4;
				pc3=5;
				pc4=0;
				
				if(board[pl1][pc1]!=0 || board[pl1][pc2]!=0 || board[pl2][pc2]!=0 || board[pl2][pc3]!=0){break;}
				
				board[pl1][pc1]=1;
				board[pl1][pc2]=1;
				board[pl2][pc2]=1;
				board[pl2][pc3]=1;
				
				cycle++;
			}
			
			printf("										XXXXXXXXXXXX\n");
			for(int i=0;i<20;i++)
			{ //print board
				printf("										X");
				for(int j=0;j<10;j++)
				{
					if(board[i][j]==0)
					{
						printf(" ");
					}
					else if(board[i][j]==1)
					{
						printf("0");
					}
				}
				printf("X\n");
			}
			printf("										XXXXXXXXXXXX\n");
			score+=10;
			


			system("stty raw");
			direction=getchar();
			system("stty cooked");
			
			system("tput reset");
			
			if(direction=='w')
			{ //rotate
				if(cycle==3)
				{ //s - 2
					if(rot==0)
					{
						if((board[pl2][pc2+1]==0) && (board[pl2+1][pc2+1]==0) && (pl2!=19))
						{
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							
							pc3=0;
							pl3=pl2+1;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
							
							rot++;
						}
					}
					else if(rot==1)
					{
						if((board[pl2][pc2+1]==0) && (board[pl2+1][pc2+1]==0) && (pc2!=9))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pc3=pc2+1;
							pl3=0;
							
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							
							rot=0;
						}
					}
				}
				else if(cycle==5)
				{ //L - 4
					if(rot==0)
					{
						if((board[pl2][pc1-1]==0) && (board[pl2][pc1+1]==0) && (board[pl3][pc1-1]==0) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							board[pl3][pc2]=0;
							
							pl1=pl1+1;
							pl2=pl2+1;
							pl3=0;
							pc1=pc1-1;
							pc2=pc2-1;
							pc3=pc2+1;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc1]=1;
							
							rot++;
						}
					}
					else if(rot==1)
					{
						if((board[pl1-1][pc1]==0) && (board[pl1-1][pc2]==0) && (board[pl1+1][pc2]==0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							
							pl1=pl1-1;
							pl2=pl2-1;
							pl3=pl2+1;
							pc3=0;
														
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
							
							rot++;
						}
					}
					else if(rot==2)
					{
						if((board[pl1+1][pc1]==0) && (board[pl1][pc2+1]==0) && (board[pl2][pc2+1]==0) && (pc2!=9))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pl3=0;
							pc3=pc2+1;
							
							board[pl1][pc3]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							
							rot++;
						}
					}
					else if(rot==3)
					{
						if((board[pl1][pc3-1]==0) && (board[pl2+1][pc2]==0) && (board[pl2+1][pc3]==0) && (pl2!=19))
						{
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pl3=pl2+1;
							pc1=pc2;
							pc2=pc3;
							pc3=0;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
							board[pl3][pc2]=1;
							
							rot=0;
						}
					}
				}
				else if(cycle==7)
				{ //T - 4
					if(rot==0)
					{
						if(board[pl1-1][pc2]==0)
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc2]=0;
							
							pl1=pl1-1;
							pl2=pl2-1;
							pl3=pl2+1;
							pc3=0;
							
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
							
							rot++;
						}
					}
					else if(rot==1)
					{
						if((board[pl2][pc2+1]==0) && (pc2!=9))
						{
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pc3=pc2+1;
							pl3=0;
							
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							
							rot++;
						}
					}
					else if(rot==2)
					{
						if((board[pl2+1][pc2]==0) && (pl2!=19))
						{
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pl3=pl2+1;
							pc1=pc2;
							pc2=pc3;
							pc3=0;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc1]=1;
							
							rot++;
						}
					}
					else if(rot==3)
					{
						if((board[pl2][pc1-1]==0) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc1]=0;
							
							pl1=pl2;
							pl2=pl3;
							pl3=0;
							pc1=pc1-1;
							pc2=pc2-1;
							pc3=pc2+1;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc2]=1;
							
							rot=0;
						}
					}
				}
				else if(cycle==9)
				{ // | - 2
					if(rot==0)
					{
						if((board[pl2][pc1+1]==0) && (board[pl2][pc1+2]==0) && (board[pl2][pc1-1]==0) && (pc1<8) && (pc1>0))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							board[pl4][pc1]=0;
							
							pl1=0;
							pl3=0;
							pl4=0;
							
							pc1-=1;
							pc2=pc1+1;
							pc3=pc1+2;
							pc4=pc1+3;
							
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							board[pl2][pc4]=1;
							
							rot++;
						}
					}
					else if(rot==1)
					{
						if((board[pl2-1][pc2]==0) && (board[pl2+1][pc2]==0) && (board[pl2+2][pc2]==0) && (pl2<18))
						{
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							board[pl2][pc4]=0;
							
							pc1=pc2;
							pc2=0;
							pc3=0;
							pc4=0;
							
							pl1=pl2-1;
							pl3=pl2+1;
							pl4=pl2+2;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
							board[pl4][pc1]=1;
							
							rot=0;
						}
					}
				}
				else if(cycle==11)
				{ // |- - 4
					if(rot==0)
					{
						if((board[pl2][pc1-1]==0) && (board[pl2][pc1+1]==0) && (board[pl3][pc1+1]==0) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							
							pl1=pl2;
							pl2=pl3;
							pl3=0;
							pc1=pc1-1;
							pc2=pc2-1;
							pc3=pc2+1;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc3]=1;
							
							rot++;
						}
					}
					else if(rot==1)
					{
						if((board[pl1+1][pc1]==0) && (board[pl1+1][pc2]==0) && (board[pl1-1][pc2]==0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc3]=0;
							
							pl1=pl1-1;
							pl2=pl2-1;
							pl3=pl2+1;
							pc3=0;
							
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl3][pc1]=1;
							board[pl3][pc2]=1;
							
							rot++;
						}
					}
					else if(rot==2)
					{
						if((board[pl1][pc2-1]==0) && (board[pl2][pc2-1]==0) && (board[pl2][pc2+1]==0) && (pc2!=9))
						{
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl3][pc1]=0;
							board[pl3][pc2]=0;
							
							pl3=0;
							pc3=pc2+1;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							
							rot++;
						}
					}
					else if(rot==3)
					{
						if((board[pl2-1][pc2]==0) && (board[pl2-1][pc3]==0) && (board[pl2+1][pc2]==0) && (pl2!=19))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pl3=pl2+1;
							pc1=pc2;
							pc2=pc3;
							pc3=0;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
							
							rot=0;
						}
					}
				}
				else if(cycle==13)
				{ // z - 2
					if(rot==0)
					{
						if((board[pl2+1][pc2]==0) && (board[pl1][pc3]==0) && (pl2!=19))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1=0;
							pl3=pl2+1;
							
							board[pl1][pc3]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							board[pl3][pc2]=1;
							
							rot++;
						}
					}
					else if(rot==1)
					{
						if((board[pl1][pc2]==0) && (board[pl1][pc2-1]==0) && (pc2!=0))
						{
							board[pl1][pc3]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							board[pl3][pc2]=0;
							
							pl3=0;
							pc1=pc2-1;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							
							rot=0;
						}
					}
				}
			}
			else if(direction=='a')
			{ //left
				if(cycle==1)
				{ //square
					if(((board[pl1][pc1-1]==0) && (board[pl2][pc1-1]==0)) && (pc1!=0))
					{
						board[pl1][pc1]=0;
						board[pl1][pc2]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						
						pc1--;
						pc2--;
						
						board[pl1][pc1]=1;
						board[pl1][pc2]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
					}
				}
				else if(cycle==3)
				{ //s
					if(rot==0)
					{
						if(((board[pl2][pc1-1]==0) && (board[pl1][pc2-1]==0)) && (pc1!=0))
						{
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							
							pc1--;
							pc2--;
							pc3--;
							
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
						}
					}
					else if(rot==1)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc1-1]==0) && (board[pl3][pc2-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pc1--;
							pc2--;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
						}
					}
				}
				else if(cycle==5)
				{ //L
					if(rot==0)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc1-1]==0) && (board[pl3][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							board[pl3][pc2]=0;
							
							pc1--;
							pc2--;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
							board[pl3][pc2]=1;
						}
					}
					else if(rot==1)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							
							pc1--;
							pc2--;
							pc3--;
							
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
						}
					}
					else if(rot==2)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc2-1]==0) && (board[pl3][pc2-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pc1--;
							pc2--;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
						}
					}
					else if(rot==3)
					{
						if(((board[pl1][pc3-1]==0) && (board[pl2][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1--;
							pc2--;
							pc3--;
							
							board[pl1][pc3]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
						}
					}
					
				}
				else if(cycle==7)
				{ //T
					if(rot==0)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc2-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc2]=0;
							
							pc1--;
							pc2--;
							pc3--;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc2]=1;
						}
					}
					else if(rot==1)
					{
						if(((board[pl1][pc2-1]==0) && (board[pl2][pc1-1]==0) && (board[pl3][pc2-1]==0)) && (pc1!=0))
						{
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pc1--;
							pc2--;
							
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
						}
					}
					else if(rot==2)
					{
						if(((board[pl1][pc2-1]==0) && (board[pl2][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1--;
							pc2--;
							pc3--;
							
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
						}
					}
					else if(rot==3)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc1-1]==0) && (board[pl3][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc1]=0;
							
							pc1--;
							pc2--;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc1]=1;
						}
					}
				}
				else if(cycle==9)
				{ // |
					if(rot==0)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc1-1]==0) && (board[pl3][pc1-1]==0) && (board[pl4][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							board[pl4][pc1]=0;
							
							pc1--;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
							board[pl4][pc1]=1;
						}
					}
					else if(rot==1)
					{
						if((board[pl2][pc1-1]==0) && (pc1!=0))
						{
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							board[pl2][pc4]=0;
							
							pc1--;
							pc2--;
							pc3--;
							pc4--;
							
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							board[pl2][pc4]=1;
						}
					}
				}
				else if(cycle==11)
				{ // |-
					if(rot==0)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc1-1]==0) && (board[pl3][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							
							pc1--;
							pc2--;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
						}
					}
					else if(rot==1)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc3-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc3]=0;
							
							pc1--;
							pc2--;
							pc3--;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc3]=1;
						}
					}
					else if(rot==2)
					{
						if(((board[pl1][pc2-1]==0) && (board[pl2][pc2-1]==0) && (board[pl3][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl3][pc1]=0;
							board[pl3][pc2]=0;
							
							pc1--;
							pc2--;
							
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl3][pc1]=1;
							board[pl3][pc2]=1;
						}
					}
					else if(rot==3)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc1-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1--;
							pc2--;
							pc3--;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
						}
					}
				}
				else if(cycle==13)
				{ // z
					if(rot==0)
					{
						if(((board[pl1][pc1-1]==0) && (board[pl2][pc2-1]==0)) && (pc1!=0))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1--;
							pc2--;
							pc3--;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
						}
					}
					else if(rot==1)
					{
						if((board[pl1][pc3-1]==0) && (board[pl2][pc2-1]==0) && (board[pl3][pc2-1]==0) && (pc2!=0))
						{
							board[pl1][pc3]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							board[pl3][pc2]=0;
							
							pc2--;
							pc3--;
							
							board[pl1][pc3]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							board[pl3][pc2]=1;
						}
					}
				}
			}
			else if(direction=='d')
			{ //right
				if(cycle==1)
				{ //square
					if(((board[pl1][pc2+1]==0) && (board[pl2][pc2+1]==0)) && (pc2!=9))
					{
						board[pl1][pc1]=0;
						board[pl1][pc2]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						
						pc1++;
						pc2++;
						
						board[pl1][pc1]=1;
						board[pl1][pc2]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
					}
				}
				else if(cycle==3)
				{ //s
					if(rot==0)
					{
						if(((board[pl1][pc3+1]==0) && (board[pl2][pc2+1]==0)) && (pc3!=9))
						{
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							
							pc1++;
							pc2++;
							pc3++;
							
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
						}
					}
					else if(rot==1)
					{
						if(((board[pl1][pc1+1]==0) && (board[pl2][pc2+1]==0) && (board[pl3][pc2+1]==0)) && (pc2!=9))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pc1++;
							pc2++;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
						}
					}
				}
				else if(cycle==5)
				{ //L
					if(rot==0)
					{
						if(((board[pl1][pc1+1]==0) && (board[pl2][pc1+1]==0) && (board[pl3][pc2+1]==0)) && (pc2!=9))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							board[pl3][pc2]=0;
							
							pc1++;
							pc2++;
												
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
							board[pl3][pc2]=1;
						}
					}
					else if(rot==1)
					{
						if(((board[pl1][pc3+1]==0) && (board[pl2][pc1+1]==0)) && (pc3!=9))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							
							pc1++;
							pc2++;
							pc3++;
												
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc1]=1;
						}
					}
					else if(rot==2)
					{
						if(((board[pl1][pc2+1]==0) && (board[pl2][pc2+1]==0) && (board[pl3][pc2+1]==0)) && (pc2!=9))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pc1++;
							pc2++;
												
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
						}
					}
					else if(rot==3)
					{
						if(((board[pl1][pc3+1]==0) && (board[pl2][pc3+1]==0)) && (pc3!=9))
						{
							board[pl1][pc3]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1++;
							pc2++;
							pc3++;
												
							board[pl1][pc3]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
						}
					}
				}
				else if(cycle==7)
				{ //T
					if(rot==0)
					{
						if(((board[pl1][pc3+1]==0) && (board[pl2][pc2+1]==0)) && (pc3!=9))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc2]=0;
							
							pc1++;
							pc2++;
							pc3++;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc2]=1;
						}
					}
					else if(rot==1)
					{
						if(((board[pl1][pc2+1]==0) && (board[pl2][pc2+1]==0) && (board[pl3][pc2+1]==0)) && (pc2!=9))
						{
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc2]=0;
							
							pc1++;
							pc2++;
							
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc2]=1;
						}
					}
					else if(rot==2)
					{
						if(((board[pl1][pc2+1]==0) && (board[pl2][pc3+1]==0)) && (pc3!=9))
						{
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1++;
							pc2++;
							pc3++;
							
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
						}
					}
					else if(rot==3)
					{
						if(((board[pl1][pc1+1]==0) && (board[pl2][pc2+1]==0) && (board[pl3][pc1+1]==0)) && (pc2!=9))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl3][pc1]=0;
							
							pc1++;
							pc2++;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl3][pc1]=1;
						}
					}
				}
				else if(cycle==9)
				{ // |
					if(rot==0)
					{
						if(((board[pl1][pc1+1]==0) && (board[pl2][pc1+1]==0) && (board[pl3][pc1+1]==0) && (board[pl4][pc1+1]==0)) && (pc1!=9))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							board[pl4][pc1]=0;
							
							pc1++;
												
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
							board[pl4][pc1]=1;
						}
					}
					else if(rot==1)
					{
						if((board[pl2][pc4+1]==0) && (pc4!=9))
						{
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							board[pl2][pc4]=0;
							
							pc1++;
							pc2++;
							pc3++;
							pc4++;
							
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							board[pl2][pc4]=1;
						}
					}
				}
				else if(cycle==11)
				{ // |-
					if(rot==0)
					{
						if(((board[pl1][pc2+1]==0) && (board[pl2][pc1+1]==0) && (board[pl3][pc1+1]==0)) && (pc2!=9))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc1]=0;
							board[pl3][pc1]=0;
							
							pc1++;
							pc2++;
												
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc1]=1;
							board[pl3][pc1]=1;
						}
					}
					else if(rot==1)
					{
						if(((board[pl1][pc3+1]==0) && (board[pl2][pc3+1]==0)) && (pc3!=9))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl1][pc3]=0;
							board[pl2][pc3]=0;
							
							pc1++;
							pc2++;
							pc3++;
							
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl1][pc3]=1;
							board[pl2][pc3]=1;
						}
					}
					else if(rot==2)
					{
						if(((board[pl1][pc2+1]==0) && (board[pl2][pc2+1]==0) && (board[pl3][pc2+1]==0)) && (pc2!=9))
						{
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl3][pc1]=0;
							board[pl3][pc2]=0;
							
							pc1++;
							pc2++;
							
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl3][pc1]=1;
							board[pl3][pc2]=1;
						}
					}
					else if(rot==3)
					{
						if(((board[pl1][pc1+1]==0) && (board[pl2][pc3+1]==0)) && (pc3!=9))
						{
							board[pl1][pc1]=0;
							board[pl2][pc1]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1++;
							pc2++;
							pc3++;
							
							board[pl1][pc1]=1;
							board[pl2][pc1]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
						}
					}
				}
				else if(cycle==13)
				{ //z
					if(rot==0)
					{
						if(((board[pl1][pc2+1]==0) && (board[pl2][pc3+1]==0)) && (pc3!=9))
						{
							board[pl1][pc1]=0;
							board[pl1][pc2]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							
							pc1++;
							pc2++;
							pc3++;
												
							board[pl1][pc1]=1;
							board[pl1][pc2]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
						}
					}
					else if(rot==1)
					{
						if((board[pl1][pc3+1]==0) && (board[pl2][pc3+1]==0) && (board[pl3][pc2+1]==0) && (pc3!=9))
						{
							board[pl1][pc3]=0;
							board[pl2][pc2]=0;
							board[pl2][pc3]=0;
							board[pl3][pc2]=0;
							
							pc2++;
							pc3++;
							
							board[pl1][pc3]=1;
							board[pl2][pc2]=1;
							board[pl2][pc3]=1;
							board[pl3][pc2]=1;
						}
					}
				}
			}
			
			//drop piece
			if(cycle==1)
			{ //square
				if(((board[pl2+1][pc1]==0) && (board[pl2+1][pc2]==0)) && (pl2!=19))
				{
					board[pl1][pc1]=0;
					board[pl1][pc2]=0;
					board[pl2][pc1]=0;
					board[pl2][pc2]=0;
					
					pl1++;
					pl2++;
					
					board[pl1][pc1]=1;
					board[pl1][pc2]=1;
					board[pl2][pc1]=1;
					board[pl2][pc2]=1;
				}
				else
				{
					next=1;
				}
			}
			else if(cycle==3)
			{ //s
				if(rot==0)
				{
					if(((board[pl2+1][pc1]==0) && (board[pl2+1][pc2]==0) && (board[pl1+1][pc3]==0)) && (pl2!=19))
					{
						board[pl1][pc2]=0;
						board[pl1][pc3]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						
						pl1++;
						pl2++;
						
						board[pl1][pc2]=1;
						board[pl1][pc3]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==1)
				{
					if(((board[pl2+1][pc1]==0) && (board[pl3+1][pc2]==0)) && (pl3!=19))
					{
						board[pl1][pc1]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						board[pl3][pc2]=0;
						
						pl1++;
						pl2++;
						pl3++;
						
						board[pl1][pc1]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
						board[pl3][pc2]=1;
					}
					else
					{
						next=1;
					}
				}
			}
			else if(cycle==5)
			{ //L
				if(rot==0)
				{
					if(((board[pl3+1][pc1]==0) && (board[pl3+1][pc2]==0)) && (pl3!=19))
					{
						board[pl1][pc1]=0;
						board[pl2][pc1]=0;
						board[pl3][pc1]=0;
						board[pl3][pc2]=0;
						
						pl1++;
						pl2++;
						pl3++;
						
						board[pl1][pc1]=1;
						board[pl2][pc1]=1;
						board[pl3][pc1]=1;
						board[pl3][pc2]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==1)
				{
					if(((board[pl2+1][pc1]==0) && (board[pl1+1][pc2]==0) && (board[pl1+1][pc3]==0)) && (pl2!=19))
					{
						board[pl1][pc1]=0;
						board[pl1][pc2]=0;
						board[pl1][pc3]=0;
						board[pl2][pc1]=0;
						
						pl1++;
						pl2++;
						
						board[pl1][pc1]=1;
						board[pl1][pc2]=1;
						board[pl1][pc3]=1;
						board[pl2][pc1]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==2)
				{
					if(((board[pl1+1][pc1]==0) && (board[pl3+1][pc2]==0)) && (pl3!=19))
					{
						board[pl1][pc1]=0;
						board[pl1][pc2]=0;
						board[pl2][pc2]=0;
						board[pl3][pc2]=0;
						
						pl1++;
						pl2++;
						pl3++;
						
						board[pl1][pc1]=1;
						board[pl1][pc2]=1;
						board[pl2][pc2]=1;
						board[pl3][pc2]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==3)
				{
					if(((board[pl2+1][pc1]==0) && (board[pl2+1][pc2]==0) && (board[pl2+1][pc3]==0)) && (pl2!=19))
					{
						board[pl1][pc3]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						board[pl2][pc3]=0;
						
						pl1++;
						pl2++;
						
						board[pl1][pc3]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
						board[pl2][pc3]=1;
					}
					else
					{
						next=1;
					}
				}
			}
			else if(cycle==7)
			{ //T
				if(rot==0)
				{
					if(((board[pl1+1][pc1]==0) && (board[pl1+1][pc3]==0) && (board[pl2+1][pc2]==0)) && (pl2!=19))
					{
						board[pl1][pc1]=0;
						board[pl1][pc2]=0;
						board[pl1][pc3]=0;
						board[pl2][pc2]=0;
						
						pl1++;
						pl2++;
						
						board[pl1][pc1]=1;
						board[pl1][pc2]=1;
						board[pl1][pc3]=1;
						board[pl2][pc2]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==1)
				{
					if(((board[pl2+1][pc1]==0) && (board[pl3+1][pc2]==0)) && (pl3!=19))
					{
						board[pl1][pc2]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						board[pl3][pc2]=0;
						
						pl1++;
						pl2++;
						pl3++;
						
						board[pl1][pc2]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
						board[pl3][pc2]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==2)
				{
					if(((board[pl2+1][pc1]==0) && (board[pl2+1][pc2]==0) && (board[pl2+1][pc3]==0)) && (pl2!=19))
					{
						board[pl1][pc2]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						board[pl2][pc3]=0;
						
						pl1++;
						pl2++;
						
						board[pl1][pc2]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
						board[pl2][pc3]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==3)
				{
					if(((board[pl3+1][pc1]==0) && (board[pl2+1][pc2]==0)) && (pl3!=19))
					{
						board[pl1][pc1]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						board[pl3][pc1]=0;
						
						pl1++;
						pl2++;
						pl3++;
						
						board[pl1][pc1]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
						board[pl3][pc1]=1;
					}
					else
					{
						next=1;
					}
				}
			}
			else if(cycle==9)
			{ // |
				if(rot==0)
				{
					if(((board[pl4+1][pc1]==0)) && (pl4!=19))
					{
						board[pl1][pc1]=0;
						board[pl2][pc1]=0;
						board[pl3][pc1]=0;
						board[pl4][pc1]=0;
						
						pl1++;
						pl2++;
						pl3++;
						pl4++;
						
						board[pl1][pc1]=1;
						board[pl2][pc1]=1;
						board[pl3][pc1]=1;
						board[pl4][pc1]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==1)
				{
					if((board[pl2+1][pc1]==0) && (board[pl2+1][pc2]==0) && (board[pl2+1][pc3]==0) && (board[pl2+1][pc4]==0) && (pl2!=19))
					{
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						board[pl2][pc3]=0;
						board[pl2][pc4]=0;
						
						pl2++;
						
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
						board[pl2][pc3]=1;
						board[pl2][pc4]=1;
					}
					else
					{
						next=1;
					}
				}
			}
			else if(cycle==11)
			{ // |-
				if(rot==0)
				{
					if(((board[pl3+1][pc1]==0) && (board[pl1+1][pc2]==0)) && (pl3!=19))
					{
						board[pl1][pc1]=0;
						board[pl1][pc2]=0;
						board[pl2][pc1]=0;
						board[pl3][pc1]=0;
						
						pl1++;
						pl2++;
						pl3++;
						
						board[pl1][pc1]=1;
						board[pl1][pc2]=1;
						board[pl2][pc1]=1;
						board[pl3][pc1]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==1)
				{
					if(((board[pl1+1][pc1]==0) && (board[pl1+1][pc2]==0) && (board[pl2+1][pc3]==0)) && (pl2!=19))
					{
						board[pl1][pc1]=0;
						board[pl1][pc2]=0;
						board[pl1][pc3]=0;
						board[pl2][pc3]=0;
						
						pl1++;
						pl2++;
						
						board[pl1][pc1]=1;
						board[pl1][pc2]=1;
						board[pl1][pc3]=1;
						board[pl2][pc3]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==2)
				{
					if(((board[pl3+1][pc1]==0) && (board[pl3+1][pc2]==0)) && (pl3!=19))
					{
						board[pl1][pc2]=0;
						board[pl2][pc2]=0;
						board[pl3][pc1]=0;
						board[pl3][pc2]=0;
						
						pl1++;
						pl2++;
						pl3++;
						
						board[pl1][pc2]=1;
						board[pl2][pc2]=1;
						board[pl3][pc1]=1;
						board[pl3][pc2]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==3)
				{
					if(((board[pl2+1][pc1]==0) && (board[pl2+1][pc2]==0) && (board[pl2+1][pc3]==0)) && (pl2!=19))
					{
						board[pl1][pc1]=0;
						board[pl2][pc1]=0;
						board[pl2][pc2]=0;
						board[pl2][pc3]=0;
						
						pl1++;
						pl2++;
						
						board[pl1][pc1]=1;
						board[pl2][pc1]=1;
						board[pl2][pc2]=1;
						board[pl2][pc3]=1;
					}
					else
					{
						next=1;
					}
				}
			}
			else if(cycle==13)
			{ // z
				if(rot==0)
				{
					if(((board[pl1+1][pc1]==0) && (board[pl2+1][pc2]==0) && (board[pl2+1][pc3]==0)) && (pl2!=19))
					{
						board[pl1][pc1]=0;
						board[pl1][pc2]=0;
						board[pl2][pc2]=0;
						board[pl2][pc3]=0;
						
						pl1++;
						pl2++;
						
						board[pl1][pc1]=1;
						board[pl1][pc2]=1;
						board[pl2][pc2]=1;
						board[pl2][pc3]=1;
					}
					else
					{
						next=1;
					}
				}
				else if(rot==1)
				{
					if((board[pl3+1][pc2]==0) && (board[pl2+1][pc3]==0) && (pl3!=19))
					{
						board[pl1][pc3]=0;
						board[pl2][pc2]=0;
						board[pl2][pc3]=0;
						board[pl3][pc2]=0;
						
						pl1++;
						pl2++;
						pl3++;
						
						board[pl1][pc3]=1;
						board[pl2][pc2]=1;
						board[pl2][pc3]=1;
						board[pl3][pc2]=1;
					}
					else
					{
						next=1;
					}
				}
			}
			
			if(next==1)
			{
				next=0;
				
				for(int i=0;i<20;i++)
				{ // linhas completadas
					for(int j=0;j<10;j++)
					{
						check+=board[i][j];
						if(check==10)
						{
							for(int h=0;h<10;h++)
							{ // zera a linha
								board[i][h]=0;
							}
							
							for(int h=i;h>=0;h--)
							{
								for(int z=0;z<10;z++)
								{
									if(h!=0)
									{
										board[h][z]=board[h-1][z];
									}
									else
									{
										board[h][z]=0;
									}
								}
							}
							score+=250;
						}
					}
					check=0;
				}
				check=0;
				
				if(cycle==13)
				{
					cycle=0;
				}
				else
				{
					cycle++;
				}
			}
		}
		direction='.';

		printf("\n        GGGGGGGGGGGGG                                                                        OOOOOOOOO                                                                   \n     GGG::::::::::::G                                                                      OO:::::::::OO                                                                 \n   GG:::::::::::::::G                                                                    OO:::::::::::::OO                                                               \n  G:::::GGGGGGGG::::G                                                                   O:::::::OOO:::::::O                                                              \n G:::::G       GGGGGG  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee         O::::::O   O::::::Ovvvvvvv           vvvvvvv eeeeeeeeeeee    rrrrr   rrrrrrrrr   \nG:::::G                a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::ee       O:::::O     O:::::O v:::::v         v:::::vee::::::::::::ee  r::::rrr:::::::::r  \nG:::::G                aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::::ee     O:::::O     O:::::O  v:::::v       v:::::ve::::::eeeee:::::eer:::::::::::::::::r \nG:::::G    GGGGGGGGGG           a::::a m::::::::::::::::::::::me::::::e     e:::::e     O:::::O     O:::::O   v:::::v     v:::::ve::::::e     e:::::err::::::rrrrr::::::r\nG:::::G    G::::::::G    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e     O:::::O     O:::::O    v:::::v   v:::::v e:::::::eeeee::::::e r:::::r     r:::::r\nG:::::G    GGGGG::::G  aa::::::::::::a m::::m   m::::m   m::::me:::::::::::::::::e      O:::::O     O:::::O     v:::::v v:::::v  e:::::::::::::::::e  r:::::r     rrrrrrr\nG:::::G        G::::G a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee       O:::::O     O:::::O      v:::::v:::::v   e::::::eeeeeeeeeee   r:::::r            \n G:::::G       G::::Ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e                O::::::O   O::::::O       v:::::::::v    e:::::::e            r:::::r            \n  G:::::GGGGGGGG::::Ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e               O:::::::OOO:::::::O        v:::::::v     e::::::::e           r:::::r            \n   GG:::::::::::::::Ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee        OO:::::::::::::OO          v:::::v       e::::::::eeeeeeee   r:::::r            \n     GGG::::::GGG:::G a::::::::::aa:::am::::m   m::::m   m::::m  ee:::::::::::::e          OO:::::::::OO             v:::v         ee:::::::::::::e   r:::::r            \n        GGGGGG   GGGG  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee            OOOOOOOOO                vvv            eeeeeeeeeeeeee   rrrrrrr            \n");

		printf("\n\nScore: %lld\n\n", score);

		printf("Continuar? [s]=Sim [n]=Nao\n\n");
		
		while(direction=='.')
		{ // continue
			scanf(" %c", &direction);
			if(direction=='n')
			{
				retry=1;
			}
			else if(direction=='s')
			{
			
			}
			else
			{
				direction='.';
			}
		}
		
		system("tput reset");
	}
	
	return 0;
}

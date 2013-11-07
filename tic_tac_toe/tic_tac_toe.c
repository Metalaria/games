#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

char pos_board[3][3];
int count=0;
char name[20];
bool player_count=false;
bool computer_count=false;
int z;
int a=3;
int b=3;
int blank_row;
int blank_column;
int blank_count=0;
bool draw_count=false;

void print()
{
	printf("\n");
	int i,j;
	for(i=0; i<3; ++i)
	{
		printf("\t\t\t");
		for(j=0; j<3; ++j)
		{
			printf("%c\t",pos_board[i][j]);
		}
		printf("\n\n");
	}
}

void player()
{
	int x,y;
	printf("\nEnter position (x,y) where u want to input : ");
	scanf("%d %d",&x,&y);
	if((pos_board[x-1][y-1]!='-')||(x<1)||(x>3)||(y<1)||(y>3))
	{
		printf("Wrong Position\n");
		player();
	}
	else
	{
		pos_board[x-1][y-1]='X';
		printf("\n\nAfter your turn board is : \n\n");
		print();
		count++;
	}
}

bool check1()
{
	a=3;
	b=3;
	int i,j;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			if((pos_board[i][j]!='O') && (pos_board[i][(j+1)%3]=='X') && (pos_board[i][(j+2)%3]=='X'))
			{
				a=i;
				b=j;
			}
		}
	}
	return a==3;
}

bool check2()
{
	a=3;
	b=3;
	int i,j;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			if((pos_board[i][j]!='O') && (pos_board[(i+1)%3][j]=='X') && (pos_board[(i+2)%3][j]=='X'))
			{
				a=i;
				b=j;
			}
		}
	}
	return a==3;
}

bool check3()
{
	a=3;
	b=3;
	if((pos_board[0][0]=='X')&&(pos_board[1][1]=='X')&&(pos_board[2][2]!='O'))
	{
		a=2;
		b=2;
	}
	else if((pos_board[1][1]=='X')&&(pos_board[2][2]=='X')&&(pos_board[0][0]!='O'))
	{
		a=2;
		b=2;
	}
	return a==3;
}

bool check4()
{
	a=3;
	b=3;
	if((pos_board[2][0]=='X')&&(pos_board[1][1]=='X')&&(pos_board[0][2]!='O'))
	{
		a=0;
		b=2;
	}
	else if((pos_board[1][1]=='X')&&(pos_board[0][2]=='X')&&(pos_board[2][0]!='O'))
	{
		a=2;
		b=0;
	}
	return a==3;
}

bool check_player_line()
{
	return (check1() && check2() && check3() && check4());
}

void find_blank_c3()							// To find blank position in proximity of computer position when count=3 and z=1
{
	int i,j,k;
	for(i=0; i<3; ++i)
	{
		for(j=0; j<3; ++j)
		{
			if((i+j)%2!=0)
			{
				continue;
			}
			else
			{
			if(pos_board[i][j]=='O')
			{
				if((i==0)&&(j==0))
				{
					if((pos_board[0][1]=='-')&&(pos_board[0][2]=='-'))
					{
						blank_count=blank_count+2;
					}
					if(blank_count==2)
					{
						blank_row=0;
						blank_column=2;
						return;
					}
					else
					{
						blank_count=0;
						if((pos_board[1][0]=='-')&&(pos_board[2][0]=='-'))
						{
							blank_count=blank_count+2;
						}
						if(blank_count==2)
						{
							blank_row=2;
							blank_column=0;
							return;
						}
					}
				}
				else if((i==0)&&(j==2))
				{
					if((pos_board[0][0]=='-')&&(pos_board[0][1]=='-'))
					{
						blank_count=blank_count+2;
					}
					if(blank_count==2)
					{
						blank_row=0;
						blank_column=0;
						return;
					}
					else
					{
						blank_count=0;
						if((pos_board[1][2]=='-')&&(pos_board[2][2]=='-'))
						{
							blank_count=blank_count+2;
						}
						if(blank_count==2)
						{
							blank_row=2;
							blank_column=2;
							return;
						}
					}
				}
				else if((i==2)&&(j==2))
				{
					if((pos_board[2][0]=='-')&&(pos_board[2][1]=='-'))
					{
						blank_count=blank_count+2;
					}
					if(blank_count==2)
					{
						blank_row=2;
						blank_column=0;
						return;
					}
					else
					{
						blank_count=0;
						if((pos_board[0][2]=='-')&&(pos_board[1][2]=='-'))
						{
							blank_count=blank_count+2;
						}
						if(blank_count==2)
						{
							blank_row=0;
							blank_column=2;
							return;
						}
					}
				}
				else if((i==2)&&(j==0))
				{
					if((pos_board[2][1]=='-')&&(pos_board[2][2]=='-'))
					{
						blank_count=blank_count+2;
					}
					if(blank_count==2)
					{
						blank_row=2;
						blank_column=2;
						return;
					}
					else
					{
						blank_count=0;
						if((pos_board[0][0]=='-')&&(pos_board[1][0]=='-'))
						{
							blank_count=blank_count+2;
						}
						if(blank_count==2)
						{
							blank_row=0;
							blank_column=0;
							return;
						}
					}
				}
				else if((i==1)&&(j==1))
				{
					if((pos_board[1][0]=='-')&&(pos_board[1][2]=='-'))
					{
						blank_count=2;
					}
					if(blank_count==2)
					{
						blank_row=1;
						blank_column=0;
						return;
					}
					else
					{
						blank_count=0;
						if((pos_board[0][1]=='-')&&(pos_board[2][1]=='-'))
						{
							blank_count=2;
						}
						if(blank_count==2)
						{
							blank_row=0;
							blank_column=1;
							return;
						}
						else
						{
							if((pos_board[0][0]=='-')&&(pos_board[2][2]=='-'))
							{
								blank_count=2;
							}
							if(blank_count==2)
							{
								blank_row=0;
								blank_column=0;
								return;
							}
							else
							{
								if((pos_board[2][0]=='-')&&(pos_board[0][2]=='-'))
								{
									blank_count=2;
								}
							}
							if(blank_count==2)
							{
								blank_row=0;
								blank_column=2;
								return;
							}
						}
					}
				}
			}
		}
	}
	}
}

void find_blank_c4()							// To find blank position in proximity of computer position when count=4 and z=2
{
	int i,j,k;
	for(i=0; i<3; ++i)
	{
		for(j=0; j<3; ++j)
		{
			if((pos_board[i][j]=='O'))
			{
				if((i==0)&&(j==0))
				{
					for(k=1; k<3; ++k)
					{
						if(pos_board[0][k]=='-')
						{
							blank_count++;
						}
					}
					if(blank_count==2)
					{
						blank_row=0;
						blank_column=2;
						return;
					}
					else
					{
						blank_count=0;
						for(k=1; k<3; ++k)
						{
							if(pos_board[k][0]=='-')
							{
								blank_count++;
							}
						}
						if(blank_count==2)
						{
							blank_row=2;
							blank_column=0;
							return;
						}
					}
				}
				else if((i==0)&&(j==2))
				{
					if((pos_board[0][1]=='-')&&(pos_board[0][0]=='-'))
					{
						blank_count++;
					}
					if(blank_count==2)
					{
						blank_row=0;
						blank_column=0;
						return;
					}
					else
					{
						blank_count=0;
						if((pos_board[1][2]=='-')&&(pos_board[2][2]=='-'))
						{
							blank_count++;
						}
						if(blank_count==2)
						{
							blank_row=2;
							blank_column=2;
							return;
						}
					}
				}
				else if((i==2)&&(j==2))
				{
					for(k=0; k<2; ++k)
					{
						if(pos_board[2][k]=='-')
						{
							blank_count++;
						}
					}
					if(blank_count==2)
					{
						blank_row=2;
						blank_column=0;
						return;
					}
					else
					{
						blank_count=0;
						for(k=0; k<2; ++k)
						{
							if(pos_board[k][2]=='-')
							{
								blank_count++;
							}
						}
						if(blank_count==2)
						{
							blank_row=0;
							blank_column=2;
							return;
						}
					}
				}
				else if((i==2)&&(j==0))
				{
					for(k=1; k<3; ++k)
					{
						if(pos_board[2][k]=='-')
						{
							blank_count++;
						}
					}
					if(blank_count==2)
					{
						blank_row=2;
						blank_column=2;
						return;
					}
					else
					{
						blank_count=0;
						for(k=0; k<2; ++k)
						{
							if(pos_board[k][0]=='-')
							{
								blank_count++;
							}
						}
						if(blank_count==2)
						{
							blank_row=0;
							blank_column=0;
							return;
						}
					}
				}
				else if((i==1)&&(j==1))
				{
					for(k=0; k<3; k=k+2)
					{
						if(pos_board[k][k]=='-')
						{
							blank_count++;
						}
					}
					if(blank_count==2)
					{
						blank_row=0;
						blank_column=0;
						return;
					}
					else
					{
						blank_count=0;
						if((pos_board[2][0]=='-')&&(pos_board[0][2]=='-'))
						{
							blank_count=blank_count+2;
						}
					}
					if(blank_count==2)
					{
						blank_row=0;
						blank_column=2;
						return;
					}
					else
					{
						if((pos_board[1][0]=='-')&&(pos_board[1][2]=='-'))
						{
							blank_count=blank_count+2;
						}
						if(blank_count==2)
						{
							blank_row=1;
							blank_column=0;
							return;
						}
						else
						{
							blank_count=0;
							if((pos_board[0][1]=='-')&&(pos_board[2][1]=='-'))
							{
								blank_count=blank_count+2;
							}
							if(blank_count==2)
							{
								blank_row=0;
								blank_column=1;
								return;
							}
						}
					}
				}
			}
		}
	}
}

bool check1_AI()
{
	a=3;
	b=3;
	int i,j;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			if((pos_board[i][j]!='O') && (pos_board[i][(j+1)%3]=='X') && (pos_board[i][(j+2)%3]=='X'))
			{
				a=i;
				b=j;
			}
		}
	}
	return a==3;
}

bool check2_AI()
{
	a=3;
	b=3;
	int i,j;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			if((pos_board[i][j]!='O') && (pos_board[(i+1)%3][j]=='X') && (pos_board[(i+2)%3][j]=='X'))
			{
				a=i;
				b=j;
			}
		}
	}
	return a==3;
}

bool check3_AI()
{
	a=3;
	b=3;
	if((pos_board[0][0]=='O')&&(pos_board[1][1]=='O')&&(pos_board[2][2]!='X'))
	{
		a=2;
		b=2;
	}
	else if((pos_board[1][1]=='O')&&(pos_board[2][2]=='O')&&(pos_board[0][0]!='X'))
	{
		a=0;
		b=0;
	}
	return a==3;
}
bool check4_AI()
{
	a=3;
	b=3;
	if((pos_board[2][0]=='O')&&(pos_board[1][1]=='O')&&(pos_board[0][2]!='X'))
	{
		a=0;
		b=2;
	}
	else if((pos_board[1][1]=='O')&&(pos_board[0][2]=='O')&&(pos_board[2][0]!='X'))
	{
		a=2;
		b=0;
	}
	return a==3;
}

bool check_computer_line()
{
	return(check1_AI() && check2_AI() && check3_AI() && check4_AI());
}

void draw()
{
	draw_count=true;
	printf("\n\nGame draw!!!!!\n");
	return;
}

void computer_play(int x, int y)
{
	pos_board[x][y]='O';
	printf("\n\nAfter computer's turn board is : \n\n");
	print();
	count++;
}

void computer()
{
	if(z==1)
	{
		if(count==1)
		{
			if(pos_board[1][1]=='X')
			{
				computer_play(0,0);
			}
			else
			{
				computer_play(1,1);
			}
		}
		else if(count==3)
		{
			check_player_line();				//To check if player has two continous X
			if(a==3)
			{
				find_blank_c3();
				computer_play(blank_row,blank_column);
			}
			else
			{
				computer_play(a,b);
			}
		}
		else if(count==5)
		{
			check_computer_line();
			if(a==3)
			{
				if(!check_player_line())
				{
					computer_play(a,b);
				}
				else
				{
					find_blank_c3();
					computer_play(blank_row,blank_column);
				}
			}
			else
			{
				computer_play(a,b);
			}
		}
		else if(count==7)
		{
			check_computer_line();
			if(a==3)
			{
				if(!check_player_line())
				{
					computer_play(a,b);
				}
				else
				{
					draw();
				}
			}
			else
			{
				computer_play(a,b);
			}
		}
	}

	if(z==2)
	{
		if(count==0)
		{
			computer_play(1,1);
		}
		else if(count==2)
		{
			if(pos_board[0][0]!='X')
			{
				computer_play(0,0);
			}
			else if(pos_board[0][2]!='X')
			{
				computer_play(0,2);
			}
			else if(pos_board[2][0]!='X')
			{
				computer_play(2,0);
			}
			else if(pos_board[2][2]!='X')
			{
				computer_play(2,2);
			}
		}
		else if(count==4)
		{
			check_computer_line();
			if(a==3)
			{
				if(!check_player_line())
				{
					computer_play(a,b);
				}
				else
				{
					find_blank_c4();
					computer_play(blank_row,blank_column);
				}
			}
			else
			{
				computer_play(a,b);
			}
		}
		else if(count==6)
		{
			check_computer_line();
			if(a==3)
			{
				if(!check_player_line())
				{
					computer_play(a,b);
				}
				else
				{
					find_blank_c4();
					computer_play(blank_row,blank_column);
				}
			}
			else
			{
				computer_play(a,b);
			}
		}
		else if(count==8)
		{
			check_computer_line();
			if(a==3)
			{
				if(check_player_line())
				{
					computer_play(a,b);
				}
				else
				{
					draw();
				}
			}
			else
			{
				computer_play(a,b);
			}
		}
	}
}

void player_win()
{
	int i;
	for(i=0;i<3;i++)
	{
		if(pos_board[i][0]=='X' && pos_board[i][1]=='X' && pos_board[i][2]=='X')
		{
			player_count=true;
			printf("\n\nCongrats %s you win\n",name);
			return;
		}
	}
	for(i=0;i<3;i++)
	{
		if(pos_board[0][i]=='X' && pos_board[1][i]=='X' && pos_board[2][i]=='X')
		{
			player_count=true;
			printf("\n\nCongrats %s you win\n",name);
			return;
		}
	}
	if(pos_board[0][0]=='X' && pos_board[1][1]=='X' && pos_board[2][2]=='X')
	{
		player_count=true;
		printf("\n\nCongrats %s you win\n",name);
		return;
	}
	else if(pos_board[0][2]=='X' && pos_board[1][1]=='X' && pos_board[2][0]=='X')
	{
		player_count=true;
		printf("\n\nCongrats %s you win\n",name);
		return;
	}
}

void computer_win()
{
	int i;
	for(i=0;i<3;i++)
	{
		if((pos_board[i][0]=='O')&&(pos_board[i][1]=='O')&&(pos_board[i][2]=='O'))
		{
			computer_count=true;
			printf("\n\nComputer wins!!!!!\n");
			return;
		}
	}
	for(i=0;i<3;i++)
	{
		if(pos_board[0][i]=='O' && pos_board[1][i]=='O' && pos_board[2][i]=='O')
		{
			computer_count=true;
			printf("\n\nComputer wins!!!!!\n");
			return;
		}
	}
	if(pos_board[0][0]=='O' && pos_board[1][1]=='O' && pos_board[2][2]=='O')
	{
		computer_count=true;
		printf("\n\nComputer wins!!!!!\n");
		return;
	}
	else if(pos_board[0][2]=='O' && pos_board[1][1]=='O' && pos_board[2][0]=='O')
	{
		computer_count=true;
		printf("\n\nComputer wins!!!!!\n");
		return;
	}
}

int main()
{
	int i,j;
	char w;
	printf("\nEnter player name : ");
	scanf(" %s",&name);
	start :printf("\nHello %s ,Wanna play tic tac toe!!!\n",name);
	scanf(" %c",&w);
	if(w=='y' || w=='Y')
	{
		char ch='y';
		while((ch=='y')||(ch=='Y'))
		{
			printf("\n%s, You want to start (press 1) or you want computer to start (press 2) : ",name);
			scanf(" %d",&z);
			switch(z)
			{
				case 1:
					count=0;
					computer_count=false;
					player_count=false;
					draw_count=false;
					for(i=0; i<3; ++i)
					{
						for(j=0; j<3; ++j)
						{
							pos_board[i][j]='-';
						}
					}
					a=3;
					b=3;
					blank_count=0;
					while(!computer_count&&!player_count&&(count<9)&&!draw_count)
					{
						player();
						if(count>=5)
						{
							player_win();
							if(player_count)
								break;
						}
						computer();
						if(count>=5)
						{
							computer_win();
							if(computer_count)
								break;
						}
						if((count==8)&&check_player_line())
						{
							draw();
						}
					}
					if((count==9)&&!player_count&&!computer_count&&!draw_count)
					{
						draw();
					}
					break;
				case 2:
					count=0;
					computer_count=false;
					player_count=false;
					draw_count=false;
					for(i=0; i<3; ++i)
					{
						for(j=0; j<3; ++j)
						{
							pos_board[i][j]='-';
						}
					}
					a=3;
					b=3;
					blank_count=0;
					while(!computer_count&&!player_count&&(count<9)&&!draw_count)
					{
						computer();
						if(count>=4)
						{
							computer_win();
							if(computer_count)
								break;
						}
						player();
						if(count>=4)
						{
							player_win();
							if(player_count)
								break;
						}
						if((count==8)&&check_computer_line())
						{
							draw();
						}
					}
					if((count==9)&&!player_count&&!computer_count&&!draw_count)
					{
						draw();
					}
					break;
		default:
			printf("\nYou entered wrong value....... try entering correct value....\n");
			continue;
			}
			printf("\n\nWant to play again!!!!!!! (y/n)");
			scanf(" %c",&ch);
		}
	}
	else if(w=='n' || w=='N')
	{
		printf("\n\t\tBye %s Have A Nice Day !!!",name);
	}
	else
	{
		printf("\nTry entering valid input (either y/Y or n/N)\n");
		goto start;
	}
}

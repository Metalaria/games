#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char pos_board[3][3];
int count=0;
char name[20];
int z;
int a=3;
int b=3;
int blank_row;
int blank_column;
int blank_count=0;
bool end;

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
		a=0;
		b=0;
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

bool empty_rest_of_row(int x,int y)
{
	return (pos_board[(x+1)%3][y]=='-' && pos_board[(x+2)%3][y]=='-');
}

bool empty_rest_of_column(int x,int y)
{
	return (pos_board[x][(y+1)%3]=='-' && pos_board[x][(y+2)%3]=='-');
}

void find_blank()		// To find blank position in proximity of computer position when (count==3 and z==1) or (count==4 and z==2)
{
	int i,j,k;
	for(i=0; i<3; ++i)
	{
		for(j=0; j<3; ++j)
		{
			if(pos_board[i][j]=='O')
			{
				if(i%2==0 && j%2==0) //i and j are either 0 or 2
				{
					if(empty_rest_of_row(i,j))
					{
						blank_row=2-i;
						blank_column=j;
						return;
					}
					else if(empty_rest_of_column(i,j))
					{
						blank_row=i;
						blank_column=2-j;
						return;
					}
				}
				else if(i==1 && j==1)
				{
					if(empty_rest_of_row(1,1))
					{
						blank_row=0;
						blank_column=1;
						return;
					}
					else if(empty_rest_of_column(1,1))
					{
						blank_row=1;
						blank_column=0;
						return;
					}
					else if(pos_board[0][0]=='-' && pos_board[2][2]=='-')
					{
						blank_row=0;
						blank_column=0;
						return;
					}
					else if(pos_board[0][2]=='-' && pos_board[2][0]=='-')
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

bool check1_AI()
{
	a=3;
	b=3;
	int i,j;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			if((pos_board[i][j]!='X') && (pos_board[i][(j+1)%3]=='O') && (pos_board[i][(j+2)%3]=='O'))
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
			if((pos_board[i][j]!='X') && (pos_board[(i+1)%3][j]=='O') && (pos_board[(i+2)%3][j]=='O'))
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

void game_end()
{
	end=true;
	return;
}

void set_player_win()
{
	game_end();
	printf("\n\nCongrats %s you win\n",name);
	return;
}

void set_computer_win()
{
	game_end();
	printf("\n\nComputer wins!!!!!\n");
	return;
}

void set_draw()
{
	game_end();
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
				find_blank();
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
					find_blank();
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
					set_draw();
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
		else if(count==4 || count==6)
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
					find_blank();
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
					set_draw();
				}
			}
			else
			{
				computer_play(a,b);
			}
		}
	}
}

bool player_win()
{
	int i;
	for(i=0;i<3;i++)
	{
		if(pos_board[i][0]=='X' && pos_board[i][1]=='X' && pos_board[i][2]=='X')
		{
			return true;
		}
		if(pos_board[0][i]=='X' && pos_board[1][i]=='X' && pos_board[2][i]=='X')
		{
			return true;
		}
	}
	if(pos_board[0][0]=='X' && pos_board[1][1]=='X' && pos_board[2][2]=='X')
	{
		return true;
	}
	else if(pos_board[0][2]=='X' && pos_board[1][1]=='X' && pos_board[2][0]=='X')
	{
		return true;
	}
	return false;
}

bool computer_win()
{
	int i;
	for(i=0;i<3;i++)
	{
		if((pos_board[i][0]=='O')&&(pos_board[i][1]=='O')&&(pos_board[i][2]=='O'))
		{
			return true;
		}
		if(pos_board[0][i]=='O' && pos_board[1][i]=='O' && pos_board[2][i]=='O')
		{
			return true;
		}
	}
	if(pos_board[0][0]=='O' && pos_board[1][1]=='O' && pos_board[2][2]=='O')
	{
		return true;
	}
	else if(pos_board[0][2]=='O' && pos_board[1][1]=='O' && pos_board[2][0]=='O')
	{
		return true;
	}
	return false;
}

int init()
{
    int i,j;
	count=0;
	end=false;
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
}

int main()
{
	int i,j;
	char w;
	printf("\nEnter player name : ");
	scanf(" %s",&name);
	start :printf("\nHello %s ,Wanna play tic tac toe!!!\n",name);
	scanf(" %c",&w);
	while(w=='y' || w=='Y')
	{
		printf("\n%s, You want to start (press 1) or you want computer to start (press 2) : ",name);
		scanf(" %d",&z);
		switch(z)
		{
			case 1:
				init();
				while(count<9 && !end)
				{
					player();
					if(count>=5 && player_win())
					{
						set_player_win();
						break;
					}
					computer();
					if(count>=5 && computer_win())
					{
						set_computer_win();
						break;
					}
					if(count==8 && check_player_line())
					{
						set_draw();
					}
				}
				if(count==9)
				{
					set_draw();
				}
				break;
			case 2:
				init();
				while(count<9 && !end)
				{
					computer();
					if(count>=4 && computer_win())
					{
						set_computer_win();
						break;
					}
					player();
					if(count>=4 && player_win())
					{
						set_player_win();
						break;
					}
					if(count==8 && check_computer_line())
					{
						set_draw();
					}
				}
				if(count==9)
				{
					set_draw();
				}
				break;
			default:
				printf("\nYou entered wrong value....... try entering correct value....\n");
				continue;
		}
		printf("\n\nWant to play again!!!!!!! (y/n)");
		scanf(" %c",&w);
	}
	if(w=='n' || w=='N')
	{
		printf("\n\t\tBye %s Have A Nice Day !!!",name);
	}
	else
	{
		printf("\nTry entering valid input (either y/Y or n/N)\n");
		goto start;
	}
}

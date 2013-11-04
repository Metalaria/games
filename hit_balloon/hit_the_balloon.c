#define PAGE_UP 73
#define HOME 71
#define END 79
#define PAGE_DOWN 81
#define UP_ARROW 72
#define LEFT_ARROW 75
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define F6 64
#define F7 65
#define F8 66
#define F9 67
#define F10 68
#include<iostream.h>
#include <conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
int x=50,x1,y1,r,a=0;
float hits=0,shoots=0,scr;
void back()
{
setcolor(WHITE);
rectangle(0,0,638,398);
line(538,0,538,398);
rectangle(540,0,638,70);
rectangle(0,400,638,478);
setcolor(5);
outtextxy(558,30,"HIT THE");
outtextxy(555,45,"BALLOONS");
outtextxy(200,410,"*  USE ARROW KEYS TO MOVE");
outtextxy(200,450,"*  PRESS PAGE UP TO QUIT");
outtextxy(200,430,"*  PRESS UP ARROW TO SHOOT");
outtextxy(200,470,"*  ENJOY THE GAME");
outtextxy(545,105,"SHOOTS LEFT:");
setfillstyle(1,4);
for(int j=0;j<10;j++)
{
a+=20;
fillellipse(588,125+a,4,4);
}
};

void player()
{
setfillstyle(1,4);
bar(x,380,x+10,397);
bar(x+3,372,x+7,380);
};

void target()
{
x1=random(480)+20;
y1=random(220)+20;
r=random(9)+3;
int c=random(15);
setcolor(WHITE);
setfillstyle(1,c);
fillellipse(x1,y1,r,r);
};

void check()
{
if(x+5>=x1-r && x+5<=x1+r)
{
sound(3500);
delay(10);
nosound();
setfillstyle(1,0);
fillellipse(x1,y1,r,r);
++hits;
target();
}
if(shoots==10)
{
cleardevice();
back();
scr=(hits/shoots)*100;
setcolor(WHITE);
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t    No.of shoots\t:\t"<<shoots;
cout<<"\n\t\t    No. of hits\t\t:\t"<<hits;
cout<<"\n\t\t    Accuracy\t\t:\t"<<scr<<" %";
rectangle(0,0,638,398);
delay(3000);
exit(0);
}
};

void move()
{
int key;
yo:
key=getch();
if(key==77)
{
setfillstyle(1,0);
bar(x,380,x+10,397);
bar(x+3,372,x+7,380);
x+=8;
player();
}
if(key==75)
{
setfillstyle(1,0);
bar(x,380,x+10,397);
bar(x+3,372,x+7,380);
x-=8;
player();
}
if(key==72)
{
++shoots;
setcolor(0);
setfillstyle(1,0);
fillellipse(588,125+a,4,4);
a-=20;
for(int i=370;i>y1+r;i-=20)
{
setcolor(2);
line(x+5,i,x+5,i-20);
delay(100);
setcolor(0);
line(x+5,i,x+5,i-20);
}
check();
}
if(key==73)
{
exit(0);
}
goto yo;
};

void balloon()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
randomize();
cleardevice();
back();
player();
target();
move();
getch();
}
void main()
{
balloon();
}

#include<iostream>
#include<graphics.h>
using namespace std;

main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	setcolor(YELLOW);
	rectangle(50,200,600,450);
	rectangle(70,240,130,450);
	line(150,200,150,450);
	line(50,200,100,100);
	line(100,100,150,200);
	line(100,100,550,100);
	line(550,100,600,200);
	setfillstyle(LINE_FILL,BROWN);
	floodfill(150,110,YELLOW);
	setfillstyle(LTSLASH_FILL,GREEN);
	floodfill(80,250,YELLOW);
	floodfill(500,400,YELLOW);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(60,220,YELLOW);
	setfillstyle(SOLID_FILL,RED);
	floodfill(100,150,YELLOW);
	delay(4000);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(60,220,YELLOW);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(100,150,YELLOW);
	getch();
}

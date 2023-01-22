#include<iostream>
#include<graphics.h>
using namespace std;

main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	setcolor(YELLOW);
	circle(250,250,150);
	ellipse(180,200,0,360,25,10);
	ellipse(320,200,0,360,25,10);
	rectangle(240,220,260,260);
	ellipse(250,310,180,360,60,15);
	ellipse(320,206,-40,220,5,5);
	delay(1000);
	ellipse(180,206,-40,220,5,5);
	delay(1000);
	floodfill(250,310,YELLOW);
	delay(1000);
	floodfill(180,200,YELLOW);
	floodfill(320,200,YELLOW);
	delay(1000);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(250,250,YELLOW);
	getch();
}

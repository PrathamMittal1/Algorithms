#include<iostream>
#include<graphics.h>
using namespace std;

void boundaryfill(int x,int y, int boundarycolor,int fillcolor){
	int pixelcolor=getpixel(x,y);
	if (pixelcolor!=boundarycolor && pixelcolor!=fillcolor){
		putpixel(x,y,fillcolor);
		boundaryfill(x+1,y,boundarycolor,fillcolor);
		boundaryfill(x-1,y,boundarycolor,fillcolor);
		boundaryfill(x,y-1,boundarycolor,fillcolor);
		boundaryfill(x,y+1,boundarycolor,fillcolor);
		
	}
}

main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	circle(200,200,100);
	rectangle(150,150,250,250);
	boundaryfill(140,200,WHITE,RED);
	getch();
}

#include<iostream>
#include<graphics.h>
using namespace std;

void floodfill(int x,int y,int fillcolor,int basecolor){
	int pixelcolor=getpixel(x,y);
	if (pixelcolor==basecolor){
		putpixel(x,y,fillcolor);
		floodfill(x+1,y,fillcolor,basecolor);
		floodfill(x-1,y,fillcolor,basecolor);
		floodfill(x,y-1,fillcolor,basecolor);
		floodfill(x,y+1,fillcolor,basecolor);
		
	}
}

main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	circle(200,200,100);
	rectangle(150,150,250,250);
	floodfill(140,200,GREEN,BLACK);
	getch();
}

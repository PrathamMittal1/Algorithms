#include<iostream>
#include<graphics.h>
using namespace std;

int x0,y0; //global variables

void drawpixel(int x,int y){
	putpixel(x0+x,y0+y,YELLOW);
	putpixel(x0-x,y0-y,YELLOW);
	putpixel(x0-x,y0+y,YELLOW);
	putpixel(x0+x,y0-y,YELLOW);
	putpixel(x0+y,y0+x,YELLOW);
	putpixel(x0-y,y0-x,YELLOW);
	putpixel(x0-y,y0+x,YELLOW);
	putpixel(x0+y,y0-x,YELLOW);
}
main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	int r,x,y,p;
	cout<<"Enter center of the circle: ",cin>>x0>>y0;
	cout<<"Enter radius of the circle: ",cin>>r;
	x=0;y=r;
	p=1-r;
	drawpixel(x,y);
	while(x<=y){
		if (p<0){
			p+=2*x+1;
			x+=1;
		}
		else{
			p+=2*x-2*y+1;
			x+=1;
			y-=1;
		}
		delay(100);
		drawpixel(x,y);
	}
	getch();
}

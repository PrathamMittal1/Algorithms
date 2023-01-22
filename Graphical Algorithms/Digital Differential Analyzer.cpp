#include<iostream>  
#include<conio.h>  
#include<graphics.h>  
#include<dos.h>  
#include<math.h>
using namespace std;

void dda(float x, float y,int x1,int y1,float xinc,float yinc,int steps);
main()  
{   int gd=DETECT, gm,i;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
    int x1,y1,x2,y2,steps;
    float dx, dy, xinc, yinc;
    cout<<"Enter starting point: ";
    cin>>x1>>y1;
    cout<<"Enter ending point: ";
    cin>>x2>>y2;
    dx=(x2-x1);
    dy=(y2-y1);
    if (abs(dx)>=abs(dy))
    {
    	steps=abs(dx);
	}
	else{
		steps=abs(dy);
	}
	xinc=dx/steps;
	yinc=dy/steps;
	dda(x1,y1,x2,y2,xinc,yinc,steps);
    getch();  
}

void dda(float x, float y,int x1,int y1,float xinc,float yinc,int steps){
	putpixel(x,y,WHITE);
	for(int i=0;i<steps;i++){
		x+=xinc;
		y+=yinc;
		cout<<x<<','<<y<<endl;
		putpixel(round(x),round(y),WHITE);
	}
}

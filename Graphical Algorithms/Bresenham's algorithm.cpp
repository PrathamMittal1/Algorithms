#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;

void slopelessthan1(int x,int y, int dx, int dy,int x1)
{
	int p=2*dy-dx;
	putpixel(x,y,WHITE);
    while(x<x1){
    	if(p<0){
    		x+=1;
    		p+=2*dy;
		}
		else{
			x+=1;
			y+=1;
			p+=2*dy-2*dx;
		}
		cout<<x<<','<<y<<endl;
		putpixel(x,y,WHITE);
	}
}

void slopemorethan1(int x,int y,int dx,int dy,int y1)
{
	int p=2*dx-dy;
	putpixel(x,y,WHITE);
	while(y<y1){
		if(p<0){
			y+=1;
			p+=2*dx;
		}
		else{
			y+=1;
			x+=1;
			p+=2*(dx-dy);
		}
		cout<<x<<','<<y<<endl;
		putpixel(x,y,WHITE);
	}
}

main()
{
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
    int x,y,x2,y2;
    int dx, dy;
    float m;
    cout<<"Enter starting point: ";
    cin>>x>>y;
    cout<<"Enter ending point: ";
    cin>>x2>>y2;
    dx=x2-x;
    dy=y2-y;
    m=dy/dx;
    if(m<1){
    	slopelessthan1(x,y,dx,dy,x2);
	} 
	else{
		slopemorethan1(x,y,dx,dy,y2);
	}

	getch();
}

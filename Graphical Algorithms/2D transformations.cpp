#include<iostream>
#include<graphics.h>
#include<math.h>
#include<process.h>
using namespace std;

void translation(int& x1,int& y1,int& x2,int& y2,int& x3,int& y3){          //translate
	int tx, ty;
	cout<<"-+-+TRANSLATION+-+-"<<endl;
	cout<<"Enter translation factors..."<<endl<<"tx: ";cin>>tx;cout<<"ty: ";cin>>ty;
	cleardevice();
	x1=x1+tx; y1=y1+ty;
	x2=x2+tx; y2=y2+ty;
	x3=x3+tx; y3=y3+ty;
	line(x1,y1,x2,y2);	
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
}
void rotation(int& x1,int& y1,int& x2,int& y2,int& x3,int& y3){           //rotate
	float deg, rx, ry, radian;
	cout<<"-+-+ROTATION+-+-"<<endl<<"Enter degree of rotation: "; cin>>deg;
	cleardevice();
	radian=deg*(22/7)/180; 
	ry=x1*sin(radian) + y1*cos(radian); rx=x1*cos(radian)-y1*sin(radian); x1=round(rx); y1=round(ry);
	ry=x2*sin(radian) + y2*cos(radian); rx=x2*cos(radian)-y2*sin(radian); x2=round(rx); y2=round(ry);
	ry=x3*sin(radian) + y3*cos(radian); rx=x3*cos(radian)-y3*sin(radian); x3=round(rx); y3=round(ry);
	
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
}
void scaling(int& x1,int& y1,int& x2,int& y2,int& x3,int& y3){             //scale
	float sx,sy;
	cout<<"-+-+SCALING+-+-"<<endl;
	cout<<"Enter scaling factors..."<<endl<<"Sx: ";cin>>sx;
	cout<<"Sy: ";cin>>sy;
	cleardevice();
	x1=sx*x1; x2=x2*sx; x3=sx*x3;
	y1=sy*y1; y2=y2*sy; y3=sy*y3;
	
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
}
main()
{
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	int c, x1, y1, x2, y2, x3, y3;
	cout<<"Enter coordinates of triangle... "<<endl<<"Vertex 1: "; cin>>x1>>y1;
	cout<<"Vertex 2: ";cin>>x2>>y2;
	cout<<"Vertex 3: ";cin>>x3>>y3;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
	while(1){
		cout<<"Choose the transformation to perform..."<<endl;
		cout<<"[1] Translation"<<endl<<"[2] Rotation"<<endl<<"[3] Scaling"<<endl<<"[4] Exit program!"<<endl;
		cout<<"Enter number: "; cin>>c;
		switch(c){
			case 1: translation(x1,y1,x2,y2,x3,y3); break;
			case 2: rotation(x1,y1,x2,y2,x3,y3); break;
			case 3: scaling(x1,y1,x2,y2,x3,y3); break;
			case 4: cout<<"Exiting program..."<<endl; delay(1000); exit(0); break;
			default: cout<<"Invalid input! Please try again."<<endl; 
		}
	}
}

#include<iostream>
#include<graphics.h>
using namespace std;
void drawtriangle(int x1,int y1,int x2,int y2,int x3,int y3){
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
}
int tx, ty;
void translate(int& x, int& y){
	x+=tx;
	y+=ty;
}
void rotate(int& x, int& y,char axis){
	if(axis=='y'){
		x= -x; y= y;
	} else if(axis=='x'){
		x= x; y= -y;
	} else
	{
		x= -x; y= -y;
	}
	
}
main(){
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	cout<<"-+-+2-D Reflection+-+-"<<endl;
	int x1,y1,x2,y2,x3,y3,rx1,ry1,rx2,ry2;
	cout<<"Enter coordinates of triangle..."<<endl;
	cout<<"X1 and Y1: "; cin>>x1>>y1;
	cout<<"X2 and Y2: "; cin>>x2>>y2;
	cout<<"X3 and Y3: "; cin>>x3>>y3;
	drawtriangle(x1,y1,x2,y2,x3,y3);
	cout<<"Enter coordinates of reflection axis...\n";
	cout<<"RX1 and RY1: "; cin>>rx1>>ry1;
	cout<<"RX2 and RY2: "; cin>>rx2>>ry2;
	setcolor(LIGHTRED);
	line(rx1,ry1,rx2,ry2);	
	int rx=(rx1+rx2)/2 , ry=(ry1+ry2)/2;
	if(rx1==rx2){
		tx=-rx,ty=0;
		translate(x1,y1);
		translate(x2,y2);
		translate(x3,y3);
		rotate(x1,y1,'y');
		rotate(x2,y2,'y');
		rotate(x3,y3,'y');
	} else if (ry1==ry2){
		tx=0,ty=-ry;
		translate(x1,y1);
		translate(x2,y2);
		translate(x3,y3);
		rotate(x1,y1,'x');
		rotate(x2,y2,'x');
		rotate(x3,y3,'x');
	} else {
		tx=-rx,ty=-ry;
		translate(x1,y1);
		translate(x2,y2);
		translate(x3,y3);
		rotate(x1,y1,'o');
		rotate(x2,y2,'o');
		rotate(x3,y3,'o');
	}
	tx= -tx; ty= -ty;
	translate(x1,y1);
	translate(x2,y2);
	translate(x3,y3);
	setcolor(LIGHTCYAN);
	drawtriangle(x1,y1,x2,y2,x3,y3);
	getch();
}

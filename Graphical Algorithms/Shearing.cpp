#include<iostream>
#include<graphics.h>
using namespace std;

main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://tc//bgi");
	int x1,y1,x2,y2,c;
	float sh;
	cout<<"||||| 2-Dimensional Shearing |||||"<<endl;
	cout<<"Enter coordinates of rectangle vertices..."<<endl;
	cout<<"X1 and Y1: "; cin>>x1>>y1;
	cout<<"X2 and Y2: "; cin>>x2>>y2;
	rectangle(x1,y1,x2,y2);
	cout<<"Shear along:"<<endl<<"[1] x-axis\n[2] y-axis\nEnter choice: ";cin>>c;
	cout<<"Enter shearing factor: "; cin>>sh;
	cleardevice();
	if(c==1){
		int xn1,xn2;
		xn1=x1+sh;
		xn2=x2+sh;
		line(xn1,y1,xn2,y1);
		line(xn1,y1,x1,y2);
		line(x1,y2,x2,y2);
		line(x2,y2,xn2,y1);
	} else if(c==2){
		int yn1,yn2;
		yn1=y1+sh;
		yn2=y2+sh;
		line(x1,yn1,x2,y1);
		line(x1,yn1,x1,yn2);
		line(x1,yn2,x2,y2);
		line(x2,y2,x2,y1);
	} else {
		cout<<"Invalid input! Try again.";
	}
	getch();
}

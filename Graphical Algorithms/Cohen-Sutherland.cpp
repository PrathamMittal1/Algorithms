#include<iostream>
#include<graphics.h>
using namespace std;
static int TOP=8,BOTTOM=4,LEFT=1,RIGHT=2,xw_max, yw_max, xw_min, yw_min;
int encode(int x,int y){
	int rcode=0;
	if(x<xw_min){
		rcode|=LEFT;
	}
	if(x>xw_max){
		rcode|=RIGHT;
	}
	if(y<yw_min){
		rcode|=BOTTOM;
	}
	if(y>yw_max){
		rcode|=TOP;
	}
	return rcode;
}
main()
{
	int rcode_begin=0, rcode_end=0, rcode=0,OR,AND;
	float m;
	int x2,y2,x1,y1;
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	cout<<"-+-+-+-+Cohen-Sutherland line clipping algorithm+-+-+-+-"<<endl;
	cout<<"Enter details about clipping window..."<<endl<<"Xmin: ";cin>>xw_min;
	cout<<"Ymin: ";cin>>yw_min; cout<<"Xmax: ";cin>>xw_max; cout<<"Ymax: ";cin>>yw_max;
	rectangle(xw_min,yw_min,xw_max,yw_max);
	cout<<"Enter initial and terminating points of line..."<<endl;
	cout<<"X1 and Y1: "; cin>>x1>>y1;
	cout<<"X2 and Y2: "; cin>>x2>>y2;
	line(x1,y1,x2,y2);
	m=(float)(y2-y1)/(x2-x1);
	rcode_begin=encode(x1,y1);
	rcode_end=encode(x2,y2);
	OR=rcode_begin|rcode_end;
	AND=rcode_begin&rcode_end;
	
	if(OR==0){
		cout<<"No clipping needed as line is completely inside clip window."<<endl;
	} else if(AND>=1){
		cout<<"Line is completely outside clip window."<<endl;
		delay(5000);
		cleardevice();
		rectangle(xw_min,yw_min,xw_max,yw_max);
	} else{
		cout<<"Line is intersecting clipping window. Therefore clipping required!"<<endl;
		int t=1;
		while(1){
			if (t==0){
				break;
			}
			else{
				if(rcode_begin&LEFT){
					y1+=(xw_min-x1)*m;
					x1=xw_min;
				} else if(rcode_begin&RIGHT){
					y1+=(xw_max-x1)*m;
					x1=xw_max;
				} else if(rcode_begin&BOTTOM){
					x1+=(yw_min-y1)/m;
					y1=yw_min;
				} else if(rcode_begin&TOP){
					x1+=(yw_max-y1)/m;
					y1=yw_max;
				}
				if(rcode_end&LEFT){
					y2+=(xw_min-x2)*m;
					x2=xw_min;
				} else if(rcode_end&RIGHT){
					y2+=(xw_max-x2)*m;
					x2=xw_max;
				} else if(rcode_end&BOTTOM){
					x2+=(yw_min-y2)/m;
					y2=yw_min;
				} else if(rcode_end&TOP){
					x2+=(yw_max-y2)/m;
					y2=yw_max;
				}
			}
			rcode_begin=encode(x1,y1);
			rcode_end=encode(x2,y2);
			t=rcode_begin|rcode_end;
		}
		delay(5000);
		cleardevice();
		rectangle(xw_min,yw_min,xw_max,yw_max);
		line(x1,y1,x2,y2);
	}
	getch();
}



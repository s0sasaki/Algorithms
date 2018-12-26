#include<iostream>
#include<cmath>
using namespace std;

void koch(double x0, double y0, double x1, double y1, int n){
	if(n==0) return;
	double xa = x0*2.0/3.0 + x1*1.0/3.0;
	double ya = y0*2.0/3.0 + y1*1.0/3.0;
	double xc = x0*1.0/3.0 + x1*2.0/3.0;
	double yc = y0*1.0/3.0 + y1*2.0/3.0;
	double xb = xa + (xc-xa)*cos(60.0*M_PI/180.0) - (yc-ya)*sin(60*M_PI/180.0);
	double yb = ya + (xc-xa)*sin(60.0*M_PI/180.0) + (yc-ya)*cos(60*M_PI/180.0);
	koch(x0,y0,xa,ya,n-1);
	cout<<xa<<" "<<ya<<endl;
	koch(xa,ya,xb,yb,n-1);
	cout<<xb<<" "<<yb<<endl;
	koch(xb,yb,xc,yc,n-1);
	cout<<xc<<" "<<yc<<endl;
	koch(xc,yc,x1,y1,n-1);
}

int main(){
	double x0=0.0, y0=0.0, x1=100.0, y1=0.0;
	int n;
	cin >> n;
	cout<<x0<<" "<<y0<<endl;
	koch(x0,y0,x1,y1,n);
	cout<<x1<<" "<<y1<<endl;
	return 0;
}

#include<iostream>
#include<iomanip>
#include<cmath>
#define r 6371
#define pi 3.1415926
using namespace std;

double hav(double a){
	return (sin(a/2))*(sin(a/2));
}

int main(){
	long double w1,j1,w2,j2,d;
	cin>>w1>>j1;
	cin>>w2>>j2;
	w1=w1*pi/180;
	w2=w2*pi/180;
	j1=j1*pi/180;
	j2=j2*pi/180;
	d=r*2*asin(sqrt(hav(w2-w1)+cos(w1)*cos(w2)*hav(j2-j1)));
	cout<<fixed<<setprecision(4)<<d<<"km"<<endl;
	return 0;
}

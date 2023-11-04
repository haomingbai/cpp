#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double a,b,O;
	cin>>a>>b;
	O=round(13.12+0.6215*b-11.37*pow(a,0.16)+0.3965*b*pow(a,0.16));
	cout<<O<<endl;
	return 0;
}

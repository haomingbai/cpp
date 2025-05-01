/*************************************************************************
    > File Name: 8-008.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月03日 星期三 17时16分15秒
 ************************************************************************/

#include <cstdio>
#include<iostream>
using namespace std;

int main(){
	double a,b,c,d,e,f,g,h,i;
	cin>>a>>b>>c>>d>>e>>f;
	g=(b-a)*(c*d+e*f);
	h=(b-a)*(c*d)/g;
	i=(b-a)*(e*f)/g;
	g/=1000;
	//cout<<g<<" "<<h<<" "<<i<<endl; h,i reverse
	printf("%.2lfkJ,%.2lf%%,%.2lf%%",g,i,h);
}

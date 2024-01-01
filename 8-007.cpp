/*************************************************************************
    > File Name: 8-007.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月20日 星期三 21时11分10秒
 ************************************************************************/

#include <cmath>
#include<iostream>
#define _USE_MATH_DEFINES
using namespace std;

int main(){
	double side[4],cross_section;
	for(int i=0;i<4;i++){
		cin>>side[i];
	}
		cin>>cross_section;
	double A;
	int P1,P2;
	P1=(side[0]+side[1]+cross_section)/2;
	P2=(side[3]+side[2]+cross_section)/2;
	A=sqrt((P1)*(P1-side[0])*(P1-side[1])*(P1-cross_section))
		+sqrt((P2)*(P2-side[2])*(P2-side[3])*(P2-cross_section));
	double cs;
	double another_cross_section;
	another_cross_section=(pow(side[0],2)+pow(side[3],2)-2.0*side[0]*side[3])
}

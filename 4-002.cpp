/*************************************************************************
    > File Name: 4-001.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov  6 19:08:25 2023
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<stdarg.h>
using namespace std;

//The definition of the function

double avg(int v ,...){
	va_list m;
	va_start(m,v);
	double s0=0;
	int i=v;
	while(i>0){
		s0+=va_arg(m,double);
		i--;
	}
	s0/=v;
	return s0;
}
int main(){
	double variable[5]={0};
	scanf("%lf %lf %lf %lf %lf",&variable[0],&variable[1],&variable[2],&variable[3],&variable[4]);
	//Now we use the sum func
	printf("%.4lf\n",avg(2,variable[0],variable[1])
		-avg(3,variable[2],variable[3],variable[4]));
	return 0;
}

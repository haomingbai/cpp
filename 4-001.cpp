/*************************************************************************
    > File Name: 4-001.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov  6 19:08:25 2023
 ************************************************************************/

#include<iostream>
#include<stdarg.h>
using namespace std;

//The definition of the function

int sum(int a ,...){
	va_list m;
	va_start(m,6);
	int s0=a,s1=a;
	while(1){
		s0+=va_arg(m,int);
		if(s0==s1) break;
		s1=s0;
	}
	return s0;
}
int main(){
	int variable[6]={0};
	scanf("%d %d %d %d %d %d",&variable[0],&variable[1],&variable[2],&variable[3],&variable[4],&variable[5]);
	//Now we use the sum func
	cout<<sum(variable[0],variable[1],0)
		-sum(variable[2],variable[3],variable[4],variable[5],0)<<endl;
	return 0;
}

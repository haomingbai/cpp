/*************************************************************************
    > File Name: 1-006.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Thu Oct  5 15:43:45 2023
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	float i;
	int n,d,t;
	scanf("%f",&i);
	t=1;;
	while((int)(i*t)!=i*t){
		t++;
	}
	d=t;
	n=i*t;
	printf("%d/%d",n,d);
	return 0;
}

/*************************************************************************
    > File Name: 3-007.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Wed Nov  1 22:22:21 2023
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a,b,c=0;
	for(a=1;a<=n/2+1;a++){
		for(b=1;b<=a;b++){
			if(sqrt(a*a+b*b)+a+b==n){
				c=sqrt(a*a+b*b);
				break;
			}
			if(sqrt(a*a+b*b)+a+b>n){
				break;
			}
		}
		if(c!=0){
			break;
		}
	}
	//printf("%d,%d,%d\n",a,b,c);
	cout<<a*b*c<<endl;
}

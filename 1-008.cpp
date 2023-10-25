/*************************************************************************
    > File Name: 1-008.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Fri Oct  6 15:01:55 2023
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int row(int n,int r){
	int c=n-1;
	for(int i=1;i<=r;i++){
		cout<<abs(c)<<" ";
		c--;
	}
	return 0;
}

int main(){
	int r;
	cin>>r;
	for(int i=1;i<=r;i++){
		row(i,r);
		printf("\n");
	}
	return 0;
}

/*************************************************************************
    > File Name: 3-006.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Wed Nov  1 22:13:25 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int n,k,G=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		G+=(k%i);
	}
	printf("%d\n",G);
	return 0;
}

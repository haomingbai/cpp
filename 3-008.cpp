/*************************************************************************
    > File Name: 3-008.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Thu Nov  2 07:43:29 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int n,m=1,s=1,c;
	scanf("%d",&n);
	while(1){
		for(int i=1;i<=m;i++){
			if(s==n){
				c=i;
				break;
			};
			s++;
		}
		m++;
		if(s==n) break;
	}
	printf("%d\n",c);
	return 0;
}

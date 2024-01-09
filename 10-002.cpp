/*************************************************************************
    > File Name: 10-002.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月07日 星期日 16时51分25秒
 ************************************************************************/

#include <cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	char *a=(char *)malloc(sizeof(char)*7);
	char *b=(char *)malloc(sizeof(char)*7);
	cin>>a>>b;
	int cnt=0;
	for(int i=0;i<2;i++){
		if(b[i]>=a[i]){
			cnt+=(b[i]-a[i]);
		}else{
			cnt+=(26+b[i]-a[i]);
		}
	}
	for(int i=2;i<6;i++){
		if(b[i]>=a[i]){
			cnt+=(b[i]-a[i]);
		}else{
			cnt+=(10+b[i]-a[i]);
		}
	}
	cout<<cnt<<endl;
}

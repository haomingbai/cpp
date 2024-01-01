/*************************************************************************
    > File Name: 9-002.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月26日 星期二 21时32分41秒
 ************************************************************************/

#include <cmath>
#include <cstdio>
#include<iostream>
#include <system_error>
#include <vector>
using namespace std;

int calc(int,int,int);
int C(int N,int M);
int pow(int base,int factor);

int main(){
	vector<int> data;
	int swp;
	while(scanf("%d",&swp)!=EOF){
		if(swp==0)
			break;
		data.push_back(swp);
	}
	for(auto it:data){
		cout<<calc(it,3,3)<<endl;
	}
	return 0;
}

//a means the length of the queue, b the length you still need to cover, o the ~ you should cover originally.
int calc(int a,int b,int o){
	if(a<b)
		return 0;
	if(a==b)
		return 1;
	if(b==0)
		return pow(2,a);
	return calc(a-1,o,o)+calc(a-1,b-1,o);
}

int pow(int a,int b){
	if(b==0)
		return 1;
	return a*pow(a,b-1);
}

int C(int n,int m){
	int k=n-m;
	long double r=1;
	while(k){
		r*=n--;
		r/=k--;
	}
	while(m){
		r*=n--;
		r/=m--;
	}
	return (int)r;
}

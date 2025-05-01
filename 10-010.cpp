/*************************************************************************
    > File Name: 10-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月07日 星期日 21时56分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int acm(int,int);

int main(){
	int m,n;
	cin>>m>>n;
	cout<<acm(m,n)<<endl;
}

int acm(int m,int n){
	if(m==0){
		return n+1;
	}else if(n==0){
		return acm(m-1,1);
	}else{
		return acm(m-1,acm(m,n-1));
	}
}

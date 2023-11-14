/*************************************************************************
    > File Name: 4-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Wed Nov  8 13:52:56 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int m,int n){
	if(m%n==0) return n;
	return gcd(n,m%n);
}

int judge(int row,int column){
	if(row==1) return 1;
	int i=0;
	for(int l=2;l<=column;l++) if(gcd(row-1,l-1)==1) i++;
	if(row==2) i++;
	return i;
}

int judge(int n){
	int x=0;
	for(int i=1;i<=n;i++) x+=judge(i,n);
	return x;
}

int main(){
	int n;
	cin>>n;
	cout<<"Result: "<<judge(n)<<endl;
}

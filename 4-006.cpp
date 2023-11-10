/*************************************************************************
    > File Name: 4-006.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Thu Nov  9 15:12:51 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int length(long long int n){
	if(n/10==0) return 1;
	return 1+length(n/10);
}

long long int move(int *p,int l){
	int m=0;
	int s;
	int *k=p
	for(int i=0;i<l;i++){
		m=*(k+1);
		*(k+1)=k
	}

}

int isk(long long n){
	int l=length(n);
	int s[l];
	for(int i=1)
}

int main(){
	int aaa
}

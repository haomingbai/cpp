/*************************************************************************
    > File Name: 3-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Thu Nov  2 08:08:23 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int judgement(int n){
	long long int p,q;
	while(n>0){
		p=n%10;
		n/=10;
		q=n%10;
		//printf("%d,%d\n",p,q);
		if(p<q) return 0;
	}
	return 1;
}

int main(){
	int N,O;
	cin>>N;
	//O=N;
	for(O=N;judgement(O)==0;O--) ;
	cout<<O<<endl;
	return 0;
}

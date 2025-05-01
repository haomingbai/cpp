/*************************************************************************
    > File Name: 3-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Wed Oct 18 14:30:53 2023
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

long long int calc(int N){
	if(N<=2){
		if(N==1) return 5;
		if(N==2) return 20;
	}
	return 20*(calc(N-2))%1000000007;
}

int main(){
	long long int N;
	cin>>N;
	cout<<calc(N)<<endl;
	return 0;
}

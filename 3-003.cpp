/*************************************************************************
    > File Name: 3-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Wed Oct 18 14:30:53 2023
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	unsigned long long int N;
	cin>>N;
	int count[N]={0};
	//int odd=N/2;
	//int even=N-odd;
	int odd_per{4},even_per{5};
	for(int n=1;n<=N;n++){
		int even=n/2;
		int odd=n-even;
		if(odd==even) count[n-1]=pow(odd_per,odd)*(pow(even_per,even)-1);
		if(odd!=even) count[n-1]=pow(odd_per,odd)*(pow(even_per,even));
	}
	int M{1};
	for(int i=0;i<=N-1;i++){
		M+=count[i];
	}
	M=M%1000000007;
	cout<<M<<endl;
}

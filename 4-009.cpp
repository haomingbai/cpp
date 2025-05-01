/*************************************************************************
    > File Name: 4-009.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Tue Nov 14 20:02:18 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	long long int N,X,R;
	cin>>N>>X;
	if(N%2==0) R=3*(N-X);
	else R=3*(N-1);
	cout<<R<<endl;
	return 0;
}

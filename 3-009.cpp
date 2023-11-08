/*************************************************************************
    > File Name: 3-009.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sat Nov  4 16:21:13 2023
 ************************************************************************/

#include<iostream>
using namespace std;

/*This function will be performed thus:
 * First, we should derive the value of N from input;
 * Then, we should realize a function which can do factorial for us.
 * Actually,we can set a function to n*n+1*n+2*...*n+9.
 * This might be the ultimate solution.*/

int mutiplier(int n){
	return (n*(n+1)*(n+2)*(n+3)*(n+4)*(n+5)*(n+6)*(n+7)*(n+8)*(n+9));
}

int general_factorial_remain(int n,int d){
	while(n>10)
}

int main(){
	int N;
	cin>>N;
}

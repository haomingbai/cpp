/*************************************************************************
    > File Name: 4-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov  6 20:22:58 2023
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int is_prime(int n);

int find_prime(int beginning,int ending){
	int counter=0;
	for(int probe=beginning;probe<=ending;probe++){
		if(probe%6==1||probe%6==5) counter+=is_prime(probe);
	}
	return counter;
}

int is_prime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	int beginning,ending;
	cin>>beginning>>ending;
	cout<<find_prime(beginning,ending)<<endl;
	return 0;
}

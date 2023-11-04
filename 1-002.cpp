/*************************************************************************
    > File Name: 1-002.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年09月28日 星期四 14时33分00秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int opt(int a){
	int t1,t2{0},t3{0};
	t1=a;
	t2=a;
	while(t2!=0){
		t1=t1-t2%10;
		t2=t2/10;
	}
	return t1;
}

int main(){
	int a,t{0};
	cin>>a;
	while(a>0){
		a=opt(a);
		t++;
	}
	cout<<t<<endl;
}

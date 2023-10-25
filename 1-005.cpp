/*************************************************************************
    > File Name: 1-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Thu Oct  5 13:32:34 2023
 ************************************************************************/

#include<iostream>
using namespace std;


int main(){
	unsigned long long int a,b,c,d,e,t;
	cin>>a>>b>>c;
	d=a%c;
	e=b%c;
	t=d*e;
	/*for (int i=1;i<=b;i++){
		t=t+a;
	}*/
	/*while(t>=c){
		t=t-c;
		cout<<t<<endl;
	}*/
	t=t%c;
	cout<<t<<endl;
}

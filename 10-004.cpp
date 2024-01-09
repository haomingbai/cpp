/*************************************************************************
    > File Name: 10-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月07日 星期日 17时02分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

int* calculate(int);

int main(){
	int n;
	cin>>n;
	auto x=calculate(n);
	for(int i=0;i<4;i++){
		if(x[i]==0){
			continue;
		}else{
			switch(i){
				case 0:cout<<"1=";
					   break;
				case 1:cout<<"2=";
					   break;
				case 2:cout<<"5=";
					   break;
				case 3:cout<<"10=";
					   break;
			}
			cout<<x[i]<<endl;
		}
	}
}

int* calculate(int n){
	auto x=new int[4];
	if(n==0) return x;
	x[3]=n/10;
	n%=10;
	if(n==0) return x;
	x[2]=n/5;
	n%=5;
	if(n==0) return x;
	x[1]=n/2;
	n%=2;
	x[0]=n;
	return x;
}

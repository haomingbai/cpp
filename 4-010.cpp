/*************************************************************************
    > File Name: 4-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Tue Nov 14 13:45:23 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int HarshadNumber(int n)
{
    int t = n, s = 0;
    while(t){
        s=s+t%10;
        t=t/10;
    }
    if (s && n % s == 0) return n / s;
    return 0;
}

int ish(int n){
	if (HarshadNumber(n)==0) return 0;
	if (HarshadNumber(n)==1) return 1;
	return 1+ish(HarshadNumber(n));
}

int main(){
	int a=0;
	cin>>a;
	int b;
	b=ish(a);
	cout<<b<<endl;
	return 0;
}

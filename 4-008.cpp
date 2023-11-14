/*************************************************************************
    > File Name: 4-008.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov 13 21:54:13 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int PA(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else return 2*PA(n-1)+PA(n-2);
}

int PB(int n)
{
	int p0=0,p1=1,pn,i;
    for(int i=0;i<=n;i++)
        if(i==0) pn=p0;
        else if(i==1) pn=p1;
        else
        {
            pn=2*pn+p0;
            p0=p1;
			p1=pn;
        }
    return pn;
}


int main(){
	int n,pn;
	scanf("%d",&n);
	if(n%2==0) pn=PB(n);
	else pn=PA(n);
	cout<<pn<<endl;
}

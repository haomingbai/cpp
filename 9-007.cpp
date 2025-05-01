/*************************************************************************
    > File Name: 9-007.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月27日 星期三 21时19分10秒
 ************************************************************************/

#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;

#define d 1000000007
long long int calc(long long int n);

int main(){
	long long int n,m;
	cin>>n>>m;
	vector<int> broken;
	broken.resize(m);
	for(auto it=broken.begin();it!=broken.end();it++){
		cin>>*it;
	}
	sort(broken.begin(),broken.end());
	long long int a=0,cnt=1;
	for(auto it:broken){
		cnt*=calc(it-1-a);
		if(cnt==0)
			break;
		a=it;
		a++;
	}
	cnt*=calc(n-a);
	cnt%=d;
	cout<<cnt<<endl;
}

long long  int calc(long long int n){
	if(n==-1)
		return 0;
	if(n==1||n==0)
		return 1;
	if(n==2)
		return 2;
	return calc(n-1)+calc(n-2);
}

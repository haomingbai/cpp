/*************************************************************************
    > File Name: 9-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月27日 星期三 17时42分38秒
 ************************************************************************/

#include <algorithm>
#include <cstdlib>
#include<iostream>
#include <pthread.h>
#include <vector>
using namespace std;

int process(vector<int> &);

int main(){
	int N;
	cin>>N;
	vector<int> data;
	data.resize(N);
	for(auto it=data.begin();it!=data.end();it++){
		cin>>*it;
	}
	cout<<process(data)<<endl;
}

int process(vector<int> &data){
	int a=(int)2e9+1;
	if(data.size()==0)
		return a;
	for(auto it=data.begin()+1;it!=data.end();it++){
		a=min(a,abs(*data.begin()-*it));
	}
	data.erase(data.begin());
	a=min(a,process(data));
	return a;
}

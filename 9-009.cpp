/*************************************************************************
    > File Name: 9-009.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月28日 星期四 21时02分51秒
 ************************************************************************/

#include <algorithm>
#include <utility>
#include<vector>
#include<iostream>
using namespace std;

bool compare(pair<int,int> &a,pair<int,int> &b){
	if(a.second>b.second)
		return 1;
	return 0;
}

int main(){
	vector<pair<int,int>> data;
	int n;
	cin>>n;
	data.resize(n);
	for(int i=0,t=0,d=0;i<n;i++){
		cin>>t>>d;
		data[i]={i+1,t+d};
		t=0,d=0;
	}
	sort(data.rbegin(),data.rend(),compare);
	for(auto it:data){
		cout<<it.first<<" ";
	}
	cout<<endl;
	return 0;
}

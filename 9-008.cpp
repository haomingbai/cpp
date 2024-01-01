/*************************************************************************
    > File Name: 9-008.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月28日 星期四 11时01分50秒
 ************************************************************************/

#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;

int max_subarray(vector<int>&);
int merge(vector<int>&);

int main(){
	vector<int> data;
	int n;
	cin>>n;
	data.resize(n);
	for(auto it=data.begin();it!=data.end();it++){
		cin>>*it;
	}
	cout<<max_subarray(data)<<endl;
	return 0;
}

int max_subarray(vector<int> &d){
	vector<int> n;
	for(int i=0;i<d.size();i++){
		if(d[i]>0){
			n.push_back(d[i]);
		}else{
			int tmp=0;
			while(i<d.size()&&d[i]<=0){
				tmp+=d[i];
				i++;
			}
			n.push_back(tmp);
			i--;
		}
	}
	return merge(n);
}

int merge(vector<int> &x){
	if(x.size()==1){
		return x.front();
	}
	int remain=0;
	for(int i=0,with=0;i<x.size();i++){
		if(x[i]<=0){
			with+=x[i];
			continue;
		}else{
			with+=x[i];
			remain=max(remain,with);
		}
	}
	vector<int> y=x;
	y.erase(y.begin());
	return max(merge(y),remain);
}

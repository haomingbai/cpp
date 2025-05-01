/*************************************************************************
    > File Name: 9-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月29日 星期五 19时36分40秒
 ************************************************************************/

#include <algorithm>
#include<iostream>
#include <list>
using namespace std;

int calculate(const list<int>&);

int main(){
	int n;
	list<int> dat;
	cin>>n;
	for(int i=0,tp;i<n;i++){
		cin>>tp;
		dat.push_back(tp);
	}
	cout<<calculate(dat)<<endl;
	return 0;
}

int calculate(const list<int>& lst){
	list<int> l=lst,ps=lst;
	l.unique();
	if(l.size()==1){
		return l.front()*count(lst.begin(),lst.end(),l.front());
	}
	int cnt,r=0;
	for(auto it:l){
		cnt=count(ps.begin(),ps.end(),it);
		ps.remove(it);
		ps.remove(it+1);
		ps.remove(it-1);
		r=max(r,cnt*it+calculate(ps));
		ps=lst;
	}
	return r;
}

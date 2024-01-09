/*************************************************************************
    > File Name: 10-009.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月07日 星期日 19时04分47秒
 ************************************************************************/

#include<iostream>
#include <list>
using namespace std;

int main(){
	int n;
	cin>>n;
	list<int> dat,a;
	for(int i=0,swp;i<n;i++){
		cin>>swp;
		dat.push_back(swp);
	}
	a=dat;
	a.sort();
	a.unique();
	cout<<dat.size()-a.size()<<endl;
}

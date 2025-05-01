/*************************************************************************
    > File Name: 10-007.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月07日 星期日 17时24分53秒
 ************************************************************************/

#include <algorithm>
#include<iostream>
using namespace std;

string process(string&);

int main(){
	string dat;
	cin>>dat;
	auto x=process(dat);
	cout<<x<<endl;
}

string process(string& str){
	string a="";
	string front=str.substr(0,str.length()/2);
	sort(front.rbegin(),front.rend());
	a.append(front);
	string back;
	if(str.length()%2){
		a.push_back(str[str.length()/2]);
		back=str.substr(str.length()/2+1);
	}else{
		back=str.substr(str.length()/2);
	}
	reverse(back.begin(),back.end());
	a.append(back);
	return a;
}

/*************************************************************************
    > File Name: 6-008.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Tue Dec  5 20:35:52 2023
 ************************************************************************/

#include<iostream>
using namespace std;

string pre(string s,string cut){
	int l=cut.length();
	while(s.substr(0,l)==cut){
		s.erase(0,l);
	}
	return s;
}

string pro(string s,string cut){
	int l=cut.length();
	while(s.substr(s.length()-l,l)==cut){
		s.erase(s.length()-l);
		if(s.length()<l) break;
	}
	return s;
}

int main(){
	string m,n;
	getline(cin,m);
	getline(cin,n);
	m=pre(m,n);
	cout<<m<<endl;
	m=pro(m,n);
	cout<<m<<endl;
}

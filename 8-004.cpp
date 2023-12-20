/*************************************************************************
    > File Name: 8-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月20日 星期三 19时22分00秒
 ************************************************************************/

#include <cstdlib>
#include<iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(){
	char *ori=(char *)malloc(sizeof(char )*5000);
	cin>>ori;
	vector<int> num;
	vector<char *> ele;
	int pos=0;
	int upos=0;
	int swp=0;
	char *tmp;
	for(char *mv=ori;*mv;mv++){
		if(*mv>='A'&&*mv<='Z'&&find(ele.begin(), ele.end(),mv) != v.end()){
			pos=0;
			num.push_back(1);
			ele.push_back((char *)malloc(sizeof(char)*3));
			for(int i=0;i<3;i++){
				*(ele.at(upos)+i)='\0';
			}
			ele.at(upos)[pos]=*mv;
			pos++;
			upos++;
		}else if(*mv>='a'&&*mv<='z'){
			//(ele.at(mv-ori)+1)=*mv;
			tmp=ele.at(upos-1);
			tmp[pos]=*mv;
			pos++;
		}else if(*mv>='0'&&*mv<='9'){
			num.at(upos-1)=(int)(*mv-'0');
		}
	}
	vector<int>::iterator itn=num.begin();
	vector<char *>::iterator ite=ele.begin();
	while(itn!=num.end()&&ite!=ele.end()){
		cout<<*ite<<" "<<*itn<<endl;
		ite++;
		itn++;
	}
	return 0;
}

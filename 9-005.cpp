/*************************************************************************
    > File Name: 9-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月27日 星期三 19时22分00秒
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int read(string);
int count(int);

int main(){
	string data;
	getline(cin,data);
	cout<<read(data)<<endl;
	return 0;
}

int read(string str){
	int l=str.length();
	int res=1;
	for(int i=0;i<l;i++){
		if(str[i]=='u'||str[i]=='n'){
			char c=str[i];
			int m=0;
			while(str[i+m++]==c);
			m--;
			res*=count(m);
			i+=(m-1);
		}
		if(str[i]=='m'||str[i]=='w')
			return 0;
	}
	return res;
}

int count(int a){
	if(a==1)
		return 1;
	if(a==2)
		return 2;
	return count(a-1)+count(a-2);
}

/*************************************************************************
    > File Name: 6-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Tue Dec  5 18:37:05 2023
 ************************************************************************/

#include<iostream>
using namespace std;

string str_swapcase(string str){
	string result;
	char s;
	while(str.length()){
		s=str.at(0);
		if(s>64&&s<91) s+=32;
		else if(s>96&&s<123) s-=32;
		result.push_back(s);
		str.erase(0,1);
	}
	return result;
}

int main(){
	string str;
	//cin>>str;
	getline(cin,str);
	cout<<str_swapcase(str)<<endl;
	return 0;
}

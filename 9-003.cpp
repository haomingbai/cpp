/*************************************************************************
    > File Name: 9-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月27日 星期三 17时12分17秒
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int calc(string);

int main(){
	string str;
	getline(cin,str);
	switch(calc(str)){
		case 0:cout<<"false"<<endl;
			   break;
		case 1:cout<<"true"<<endl;
			   break;
	}
	return 0;
}

int calc(string str){
	for(int P=1;P<str.length()/2;P++){
		if(str.substr(0,P)==str.substr(P,P)||calc(str.substr(P)))
			return 1;
	}
	return 0;
}

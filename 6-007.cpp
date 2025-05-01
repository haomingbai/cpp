/*************************************************************************
    > File Name: 6-007.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Tue Dec  5 19:15:57 2023
 ************************************************************************/

#include<iostream>
using namespace std;

long conv(string s){
	long long int res=0;
	int state=1;
	if(s.at(0)=='+'){
		s.erase(0,1);
	}else if(s.at(0)=='-'){
		s.erase(0,1);
		state=0;
	}
	while(s.length()&&s.at(0)>='0'&&s.at(0)<='9'){
		res*=10;
		res+=(int)(s.at(0)-'0');
		if(res>=2147483648){
			if(state==0) return -2147483648;
			else return 2147483648;
		}
		s.erase(0,1);
	}
	if(state==0) res=-res;
	long c=res;
	return c;
}

int main(){
	string c;
	cin>>c;
	cout<<conv(c)<<endl;
}

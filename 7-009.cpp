/*************************************************************************
    > File Name: 7-009.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月12日 星期二 19时42分41秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<time.h>
using namespace std;

string tohex(int x){
	string res;
	char t[17]="0123456789ABCDEF";
	while(x){
		res.insert(0,1,t[x%16]);
		x/=16;
	}
	return res;
}

tm process(string origin){
	char check=0;
	for(int i=1;origin[i]!='*';i++){
		check^=origin[i];
	}
	string check_x=tohex((int)check);
	tm result;
	if(check_x==origin.substr(origin.length()-2)){
		sscanf(origin.substr(7,2).c_str(),"%d",&result.tm_hour);
		sscanf(origin.substr(9,2).c_str(),"%d",&result.tm_min);
		sscanf(origin.substr(11,2).c_str(),"%d",&result.tm_sec);
		result.tm_hour+=8;
		if(result.tm_hour>24) result.tm_hour-=24;
	}else{
		result.tm_hour=-1;
		result.tm_min=-1;
		result.tm_sec=-1;
	}
	return result;
}

int main(){
	vector<tm> outfile;
	string buffer;
	while(buffer!="END"){
		cin>>buffer;
		if(buffer.substr(0,6)=="$GPRMC") outfile.push_back(process(buffer));
	}
	for(int i=0;i<outfile.size();i++) {
		if(outfile[i].tm_hour!=-1) cout<<setw(2)<<right<<setfill('0')<<outfile[i].tm_hour<<':'<<outfile[i].tm_min<<':'<<outfile[i].tm_sec<<endl;
		else cout<<"error"<<endl;
	}
}

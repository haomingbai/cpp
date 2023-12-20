/*************************************************************************
    > File Name: 7-007.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月12日 星期二 17时30分36秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;

char plusc(char a,int x){
	a+=x;
	while(a<=96) a+=26;
	while(a>=123) a-=26;
	return a;
}

char minusc(char a,int x){
	a-=x;
	while(a<=96) a+=26;
	while(a>=123) a-=26;
	return a;
}

string process(string origin,int n){
	map<char,int> data;
	string backup=origin;
	while(backup.length()){
		if(data.find(backup.at(0))!=data.end()){
			data[backup[0]]+=1;
		}else{
			data.insert(make_pair(backup.at(0),1));
		}
		backup.erase(0,1);
	}
	backup=origin;
	int i=backup.length()-1;
	while(i>=0){
		if(data[backup[i]]%2==0) backup[i]=plusc(backup[i],n);
		else backup[i]=minusc(backup[i],n);
		i--;
	}
	return backup;
}

int main(){
	string data;
	int i;
	getline(cin,data);
	cin>>i;
	cout<<process(data,i)<<endl;
}

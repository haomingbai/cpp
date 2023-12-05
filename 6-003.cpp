/*************************************************************************
    > File Name: 6-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Thu Nov 30 13:04:43 2023
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

/*
 * void seperate(char line[],char sep[]){
	int linelen=strlen(line);
	int seplen=strlen(sep);
	int probe;
	for(int i=0,p=0;line[i]!=0;i++){
		if(line[i]!=sep[0]) continue;
		else{
			probe=1;
			for(int r=0;sep[r]!=0;r++){
				if(sep[r]!=line[i+r]){
					probe=0;
					break;
				}
			}
			if(probe){
				for(int x=p;x<i;x++){
					printf("%c",line[x]);
				}
				i+=seplen;
				p+=i;
			}
		}
		printf("\n");
		cout<<p<<endl;
	}
}
*/

void seperate(string line,string sep){
	//string out[100];
	int len,where;
	len=sep.length();
	where=line.find(sep);
	if(where!=-1){
		cout<<line.substr(0,where)<<endl;
		line.erase(0,where+len);
	}else{
		cout<<line<<endl;
		line="";
	}
	//cout<<line.substr(where,where+len)<<endl;
	if(line!="") seperate(line,sep);
}
int main(){
	string line,sep;
	getline(cin,line);
	getline(cin,sep);
	seperate(line,sep);
	return 0;
}

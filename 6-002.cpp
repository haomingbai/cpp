/*************************************************************************
    > File Name: 6-002.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov 27 21:51:52 2023
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

//这个函数的实现原理是使用string和它的查找替换功能
//但是很明显TE了
//是我低估姜老登了
//我的问题
/*
int main(){
	string a,b,c;
	getline(cin,a);
	cin>>b>>c;
	while(a.find(b)!=string::npos){
		a.replace(a.find(b),b.length(),c);
	}
	cout<<a<<endl;
}
*/

//下面我们来写一个新的，原理是使用C语言特有的字符串类型数组

void strinsert(char str[],const	char oldstr[],const	char newstr[]){
	char swap[1001];
	char *find;
	if((find=strstr(str,oldstr))!=NULL){
		strcpy(swap,find+strlen(oldstr));
		strcpy(find+strlen(newstr),swap);
		for(int i=0;i<strlen(newstr);i++) *(find+i)=*(newstr+i);
		strinsert(str,oldstr,newstr);
	}
}

int main(){
	char str[1000]={0},o[1000]={0},n[1000]={0};
	cin.getline(str,1001);
	cin.getline(o,1001);
	cin.getline(n,1001);
	strinsert(str,o,n);
	printf("%s\n",str);
	return 0;
}

/*************************************************************************
    > File Name: 7-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月12日 星期二 15时19分55秒
 ************************************************************************/

#include<iostream>
using namespace std;

int NUM[]={6,2,5,5,4,5,6,3,7,6};

int judge(int n){
	int res=0;
	int tmp,t;
	//Plus
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			tmp=4;
			tmp+=NUM[i];
			tmp+=NUM[j];
			t=i+j;
			while(t){
				tmp+=(t%10);
				t/=10;
			}
			if(tmp==n) res++;
		}	
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	cout<<judge(n)<<endl;
	return 0;
}

/*************************************************************************
    > File Name: 7-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月12日 星期二 15时19分55秒
 ************************************************************************/

#include<iostream>
using namespace std;

int NUM[]={6,2,5,5,4,5,6,3,7,6};

int jdg(int i){
	int t=0;
	/*while(i){
		t+=NUM[i%10];
		i/=10;
	}*/
	do{
		t+=NUM[i%10];
		i/=10;
	}while(i);
	return t;
}

int judge(int n){
	int res=0;
	int tmp,t;
	//Plus
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			tmp=4;
			tmp+=jdg(i);
			tmp+=jdg(j);
			t=i+j;
			tmp+=jdg(t);
			if(tmp==n){
				res++;
				//cout<<jdg(i)<<jdg(j)<<jdg(i+j)<<endl;
				//cout<<i<<"+"<<j<<"="<<i+j<<endl;
			}
		}	
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	//cout<<jdg(1)<<endl;
	cout<<judge(n)<<endl;
	return 0;
}

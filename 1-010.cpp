/*************************************************************************
    > File Name: 1-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sun Oct  8 11:51:02 2023
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int row_num;
	cin>>row_num;
	int* max_val=new int[row_num];
	for(int i=1;i<=row_num;i++){
		max_val[i]=0;
	}
	for(int i=1;i<=row_num;i++){
		cin>>max_val[i];
	}
	int i=1;
	while(max_val[i]!=0){
		int t=0;
		for(int m=1;m<max_val[i];m++){
			if(m%3==0||m%5==0){
				t=t+m;
				//cout<<m<<endl;
			}
		}
		i++;
		cout<<t<<endl;
		t=0;
	}
}

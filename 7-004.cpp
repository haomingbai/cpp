/*************************************************************************
    > File Name: 7-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月12日 星期二 13时37分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

char DATA[97]="ATTAATTATAGCTAGCCGCGATATTAATATGCATCGTACGCGTAGCATATTAATTATAGCTAGCCGCGATATTAATATGCATCGTACGCGTAGCAT";

void output(int n){
	while(n>11) n-=11;
	for(int i=8*n;i<8*(n+1);i+=2){
		switch(i%16/2){
			case 0:cout<<"   "<<DATA[i]<<DATA[i+1]<<endl;
				   break;
			case 1:cout<<"  "<<DATA[i]<<"--"<<DATA[i+1]<<endl;
				   break;
			case 2:cout<<" "<<DATA[i]<<"----"<<DATA[i+1]<<endl;
				   break;
			case 3:cout<<DATA[i]<<"------"<<DATA[i+1]<<endl;
				   break;
			case 7:cout<<"   "<<DATA[i]<<DATA[i+1]<<endl;
				   break;
			case 6:cout<<"  "<<DATA[i]<<"--"<<DATA[i+1]<<endl;
				   break;
			case 5:cout<<" "<<DATA[i]<<"----"<<DATA[i+1]<<endl;
				   break;
			case 4:cout<<DATA[i]<<"------"<<DATA[i+1]<<endl;
				   break;
		}
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) output(i);
}

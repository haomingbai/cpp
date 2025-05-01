/*************************************************************************
    > File Name: 10-001.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月07日 星期日 16时41分27秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	int n;
	cin>>n;
	ofstream result;
	result.open("rr.dat");
	for(int i=1;i<=n;i++){
		printf("%.6lf ",sqrt(i));
		//cout<<sqrt(i)<<" ";
		result<<fixed<<setprecision(6)<<sqrt(i)<<endl;
	}
	cout<<endl;
}

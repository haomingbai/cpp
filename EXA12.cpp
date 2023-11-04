/*************************************************************************
    > File Name: EXA12.cpp
    > Author: Haoming Bai
    */
#include<iostream>
#include<iomanip>

using namespace std;

int main (){
	int(a)=345678;
	cout<<fixed<<setw(15)<<right<<setfill('0')<<setprecision(3)<<(double)a<<endl;
	return 0;
}

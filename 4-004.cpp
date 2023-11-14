/*************************************************************************
    > File Name: 4-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sun Nov 12 22:12:42 2023
 ************************************************************************/

#include<iostream>
using namespace std;


double pow(double base,int exp=2){
    if(exp==1) return base;
    return base*pow(base,exp-1);
}

int main(){
    double base;
    int exp;
    cin>>base>>exp;
    printf("%.6lf\n%.6lf",pow(base),pow(base,exp));
    return 0;
}
}

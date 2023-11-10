/*************************************************************************
    > File Name: 3-009.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: Thu Nov  2 07:57:41 2023
 ************************************************************************/

#include<iostream>
using namespace std;

/*long long int factorial_remain(int n){
        if(n==0) return 1;
        else return n*factorial_remain(n-1);
}*/

int gcd(int a, int b){
    if (a%b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

int main(){
        long long int N=0,K;
        cin>>K;
        long long int a=1;
        while(K!=1){
                N++;
                K=K/gcd(N,K);
        }
        cout<<N<<endl;
        return 0;
}

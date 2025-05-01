/*************************************************************************
    > File Name: 7-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月02日 星期二 17时04分22秒
 ************************************************************************/

/*
 * Input: n = 6
 * Output: 132
 *
 * Input: n = 8
 * Output: 1430
 */


// Catlan number: C(2*n,n)/(n+1)

#include<iostream>
using namespace std;

/*
long long C(int n,int m){
	long long int res=1,x=1;
	m=n-m;
	while(x<=m){
		res*=n;
		res/=x;
		n--,x++;
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	cout<<C(2*n,n)/(n+1)<<endl;
}
*/

int catalan(int);

int main(){
	int n;
	cin>>n;
	cout<<catalan(n)<<endl;
}

int catalan(int n){
	if(n==1)
		return 1;
	int res=0;
	for(int i=1;i<=n-1;i++){
		res+=catalan(i)*catalan(n-i);
	}
	return res;
}

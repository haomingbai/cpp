/*************************************************************************
    > File Name: 1-009.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Fri Oct  6 15:44:19 2023
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

/*这个程序的思路：
 1、将b除以2，除不尽则将判断参量变成1
 2、将上一次结果自乘
 3、求余数
 4、若判断参量为1，则将上一次结果再寄存
 5、流程结束后，将所有寄存结果相乘，再求余数
 */
/*(a^b)%m*/
int main(){
        //unsigned long long int a,b,t,m,r,i;
        unsigned __int128 t,i;
	unsigned long long int a,b,m,r;
        cin>>a>>b>>m;
        t=a;
	i=0;
	t=t%m;
	//数组的初始化，初始化一个大小为64的数组
	int* c=new int[64];
	for(int i=0;i<=64;i++){
		c[i]=0;
	}
	while(b>1){
		if(b%2!=0){
			//unsigned long long int c[i];
			c[i]=t;
			//cout<<c[i]<<endl;
			i++;
		}
		t=t*t;
		t=t%m;
		b=b/2;
	}
	//cout<<c[i]<<end;
	/*for(int l=1;l<=i;l++){
		t=t*c[l];
		t=t%m;
	}*/
	int di=0;
	while(c[di]!=0){
		t=t*c[di];
		t=t%m;
		di++;
	}
	r=t;
        cout<<r<<endl;
        return 0;
}


/*int main(){
	unsigned long long int a,b,m;
	cin>>a>>b>>m;
}*/

/*************************************************************************
    > File Name: 1-001.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2023年09月28日 星期四 14时10分09秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,i,t{0};
	cin>>i;
	if (i>36) printf("傻逼呀你\n");
	for (a=0;a<=9;a++){
		for (b=0;b<=9;b++){
			for(c=0;c<=9;c++){
				for(d=0;d<=9;d++){
					if(a+b+c+d==i) t++;
				}
			}
		}
	}
	printf("%d\n",t);
}

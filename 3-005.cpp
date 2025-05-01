/*************************************************************************
    > File Name: 3-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sun Oct 29 11:40:41 2023
 ************************************************************************/

#include<iostream>
using namespace std;

/*这个程序，我们的思路如下：
 * 首先，我们获取数字
 * 接着，由于连续整数的特性，除了N自身以外，起始的整数并不能超过[N/2]
 * 最后，从1开始，我们用这个循环：
 * 当和小于N的时候，我们就再加1，等于，就打断并加一次，大于就打断*/


int main(){
	int N,times=0;
	scanf("%d",&N);

	for(int i=1;i<=N/2;i++){
		for(int addendn=i,combination=0;addendn<=N/2+1;addendn++){
			combination+=addendn;
			if(combination<N) continue;
			if(combination==N) times++;
			break;
		}
	}

	printf("%d\n",times+1);
	return 0;
}

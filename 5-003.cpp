/*************************************************************************
    > File Name: 5-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Tue Nov 21 18:48:10 2023
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
using namespace std;

int prime(int n);

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",prime(n));
	return 0;
}

int prime(int n){
	int count=1;
	if(n==1) return 0;
	int *P=(int *)malloc((n+1)*sizeof(int));
	*P=2;
	for(int i=2;i<=n;i++){
//		if(*(N+i)==1) continue;
		for(int j=0;*(P+j);j++){
			if(i%*(P+j)==0) break;
			if(*(P+j+1)==0){
				count++;
				*(P+j+1)=i;
			}
		}
//		count++;
	}
	return count;
}

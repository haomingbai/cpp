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
	int count=0;
	if(n==1) return 0;
	int *N=(int *)malloc((n+1)*sizeof(int));
	int *P=(int *)malloc((n+1)*sizeof(int));
/*	for(int i=2;i<=n;i++){
//		if(*(N+i)==1) continue;
		for(int j=0;*(P+j);j++){
			if(i%*(P+j)==0) break;
			if(*(P+j+1)==0){
				count++;
				*(P+j+1)=i;
			}
		}
//		count++;
	}*/
	for(int i=2;i<=n;i++){
		if(!*(N+i)) *(P+(++count))=i;
		for(int j=1;i**(P+j)<=n&&j<=count;j++){
			*(N+i**(P+j))=1;
			if((i)%*(P+j)==0) break;
		}
	}
	return count;
}

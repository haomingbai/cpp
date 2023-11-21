/*************************************************************************
    > File Name: 5-002.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov 20 21:14:18 2023
 ************************************************************************/
#include<stdio.h>
#include<malloc.h>
using namespace std;

//由小到大的排序
void sort(int *p,int n);
int judge(int *p);

int main(){
	int T;
	scanf("%d",&T);
	int **S=(int **)malloc(sizeof(int*)*T);
	//int *i=*S,*F=*S;
	/*for(int *i=*S;i<*S+T;i++)
		i=(int *)malloc(sizeof(int)*5);*/
	for(int i=0;i<T;i++)
		S[i]=(int *)malloc(sizeof(int)*6);
	int *F=*S;
	for(int i=0;i<T;i++)
		scanf("%d %d %d %d %d",S[i],S[i]+1,S[i]+2,S[i]+3,S[i]+4);
	for(int *i=F;i<F+T;i++)
		judge(i);
	return 0;
}

int judge(int *p){
	sort(p,3);
//	printf("%d %d %d %d %d\n",*p,*(p+1),*(p+2),*(p+3),*(p+4));
	if(*p+*(p+1)+*(p+2)>*(p+3)+*(p+4)){
		printf("NO\n");
		return 0;
	}else{
		for(int i=2;i>=0;i--){
			if(*(p+i)<=*(p+3)){
				*(p+3)-=*(p+i);
				*(p+i)=0;
			}
		}
		if(*p+*(p+1)+*(p+2)<=*(p+4)){
			printf("YES\n");
			return 0;
		}
		printf("NO\n");
		return 0;
	}
}

void sort(int *p,int n){
	for(int i=n-1;i>=1;i--){
		for(int r=i;r>=1;r--){
			if(*(p+r-1)>*(p+r)) *(p+r-1)^=*(p+r)^=*(p+r-1)^=*(p+r);
		}
	}
}

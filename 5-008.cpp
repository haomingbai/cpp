/*************************************************************************
    > File Name: 5-008.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov 27 16:51:40 2023
 ************************************************************************/

#include<iostream>
#include<malloc.h>
using namespace std;

int det(int **p,int n){
	int add[n],min[n];
	for(int i=0,r=0,c=0;i<n;i++){
		add[i]=1;
		for(int j=0;j<n;j++){
			if(r>=n) r-=n;
			if(c>=n) c-=n;
			add[i]*=p[r][c];
			r++;
			c++;
		}
		//cout<<add[i]<<endl;
		r=0,c=i;
	}
	for(int i=0,r=n-1,c=0;i<n;i++){
		min[i]=1;
		for(int j=0;j<n;j++){
			if(r<0) r+=n;
			if(c>=n) c-=n;
			min[i]*=p[r][c];
			r--;
			c++;
		}
		r=n-1;
		c=i;
		//cout<<min[i]<<endl;
	}
	int res=0;
	for(int i=0;i<n;i++) res+=(add[i]-min[i]);
	return res;
}

int main(){
	int **mat=NULL,n;
	cin>>n;
	mat=(int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++){
		*(mat+i)=(int *)malloc(sizeof(int)*n);
		for(int j=0;j<n;j++) cin>>*(*(mat+i)+j);
	}
	cout<<det(mat,n)<<endl;
	return 0;
}

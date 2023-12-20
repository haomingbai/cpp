/*************************************************************************
    > File Name: 5-008.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov 27 16:51:40 2023
 ************************************************************************/

#include<iostream>
#include<malloc.h>
using namespace std;

int det(int **mat,int n);

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

int det(int **m,int n){
	if(n==2) return(m[0][0]*m[1][1]-m[1][0]*m[0][1]);
	int result=0;
	int m_diagonal[n],s_diagonal[n];
	for(int i=0;i<n;i++){
		m_diagonal[i]=1;
		for(int j=0,k=i;j<n;j++,k++){
			if(k>=n) k-=n;
			m_diagonal[i]*=m[j][k];
		}
		//cout<<m_diagonal[i]<<endl;
	}
	for(int i=0;i<n;i++){
		s_diagonal[i]=1;
		for(int j=0,k=i;j<n;j++,k--){
			if(k<0) k+=n;
			s_diagonal[i]*=m[j][k];
		}
		//cout<<s_diagonal[i]<<endl;
	}
	for(int i=0;i<n;i++){
		result+=m_diagonal[i];
		result-=s_diagonal[i];
	}
	return result;
}

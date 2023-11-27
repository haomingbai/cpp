/*************************************************************************
    > File Name: 5-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Nov 27 18:43:54 2023
 ************************************************************************/

#include<iostream>
#include<malloc.h>
using namespace std;

//Begin With 0
int isperfect(int **p,int begin_row,int begin_column,int row,int column){
	int cnt0=0,cnt1=0;
	if(row<2||column<2) return 0;
	for(int r=0;r<row;r++){
		for(int c=0;c<column;c++){
			if(r==0||c==0||r==row-1||c==column-1){
				//cout<<p[begin_row+r][begin_column+c]<<" "<<begin_row<<" "<<begin_column<<" "<<r<<" "<<c<<endl;
				if(p[begin_row+r][begin_column+c]==0) return 0;
			}else{
				if(p[begin_row+r][begin_column+c]==0) cnt0++;
				else cnt1++;
			}
		}
	}
	cout<<begin_row<<" "<<begin_column<<" "<<row<<" "<<column<<endl;
	//if(cnt0-cnt1<=1&&cnt0-cnt1>=-1) return 1;
	if(cnt0-cnt1<=1&&cnt0-cnt1>=-1){
		//cout<<1<<endl;
		return 1;
	}
	else return 0;
}

int main(){
	int **mat,row,column,cnt=0;
	cin>>row>>column;
	mat=(int **)malloc(row*sizeof(int*));
	for(int i=0;i<row;i++){
		*(mat+i)=(int *)malloc(column*sizeof(int));
		for(int r=0;r<column;r++){
			cin>>mat[i][r];
		}
	}
	for(int r=0;r<row;r++){
		for(int c=0;c<column;c++){
			for(int br=0;br<=row-r;br++){
				for(int bc=0;bc<=column-c;bc++) cnt+=isperfect(mat,r,c,br,bc);
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

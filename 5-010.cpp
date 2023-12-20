/*************************************************************************
    > File Name: 5-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月15日 星期五 20时02分54秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<algorithm>
using namespace std;


int is_perfect(int **the_0_0_position_of_the_matrix,int the_original_column_of_the_matrix,int the_number_of_rows_and_colunms_of_the_matrix);
//我查到资料，所有的完美矩阵都是方阵，有力地论证了姜老登的阴险
//他还说不一定是方阵来着？
//我******
//如果都是方阵，那它的第二个例子就是没有问题的。
//F**k

int** init_matrix(int,int);

int main(){
	int row,column;	//代表row行，column列的矩阵
	scanf("%d %d",&row,&column);
	int** base_matrix=init_matrix(row,column);
	int cnt=0;
	for(int i=0;i<row;i++) for(int j=0;j<column;j++) scanf("%d",base_matrix[i]+j);	//这个地方主要是扫描一下原矩阵的数据，还是用循环的扫法。
	for(int i=0;i<row-1;i++){
		for(int j=0;j<column-1;j++){
			if(base_matrix[i][j]==0&&base_matrix[i][j+1]==0&&base_matrix[i+1][j]==0) continue;
			for(int k=2;k<=min(row-i,column-j);k++){
				if(base_matrix[i+k-1][j+k-1]==0&&base_matrix[i+k-2][j+k-1]&&base_matrix[i+k-1][j+k-2]) continue;
				cnt+=is_perfect(base_matrix+i,j,k);
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

int** init_matrix(int row,int column){
	int **m=(int **)malloc(sizeof(int *)*row);
	for(int i=0;i<row;i++) *(m+i)=(int *)malloc(sizeof(int)*column);
	return m;
}

int is_perfect(int **base,int ori_col,int rows){
	int cnt0=0,cnt1=0;
	for(int **tmp=base;tmp<base+rows;tmp++){
		for(int *cmp=*tmp+ori_col;cmp<*tmp+ori_col+rows;cmp++){
			if(tmp-base==0&&tmp-base==rows-1&&cmp==*tmp+ori_col&&cmp==*tmp+ori_col+rows-1)
				if(*cmp==0) return 0;
			else if(*cmp==0)
				cnt0++;
			else
				cnt1++;
		}
	}
	if(abs(cnt0-cnt1)<=1) return 1;
	return 0;
}

/*************************************************************************
    > File Name: 5-006.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Fri Nov 24 22:01:56 2023
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int R,C;
	cin>>R>>C;
	int mat[R][C];
	for(int r=0;r<R;r++) for(int c=0;c<C;c++) cin>>mat[r][c];
	int f=0;
	for(int r=0;r<R;r++) for(int c=0;c<C;c++) if(mat[r][c]) f++;
	if((double)f/(double)(R*C)<=0.25&&(f<=R||f<=C)){
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}

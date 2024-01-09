/*************************************************************************
    > File Name: 5-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月01日 星期一 16时24分02秒
 ************************************************************************/

#include<iostream>
#include <utility>
#include <vector>
using namespace std;

int calculate(int **,int row,int column,int start_row=0,int start_column=0);
int judge(int **,int start_row=0,int start_column=0,int size=2);

int main(){
	int row,column;
	cin>>row>>column;
	vector<pair<int,int>> start_point;
	int **data=new int*[row];
	for(int i=0,swp=0;i<row;i++){
		*(data+i)=new int[column];
		for(int x=0;x<column;x++){
			cin>>swp;
			data[i][x]=swp;
			if(i!=row-1&&x!=column-1&&swp==1){
				start_point.push_back({i,x});
			}
		}
	}
	long long cnt=0;
	for(auto it:start_point){
		cnt+=calculate(data,row,column,it.first,it.second);
	}
	cout<<cnt<<endl;
}

int calculate(int **data,int row,int column,int start_row,int start_column){
	int result=0;
	for(int i=start_row+1,j=start_column+1;i<row&&j<column;i++,j++){
		if(data[i][start_column]==0||data[start_row][j]==0){
			return result;
		}else if(data[i][j]==0){
			continue;
		}else{
			result+=judge(data,start_row,start_column,i-start_row+1);
		}
	}
	return result;
}

//To save the time, I only took the necessary part into consideration
int judge(int **data,int start_row,int start_column,int size){
	int cnt0=0,cnt1=0;
	int end_row=start_row+size-1,end_column=start_column+size-1;
	//if(size==4)
	//	cout<<end_row<<" "<<end_column<<endl;
	for(int row=start_row+1,i=1;i<size-1;row++,i++){
		if(data[row][end_column]==0){
			return 0;
		}else{
			for(int column=start_column+1,j=1;j<size-1;j++,column++){
				if(data[end_row][column]==0){
					return 0;
				}else if(data[row][column]==0){
					cnt0++;
				}else{
					cnt1++;
				}
			}
		}
	}
	//int res=((abs(cnt0-cnt1))<=1);
	//if(res==1){
	//	cout<<start_row<<" "<<start_column<<" "<<size<<endl;
	//}
	return (abs(cnt0-cnt1))<=1;
}

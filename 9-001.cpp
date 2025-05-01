/*************************************************************************
    > File Name: 9-001.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月26日 星期二 12时20分21秒
 ************************************************************************/

#include <algorithm>
#include <cstdlib>
#include<iostream>
#include <vector>

template<typename T> T **alloc_2d(int row,int column){
	T** a;
	a=(T **)malloc(row*sizeof(T *));
	for(T ** it=a;it<a+row;it++){
		*it=(T *)malloc(column*sizeof(T));
	}
	return a;
}

std::vector<std::vector<int>> &process(int **,int,int);
int path(std::vector<int> &route,std::vector<std::vector<int>> &data);

int main(){
	int N,M;
	std::cin>>N>>M;
	int **data=alloc_2d<int>(M,3);
	for(int i=0;i<M;i++){
		std::cin>>data[i][0]>>data[i][1]>>data[i][2];
		data[i][0]--,data[i][1]--;
	}
	std::vector<std::vector<int>> d=process(data,M,N);
	std::vector<int> route;
	int len=0;
	for(int i=0;i<N;i++){
		len=std::max(len,path(route,d));
	}
	std::cout<<len<<std::endl;
}

//The n-1 pos indicate the node N;
std::vector<std::vector<int>> &process(int **data,int row,int N){
	std::vector<std::vector<int>> *res=new std::vector<std::vector<int>>;
	std::vector<std::vector<int>> &r=*res;
	r.resize(N);
	for(int i=0;i<N;i++){
		r.at(i).resize(N);
	}
	for(int i=0;i<row;i++){
		r.at(data[i][0]).at(data[i][1])=data[i][2];
		r.at(data[i][1]).at(data[i][0])=data[i][2];
	}
	return *res;
}

int path(std::vector<int> &route,std::vector<std::vector<int>> &data){
	if(route.size()==data.size())
		return 0;
	std::vector<std::vector<int>> m;
	int len=0;
	if(route.size()==0){
		for(int a=0,i=0;a<(data.size()-route.size());a++){
		m.push_back(route);
		m.at(i).push_back(a);
		len=std::max(len,path(m.at(i),data));
		i++;
		}
		return len;
	}
	for(int a=0,i=0;a<data.size();a++){
		if(data.at(route.back()).at(a)==0||std::find(route.begin(),route.end(),a)!=route.end())
			continue;
		m.push_back(route);
		m.at(i).push_back(a);
		len=std::max(len,path(m.at(i),data)+data[route.back()][a]);
		i++;
	}
	return len;
}

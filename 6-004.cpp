/*************************************************************************
    > File Name: 6-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sat Dec  2 10:07:43 2023
 ************************************************************************/

#include<iostream>
#include<malloc.h>
using namespace std;

string cut_string(string str,int start,int stop=-65536,int step=1){
	string r;
	if(stop==-65536) stop=str.length();
	if(stop<0) stop=0;
	//int i=start;
	//for(int i=7;i-stop==1||i-stop==-1;i+=step){
	/*for(int i=start;i!=stop;i+=step){
		r.push_back(str.at(i));
	}*/
	switch(start>=stop){
		case 0: {
					for(int i=start;i<stop;i+=step){
						r.push_back(str.at(i));
					}
					break;
				}
		case 1: {

					for(int i=start;i>=stop;i+=step){
						r.push_back(str.at(i));
					}
					break;
				} 
	}
	return r;
}

int main(){
	string source;
	int pgn;
	getline(cin,source);
	scanf("%d",&pgn);
	int **G=(int **)malloc(sizeof(int *)*pgn);
	int *pn=(int *)malloc(sizeof(int));
	for(int i=0;i<pgn;i++){
		scanf("%d",pn+i);
		*(G+i)=(int *)malloc(sizeof(int)*(*(pn+i)));
		for(int m=0;m<*(pn+i);m++){
			scanf("%d",*(G+i)+m);
			if((m==0||m==1)&&(G[i][m]<0)){
				*(*(G+i)+m)+=source.length();
			}
		}
	}
	for(int i=0;i<pgn;i++){
		switch(pn[i]){
			case 0 :{
						cout<<""<<endl;
						break;
					}
			case 1 :{
						cout<<cut_string(source,**(G+i))<<endl;
						break;
					}
			case 2 :{
						cout<<cut_string(source,**(G+i),*(*(G+i)+1))<<endl;
						break;
					}
			case 3 :{
						cout<<cut_string(source,**(G+i),*(*(G+i)+1),*(*(G+i)+2))<<endl;
						break;
					}
		}
	}
	return 0;
}

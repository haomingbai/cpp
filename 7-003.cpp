#include<iostream>
#include<malloc.h>

using namespace std;

int isv(int *j,int n){
    for(int i=0;i<n;i++){
        //cout<<"a"<<endl;
        if(j[i]==0) return 0;
    }
    return 1;
}

int main(){
    int **data,i=0;
    do{
        if(i==0) data=(int **)malloc(sizeof(int*));
        else data=(int **)realloc(data,sizeof(int *)*(i+1));
        data[i]=(int *)malloc(sizeof(int)*4);
        for(int m=0;m<4;m++){
            cin>>data[i][m];
        }
        i++;
    }while(isv(data[i-1],4));
}

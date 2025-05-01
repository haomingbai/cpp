#include<iostream>

using namespace std;

void seq(int *data,int length){
    for(int i=length-1;i>0;i--){
        //cout<<i<<endl;
        for(int *m=data;m<data+i;m++){
            if(*m>*(m+1))
            *(m+1)^=*m^=*(m+1)^=*m;
        }
        //cout<<i<<endl;
    }
}

int main(){
    int len;
    cin>>len;
    int data[len];
    for(int i=0;i<len;i++){
        cin>>data[i];
    }
    seq(data,len);
    for(int i=0;i<len;i++){
        cout<<data[i]<<" ";
    }
    cout<<'\n'<<endl;
}
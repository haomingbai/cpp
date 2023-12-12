#include<iostream>

using namespace std;

/*void seq(int *data,int length){
    for(int i=length;i>0;i--){
        for(int *m=data+i;m>data;m--){
            if(*m<*(m-1)){
                *m^=*(m+1)^=*m^=*(m+1);
            }
        }
    }
}*/

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

int find(int tofind,int *data,int length){
    int *front=data,*rare=data+length-1;
    int phase=(rare-front)/3;
    int *mid1=front+phase;
    int *mid2=rare-phase;
    while(phase>1){
        if(tofind<*front||tofind>*rare) return -1;
        if(tofind<*mid1){
            front=front;
            rare=mid1;
        }else if(tofind<*mid2){
            front=mid1;
            rare=mid2;
        }else{
            front=mid2;
            rare=rare;
        }
        phase=(rare-front)/3;;
        mid1=front+phase;
        mid2=rare-phase;
    }
    for(int *a=front;a<=rare;a++){
        if(*a==tofind) return (a-data);
    }
}

int main(){
    int length;
    cin>>length;
    int data[length];
    for(int i=0;i<length;i++) cin>>data[i];
    int tofind;
    cin>>tofind;
    seq(data,length);
    //for(int i=0;i<length;i++) cout<<data[i]<<endl;
    cout<<find(tofind,data,length)<<endl;
}
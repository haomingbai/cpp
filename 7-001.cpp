/*************************************************************************
    > File Name: 7-001.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月13日 星期三 08时53分56秒
 ************************************************************************/

/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) cin>>vec[n];
	int val;
	cin>>val;
	vector<int>::iterator it = find(vec.begin(), vec.end(), val);

    if (it != vec.end())
        cout<<it-vec.begin()<<endl;
    else
        cout<<-1<<endl;
	return 0;
}
*/

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
        return -1;
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
    //cout<<find(tofind,data,length)<<endl;
	printf("%d in [%d]",tofind,find(tofind,data,length));
	return 0;
}


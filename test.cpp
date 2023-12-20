#include<iostream>
using namespace std;

template<typename T> void sort_down(T *data,int n=1){
        T swap;
        for(int i=n-2;i>=0;i--){
                for(int j=0;j<=i;j++){
                        if(data[j]<data[j+1]){
                                swap=data[j];
                                data[j]=data[j+1];
                                data[j+1]=swap;
                                //cout<<data[j]<<endl;
                        }
                }
        }
}

int main(){
	int a[]={1,3,4,2,6,7};
	sort_down(a,6);
	for(int i=0;i<6;i++) cout<<a[i]<<endl;
}

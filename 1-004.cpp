/*************************************************************************
    > File Name: 1-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Wed Oct  4 17:59:30 2023
 ************************************************************************/

#include<iostream>
using namespace std;

//这个函数里面，和分子有关的叫n，和分母有关的叫d
int plusn(int n1,int d1,int n2,int d2){
	n1=n1*d2;
	n2=n2*d1;
	return n1+n2;
}

int cald(int d1,int d2){
	return d1*d2;
}

int minusn(int n1,int d1,int n2,int d2){
	n1=n1*d2;
	n2=n2*d1;
	return n1-n2;
}

string mutiply(int n1,int d1,int n2,int d2){
	int n,d;
	n=n1*n2;
	d=d1*d2;
	int temp=d;
	while ((n/temp)*temp!=n||(d/temp)*temp!=d){
		temp--;
	}
	n=n/temp;
	d=d/temp;
	return to_string(n)+"/"+to_string(d);
}





string devide(int n1,int d1,int n2,int d2){
	int n,d;
	n=n1*d2;
	d=d1*n2;
	int temp=d;
	while ((n/temp)*temp!=n||(d/temp)*temp!=d){
		temp--;
	}
	n=n/temp;
	d=d/temp;
	return to_string(n)+"/"+to_string(d);
}

string plusf(int n1,int d1,int n2,int d2){
	int n,d;
	n=plusn(n1,d1,n2,d2);
	d=cald(d1,d2);

	int temp=d;
	while ((n/temp)*temp!=n||(d/temp)*temp!=d){
		temp--;
	}
	n=n/temp;
	d=d/temp;
	return to_string(n)+"/"+to_string(d);

}


string minusf(int n1,int d1,int n2,int d2){

	int n,d;
	n=minusn(n1,d1,n2,d2);
	d=cald(d1,d2);

	int temp=d;
	while ((n/temp)*temp!=n||(d/temp)*temp!=d){
		temp--;
	}
	n=n/temp;
	d=d/temp;
	return to_string(n)+"/"+to_string(d);

}

int main(){
	int n1,d1,n2,d2;
	scanf("%d/%d\n%d/%d",&n1,&d1,&n2,&d2);
	//printf("%d,%d,%d,%d",n1,n2,d1,d2);
	//string p = plusf(n1,d1,n2,d2);
	//printf("(%d/%d)+(%d/%d)=%s\n",n1,d1,n2,d2,plusf(n1,d1,n2,d2));
	printf("(%d/%d)+(%d/%d)=",n1,d1,n2,d2);
	cout<<plusf(n1,d1,n2,d2)<<endl;
	
	printf("(%d/%d)-(%d/%d)=",n1,d1,n2,d2);
	cout<<minusf(n1,d1,n2,d2)<<endl;

	printf("(%d/%d)*(%d/%d)=",n1,d1,n2,d2);
	cout<<mutiply(n1,d1,n2,d2)<<endl;

	printf("(%d/%d)/(%d/%d)=",n1,d1,n2,d2);
	cout<<devide(n1,d1,n2,d2)<<endl;

	return 0;
}

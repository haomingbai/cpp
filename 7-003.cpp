/*************************************************************************
    > File Name: 7-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月22日 星期五 18时59分53秒
 ************************************************************************/

#include <cstdio>
#include <initializer_list>
#include<map>
#include<iostream>
#include <memory>
#include <vector>

using namespace std;

template <int T> class point{
private:
	int *data;
	const map<char,int> pos={{'x',0},{'y',1},{'z',2},{'a',3},{'b',4},{'c',5},{'d',6},{'i',7},{'j',8},{'k',9},{'m',10},{'n',11}};
public:
	point(){
		data=new int [T];
	}
	point(initializer_list<int> li){
		int x=0;
		data=new int [T];
		for(auto i=li.begin();i!=li.end()&&x<T;i++){
			data[x]=*i;
			x++;
		}
		while(x<T){
			data[x]=0;
		}
	}
	point(int *p){
		data=new int [T];
		for(int m=0;m<T;m++){
			data[m]=p[m];
		}
	}
	int get(char c)const{
		return data[pos.at(c)];
	}
	int get(int n)const{
		return data[n];
	}
	int move(char c='x',int n=1){
		if(pos.find(c)==pos.end()) return -1;
		int x=pos.at(c);
		if(x>=T) return -1;
		data[x]+=n;
		return 0;
	}
	int move(int x=0,int n=1){
		if(x>=T) return -1;
		data[x]+=n;
		return 0;
	}
	point operator+(point<T> p){
		int a[T];
		for(int i=0;i<T;i++){
			a[i]=data[i]+p.get(i);
		}
		point<T> r(a);
		return r;
	}
	point operator-(point<T> p){
		int a[T];
		for(int i=0;i<T;i++){
			a[i]=data[i]-p.get(i);
		}
		point<T> r(a);
		return r;
	}
	int operator*(point<T> p){
		int r=0;
		for(int i=0;i<T;i++){
			r+=data[i]*p.get(i);
		}
		return r;
	}
	int operator==(const point<T> &p){
		for(int i=0;i<T;i++){
			if(data[i]!=p.get(i)) return 0;
		}
		return 1;
	}
	point<T> operator=(const point<T> &p){
		for(int i=0;i<T;i++){
			data[i]=p.get(i);
		}
		return *this;
	}
	point<T> operator=(initializer_list<int> l){
		int i=0;
		for(auto it=l.begin();it!=l.end()&&i<T;it++){
			data[i]=*it;
			i++;
		}
		while(i<T){
			data[i]=0;
			i++;
		}
		return *this;
	}
};

int C(int n,int m){
	if(m==0||m==n) return 1;
	double x=1;
	int a=n;
	for(int b=m;b>0;b--,a--){
		x*=a;
		x/=b;
	}
	for(int b=(n-m);b>0&&a>0;b--,a--){
		x*=a;
		x/=b;
	}
	return (int)x;
}

int to(const point<2> pt){
	int x=pt.get(0);
	int m=pt.get(1);
	int n=x+m;
	return C(n,m);
}

int main(){
	vector<pair<point<2>,point<2>>> v;
	pair<point<2>,point<2>> o;
	//v.push_back(o);
	int swp[4];
	point<2> poswp;
	//pair<point<2>,point<2>> pswp;
	while(1){
		cin>>swp[0]>>swp[1]>>swp[2]>>swp[3];
		for(int i=0;i<4;i++){
			swp[i]--;
		}
		//pswp={{swp[0],swp[1]},{swp[2],swp[3]}};
		if(swp[0]<=0||swp[1]<=0||swp[2]<=0||swp[3]<=0) break;
		//cout<<swp[0]<<swp[1]<<swp[2]<<swp[3]<<endl;
		//cout<<pswp.first.get(0)<<" "<<pswp.first.get(1)<<endl;
		v.push_back({{swp[0],swp[1]},{swp[2],swp[3]}});
		//cout<<v.at(0).first.get(0)<<endl;
		//cout<<v.size()<<endl;
	}
		//cout<<v.size()<<endl;
		//cout<<v.at(0).first.get(0)<<endl;
	point<2> B,P;
	for(auto it:v){
		B=it.first,P=it.second;
		//cout<<B.get(0)<<" "<<B.get(1)<<endl;
		if(P.get('x')>B.get('x')||P.get('y')>B.get('y')){
			cout<<to(B)<<endl;
		}else{
			cout<<to(B)-to(P)*to(B-P)<<endl;
		}
	}
	return 0;
}


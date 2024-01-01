/*************************************************************************
    > File Name: 9-006.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月27日 星期三 20时53分10秒
 ************************************************************************/

#include <algorithm>
#include <deque>
#include <initializer_list>
#include<iostream>
#include <list>
#include <vector>
using namespace std;

class triangle{
public:
	long long int a,b,c;
	long long int circumference()const{
		return a+b+c;
	}
	long long int longest()const{
		return max({a,b,c});
	}
	long long int shortest()const{
		return min({a,b,c});
	}
	bool operator>(const triangle &t){
		if(circumference()>t.circumference())
			return 1;
		if(longest()>t.longest())
			return 1;
		if(shortest()>t.shortest())
			return 1;
		return 0;
	}
	bool operator>=(const triangle &t){
		if(circumference()>=t.circumference())
			return 1;
		if(longest()>=t.longest())
			return 1;
		if(shortest()>=t.shortest())
			return 1;
		return 0;
	}
	bool operator<(const triangle &t)const{
		if(circumference()<t.circumference())
			return 1;
		if(longest()<t.longest())
			return 1;
		if(shortest()<t.shortest())
			return 1;
		return 0;
	}
	bool operator<=(const triangle &t){
		if(circumference()<=t.circumference())
			return 1;
		if(longest()<=t.longest())
			return 1;
		if(shortest()<=t.shortest())
			return 1;
		return 0;
	}
	triangle(initializer_list<int> &l){
		auto it=l.begin();
		a=*it;
		it++;
		b=*it;
		it++;
		c=*it;
		it++;
	}
	triangle():a(0),b(0),c(0){}
	triangle(long long int x,long long int y,long long int z):a(x),b(y),c(z){}
	triangle& operator=(initializer_list<int> &l){
		auto it=l.begin();
		a=*it;
		it++;
		b=*it;
		it++;
		c=*it;
		it++;
		return *this;
	}
	triangle& operator=(const triangle &t){
		a=t.a;
		b=t.b;
		c=t.c;
		return *this;
	}
	bool operator==(const triangle &T){
		if(longest()==T.longest()&&shortest()==T.shortest()&&circumference()==T.circumference()){
			return 1;
		}
		return 0;
	}
};

bool valid_triangle(long long int a,long long int b,long long int c){
	vector<long long int> m{a,b,c};
	sort(m.begin(),m.end());
	if(m[0]+m[1]>m[2]&&min({a,b,c})>0){
		return 1;
	}
	return 0;
}

int main(){
	int n;
	vector<long long int> dat;
	cin>>n;
	dat.resize(n);
	for(int i=0;i<n;i++){
		cin>>dat.at(i);
	}
	triangle v,s;
	for(int i=0;i<n-2;i++){
		for(int t=i+1;t<n-1;t++){
			for(int x=t+1;x<n;x++){
				if(!valid_triangle(dat[i],dat[t],dat[x]))
					continue;
				s={dat[i],dat[t],dat[x]};
				v=max(v,s);
			}
		}
	}
	triangle p;
	if(p==v){
		cout<<-1<<endl;
		return 0;
	}
	vector<long long int> l={v.a,v.b,v.c};
	sort(l.begin(),l.end());
	cout<<l[0]<<" "<<l[1]<<" "<<l[2]<<endl;
	return 0;
}

/*************************************************************************
    > File Name: 5-002.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月02日 星期二 15时34分11秒
 ************************************************************************/

#include<iostream>
#include <list>
using namespace std;

void calculate(list<list<int>> *,list<int> *);
int judge(list<int> &);

int main(){
	int n;
	cin>>n;
	auto data=new list<list<int>>;
	auto result=new list<int>;
	for(int i=0,swap[5];i<n;i++){
		cin>>swap[0]>>swap[1]>>swap[2]>>swap[3]>>swap[4];
		data->push_back({swap[0],swap[1],swap[2],swap[3],swap[4]});
	}
	calculate(data,result);
	for(auto it:*result){
		if(it){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}

void calculate(list<list<int>> *data,list<int> *result){
	for(auto it=data->begin();it!=data->end();it++){
		result->push_back(judge(*it));
	}
}

/*int judge(list<int> &dat){
	list<int> f;
	auto d=dat.begin();
	for(int i=0;i<3;i++){
		f.push_back(*d);
		d++;
	}
	f.sort();
	for(int i=0;i<2&&!f.empty()&&!dat.empty();i++){
		while(dat.back()>=0&&(!f.empty())&&!(dat.size()>=3)){
			if(dat.back()>=f.back()){
				*(dat.rbegin())-=f.back();
				cout<<f.back()<<endl;
				f.pop_back();
			}else{
				*(f.rbegin())-=dat.back();
				dat.pop_back();
			}
		}
	}
	cout<<f.size()<<endl;
	if(f.empty())
		return 1;
	return 0;
}*/

int judge(list<int> &dat){
	list<int> fro,bak;
	fro.push_back(*dat.begin());
	dat.pop_front();
	fro.push_back(*dat.begin());
	dat.pop_front();
	fro.push_back(*dat.begin());
	dat.pop_front();
	bak.push_back(*dat.begin());
	dat.pop_front();
	bak.push_back(*dat.begin());
	dat.pop_front();
	fro.sort(),bak.sort();
	while(fro.size()&&bak.size()){
		if(fro.back()>=bak.back()){
			fro.back()-=bak.back();
			bak.pop_back();
		}else{
			bak.back()-=fro.back();
			//cout<<fro.back()<<endl;
			fro.pop_back();
		}
	}
	//cout<<fro.size()<<endl;
	return fro.empty();
}

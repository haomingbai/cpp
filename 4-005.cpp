/*************************************************************************
    > File Name: 4-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月29日 星期五 23时43分09秒
 ************************************************************************/

#include <cstdlib>
#include <initializer_list>
#include<iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

long long int calculate(int n);

//int x[40001][40001];

auto& seive(int);

int main(){
	int n;
	long long r=0;
	cin>>n;
	//cout<<calculate(n)<<endl;
	//scanf("%d",&n);
	r=calculate(n);
	cout<<r<<endl;
	//printf("%lld\n",r);
}

/*long long int calculate(int n){
	//int **x=alloc_square(n);
	//cout<<"OK"<<endl;
	auto x=new bool[40001][40001];
	if(n==1){
		return 0;
	}else if(n==2){
		return 3;
	}
	long long int cnt=3;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(x[i][j]){
				continue;
			}else{
				cnt+=2;
				//cout<<i<<" "<<j<<endl;
				for(int k=1;k*j<n;++k){
					//cout<<x[1][3]<<endl;
					x[k*i][k*j]=1;
					//x[j*k][i*k]=1;
				}
			}
		}
	}
	//cout<<x[1][3]<<endl;
	return cnt;
}*/




//It is said that euler's Seive is useful in this problem
/*long long calculate(int n){
	if(n==0){
		return 0;
	}else if(n==1){
		return 3;
	}
	int res=3;
	auto tmp=seive(n);
	set<int> prime_column(tmp.begin(),tmp.end());
	for(auto i=1;i<n;++i){
		if(i==1||prime_column.count(i)){
			res+=(n-i-1)*2;
			continue;
		}else{
			for(auto j=i+i;j<n;j++){
				if(j==i+1||prime_column.count(j)){
					res+=2;
				}else{
					if(gcd(i,j)==1){
						res+=2;
					}
				}
			}
		}
	}
	return res;
}*/

auto& seive(int n){
	auto res=new vector<int>;
	vector<int> *mark=new vector<int>;
	mark->resize(n+1);
	for(int i=2;i<=n;i++){
		if(mark->at(i)==0)
			res->push_back(i);
		for(auto it:*res){
			if(i*it>n){
				break;
			}
			mark->at(i*it)=1;
			if(!(i%it)){
				break;
			}
		}
	}
	delete mark;
	return *res;
}

long long int calculate(int n){
	if(n==1){
		return 0;
	}else if(n==2){
		return 3;
	}
	long long r=3;
	auto prime=new vector<int>;
	auto mark=new vector<int>;
	auto not_prime=new vector<bool>;
	long long int cnt=3;
	mark->resize(n+1);
	not_prime->resize(n+1);
	fill(mark->begin(),mark->end(),0);
	fill(not_prime->begin(),not_prime->end(),0);
	mark->at(1)=1;
	for(auto i=2;i<n;i++){
		if(not_prime->at(i)==0){
			prime->push_back(i);
			not_prime->at(i)=1;
			mark->at(i)=i-1;
			cnt+=2*(i-1);
			//cout<<i<<": "<<(i-1)<<endl;
			//cout<<cnt<<endl;
		}
		for(auto it:*prime){
			if(i*it>=n){
				break;
			}
			//cout<<it<<endl;
			not_prime->at(i*it)=1;
			if(i%it==0){
				mark->at(it*i)=it*mark->at(i);
			}else{
				mark->at(it*i)=mark->at(it)*mark->at(i);
			}
			//mark->at(i*it)=it*mark->at(i);
			cnt+=2*mark->at(i*it);
			//cout<<cnt<<endl;
			//cout<<i*it<<": "<<mark->at(i*it)<<endl;
			if(i%it==0){
				break;
			}
		}
	}
	return cnt;
}

/*************************************************************************
    > File Name: 5-007.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sun Nov 26 10:16:35 2023
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/*int probe(vector<int> v){
	int n=v[5];
	v[5]=0;
	for(int i=4;i>=3;i--){
		while(a[i]!=0){
			n+=1;
			if(i==3){
				for(int k=6*6-(i+1)*(i+1);k>0;){
					if(v[1]!=0){
						v[1]--;
						k-=4
					}
					if(v[0]!=0)
				}
			}
		}
	}
}

int main(){
	return 0;
}*/

int main(){
	int n;
	vector<vector<int>> v;
	vector<int> comp(6,0);
	int cnt=0;
	do{
		v.push_back({0,0,0,0,0,0});
		if(v.empty()) printf("empty\n");
		for(int i=0;i<6;i++){
			cin>>v[cnt][i];
		}
		cnt++;
	}while(v[cnt-1]!=comp);
	for(int i=0;i<cnt-1;i++){
		n+=(v[i][5]+v[i][4]+v[i][3]);
		if(v[i][2]%4) n+=(v[i][2]/4+1);
		else n+=(v[i][2]/4);
		cout<<n<<endl;
		n=0;
	}
	return 0;
}

/*************************************************************************
    > File Name: 8-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月20日 星期三 19时22分00秒
 ************************************************************************/

#include<iostream>
#include<map>
#include <string>
#include <vector>
using namespace std;

int main(){
	string ori;
	cin>>ori;
	vector<string> name;
	map<string,int> num;
	string swap="";
	int cnt=0;
	bool state=0;
	while(ori!=""||state){
		if(ori[0]>='A'&&ori[0]<='Z'){
			if(num.count(swap)==0&&swap!="")
				name.push_back(swap);
			if(swap!=""){
				if(num.count(swap)!=0){
					if(cnt!=0)
						num[swap]+=cnt;
					else
						num[swap]+=1;
				}else if(cnt!=0){
					num[swap]=cnt;
				}else{
					num[swap]=1;
				}
				cnt=0;
				swap="";
			}
			swap.push_back(ori[0]);
		}else if(ori[0]>='a'&&ori[0]<='z'){
			swap.push_back(ori[0]);
		}else if(ori[0]>='0'&&ori[0]<='9'){
			cnt*=10;
			cnt+=(ori[0]-'0');
		}else if(ori==""){
			if(num.count(swap)==0&&swap!="")
				name.push_back(swap);
			if(swap!=""){
				if(num.count(swap)!=0){
					if(cnt!=0)
						num[swap]+=cnt;
					else
						num[swap]+=1;
				}else if(cnt!=0){
					num[swap]=cnt;
				}else{
					num[swap]=1;
				}
				cnt=0;
				swap="";
			}

		}
		ori.erase(0,1);
		if(ori=="")
			state=!state;
	}
	//for(vector<string>::iterator it=name.begin();it<name.end();it++){
	//	cout<<*it<<" "<<num[*it]<<endl;
	//}
	for(auto it:num){
		cout<<it.first<<" "<<it.second<<endl;
	}
	return 0;
}

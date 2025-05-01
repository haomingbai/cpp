/*************************************************************************
    > File Name: 8-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月20日 星期三 14时11分30秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class tagStudent{
private:
	long long ID;
	string Name;
	int Score;
	int alterTimes;
public:
	void erase(){
		ID=0;
		Name="";
		Score=0;
		alterTimes++;
	}
	tagStudent(){
		ID=0;
		Name="";
		Score=0;
		alterTimes=0;
	}
	int operator>(const tagStudent &A);
	int operator<(const tagStudent &A);
	int operator=(const tagStudent &A);
	long long get_id() const{
		return ID;
	}
	int set(long long int id,string name,int score){
		if(ID==0&&Name==""&&Score==0){
			ID=id;
			Name=name;
			Score=score;
			alterTimes++;
			return 1;
		}
		return 0;
	}
	string get_name() const{
		return Name;
	}
	int get_score() const{
		return Score;
	}
	int get_log(){
		return alterTimes;
	}
	friend istream& operator>>(istream &in,tagStudent &A){
		in>>A.ID>>A.Name>>A.Score;
		//if(A.ID==0&&A.Name==""&&A.Score==0) A.alterTimes++;
		//else A.alterTimes+=2;
		return in;
	}
	friend ostream& operator<<(ostream &out,tagStudent A){
		out<<A.get_id()<<" "<<A.get_name()<<" "<<A.get_score();
		return out;
	}
};

int tagStudent::operator>(const tagStudent &A){
	if(Score>A.get_score()){
		return 1;
	}else if(Score==A.get_score()){
		if(ID<A.get_id()){
			return 1;
		}
	}
	return 0;
}

int tagStudent::operator<(const tagStudent &A){
	if(Score<A.get_score()){
		return 1;
	}else if(Score==A.get_score()){
		if(ID>A.get_id()){
			return 1;
		}
	}
	return 0;
}

int tagStudent::operator=(const tagStudent &A){
		if(ID==0&&Name==""&&Score==0){
			ID=A.get_id();
			Name=A.get_name();
			Score=A.get_score();
			alterTimes++;
			return 1;
		}else{
			ID=A.get_id();
			Name=A.get_name();
			Score=A.get_score();
			alterTimes+=2;
			return 2;
		}
}

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
	int t;
	cin>>t;
	tagStudent *data=new tagStudent[t];
	for(int i=0;i<t;i++) cin>>data[i];
	//for(int i=0;i<t;i++) cout<<data[i]<<endl;
	sort_down(data,t);
	for(int i=0;i<t;i++) cout<<data[i]<<endl;
	//tagStudent te;
	//te.set(1,"aaaa",12);
	//cin>>te;
	//cout<<te.get_name()<<te.get_score()<<endl;;
	//cout<<(te)<<endl;
	return 0;
}

/*int main(){
	tagStudent t1,t2,t3;
	cin>>t1>>t2>>t3;
}*/

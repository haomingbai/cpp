#include<iostream>
#include<limits>

using namespace std;

int main(){
	int t;
	cin>>t;
	if (t==1) {
		char a;
		cout<<"1"<<","<<std::numeric_limits<char>::min()<<","<<std::numeric_limits<char>::max()<<endl;
	};
	if (t==2) {
		unsigned char a;
		cout<<"1"<<","<<std::numeric_limits<unsigned char>::min()<<","<<std::numeric_limits<unsigned char>::max()<<endl;
	};
	if (t==3) {
		short int a;
		cout<<"2"<<","<<std::numeric_limits<short int>::min()<<","<<std::numeric_limits<short int>::max()<<endl;
	};
	if (t==4) {
		unsigned short int a;
		cout<<"2"<<","<<std::numeric_limits<unsigned short int>::min()<<","<<std::numeric_limits<unsigned short int>::max()<<endl;
	};
	if (t==5) {
		int a;
		cout<<sizeof(a)<<","<<std::numeric_limits<int>::min()<<","<<std::numeric_limits<int>::max()<<endl;
	};
	if (t==6) {
		unsigned int a;
		cout<<sizeof(a)<<","<<std::numeric_limits<unsigned int>::min()<<","<<std::numeric_limits<unsigned int>::max()<<endl;
	};
	if (t==7) {
		long int a;
		cout<<"4"<<","<<"-2147483648"<<","<<"2147483647"<<endl;
	};
	if (t==8) {
		unsigned long int a;
		cout<<"4"<<","<<"0"<<","<<"4294967295"<<endl;
	};
	if (t==9) {
		long long int a;
		cout<<"8"<<","<<"-9223372036854775808"<<","<<"9223372036854775807"<<endl;
	};
	if (t==10) {
		unsigned long long int a;
		cout<<"8"<<","<<"0"<<","<<"18446744073709551615"<<endl;
	};
	return 0;
}	

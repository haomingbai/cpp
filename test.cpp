#include <iostream>

using namespace std;

int main(){
	int m[3][3]={{0,1,2},{3,4,5},{6,7,8}};
	int (*p)=m[0];
	cout<<*(p+5)<<endl;
}

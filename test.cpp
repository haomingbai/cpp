#include<iostream>
using namespace std;
int main(){
	int i,a=2;
	i=(a=a*3,a*5),a+6;
	printf("a=%d,i=%d\n",a,i);
	return 0;
}

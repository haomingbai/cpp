/*************************************************************************
    > File Name: 1-003.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年09月28日 星期四 14时56分17秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int a,t1{0},t2{0},t3{0};
	cin>>a;
	t2=a;
	while (t2!=0){
		t3=t2%10;
		if (t3==2||t3==3||t3==4||t3==5||t3==7) {
			break;
		}
		switch (t3) {
			case 9: t3=6;break;
			case 6: t3=9;break;
		}

		t1=10*t1+t3;
		t2=t2/10;
	}
	if (t1==a){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}

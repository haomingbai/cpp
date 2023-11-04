/*************************************************************************
    > File Name: 3-002.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Mon Oct 16 18:34:09 2023
 ************************************************************************/

#include<iostream>
using namespace std;


//我们今天使用一下位运算符
//几种计算的位运算实现方式如下：
//1.除以2并取整数：a>>1
//2.取最后一位：(a<<31)>>31
//现在我们来实现一下

int main(){
	long long int m1,m2,m{0};
	cin>>m1>>m2;
	//这时，我们有三个变量，分别名为m1,m2和m，m用作加法变量，随时判断我们的m2是否是一个奇数，如果是，我们就用m1去加m，但如果不是，我们就不加
	if((m1<<63)>>63!=0){
		m+=m2;
	}
	cout<<m1<<" "<<m2<<endl;
	//printf("%d %d\n",m1,m2);
	while(m1!=1){
		m2=m2<<1;
		m1=m1>>1;
		//printf("%d %d\n",m1,m2);
		cout<<m1<<' '<<m2<<endl;
		if((m1<<63)>>63!=0){
			m+=m2;
		}
	}
	cout<<m<<endl;
	//printf("%d\n",m);
	return 0;
}

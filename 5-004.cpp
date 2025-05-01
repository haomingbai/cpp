/*************************************************************************
    > File Name: 5-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Fri Nov 24 17:13:08 2023
 ************************************************************************/

#include<iostream>
using namespace std;

/*int reverse(int n){
	int m=0;
	while(n!=0){
		m=10*m+n%10;
		n/=10;
	}
	return m;
}*/

string convert(int num, int base) {
  // 定义一个字符串，存储所有可能的数字和字母
  string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  // 定义一个空字符串，存储转换后的结果
  string result = "";
  // 判断输入的进制是否合法，必须在2到36之间
  if (base < 2 || base > 36) {
    return "Invalid base";
  }
  // 判断输入的数是否为0，如果是，直接返回"0"
  if (num == 0) {
    return "0";
  }
  // 判断输入的数是否为负，如果是，先记录一个负号，然后取绝对值
  bool isNegative = false;
  if (num < 0) {
    isNegative = true;
    num = -num;
  }
  // 用循环的方法，不断地除以进制，取余数，然后将余数对应的数字或字母添加到结果字符串的前面
  while (num > 0) {
    int remainder = num % base;
    result = digits[remainder] + result;
    num = num / base;
  }
  // 如果输入的数是负的，还要在结果字符串的前面加上一个负号
  if (isNegative) {
    result = "-" + result;
  }
  // 返回结果字符串
  return result;
}//这个是GPT写的

string reverse(int n,int k=10){
	string m=convert(n,k);
	string r;
	int p=m.length();
	for(int i=1;i<=p;i++) r=r+m[p-i];
	while(r[0]=='0') r.erase(0,1);
	return r;
}
int judge(int n,int k=10){
	if(convert(n,k)==reverse(n,k)) return 1;
	return 0;
}

int main(){
	//printf("%d\n",reverse_dec(12345));
	int n,k;
	cin>>n>>k;
	int cnt=0;
	for(int i=0;i<n;i++) if(judge(i)&&judge(i,k)) cnt+=i;
	cout<<cnt<<endl;
	//cout<<convert(n,5)<<"\n"<<reverse(n,5)<<endl;
	return 0;
}

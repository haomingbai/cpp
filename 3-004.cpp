/*************************************************************************
    > File Name: 3-004.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Wed Oct 25 19:26:24 2023
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

/*我们这一个题目的要求是输入两个数，然后输出他们的乘法的竖式
 * 我们可以尝试这样的思路：
 * 首先，我们测定这两个数字的位数，并且发现他们的乘积的位数
 * 这时候，我们很容易知道，我们的乘法竖式的宽度大约就是（这两个数字的乘积的宽度+1）
 * 这样，我们就可以用一种计数的方法，轻而易举地得到我们的竖式：自动靠右，用“left”
 * 空格+第一个数
 * X+第二个数
 * 长度为竖式宽度的减号
 * 第一个数乘第二个数的第一位，宽度为乘积宽度减一
 * 第二个，减二
 * ……
 * 最后，我们再像之前那样，画一条分割线
 * 输出结果，长度为运算结果
 * OK
 * 所以，我们需要如下几个变量：
 * 1，乘积的宽度
 * 2，两个数字
 * 3，乘积
 * 4，第二个数字的宽度（可选）
 * 5，第二个数字的各个数位的大小（临时）
 * 最后，我们就能轻松完成任务*/

//我们先编写一个函数，这个函数可以获取一个数字的长度

int get_width(int number){
	int i=0; //i是我们的数字的位数
	while(number!=0){
		number/=10;
		i++;
	}
	return i;
}

//我们再编写一个函数，让这个函数可以自动地输出一个数字，并且不用打一长串的cout

void ot(int output,int w){
	cout<<setw(w)<<output<<endl;
}

int main(){
	int factor1,factor2,product,product_width,factor2_width,factor2_part;
	cin>>factor1>>factor2;
	product=factor1*factor2;
	product_width=get_width(product);
	factor2_width=get_width(factor2);
	ot(factor1,product_width+1);
	cout<<'x';
	ot(factor2,product_width);
	for(int i=1;i<=product_width+1;i++){
		cout<<'-';
	}
	printf("\n");

	for(int i=1;i<=factor2_width;i++){
		factor2_part=factor2%10;
		if(i==factor2_width){
			printf("+");
		}else{
			cout<<" ";
		}
		ot(factor2_part*factor1,product_width+1-i);
		factor2/=10;
	}

	for(int i=1;i<=product_width+1;i++){
		cout<<'-';
	}
	printf("\n");
	ot(product,product_width+1);
	return 0;

}

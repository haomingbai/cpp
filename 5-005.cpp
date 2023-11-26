/*************************************************************************
    > File Name: 5-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Fri Nov 24 20:01:45 2023
 ************************************************************************/

#include<iostream>
using namespace std;

void linear_fit(double data[][2], int n, double result[]) {
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
    for (int i = 0; i < n; ++i) {
        sum_x += data[i][0];
        sum_y += data[i][1];
        sum_xy += data[i][0] * data[i][1];
        sum_x2 += data[i][0] * data[i][0];
    }
    double x_mean = sum_x / n;
    double y_mean = sum_y / n;
    double slope = (sum_xy - sum_x * y_mean) / (sum_x2 - sum_x * x_mean);
    double intercept = y_mean - slope * x_mean;
    result[0] = slope;
    result[1] = intercept;
}

int main(){
	int n;
	cin>>n;
	double data[n][2];
	for(int i=0;i<n;i++) cin>>data[i][0]>>data[i][1];
	double result[2];
	linear_fit(data,n,result);
	//cout<<result[0]<<" "<<result[1]<<endl;
	printf("Y=%.4lf+%.4lf*X\n",result[1],result[0]);
	return 0;
}

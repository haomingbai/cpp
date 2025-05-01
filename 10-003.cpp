//别人写的
//https://gitee.com/annesede/noj_2023_c
#include <stdio.h>
 
double pi(int n) {
	double sum = 3.0f;
	for (int i = 2; i <= n; ++i) {
		double sgn = i % 2 ? -1.0f : 1.0;
		sum += sgn * 4 / (2 * i * (2 * i - 1) * (2 * i - 2));
	}
	return sum;
}
 
int main() {
	int n;
	scanf("%d", &n);
	printf("%.7lf\n", pi(n));
	return 0;
}

#include <stdio.h>
#include <math.h>
 
double rate(double m1, double m2) {
	return sqrt(m2 / m1);
}
 
int main() {
	double m1, m2;
	scanf("%lf %lf", &m1, &m2);
	printf("%.4lf\n", rate(m1, m2));
	return 0;
}

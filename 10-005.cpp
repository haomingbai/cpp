//抄的
//
#include <stdio.h>
#include <math.h>
 
void mach(double v, double T) {
	double m = (v / 3.6f) / (331.3f * sqrt(1 + T / 273.15f));
	printf("%.3lf ", m);
	if (m - 0.8f < 1e-6) printf("subsonic\n");
	else if (m - 1.2f < 1e-6) printf("transonic\n");
	else if (m - 5.0f < 1e-6) printf("supersonic\n");
	else printf("hypersonic\n");
}
 
int main() {
	double v, T;
	scanf("%lf %lf", &v, &T);
	mach(v, T);
	return 0;
}

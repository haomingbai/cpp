#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main (){
	double R,G,B,H,S,V,mx,mn;
	cin>>R>>G>>B;
	mx=R;
	if (G>mx) mx=G;
	if (B>mx) mx=B;
	mn=R;
	if (G<mn) mn=G;
	if (B<mn) mn=B;

	V=100*mx/255;
	if (V!=0) S=100*(mx-mn)/mx;
	if (V==0) S=0;
	if (mx==R) H=60*(G-B)/(mx-mn);
	if (mx==G) H=60*(2+(B-R)/(mx-mn));
	if (mx==B) H=60*(4+(R-G)/(mx-mn));

	if (H<0) H=H+360;

	printf("%.4f,%.4f\%,%.4f\%\n",H,S,V);

	return 0;
}

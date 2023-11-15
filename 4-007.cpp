/*************************************************************************
    > File Name: 4-007.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sun Nov 12 18:25:35 2023
 ************************************************************************/

#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include<iomanip>
#include<cstring>

using namespace std;

double vol_calc_ball(double r){
	return (4/3)*M_PI*pow(r,3.0);
}

double vol_calc_cone(double r,double h){
	return (1/3)*M_PI*r*r*h;
}

double vol_calc_cube(long int a){
	return pow(a,3);
}

double vol_calc_cylinder(double r,long h){
	return M_PI*r*r*h;
}

double vol_calc_rectangular_prism(long l,long w,long h){
	return l*w*h;
}

double vol_calc_spherical_cap(double r,double R){
	double h=R+sqrt(R*R-r*r);
	return (M_PI*h*h/3)*(3*R-h);
}

double vol_calc_spherical_cap_m(double r,double R){
	double h=R-sqrt(R*R-r*r);
//	return (1/6)*M_PI*h*(3*pow(r,2)+pow(h,2));
	return (M_PI*h*h/3)*(3*R-h);
}

double vol_calc_capsule(double r,double R,double l){
	return (vol_calc_spherical_cap(r,R)*2+vol_calc_cylinder(r,l));
}

double vol_calc_capsule_m(double r,double R,double l){
	return (vol_calc_spherical_cap_m(r,R)*2+vol_calc_cylinder(r,l));
}

double vol_calc_cone(double r,double R,double h){
	return vol_calc_cone(R,h)-vol_calc_cone(r,h);
}

double vol_calc_ellipsoid(double a,double b,long c){
	return 4*M_PI*a*b*c/3;
}

double vol_calc_rectangular_pyramid(long a,long h){
	return 	pow(a,2)*h/3;
}

double vol_calc_pipe(long d1,long d2,double l){
	return vol_calc_cylinder(d1/2,l)-vol_calc_cylinder(d2/2,l);
}


int main(){
	
//	Input
	int T;
	cin>>T;
//	cout<<vol_calc_spherical_cap(5,7)<<" "<<vol_calc_spherical_cap_m(5,7)<<endl;
	double V[T][2];
	memset(V,0,sizeof(V));
	int n[4];
//	cout<<V[5][0]<<endl;

//	Calculation
	for(int i=0;i<T;i++){
		scanf("")
	}

//	End
	return 0;

}



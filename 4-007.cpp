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
	double h=sqrt(pow(R,2)-pow(r,2));
	return (1/6)*M_PI*h*(3*pow(r,2)+pow(h,2));
}
double vol_calc_spherical_cap_m(double r,double R){
	double h=sqrt(pow(R,2)+pow(r,2));
	return (1/6)*M_PI*h*(3*pow(r,2)+pow(h,2));
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
	double v_ball,v_cone,v_cube,v_cylinder,v_rectangular_prism,v_spherical_cap,v_spherical_cap_m,v_capsule,v_capsule_m,v_cone_p,v_ellipsoid,v_rectangular_pyramid,v_pipe;
	double r;
}



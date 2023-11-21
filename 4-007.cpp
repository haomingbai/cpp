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
	return (4.0/3.0)*M_PI*r*r*r;
}

double vol_calc_cone(double r,double h){
	return (1.0/3.0)*M_PI*r*r*h;
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
	return (M_PI*h*h/3.0)*(3.0*R-h);
}

double vol_calc_spherical_cap_m(double r,double R){
	double h=R-sqrt(R*R-r*r);
//	return (1/6)*M_PI*h*(3*pow(r,2)+pow(h,2));
	return (M_PI*h*h/3.0)*(3.0*R-h);
}

double vol_calc_capsule(double r,double R,double l){
	return (vol_calc_spherical_cap(r,R)*2.0+vol_calc_cylinder(r,l));
}

double vol_calc_capsule_m(double r,double R,double l){
	return (vol_calc_spherical_cap_m(r,R)*2.0+vol_calc_cylinder(r,l));
}

double vol_calc_cone(double r,double R,double h){
	return vol_calc_cone(R,h)-vol_calc_cone(r,h);
}

double vol_calc_ellipsoid(double a,double b,long c){
	return 4.0*M_PI*a*b*c/3.0;
}

double vol_calc_rectangular_pyramid(long a,long h){
	return 	pow(a,2.0)*h/3.0;
}

double vol_calc_pipe(long d1,long d2,double l){
	return vol_calc_cylinder(d1/2.0,l)-vol_calc_cylinder(d2/2.0,l);
}


int main(){
	
//	Input
	int T;
	cin>>T;
//	cout<<vol_calc_spherical_cap(5,7)<<" "<<vol_calc_spherical_cap_m(5,7)<<endl;
	double n[4]={0};
	int m;
	double V[T][2];
	//for(int i=0;i<T;i++)
//	cout<<V[5][0]<<endl;

//	Calculation
	for(int i=0;i<T;i++){
		cin>>m;
		memset(V[i],0,2*sizeof(double));
		switch(m){
			case 1 : 
						 cin>>n[1];
						 //double r;
						 //cin>>r;
						 //printf("%.6lf\n",vol_calc_ball(n[1]));
						 V[i][0]=vol_calc_ball(n[1]);
						 break;
						 //delete &r;
					 
			case 2 : 
						 /*cin>>n[1]>>n[2];
						 printf("%.6lf\n",vol_calc_cone(n[1],n[2]));*/
						 /*double r,h;
						 cin>>r>>h;
						 V[i][0]=vol_calc_cone(r,h);
						 delete &r;
						 delete &h;*/
						 cin>>n[1]>>n[2];
						 V[i][0]=vol_calc_cone(n[1],n[2]);
						 //cout<<V[i][0]<<"debug"<<endl;
						 break;
					 
			case 3:
						 /*cin>>n[1];
						 printf("%.6lf\n",vol_calc_cube(n[1]));*/
						 /*long a;
						 cin>>a;
						 V[i][0]=vol_calc_cube(a);
						 delete &a;*/
						 cin>>n[1];
						 V[i][0]=vol_calc_cube(n[1]);
						 break;
			case 4:
						 /*cin>>n[1]>>n[2];
						 printf("%.6lf\n",vol_calc_cylinder(n[1],n[2]));*/
						 /*double r;
						 long h;
						 V[i][0]=vol_calc_cylinder(r,h);
						 delete &h;
						 delete &r;*/
						 cin>>n[1]>>n[2];
						 V[i][0]=vol_calc_cylinder(n[1],n[2]);
						 break;
			case 5:
						 /*cin>>n[1]>>n[2]>>n[3];
						 printf("%.6lf\n",vol_calc_rectangular_prism(n[1],n[2],n[3]));*/
						 /*long l,w,h;
						 cin>>l>>w>>h;
						 V[i][0]=vol_calc_rectangular_prism(l,w,h);
						 delete &l;
						 delete &w;
						 delete &h;*/
						 cin>>n[1]>>n[2]>>n[3];
						 V[i][0]=vol_calc_rectangular_prism(n[1],n[2],n[3]);
						 break;
			case 7:
						 /*cin>>n[1]>>n[2];
						 printf("%.6lf %.6f\n",vol_calc_spherical_cap(n[1],n[2]),vol_calc_spherical_cap_m(n[1],n[2]));*/
						 /*double r,R;
						 cin>>r>>R;
						 V[i][0]=vol_calc_spherical_cap(r,R);
						 V[i][1]=vol_calc_spherical_cap_m(r,R);
						 delete &r;
						 delete &R;*/
						 cin>>n[1]>>n[2];
						 V[i][0]=vol_calc_spherical_cap(n[1],n[2]);
						 V[i][1]=vol_calc_spherical_cap_m(n[1],n[2]);
						 break;
			case 6:
						 /*cin>>n[1]>>n[2]>>n[3];
						 printf("%.6lf %.6lf\n",vol_calc_capsule(n[1],n[2],n[3]),vol_calc_capsule_m(n[1],n[2],n[3]));*/
						 /*double r,R,l;
						 cin>>r>>R>>l;
						 V[i][0]=vol_calc_capsule(r,R,l);
						 V[i][1]=vol_calc_capsule_m(r,R,l);
						 delete &r;
						 delete &R;
						 delete &l;*/
						 cin>>n[1]>>n[2]>>n[3];
						 V[i][0]=vol_calc_capsule(n[1],n[2],n[3]);
						 V[i][1]=vol_calc_capsule_m(n[1],n[2],n[3]);
						 break;
			case 8:
						 /*cin>>n[1]>>n[2]>>n[3];
						 printf("%.6lf\n",vol_calc_cone(n[1],n[2],n[3]));*/
						/* double r,R,h;
						 cin>>r>>R>>h;
						 V[i][0]=vol_calc_cone(r,R,h);
						 delete &r;
						 delete &R;
						 delete &h;*/
						 cin>>n[1]>>n[2]>>n[3];
						 V[i][0]=vol_calc_cone(n[1],n[2],n[3]);
						 break;
			case 9:
						 cin>>n[1]>>n[2]>>n[3];
						 //printf("%.6lf\n",vol_calc_ellipsoid(n[1],n[2],n[3]));
						 /*double a,b;
						 long c;
						 cin>>a>>b>>c;
						 V[i][0]=vol_calc_ellipsoid(a,b,c);
						 delete &a;
						 delete &b;
						 delete &c;*/
						 V[i][0]=vol_calc_ellipsoid(n[1],n[2],n[3]);
						 break;
			case 10:
						 cin>>n[1]>>n[2];
						 //printf("%.6lf\n",vol_calc_rectangular_pyramid(n[1],n[2]));
						 /*long a,h;
						 V[i][0]=vol_calc_rectangular_pyramid(a,h);
						 delete &a;
						 delete &h;*/
						 V[i][0]=vol_calc_rectangular_pyramid(n[1],n[2]);
						 break;
			case 11:
						 cin>>n[1]>>n[2]>>n[3];
						 //printf("%.6lf\n",vol_calc_pipe(n[1],n[2],n[3]));
						 /*long d1,d2;
						 double l;
						 vol_calc_pipe(d1,d2,l);
						 delete &d1;
						 delete &d2;
						 delete &l;*/
						 V[i][0]=vol_calc_pipe(n[1],n[2],n[3]);
						 break;
		}
	}
	int M=0;
	memset(n,0,4*sizeof(double));

//	Output
	for(int i=0;i<=T;i++){
		while(M<=1&&V[i][M]>=1e-6) {
			printf("%.6lf ",V[i][M]);
			M++;
		}
		M=0;
		printf("\n");
	}

//	End
	return 0;

}



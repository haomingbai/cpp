/*************************************************************************
    > File Name: 8-001.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月18日 星期一 19时03分29秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
#include<cmath>
using namespace std;

map<string,int> AtomNumber {{"SC",1},{"BCC",2},{"FCC",4}};

map<string,double> MoleMass{
	{"Po",208.998},
	{"Li",6.941},
	{"Na",22.989770},
	{"Cr",51.9961},
	{"Mn",54.938049},
	{"Fe",55.845},
	{"Mo",95.94},
	{"Ta",180.9479},
	{"Al",26.981538},
	{"Ca",40.078},
	{"Ni",58.6934},
	{"Cu",63.546},
	{"Ge",72.64},
	{"Ag",107.8682},
	{"Pt",195.078},
	{"Au",196.96655},
	{"Pb",207.2},
};

map<string,double> AtomicRadius{
	{"Po",168},
	{"Li",152},
	{"Na",186},
	{"Cr",128},
	{"Mn",127},
	{"Fe",126},
	{"Mo",139},
	{"Ta",146},
	{"Al",143},
	{"Ca",197},
	{"Ni",124},
	{"Cu",128},
	{"Ge",122},
	{"Ag",144},
	{"Pt",139},
	{"Au",144},
	{"Pb",175},
};


double NA=6.022e23;

class Element{
private:
	string ElementName;
	string CrystalType;
public:
	Element(){
		ElementName="";
		CrystalType="";
	};
	void ElementChange(string Name){
		ElementName=Name;
		if(Name=="Po"){
			CrystalType="SC";
		}else if(
				(Name=="Li")
				||(Name=="Na")||(Name=="Cr")
				||(Name=="Mn")||(Name=="Fe")
				||(Name=="Mo")||(Name=="Ta")
				){
			CrystalType="BCC";
		}else if(
				(Name=="Al")
				||(Name=="Ca")||(Name=="Ni")
				||(Name=="Cu")||(Name=="Ge")
				||(Name=="Ag")||(Name=="Pt")
				||(Name=="Au")||(Name=="Pb")
				){
			CrystalType="FCC";
		}
	}
	Element(string Name):ElementName(Name){
		if(Name=="Po"){
			CrystalType="SC";
		}else if(
				(Name=="Li")
				||(Name=="Na")||(Name=="Cr")
				||(Name=="Mn")||(Name=="Fe")
				||(Name=="Mo")||(Name=="Ta")
				){
			CrystalType="BCC";
		}else if(
				(Name=="Al")
				||(Name=="Ca")||(Name=="Ni")
				||(Name=="Cu")||(Name=="Ge")
				||(Name=="Ag")||(Name=="Pt")
				||(Name=="Au")||(Name=="Pb")
				){
			CrystalType="FCC";
		}
	}
	int n(){
		if(CrystalType=="SC") return 1;
		if(CrystalType=="BCC") return 2;
		if(CrystalType=="FCC") return 4;
		return 0;
	}
	double A(){
		return MoleMass[ElementName];
	}
	double r(){
		return AtomicRadius[ElementName];
	}
	/*double V(){
		double V;
		V=2.0*sqrt(2)*r();
		V*=1e-10;
		V=pow(V,3.0);
		//cout<<V<<endl;
		return V;
	}*/
	double V(){
		double a;
		switch(n()){
			case 1:
				a=2.0*r();
				a*=1e-10;
				break;
			case 2:
				a=4.0*r()/sqrt(3);
				a*=1e-10;
				break;
			case 4:
				a=2.0*r()*sqrt(2);
				a*=1e-10;
				break;
		}
		double V;
		V=pow(a,3.0);
		//cout<<V<<endl;
		return V;
	}
	double p(){
		double m=1;
		m*=((double)n()*A());
		//cout<<m<<endl;
		double d=V()*NA;
		//cout<<d<<endl;
		m/=d;
		return m;
	}
};

int main(){
	int T;
	cin>>T;
	string swp;
	Element *d=new Element[3];
	double p[T];
	for(int i=0;i<T;i++){
		cin>>swp;
		(d+i)->ElementChange(swp);
		p[i]=d[i].p();
	}
	for(int i=0;i<T;i++){
		printf("%.2lf\n",p[i]);
	}
	return 0;
}

/*************************************************************************
    > File Name: 8-002.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月20日 星期三 08时32分57秒
 ************************************************************************/
//WA

#include<iostream>

using namespace std;

/*class Rocket{
private:
	double OriginalMass;
	double PureMass;
	long long Step;
	double cE;
	double g;
	double Vilocity;
	int Time;
	double FuelMass(){
		return OriginalMass-PureMass;
	}
	double MassDot(){
		return FuelMass()/(double)Time;
	}
	double T(){
		return MassDot()*cE;
	}
	double a(){
		//cout<<(T()/OriginalMass-g)<<endl;;
		return T()/OriginalMass-g;
	}
	void AlterVilocity(){
		Vilocity+=a()*0.1;
	}
	double DeltaAltitude(){
		AlterVilocity();
		return Vilocity*0.1;
	}
	void AlterMass(){
		OriginalMass-=MassDot()*0.1;
	}
public:
	double Fly(){
		if(Step==0) return 0;
		Step--;
		int H;
		H=DeltaAltitude();
		AlterMass();
		cout<<"Step "<<Step<<" FuelMass "<<FuelMass()<<endl;
		return H+Fly();
	}
	Rocket(double O,double P,int T,double cE,double g):Time(T),OriginalMass(O),PureMass(P),Step(10*T),cE(cE),g(g){}
};

int main(){
	double O,P,cE,g;
	int T;
	cin>>O>>P>>T>>cE>>g;
	Rocket r(O,P,T,cE,g);
	cout<<r.Fly()<<endl;
	return 0;
}*/

int main(){
	double O,P,cE,g;
	int T;
	double H=0;
	cin>>O>>P>>T>>cE>>g;
	double fuelmass,mdot,a,tensity,v=0;
	for(int step=T*10;step;step--){
		fuelmass=O-P;
		mdot=fuelmass/(double)(step/10.0);
		tensity=mdot*cE;
		a=tensity/O-g;
		v+=a*0.1;
		H+=v*0.1;
		fuelmass-=mdot*0.1;
	}
	cout<<H<<endl;
}

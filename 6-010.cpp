#include<string>
#include<vector>
#include<iostream>
#include<cstdbool>
using namespace std;
string lstrip(string a,string b) {
	int count=0;
	vector<bool>sup(1000,false);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				sup[i] = true;
 
			}
 
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (sup[i]==false) {
			count = i;
			break;
 
		}
	}
	a.erase(a.begin(),a.begin()+count );
	return a;
 
}
string rstrip(string a, string b) {
	int count = 0;
	vector<bool>sup(1000, false);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				sup[i] = true;
 
			}
 
		}
	}
	for (int i = a.size()-1; i >=0; i--) {
		if (sup[i] == false) {
			count = i;
			break;
 
		}
	}
	a.erase(a.begin()+count+1, a.end());
	return a;
 
}
string strip(string a, string b) {
	a = lstrip(a, b);
	a = rstrip(a, b);
	return a;
}
int main() {
	string a;
	string b;
	string e, c, d;
	getline(cin,a);
	getline(cin, b);
	e = lstrip(a,b);
	c = rstrip(a, b);
	d = strip(a, b);
	cout << e << endl;
	cout << c << endl;
	cout << d << endl;
}
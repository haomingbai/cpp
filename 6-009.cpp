#include<iostream>

using namespace std;

int main(){
    string str,suf;
    getline(cin,str);
    getline(cin,suf);
    if(str.substr(str.length()-suf.length())==suf) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
#include<iostream>
#include<iomanip>

int main(){
    int v,w;
    std::cin>>v>>w;
    std::cout<<std::setw(w)<<std::right<<std::setfill('0')<<v<<std::endl;
    return 0;
}

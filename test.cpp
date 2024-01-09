#include <iostream>
#include <pthread.h>
int main(){
	int i=1;
	i = ++i--;
	std::cout<<i<<std::endl;
}

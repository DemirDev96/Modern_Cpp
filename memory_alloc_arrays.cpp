#include <iostream>
#include <cstring>
#include <string.h>


using namespace std;

void new_arrays(){
    int *p = new int[5];
    for ( int i = 0; i < 5; ++i){
        p[i] = i;
        }
        delete[]p;
}

void strings() {
    char* p = new char[4];
    std::strcpy(p, "C++"); 
    std::cout << p << '\n';
    delete[] p;
}


int main(){

    

    return 0;
}

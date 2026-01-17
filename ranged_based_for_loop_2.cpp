#include <iostream>

using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};

    /*int *begin = &arr[0]; 
    int *end = &arr[5]; this is old c++ */

    /*int *beg = std::begin(arr);
    int *end = std::end(arr); // this will return the right pointer*/


    /*while ( beg != end )
    {
        cout << *beg << ' ';
        ++beg;
    }*/
    
    auto &&range = arr;
    auto begin = std::begin(arr); // begin and end must be same type as of c++ 17 
    auto end = std::end(arr);

    for ( auto x : arr ){
        cout << x << ' ';
    }

    return 0;
}

// author : Mohammad Moazam
// Exercise 5 - Q2
#include <iostream>

namespace func {

    inline void swap(int &x, int &y){
        x = x + y;
        y = x - y;
        x = x - y;
    }

}

namespace _func {

    inline void swap(int &x, int &y){
        x = x + y;
        y = x - y;
        x = x - y;
    }

}

using namespace std;
using namespace func;


int main(){

    int a(10),b(190);

    cout << "Values of the variables" << endl;

    cout << a << " --- " << b << endl;

    swap(a,b);

    cout << endl << "Swap function using namespaces" << endl <<endl;

    cout << a << " --- " << b << endl;

    _func :: swap(a,b);

    cout << endl << "Swap function without using namespaces" << endl <<endl;

    cout << a << " --- " << b << endl;



    return 0;
}

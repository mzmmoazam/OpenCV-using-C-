// author : Mohammad Moazam
// Exercise 4 - Q2
#include <iostream>
using namespace std;

inline void swap(int &x, int &y){
    x = x + y;
    y = x - y;
    x = x - y;
}

int main()
{
    int x,y;

    cout << "Enter the value for the first integer : ";
    cin >> x;

    cout << "Enter the value for the second integer : ";
    cin >> y;

    swap(x,y);

    cout << "Value for the first integer after the swap: " << x << endl;
    cout << "Value for the second integer after the swap: " << y << endl;



}
// author : Mohammad Moazam
// Exercise 3 - Q1
#include <iostream>
using namespace std;

int main()
{
    int a,b,*ptr1, *ptr2;
    cout << "Enter the value for an integer : ";
    cin >> a;

    cout << "Enter the value for another integer : ";
    cin >> b;

    cout << "\n\nAssigning to pointers...\n";

    ptr1 = &a,ptr2 = &b;

    cout << "\nValue for ptr1 : " << *ptr1;

    cout << "\nValue for ptr2 : " << *ptr2;
}
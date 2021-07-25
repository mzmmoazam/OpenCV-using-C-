// author : Mohammad Moazam
// Exercise 2 - Q3
#include <iostream>
using namespace std;

int main()
{
    cout << "Read input from the user and display the output in C++" << endl
         << endl;

    // Character types
    char _char;
    cout << "Enter the data for char : ";
    cin >> _char;

    // char16_t _char16_t;
    // cout << "Enter the data for char16_t";
    // cin >> _char16_t;

    // char32_t _char32_t;
    // cout << "Enter the data for char32_t";
    // cin >> _char32_t;

    // wchar_t _wchar_t; // variable length, at init only 2 bytes
    // cout << "Enter the data for wchar_t";
    // cin >> _wchar_t;

     // master_uwo
    // 9JPZnE5QSt

    // Integer types (signed)
    signed char _signedChar;
    cout << "Enter the data for signed char : ";
    cin >> _signedChar;

    signed short int _signedShortInt;
    cout << "Enter the data for signed short int : ";
    cin >> _signedShortInt;

    signed int _signedInt;
    cout << "Enter the data for signed int : ";
    cin >> _signedInt;

    signed long int _signedLongInt;
    cout << "Enter the data for signed long int : ";
    cin >> _signedLongInt;

    signed long long int _signedLongLongInt;
    cout << "Enter the data for signed long long int : ";
    cin >> _signedLongLongInt;

    // Integer types (unsigned)
    unsigned char _unsignedChar;
    cout << "Enter the data for unsigned char : ";
    cin >> _unsignedChar;

    unsigned short int _unsignedShortInt;
    cout << "Enter the data for unsigned short int : ";
    cin >> _unsignedShortInt;

    unsigned int _unsignedInt;
    cout << "Enter the data for unsigned int : ";
    cin >> _unsignedInt;

    unsigned long int _unsignedLongInt;
    cout << "Enter the data for unsigned long int : ";
    cin >> _unsignedLongInt;

    unsigned long long int _unsignedLongLongInt;
    cout << "Enter the data for unsigned long long int : ";
    cin >> _unsignedLongLongInt;

    // Floating-point types
    float _float;
    cout << "Enter the data for float : ";
    cin >> _float;

    double _double;
    cout << "Enter the data for double : ";
    cin >> _double;

    long double _longDouble;
    cout << "Enter the data for long double : ";
    cin >> _longDouble;

    // Boolean type
    bool _bool;
    cout << "Enter the data for bool : ";
    cin >> _bool;

    cout << endl
         << endl
         << "Here is the data that you provided" 
         << endl
         << endl;

    cout << "Data for char : " << _char << endl;

    cout << "Data for signed char : " << _signedChar << endl;

    cout << "Data for signed short int : " << _signedShortInt << endl;

    cout << "Data for signed int : " << _signedInt << endl;

    cout << "Data for signed long int : " << _signedLongInt << endl;

    cout << "Data for signed long long int : " << _signedLongLongInt << endl;

    cout << "Data for unsigned char : " << _unsignedChar << endl;

    cout << "Data for unsigned short int : " << _unsignedShortInt << endl;

    cout << "Data for unsigned int : " << _unsignedInt << endl;

    cout << "Data for unsigned long int : " << _unsignedLongInt << endl;

    cout << "Data for unsigned long long int : " << _unsignedLongLongInt << endl;

    cout << "Data for float : " << _float << endl;

    cout << "Data for double : " << _double << endl;

    cout << "Data for long double : " << _longDouble << endl;

    cout << "Data for bool : " << _bool << endl;
    return 0;
}
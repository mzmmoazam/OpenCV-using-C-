// author : Mohammad Moazam
// Exercise 2 - Q1
#include <iostream>
#include <iomanip>
using namespace std;

template <class T1, class T2>
void printSize(T1 dataType, T2 &x)
{
    cout << "Data type : " << setw(23) << left << dataType << " has size " << setw(2) << left << sizeof(x)
         << " bytes or " << setw(2) << left << sizeof(x) * 8 << " bits." << endl;
}

int main()
{

    cout << "Display the memory of different data types in c++" << endl
         << endl;

    // Character types
    char _char;
    printSize("char", _char);

    char16_t _char16_t;
    printSize("char16_t", _char16_t);

    char32_t _char32_t;
    printSize("char32_t", _char32_t);

    wchar_t _wchar_t; // variable length, at init only 2 bytes
    printSize("wchar_t", _wchar_t);

    // Integer types (signed)
    signed char _signedChar;
    printSize("signed char", _signedChar);

    signed short int _signedShortInt;
    printSize("signed short int", _signedShortInt);

    signed int _signedInt;
    printSize("signed int", _signedInt);

    signed long int _signedLongInt;
    printSize("signed long int", _signedLongInt);

    signed long long int _signedLongLongInt;
    printSize("signed long long int", _signedLongLongInt);

    // Integer types (unsigned)
    unsigned char _unsignedChar;
    printSize("unsigned char", _unsignedChar);

    unsigned short int _unsignedShortInt;
    printSize("unsigned short int", _unsignedShortInt);

    unsigned int _unsignedInt;
    printSize("unsigned int", _unsignedInt);

    unsigned long int _unsignedLongInt;
    printSize("unsigned long int", _unsignedLongInt);

    unsigned long long int _unsignedLongLongInt;
    printSize("unsigned long long int", _unsignedLongLongInt);

    // Floating-point types
    float _float;
    printSize("float", _float);

    double _double;
    printSize("double", _double);

    long double _longDouble;
    printSize("long double", _longDouble);

    // Boolean type
    bool _bool;
    printSize("bool", _bool);

    // Void type
    void *_void;
    printSize("void", _void);

    // Null pointer
    decltype(_char) _decltype;
    printSize("decltype", _decltype);

    return 0;
}
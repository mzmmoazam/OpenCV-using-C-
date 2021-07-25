// author : Mohammad Moazam
// Exercise 2 - Q2
#include <iostream>
#include <iomanip>
using namespace std;

// Character types
char global_char;

char16_t global_char16_t;

char32_t global_char32_t;

wchar_t global_wchar_t; // variable length, at init only 2 bytes

// Integer types (signed)
signed char global_signedChar;

signed short int global_signedShortInt;

signed int global_signedInt;

signed long int global_signedLongInt;

signed long long int global_signedLongLongInt;

// Integer types (unsigned)
unsigned char global_unsignedChar;

unsigned short int global_unsignedShortInt;

unsigned int global_unsignedInt;

unsigned long int global_unsignedLongInt;

unsigned long long int global_unsignedLongLongInt;

// Floating-point types
float global_float;

double global_double;

long double global_longDouble;

// Boolean type
bool global_bool;

// Void type
void *global_void;

// Null pointer
decltype(global_char) global_decltype;

template <class T1, class T2, class T3>
void printValue(T1 &dataType, T2 &localVar, T3 &globalVar)
{
    cout << "Data type : " << setw(23) << left << dataType << " local value " << setw(23) << left << localVar
         << " global value " << setw(2) << left << globalVar << endl;
}

int main()
{

    cout << "Display the value of local and global variables when they are not initialized" << endl
         << endl;
    // Character types
    char _char;
    printValue("char", _char, global_char);

    char16_t _char16_t;
    printValue("char16_t", _char16_t, global_char16_t);

    char32_t _char32_t;
    printValue("char32_t", _char32_t, global_char32_t);

    wchar_t _wchar_t; // variable length, at init only 2 bytes
    printValue("wchar_t", _wchar_t, global_wchar_t);

    // Integer types (signed)
    signed char _signedChar;
    printValue("signed char", _signedChar, global_signedChar);

    signed short int _signedShortInt;
    printValue("signed short int", _signedShortInt, global_signedShortInt);

    signed int _signedInt;
    printValue("signed int", _signedInt, global_signedInt);

    signed long int _signedLongInt;
    printValue("signed long int", _signedLongInt, global_signedLongInt);

    signed long long int _signedLongLongInt;
    printValue("signed long long int", _signedLongLongInt, global_signedLongLongInt);

    // Integer types (unsigned)
    unsigned char _unsignedChar;
    printValue("unsigned char", _unsignedChar, global_unsignedChar);

    unsigned short int _unsignedShortInt;
    printValue("unsigned short int", _unsignedShortInt, global_unsignedShortInt);

    unsigned int _unsignedInt;
    printValue("unsigned int", _unsignedInt, global_unsignedInt);

    unsigned long int _unsignedLongInt;
    printValue("unsigned long int", _unsignedLongInt, global_unsignedLongInt);

    unsigned long long int _unsignedLongLongInt;
    printValue("unsigned long long int", _unsignedLongLongInt, global_unsignedLongLongInt);

    // Floating-point types
    float _float;
    printValue("float", _float, global_float);

    double _double;
    printValue("double", _double, global_double);

    long double _longDouble;
    printValue("long double", _longDouble, global_longDouble);

    // Boolean type
    bool _bool;
    printValue("bool", _bool, global_bool);

    // Void type
    void *_void;
    printValue("void", _void, global_void);

    // Null pointer
    decltype(_char) _decltype;
    printValue("decltype", _decltype, global_decltype);

    return 0;
}
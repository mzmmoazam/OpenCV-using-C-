// author : Mohammad Moazam
// Exercise 6 - Q1
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

// class to represent and manipulate Complex numbers
class Complex
{

private:
    double a, b;

public:
    Complex(int a = 0, int b = 0) : a(a), b(b) {}

    void setCoord(double a, double b);

    void setPolar(double r, double theta);

    const double getImag() const;

    const double getReal() const;

    const double getMod() const;

    const double getAngle() const;
};

void Complex ::setCoord(double a_in, double b_in)
{
    a = a_in;
    b = b_in;
}

void Complex ::setPolar(double r, double theta)
{
    a = r * cos(theta);
    b = r * sin(theta);
}

const double Complex ::getImag() const
{
    return b;
}

const double Complex ::getReal() const
{
    return a;
}

const double Complex ::getMod() const
{
    return sqrt(a * a + b * b);
}

const double Complex ::getAngle() const
{
    return atan(b / a);
}

void print(const Complex &Complex) 
{
    cout << "Coordinate system : " << Complex.getReal() << " + i" << Complex.getImag() << endl;
}

// Class for an array of complex numbers
class ArrayComplex
{

private:
    int size;
    Complex *ptrArrayComplex;

public:
    ArrayComplex()
    {
        size = 0;
    }

    ArrayComplex(const ArrayComplex &arrayComplex)
    {
        // set size to 0
        size = 0; 
        Alloc(arrayComplex.getSize());
        memcpy(ptrArrayComplex,arrayComplex.getCompArr(),size*sizeof(Complex));
    }

    const int getSize() const
    {
        return size;
    }

    const Complex *getCompArr() const
    {
        return ptrArrayComplex;
    }

    const Complex &ValueAt(int index) const
    {
        if (index > size)
        {
            cout << "Index out of bounds \nReturning the first element" << endl;
            return ptrArrayComplex[0];
        }

        return ptrArrayComplex[index];
    }

    Complex &ValueAt(int index)
    {
        if (index > size)
        {
            cout << "Index out of bounds \nReturning the first element" << endl;
            return ptrArrayComplex[0];
        }

        return ptrArrayComplex[index];
    }

    void Alloc(int new_size)
    {
        if (size)
        {
            Free();
        }
        size = new_size;
        ptrArrayComplex = new Complex[new_size];
    }

    void Free()
    {
        if (size)
        {
            delete[] ptrArrayComplex;
            size = 0;
            return;
        }
    }

    //  ValueAt using operator overloading
    const Complex &operator[](int index) const
    {
        if (index > size)
        {
            cout << "Index out of bounds \nReturning the first element" << endl;
            return ptrArrayComplex[0];
        }

        return ptrArrayComplex[index];
    }

    Complex &operator[](int index)
    {
        if (index > size)
        {
            cout << "Index out of bounds \nReturning the first element" << endl;
            return ptrArrayComplex[0];
        }

        return ptrArrayComplex[index];
    }

    //   helper functions

    // fill rand values in the complex array
    void populateArray()
    {
        for (int i = 0; i < size; i++)
        {
            ptrArrayComplex[i].setCoord(rand() % 10, rand() % 100);
        }
    }

    // print the complex array
    void printArray() const
    {
        for (int i = 0; i < size; i++)
        {
            print(ptrArrayComplex[i]);
        }
    }

    ~ArrayComplex()
    {
        Free();
    }
};

int main()
{
    // declare the object for ArrayComplex
    ArrayComplex arrayComplex1;

    // arrayComplex1 = ArrayComplex();

    //  alloc memory for 5 complex numbers
    arrayComplex1.Alloc(5);

    // fill random values
    arrayComplex1.populateArray();

    // display the array
    arrayComplex1.printArray();

    cout << endl
         << "use Copy constructor to copy data >> " << endl;

    // use Copy constructor to copy data
    ArrayComplex arrayComplex2 = arrayComplex1;

    // display the arrayComplex2 results
    arrayComplex2.printArray();

    cout << endl
         << "Allocate new memory to the object and populate it>> " << endl;

    // Allocate fresh 10 memory
    arrayComplex2.Alloc(10);

    // fill rand values
    arrayComplex2.populateArray();

    // display contents of the object
    arrayComplex2.printArray();

    // declare a complex object
    Complex complexNumber;

    // set equal to the value at index 1 in the array
    complexNumber = arrayComplex2.ValueAt(1);

    cout << endl
         << "Complex object in arraycomplex AtIndex == 1 >> " << endl;

    // display te complex number
    print(complexNumber);

    cout<< endl << "Same thing using operator overloading" << endl;

    // verify the same concept with operator overloading
    print(arrayComplex2[1]);

    // declare another complex object
    Complex complexNumber2 = Complex();

    // set it to 1+1i
    complexNumber2.setCoord(0, 0);

    cout << endl << "Set value in arrayComplex AtIndex == 1; complex no = 0 + 0i " << endl ;
    // change the value in arrayComplex2
    arrayComplex2.ValueAt(1) = complexNumber2;

    // display the results
    arrayComplex2.printArray();

    // change the values of the complex object
    complexNumber2.setCoord(1, 1);

    // verify by display
    print(complexNumber2);

    cout << endl << "Set value in arrayComplex AtIndex == 1 using operator overloading; complex no = 1 + 1i " << endl ;

    // using operator overloading change the value in arrayComplex2
    arrayComplex2[1] = complexNumber2;

    // display to verify
    arrayComplex2.printArray();
}
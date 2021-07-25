// author : Mohammad Moazam
// Exercise 5 - Q1
#include <iostream>
#include <math.h>

using namespace std;

class Complex_coord
{

private:

    double a, b;

public:
    void setCoord(double a, double b);

    void setPolar(double r, double theta);

    double getImag() const;

    double getReal() const;

    double getMod() const;

    double getAngle() const;
};

void Complex_coord ::setCoord(double a_in, double b_in)
{
    a = a_in;
    b = b_in;
}

void Complex_coord ::setPolar(double r, double theta)
{
    a = r * cos(theta);
    b = r * sin(theta);
}

double Complex_coord ::getImag() const
{
    return b;
}

double Complex_coord ::getReal() const
{
    return a;
}

double Complex_coord ::getMod() const
{
    return sqrt(a * a + b * b);
}

double Complex_coord ::getAngle() const
{
    return atan(b / a);
}

void print(const Complex_coord  &complex_coord)
{
    cout << "Coordinate system : " << complex_coord.getReal() << " + i" << complex_coord.getImag() << endl;
}

class Complex_polar
{
    double r, theta;

public:
    void setCoord(double a, double b);

    void setPolar(double r, double theta);

    double getImag() const;

    double getReal() const;

    double getMod() const;

    double getAngle() const;
};

void Complex_polar ::setCoord(double a, double b)
{
    r = sqrt(a * a + b * b);
    theta = atan(b / a);
}

void Complex_polar ::setPolar(double r_in, double theta_in)
{
    r = r_in;
    theta = theta_in;
}

double Complex_polar ::getImag() const
{
    return r * sin(theta);
}

double Complex_polar ::getReal() const
{
    return r * sin(theta);
}

double Complex_polar ::getMod() const
{
    return r;
}

double Complex_polar ::getAngle() const
{
    return theta;
}

void print(const Complex_polar &complex_polar)
{
    cout << "Polar system : " << complex_polar.getMod() << "(cos(" << complex_polar.getAngle() << ") + i * sin(" << complex_polar.getAngle() << "))" << endl;
}

int main()
{
    Complex_coord complex_coord = Complex_coord();

    complex_coord.setCoord(5, 2);

    // complex_coord.setPolar(5.38516, 0.380506);

    print(complex_coord);

    cout << "Real " << complex_coord.getReal() << endl;
    cout << "angle " << complex_coord.getAngle() << endl;
    cout << "imag " << complex_coord.getImag() << endl;
    cout << "mod " << complex_coord.getMod() << endl;

    cout << endl
         << endl
         << endl;

    Complex_polar complex_polar = Complex_polar();

    // complex_polar.setCoord(5,2);

    // complex_coord.setPolar(5.38516, 0.380506);

    complex_polar.setPolar(complex_coord.getMod(), complex_coord.getAngle());

    print(complex_polar);

    cout << "Real " << complex_polar.getReal() << endl;
    cout << "angle " << complex_polar.getAngle() << endl;
    cout << "imag " << complex_polar.getImag() << endl;
    cout << "mod " << complex_polar.getMod() << endl;

    return 0;
}
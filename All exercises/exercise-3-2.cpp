// author : Mohammad Moazam
// Exercise 3 - Q2
#include <iostream>
using namespace std;

inline int getMinalue(int x,int flag){
    if (flag)
        return x < 1234567 ? 1234567 : x;
    else
        return x < 1000 ? 1000 : x;
}

enum flags{Integer, Double};

int main()
{
    int n,m;

    cout << "Enter an integer value (n) for an integer array : ";

    cin >> n;

    cout << "Enter an integer value (n) for an double array : ";

    cin >> m;

    int *dyInt = new int [getMinalue(n,Integer)];

    double *dyDouble = new double [getMinalue(m,Double)];

    if (n < 1000 || m < 123567)
        cout << "\nThe program has upgraded your values...";

    cout << "\n\nThis program just dynamically allocated  an integer array of " << getMinalue(n,Integer) << " elements.\n\n";
    cout << "\n\nThis program just dynamically allocated  a double array of " << getMinalue(n,Integer) << " elements.\n\n";

}
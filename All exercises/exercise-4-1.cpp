// author : Mohammad Moazam
// Exercise 4 - Q1
#include <iostream>
using namespace std;

void minMax(int a[], int n){
    int min ,max;

    min = max = a[0];

    for(int i = 1; i < n;i++){
        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }

    cout << "The max is " << max << endl;

    cout << "The min is " << min << endl;

}

int main()
{   
    int n = 3;

    cout << "Enter three integers \n\n";

    int x[n];

    for (int i=0; i<n;i++){
        cout <<"\nEnter the "<< i+1 << (i  ? "nd" : "st")  <<" integer : ";
        cin >> x[i];
    }

    minMax(x,n);
    

}

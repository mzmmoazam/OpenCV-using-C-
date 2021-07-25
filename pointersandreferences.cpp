// pointer and references
// complete this program

#include <iostream>

using namespace std;

void displayArrayInt ( const int array[], unsigned int size )
{

    cout << "The elements of the array are : " << endl;
    for (int i=0;i<size;i++)
        cout << array[i] << "\t";
    cout <<endl;

}

void allocAndInitArrayInt ( int  * &array, unsigned int size )
{
    array = new int [size];
    for (int i=0;i<size;i++)
        array[i] = rand()%100;
}

inline void swap(int &x, int &y){
    x = x + y;
    y = x - y;
    x = x - y;
}

void sortArrayInt ( int  * &array, unsigned int size )
{
        for (int i=0;i<size;i++)
            for (int j=0;j<size;j++)
                if (array[i] < array[j])
                    swap(array[i],array[j]); 

}

int main ( void )
{
    int* arrayInt;
    int arraySize;

    cin >> arraySize;

    allocAndInitArrayInt ( arrayInt, arraySize );
    displayArrayInt ( arrayInt, arraySize );
    sortArrayInt ( arrayInt, arraySize );
    displayArrayInt ( arrayInt, arraySize );

    return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;

struct bigStruct
{
int array[200];
int size = 200;
};


void displayBigStruct ( const bigStruct  myBig )
{
    cout << "The size of the arr : " << myBig.size <<endl;

    unsigned int counter = 0;

    for (int i=0;i<10;i++){
        for (int j=0;j<myBig.size/10;j++)
            cout << setw(5) << myBig.array[counter++];
        cout << endl;
    }

}

void populate(bigStruct &myBig){
    for (int i=0; i< 200;i++)
        myBig.array[i] = 0;
}

int main ( void )
{
    bigStruct myBig;

    populate(myBig);

    displayBigStruct ( myBig );

    return 0;
}
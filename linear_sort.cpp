#include<iostream>  

using namespace std;

int main(){
    int a[50],n,i,j,temp;

    cout << "Enter the number of elements ?" << endl;
    cin >> n;

    cout << "Enter the " << n << " numbers :" << endl;
    for(i=0;i<n;i++){
        cin >> a[i];
    }

    cout << "Here is the list of numbers" << endl;
    for (i=0;i<n;i++){
        cout << a[i] << " ";
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
                if ( a[i] < a[j] ){
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                }
    cout << "Here is the list of sorted numbers" << endl;
    for (i=0;i<n;i++){
        cout << a[i] << " ";
    }

    cout << endl;

return 0;
}
#include <iostream>

// divide and conquer
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int a[], int l, int m, int r)
{

    int leftn = m - l + 1, rightn = r - m;
    int L[leftn], R[rightn], i = 0, j = 0, k = l;

    for (i = 0; i < leftn; i++)
        L[i] = a[l + i];

    for (j = 0; j < rightn; j++)
        R[j] = a[m + j + 1];
    i = 0, j = 0, k = l;

    while (i < leftn && j < rightn)
    {
        if (L[i] < R[j])
            a[k] = L[i], i++;
        else
            a[k] = R[j], j++;

        k++;
    }

    if (i < leftn)
        a[k] = L[i], i++, k++;

    if (j < rightn)
        a[k] = R[j], j++, k++;
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {

        int m = (l + r - 1) / 2;

        // cout << l << "knkn" << r << "rrrr" << m << "mmm";

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{

    int a[50], n, i, j, temp;

    cout << "Enter the number of elements ?" << endl;
    cin >> n;

    cout << "Enter the " << n << " numbers :" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Here is the list of numbers" << endl;
    printArray(a, n);

    mergeSort(a, 0, n);

    printArray(a, n);

    cout << endl;
    return 0;
}
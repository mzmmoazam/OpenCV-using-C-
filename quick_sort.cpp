#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{

    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high], i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int ipivot = partition(arr, low, high);

        quickSort(arr, low, ipivot - 1);
        quickSort(arr, ipivot + 1, high);
    }
}

int main()
{
    int arr[] = {1, 90, 4, 5, 9};
    int n = 5;
    cout << "Unsorted array..." << endl;
    printArr(arr, n);

    quickSort(arr, 0, 4);
    cout << "Sorted array..." << endl;

    printArr(arr, n);
}
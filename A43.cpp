#include<iostream>
using namespace std;
void insertionSort(int arr[], int n,int &comparison,int &swaps)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        comparison++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        swaps++;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = { 97,7,82,18,45};
    int N = sizeof(arr) / sizeof(arr[0]);
    int comparison = 0, swaps = 0;
    insertionSort(arr, N,comparison, swaps);
    printArray(arr, N);
    cout << "Number of comparison: " << comparison << endl;
    cout << "Number of swaps: " << swaps << endl;
    return 0;
}
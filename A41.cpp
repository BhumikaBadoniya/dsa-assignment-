#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n, int &comparison, int &swaps)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            comparison++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {8, 6, 4, 7};
    int S = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0, swaps = 0;
    bubbleSort(arr, S, comparisons, swaps);
    cout << "sorted array: \n";
    printArray(arr, S);
    cout << "Number of comparison: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;
    return 0;
}
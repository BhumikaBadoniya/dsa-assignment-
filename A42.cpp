#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void selectionSort(int arr[], int n,int &comparison,int &swaps)
{
    int i,j,min_in;
    for(i=0;i<n;i++)
    {
        min_in = i;
        for(j=i+1;j<n;j++){
            comparison++;
            if (arr[j] < arr[min_in])
                min_in = j;
        swap(arr[i],arr[min_in]);
        swaps++;
        }
    }
}
int main()
{
    int arr[] = {65,25,41,87,95};
    int i,j,n,temp;
    int comparison= 0,swaps =0;
    n = sizeof(arr)/sizeof(int);

    cout<<"Unsorted Array :";
    print(arr,n);
    selectionSort(arr,n,comparison,swaps);
    cout<<"Sorted Array :";
    print(arr,n);
    cout << "Number of comparison: " << comparison << endl;
    cout << "Number of swaps: " << swaps << endl;

    return 0;
}

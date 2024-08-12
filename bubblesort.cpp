#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
    if(arr[j]>arr[j+1])
    swap (arr[j],arr[j+1]);
}
 void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[]={ 8, 6, 4, 7};
    int S= sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,S);
    cout<<"sorted array: \n"  ;
    printArray(arr,S);
    return 0;
}
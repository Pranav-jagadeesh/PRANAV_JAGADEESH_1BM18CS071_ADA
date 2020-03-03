#include<iostream>
using namespace std; 
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
// A function to print an array of size n  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  
int main()  
{  
    int n,i=0; 
    cout<<"\nEnter size of array";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array elements:";
    for(i=0;i<n;i++)
    cin>>arr[i];
  
    insertionSort(arr, n);  
    printArray(arr, n);  
  
    return 0;  
}  
  

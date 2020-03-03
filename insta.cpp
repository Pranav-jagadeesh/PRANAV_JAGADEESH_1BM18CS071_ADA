//PRANAV_JAGADEESH_1BM18CS071_ADA

#include<iostream>
#include<time.h>

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
    double x;
    clock_t start,end;
    cout<<"\nEnter size of array:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array elements:";
    for(i=0;i<n;i++)
    cin>>arr[i];
    start=clock();
    insertionSort(arr, n);  
    end=clock();
    printArray(arr, n);  
    
    x=(double)(end-start)/(CLOCKS_PER_SEC);
    cout<<"\nTime taken:"<<x<<"\n";
    return 0;  
}  

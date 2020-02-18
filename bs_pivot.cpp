//PRANAV_JAGADEESH_1BM18CS071_ADA

#include <iostream> 
using namespace std;  
int search(int arr[], int l, int h, int key) 
{ 
    if (l > h) return -1; 
  
    int mid = (l+h)/2; 
    if (arr[mid] == key) return mid; 
    if (arr[l] <= arr[mid]) 
    { 
  
        if (key >= arr[l] && key <= arr[mid]) 
        return search(arr, l, mid-1, key); 
        return search(arr, mid+1, h, key); 
    } 
  
    if (key >= arr[mid] && key <= arr[h]) 
        return search(arr, mid+1, h, key); 
  
    return search(arr, l, mid-1, key); 
} 
  
int main() 
{ 
int n,key,i;
    cout<<"enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter array elements: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"enter key element: ";
    cin>>key;
    i = search(arr, 0, n-1, key); 
  
    if (i != -1) 
    cout << "Index: " << i+1 << endl; 
    else
    cout << "Key not found"; 
} 

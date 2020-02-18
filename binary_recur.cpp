#include<iostream>
#include<time.h>
using namespace std;
int a[100];
int binary(int k,int first,int last)
{
  int mid;
  mid=(first+last)/2;
     if(first<=last)
     {
    	if(a[mid] == k)
        {
 	      cout<<"Key element is found at the position "<<mid+1<<endl;
 	      return 0;
 	    }
 	   else if(k<a[mid])
	    binary(k,first,mid-1);
	   else
	    binary(k,mid+1,last);
     }
     else
     {
      cout<<"The key element is not fount"<<endl;
      return 0;
     }
}
   
int main()
{
	int n,first=0,key;
	double x;
  	clock_t start,end;
	cout<<"Enter the number of elements in array"<<endl;
	cin>>n;
        int last=n-1;
	cout<<"Enter all "<< n <<" elements of array"<<endl;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	cout<<"Enter the key element you wish to search"<<endl;
	cin>>key;
	start=clock();
	binary(key,first,last);
	end=clock();
	x=(double)(end-start)/CLOCKS_PER_SEC;
        cout<<"Time taken = "<<x<<endl;
}

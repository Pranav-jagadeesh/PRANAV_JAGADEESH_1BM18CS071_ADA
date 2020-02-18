//PRANAV_JAGADEESH_1BM18CS071_ADA

#include<iostream>
using namespace std;
int a[100];

int linear(int n,int k,int i)
{
     if(i<n)
     {
	if(a[i]==k)
        {
	 cout<<"The key element is found at the position "<<i+1<<endl;
  	 return 0;
	}
	else
	{
         linear(n,k,i+1);
        }
     }
    else
    {
     cout<<"The key element is not found"<<endl;
     return 0;
    }
}
         	
int main()
{
        int n,key,i=0,start,end;
	double x;
	cout<<"Enter the number of elements in array"<<endl;
	cin>>n;
	cout<<"Enter all "<< n <<" elements of array"<<endl;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	cout<<"Enter the key element you wish to search"<<endl;
	cin>>key;
  i=0;
        start=clock();
	linear(n,key,i);
	end=clock();
	x=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Time taken = "<<x<<endl;
}

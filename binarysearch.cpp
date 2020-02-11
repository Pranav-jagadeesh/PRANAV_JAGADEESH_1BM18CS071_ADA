/*Given a sorted array with repeating integers ,u need to find the first occurence ,last occurence and count of a given key in the array .Use only binary search,ur algorithm should run in log n time.if element is not present print -1.*/


#include<iostream>
using namespace std;
int main()
{
int n,a[100],key,first,last,mid,count=0,m,k;
cout<<"Enter the number of elements in array"<<endl;
cin>>n;
cout<<"Enter SORTED "<< n <<" elements of array"<<endl;
for(int i=0;i<n;i++)
cin>>a[i];
cout<<"Enter the key element you wish to search"<<endl;
cin>>key;
first=0;
last=n-1;
while(first<=last)
{
mid=(first+last)/2;
if(a[mid]==key)
{
 count++;
 break;
}
else if(key<a[mid])
 last=mid-1;
else
 first=mid+1;
}
if(count==0)
{
   cout<<"The key element "<<key<<" is not found"<<endl;
}
m=mid;
while(1)
{
m=m+1;
if(a[m]==key && m<n)
{
 count++;
}
else
 break;
}
k=mid;
while(1)
{
k=k-1;
if(a[k]==key && k>=0)
{
 count++;
}
else
 break;
}
cout<<"Key element is found from "<<k+2<<" to "<<m<<endl;
cout<<"The key element "<< key <<" is found "<<count<<" times";
}


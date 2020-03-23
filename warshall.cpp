//PRANAV_JAGADEESH_1BM18CS071_ADA
#include<iostream>
using namespace std;
int a[10][10],n;
void warshall()
{
int i,j,k;
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(a[i][j]!=1)
{
if(a[i][k]==1 && a[k][j]==1)
a[i][j]=1;
}
}
int main()
{
int i,j;
cout<<"Enter no of nodes : ";
cin>>n;
cout<<"Enter adjacency matrix : \n";
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
cin>>a[i][j];
warshall();
cout<<"Transitive closure :\n";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
cout<<a[i][j]<<"\t";
cout<<endl;
}
return 0;
}

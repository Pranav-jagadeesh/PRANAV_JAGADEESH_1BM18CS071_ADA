#include <stdio.h>

int euclid(int m,int n)
{
 int r;
 while(n!=0)
 {
  r=m%n;
  m=n;
  n=r;
 }
 return m;
}
 
int euclid_rec(int m,int n)
{
 if(n==0)
  return m;
 else
  return euclid_rec(n,m%n);
}

int repitative_subraction(int m,int n)
{
 while(m!=n)
 {
  if(m>n)
   m=m-n;
  else
   n=n-m;
 }
return m;
}
 
int repitative_subraction_rec(int m,int n)
{
 if(m==n)
  return m;
 else
 {
  if(m>n)
   return repitative_subraction_rec(m-n,n);
  else
   return repitative_subraction_rec(m,n-m);
 }
}
   

int consicutive_integer(int m,int n,int small)
{
 while(1)
 if(m%small==0 && n%small==0)
  return small;
 else
 {
  small=small-1;
  m=m%small;
  n=n%small;
 }
}

int consicutive_integer_rec(int m,int n,int small)
{
 if(m%small==0 && n%small==0)
  return small;
 else
  return consicutive_integer_rec(m%small,n%small,small-1);
}
 

int middle_school(int a,int b)
{
  int c,ans=1;
  c=b>a?a:b;
  for(int i=2;i<=c;i++)
  {
   int n=0,m=0;
   if(a%i==0)
   {
    a=a/i;
    n=1;
   }
   if(b%i==0)
   {
    b=b/i;
    m=1;
   }
   if(n==1 && m==1)
    ans=ans*i;
   if(n==1 || m==1)
    i=i-1;
  }
 return ans;
   
}

void main()
{
 int a,b,n,x;
 printf("Enter the two numbers \n");
 scanf("%d%d",&a,&b);
 printf("Enter 1: for Euclid's method\nEnter 2: for Repitative subtraction method\nEnter 3: for Consicutive integer checking method\nEnter    4: for Middle school method\nEnter 5: for Euclid's reccursive method\nEnter 6: for Repitetive subtraction reccursive method\nEnter 7: for Consicutive integer reccursive method\n");
 scanf("%d",&n);
 switch(n)
 {
  case 1 :x=euclid(a,b);
          printf("GCD = %d",x);
          break;
  case 2 :x=repitative_subraction(a,b);
          printf("GCD = %d",x);
          break;
  case 3 :if(a<=b)
           x=consicutive_integer(a,b,a);
          else
           x=consicutive_integer(a,b,b);
          printf("GCD = %d",x);
          break;
  case 4 :x=middle_school(a,b);
          printf("GCD = %d",x);
          break;
  case 5 :x=euclid_rec(a,b);
          printf("GCD = %d",x);
          break;
  case 6 :x=repitative_subraction_rec(a,b);
          printf("GCD = %d",x);
          break;
  case 7 :if(a<=b)
           x=consicutive_integer_rec(a,b,a);
          else
           x=consicutive_integer_rec(a,b,b);
          printf("GCD = %d",x);
          break;
 }
}



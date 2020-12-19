						//#Created by Nitish Arya(1061) Program for reversing a string recursively.
#include<iostream> 							         			 
using namespace std;
char reverse(char C[20],int l,int m)
{ char A;
  int len;
  len=m;
  if(l<=len/2)
  {A=C[l];
  C[l]=C[m-1];
  C[m-1]=A;
  l++;
  m--;
  reverse(C,l,m);};
  return C[20];
 }
 int main()
 { char A[20];
   int a;
   cout<<"Enter a string to reverse it:";
   cin>>A;
   for(a=0;A[a]!='\0';a++);
   A[20]=reverse(A,0,a);
   cout<<"\nReversed string is:"<<A;
 }

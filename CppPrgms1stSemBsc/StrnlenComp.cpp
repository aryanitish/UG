							//#Created by Nitish Arya(1061) Program for comaparing two strings by length.
#include<iostream> 					         			 
using namespace std;
int main()
{ char A[20],B[20];
   int i,j;
   cout<<"Enter String one:";
   cin>>A;
   cout<<"\nEnter String two:";
   cin>>B;
   for(i=0;A[i]!='\0';i++);
   for(j=0;B[j]!='\0';j++);
   if(i>j)
   cout<<"\nString one is greater in length than String two.";
   else if(i==j)
   cout<<"\nBoth Strings are of equal length.";
   else
   cout<<"\nString two is greater in length than String one.";
 }
   

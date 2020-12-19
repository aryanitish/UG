							//#Created by Nitish Arya(1061) Program for comaparing two strings by character.
#include<iostream> 					         			 
using namespace std;
int main()
{ char A[20],B[20];
   int i,j,flag=0;
   cout<<"Enter String one:";
   cin>>A;
   cout<<"\nEnter String two:";
   cin>>B;
   for(i=0,j=0;(A[i]!='\0')||(B[i]!='\0');i++,j++)
   { if(A[i]!=B[i])
     {  
       cout<<"\nString one differs from string two at position "<<i+1;
       cout<<"\nString one has character: '"<<A[i]<<"' and "<<"String two has character: '"<<B[i]<<"'";
       flag=1;
     }
   }
   if(flag==0)
   cout<<"\nBoth string have same characters at same positions!";
}

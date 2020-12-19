#include<iostream>          			//#Created by Nitish Arya(1061) Program to find a substring in a string.
using namespace std;
int main()
{ char A[20],B[20];
  int i,j,k,len,str,n;
   cout<<"Enter a string:";
   cin>>A;
   for(i=0;A[i]!='\0';i++);
   cout<<"\nEnter a substring:";
   cin>>B; 
   for(len=0;B[len]!='\0';len++);
   for(j=0,k=0;n!=len;j++,k++)
   { if(A[j]!=B[k])
	   {k--;str=j+2;n=0;}
	else  n++;
   }
   if(n==len)
   cout<<"\nSubstring found at position:\t"<<str<<"\tupto\t"<<str+n;
 }
	   
	 
	   
		   
		   
		   

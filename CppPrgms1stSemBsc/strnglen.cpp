#include<iostream>          			//#Created by Nitish Arya(1061) Program to find the length of a string.
using namespace std;
int main()
{ char A[20];
  int i,len=0;
  cout<<"Enter a string to find its length:";
  cin>>A;
  for(i=0;i<20;i++)
  { if(A[i]=='\0')
      break;
    len ++; 
  }
  cout<<"\nLength of the given string is:"<<len;
}  

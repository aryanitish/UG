						//#Created by Nitish Arya(1061) Program for printing all permutations of characters in a string.
#include<iostream>			         			 
using namespace std;

int main()
{ 
  char A[20];
  int i,j,k=0;
  cout<<"Enter a string:";
  cin>>A;
  for(i=0;A[i]!=0;i++);
  do
  { if(k==0)
	       cout<<"\nStrings starting with"<<k+1<<"st character are:\n"; 
    else if(k==1)
           cout<<"\nStrings starting with"<<k+1<<"nd character are:\n";
    else if(k==2)
           cout<<"\nStrings starting with"<<k+1<<"rd character are:\n";
     else  
           cout<<"\nStrings starting with"<<k+1<<"th character are:\n";
   
   for(j=0;A[j]!='\0';j++)
      { 
		 cout<<"\nString of length"<<j+1<<"is:"; 
	    for(int z=k;z<j+1;z++)
         { 
		  cout<<A[z];
		  
         }
      }
    cout<<"\n";
    k++;
   }while(k!=i);
}

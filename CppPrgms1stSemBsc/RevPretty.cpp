 						//#Created by Nitish Arya(1061) Program for  reverse of Pretty printing.
#include<iostream> 							         			 
using namespace std;
int main()
{ char A[20],a;
  int x;
  cout<<"Enter a string for reverse pretty printing:";
  cin>>A;
  cout<<"\nEnter special character and gap :";
  cin>>a>>x;
  for(int i=0;A[i]!='\0';i++)
  {  if(!(i%x==0))
      A[i]=a;
  }
  cout<<"\nRequired string is:"<<A; 
}

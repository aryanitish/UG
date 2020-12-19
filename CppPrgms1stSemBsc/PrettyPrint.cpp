						//#Created by Nitish Arya(1061) Program for Pretty printing.
#include<iostream> 							         			 
using namespace std;
int main()
{ char A[20],a,B,C;
  int x;
  cout<<"Enter a string for pretty printing:";
  cin>>A;
  cout<<"\nEnter special character and gap after which you want to insert it in your string:";
  cin>>a>>x;
  for(int i=0;A[i]!='\0';i=i+x)
  {  B=A[i];
     A[i]=a;
     for(int j=i+1;A[j]!=0;j=j+2)
     { C=A[j];
       A[j]=B;
       B=A[j+1];
       A[j+1]=C;
     }
  }
  cout<<"\nRequired string is:"<<A;
}

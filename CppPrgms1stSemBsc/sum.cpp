   //Program for printing a table according to the number of rows and columns given by the user;
   //#Created by Nitish Arya on 25 September 2017;

#include<iostream>   
#include<stdio.h>
using namespace std;
int main()
{int a,b,i,y,z,flag=1;
  char q,r;
  y=95;q=y;
  z=124;r=z;
  cout<<"Enter the no of rows\n";
  cin>>a;
  cout<<"Enter the no of columns\n";
  cin>>b;
  for(i=0;i<a;i++)
  { cout<<"\n";
	  for(int k=0;k<b;k++)
	  { if((k==0)&&(flag==1))
		  {for(int j=0;j<b;j++){cout<<" "<<q;}cout<<"\n";
		  flag=0;}
		  cout<<r<<q;}  
	cout<<r;  
  }
}

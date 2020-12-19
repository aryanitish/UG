#include<iostream>          			//#Created by Nitish Arya(1061) Program for printing a star triangle pattern.
using namespace std;
int main()
{ int len,j;
  cout<<"Enter No of lines upto which star trianlge is to be printed:\n";
  cin>>len;
  len=len-1;
  for(int i=0;i<=len;i++)
  {for(j=len-i;j>=0;j--)
	  {cout<<" ";}
	for(j=0;j<=2 * i;j++)
	   {cout<<"*";}
	cout<<"\n";
   }
}

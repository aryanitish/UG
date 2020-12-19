#include<iostream>          			//#Created by Nitish Arya(1061) Program to find the sum of an AP.
using namespace std;
int main()
{ 
  float a,d,sum=0;
  int n;
  cout<<"Enter the first term of the AP whose sum you want to find out:";
  cin>>a;
  cout<<"\nEnter common difference of the AP:";
  cin>>d;
  cout<<"\nEnter the number of terms of the AP or the number of terms upto which the sum is required:";
  cin>>n;
  sum=(n/2)*((2* a)+(n-1)* d);
  cout<<"\nSum of the AP is:"<<sum<<"\n";
 }
  

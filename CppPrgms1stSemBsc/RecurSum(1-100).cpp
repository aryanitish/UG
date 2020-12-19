					//#Created by Nitish Arya(1061) Program for finding sum of first 100 natural numbers recursively.
#include<iostream> 							         			 
using namespace std;
int sum(int a)
{ int sm=a;
  if(a!=0)
  sm=sm + sum(a-1); 
  return sm;
}
int main()
{ cout<<"Sum of first 100 natural numbers is:\t"<<sum(100);}

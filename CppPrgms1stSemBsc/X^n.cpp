						//#Created by Nitish Arya(1061) Program for calculating x^n using recursion for n belongs to Z(+/-).
#include<iostream> 							         			 
using namespace std;
float pow(float a, int b)
{ int d;
	float c;
	c=a;
  if(b<0)
   d=(-b);
   else d=b;
  if(d!=1)
    {c=c * a;
    pow(c,d-1);}
  if(b>0)
   c=c;
   else
   c=1/c; 
   return c;
}



int main()
{ int x,n;
  cout<<"Enter a number:";
  cin>>x;
  cout<<"\nEnter its power:";
  cin>>n;
  cout<<"\nResult is:\t"<<pow(x,n);
}

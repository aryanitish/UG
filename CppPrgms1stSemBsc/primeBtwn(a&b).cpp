							//#Created by Nitish Arya(1061) Program for finding prime numbers between a and b. 
#include<iostream>  
using namespace std;
int x,a,b;
int fun(int x)
{  int j=0;
   while((j * j)<= x)
   {j++;}
	return j;
 }
int prime(int &a,int &b)
{ 
  int flag,i;
  cout<<"\nPrime numbers between\t"<<a<<"\tand\t"<<b<<"\tare:\n";
  for(int x=a;x<=b;x++,flag=0)
  { i=5;
   if((x%2==0)&&(x!=2))
   flag=1;
   else if((x%3==0)&&(x!=3))
   flag=1;
   else 
   {
     { while((i<=fun(x))&&(flag==0))
      {if(x%i==0)
      flag=1;
      i++;
      }
     } 
   }
   if(flag==0)
   cout<<x<<"\n"; 
  }
  return 0;
}
int main()
{ 
  cout<<"Enter two numbers between which you want to find all the primes"<<"\nEnter the first number:";
  cin>>a;
  cout<<"\nEnter the second number:";
  cin>>b;
  prime(a,b);
  return 0;
}

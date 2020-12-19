#include<iostream>          			//#Created by Nitish Arya(1061) Program to check whether a number is prime or not.
using namespace std;
int x;
int fun(int x)
{  int j=0;
   while((j * j)<= x)
   {j++;}
	return j;
 }
int main()
{ 
  int flag=0,i=5;
  cout<<"Enter a number to check whether it is prime or not:";
  cin>>x;
  if((x%2==0)&&(x!=2))
  {cout<<"\nThe number is not a prime!!!"; }
  else if((x%3==0)&&(x!=3))
  {cout<<"\nThe number is not a prime!!!"; }
  else
   {
     { while((i<=fun(x))&&(flag==0))
        {if(x%i==0)
      flag=1;
      i++;} 
     }
  if(flag==1)
   cout<<"\nThe number is not a prime!";
  else
    cout<<"\nThe number is a prime!!!"; 
   }
}
 

 

					//#Created by Nitish Arya(1061) Program for calculating Sine of an angle in degree upto 6 decimal places.
#include<iostream> 							
#include<math.h>         			 
using namespace std;
int main()
{ float sum,term,x;
  int n=1,d=1;
  sum=0;
  cout<<"Enter the angle to find its sine:";
  cin>>x;
  x=(3.141592/180)*x;
  term=x;
  while(fabs(term)>0.000001)
  { if(n==1)
    term=x;
    else
    {
      term= (term * x * x * (-1))/(d * 2 * n * ((2 * n)+1));
      d=d * 2 * n * ((2 * n)+1);
    } 
    sum=sum+term;
    n++;
  }
  cout<<"\nSine of input value is:\t"<<sum;
}

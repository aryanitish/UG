					//#Created by Nitish Arya(1061) Program for calculating exponential power of a number.
#include<iostream> 							
#include<math.h>      
#define e 2.71828;   			 
using namespace std;
 
int main()
{ float sum,term,x;
	int n=2;
  cout<<"Enter the number to find its exponential power(i.e e^x):";
  cin>>x;
  sum=1+x;
  term=x;
  if(x==0)
	  sum=1;
    else if(x==1)
    {sum=e;}
    else
    {
      while(fabs(term)>0.000001)
        {
		  term=(term*x)/(n);
          sum=sum+term;
           n++;
         }
     }
   cout<<"\ne^"<<x<<"is: "<<sum; 
}   

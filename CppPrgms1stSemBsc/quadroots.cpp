						//#Created by Nitish Arya(1061) Program for finding roots of a quadratic equation.
#include<iostream> 	
#include<math.h>						         			 
using namespace std;
int main()
{ float a,b,c,x,root1,root2,val;
  cout<<"Enter a quadratic equation in the form a(x^2)+b(x)+c:";
  cout<<"\nEnter a:";
  cin>>a;
  cout<<"\nEnter b:";
  cin>>b;
  cout<<"\nEnter c:";
  cin>>c;
  if((b * b)-(4 * a * c)>=0)
  { cout<<"\nRoots are real.";
	root1=((-b)+sqrt((b * b)-(4 * a * c)))/(2 * a);
    root2=((-b)-sqrt((b * b)-(4 * a * c)))/(2 * a);
    cout<<"\nRoots of the equation are:\t"<<root1<<"\t&\t"<<root2;
  }
  else
    cout<<"\nRoots are imaginary.";
  cout<<"\nEnter a value for x to evaluate the given equation:";
  cin>>x;
  val=(a * x * x)+(b * x)+c;
  cout<<"\nIts value at x="<<x<<" is: "<<val;
 }
  

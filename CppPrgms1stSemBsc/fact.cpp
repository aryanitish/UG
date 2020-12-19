#include<iostream> 							
#include<math.h>      
#define e 2.71828;   			 
using namespace std;
int fact(int a)
{ int fct=a;
  if(a==1)
    fct=fct;
    else 
    fct=fct*fact(a-1);
    return fct;
    
  }  
  int main()
  { int x;
   cin>>x;
   cout<<fact(x);
   }

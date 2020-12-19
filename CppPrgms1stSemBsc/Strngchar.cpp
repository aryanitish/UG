					//#Created by Nitish Arya(1061) Program for replacing all occurences of a particular character by another character.
#include<iostream> 					         			 
using namespace std;
int main()
{  
  char A[20],c,repl;
  int i;
  cout<<"Enter a string:";
  cin>>A;
  cout<<"\nEnter a character you want to replace:";
  cin>>c;
  cout<<"\nReplace with:";
  cin>>repl;
  for(i=0;A[i]!='\0';i++)
  { if(A[i]==c)
     A[i]=repl;
     }
  cout<<"\nModified string is: "<<A;
}
  

#include<iostream>          			//#Created by Nitish Arya(1061) Program for counting number of occurences of a character.
using namespace std;
int main()
{ char str[30],a;
  int i,count=0,flag=0;
  cout<<"Enter a string:";
  cin>>str;
  cout<<"\nEnter the character you want to check for:";
  cin>>a;
  for(i=0;str[i]!='\0';i++)
  {if(str[i]==a)
   {flag=1;count++;}  
  }
  if(flag==1)
  cout<<"\nGiven string contains\t"<<"'"<<a<<"'"<<"\t"<<count<<"\ttime(s)";
  else
  cout<<"\nGiven string does not contain\t"<<a;
}

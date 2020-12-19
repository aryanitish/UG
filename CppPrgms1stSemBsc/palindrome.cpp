#include<iostream>          			//#Created by Nitish Arya(1061) Program to check whether a string is palindrome or not.
using namespace std;
int main()
{ char str[30];
  int i,j,flag=0;
  cout<<"Enter a string to check it is palindrome or not:";
  cin>>str;
  for(i=0;str[i]!='\0';i++);
  for(j=0;j<(i/2)+1;j++,i--)
  {if(str[j]!=str[i-1])
    flag=1;
  }
  if(flag==0)
  cout<<"\nThe given string is palindrome!";
  else
  cout<<"\nThe given string is not palindrome!!";
}

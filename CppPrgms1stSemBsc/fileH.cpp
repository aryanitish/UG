#include<iostream>
#include<fstream>
using namespace std;
int main()
{ 
  char A[10];
  
  int count=0,sum=0,avg,x;
  
  fstream f;
  
    f.open("space.txt");
  
  f>>A;
  
  while(f)
  { 
	  f>>x;
	while(x!=-1)
	  {
	    sum=sum+x;
	    count++;
		f>>x;
      }
    
    if(count!=0)
    avg= (sum/count);
    else 
    avg=0;
    cout<<A<<" "<<avg<<endl;
    f>>A;
    sum=0;
    count=0;
  }
  f.close();
}

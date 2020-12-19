#include<iostream>

using namespace std;
int main(int agrc,char*argv[])
{ char ch;int i=1;
	ch=*argv[argc];
	cout<<ch;
for(int i=0;i<5;i++)
	{ int count=0;
		for(int j=1;j<5;j++)
		{if(*argv[agrc]==ch)
		count++;}
		cout<<"No. of"<<ch<<"are:"<<count;
		
		ch=*argv[i];
	}
}
       

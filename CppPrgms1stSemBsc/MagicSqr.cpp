// Program for printing a magic square of 'n' cross 'n' ;
//Created by Nitish Arya on 25 September;
#include<iostream>
using namespace std;

int check(int b,int size)
{ 
  int count,flag=0;
    
    for(count=1;count<=(size * size);count++)
      { 
		if(b==count)
		flag=1;
	  }
	
	if(flag==0)
	  return 1;
    else
	  return 0;
	  	
}	

void diagfill(int &A,int sz,int &i,int &j)
{ i+=1;
  j-=1;
  c=A[i][j];
   do
    {
	  if(
	  
	


int main()
 { 
	 
    int n,i,j,c,count=1;
  
    int A[5][5];
   
    cout<<"Enter the size of the magic square:";
	cin>>n;
  
	if(n%2==1)
	  { 
	     i=0;
	     j=n/2;
	     
	     A[i][j]=count;
	  
	     count++;
	
			do
	        { 
				if((i==0)&&(j!=n-1))
		          {  
			        i=n-1;
					j=j+1;
					c=A[i][j];
					if(check(c,n))
					{
					 A[i][j]=count;
					 count+=1;
					}
					void diagfill(A,n,i,j);
				  }
		 
				 else if(j==n-1)
				  {  i-=1;
					  j=0;
					  c=A[i][j];
					 if(check(c,n))
				    {
					 A[i][j]=count;
					  count+=1;
					 j+=1;
					 i-=1;
					 A[i][j]=count;
					 count+=1;			 
				    }
				     
				     
				  }
				  
				 else if(check(c,n))
				  { 
					 A[i][j]=count;
					  count+=1;
				    if(!(i==n-1)||(j==n-1))
				    {
					   i-=1;
					   j+=1;
					   c=A[i][j];
					 
					   while((i<=0)||(check(c,n)))
					    {
						  A[i][j]=count;
						  count+=1;
						  i-=1;
						  j+=1;
					    }
					    i+=3;
					    j-=2;
				   
				    }
				    
				  } 
				  if(!(i==n-1)||(j==n-1))
				  { 
					  i-=1;	
					  j+=1;			  
				      c=A[i][j];
			      }
			      
			  } while(count<=(n * n));
			  
			  cout<<"The required magic square is:"<<A;
			  
		  } 
		  ;

} 
	  		  
			  
			  
			  
			  
			  
			  
			  
			  
			    
 		 
		 
		 

// Program for finding a determinant of a matrix input by the user;
//Created by Nitish Arya on 30 September 2017;
#include<iostream>
using namespace std;
int calc_det(int *B)
{ 
  int k=0,l=0,detr=0,flag=0;
   
   for(int i=0;B[0][i]!='\0';i++);
	  
	 if((k==i)&&(flag==0))
	   {  flag=1;
	      return detr;
	   }
	 
	 else 
	  if(i==3)
	  detr= detr + (( B[k][l] * ((B[k+1][l+1] * B[k+2][l+2]) - (B[k+1][l+2] * B[k+2][l+1])) ) - ( B[k][l+1] * ((B[k+1][l] * B[k+2][l+2]) - (B[k+1][l+2] * B[k+2][l])) ) + ( B[k][l+2] * ((B[k+1][l] * B[k+2][l+1]) - (B[k+1][l+1] * B[k+2][l])) ));
     else return 0;
  }
	  
	
	
	
	
	
int main()
{ int i,j,size,det=0;
  int A[10];
  
  cout<<"Enter the size of the square matrix to find its determinant(enter n for n*n matrix):\n";
  
  
  cin>>size;
  
  
  cout<<"Enter its elements:\n";
  
    for(i=0;i<size;i++)
       { for(j=0;j<size;j++)
	     { cin>>A[i][j];}
       }
   
   
   cout<<"Entered matrix is:";
   
   
    for(i=0;i<size;i++)
      { for(j=0;j<size;j++)
	     { cout<<A[i][j]<<" ";}
        cout<<"\n";
      }
    det=calc_det(A);
  
  cout<<"Determinant of the given matrix is:"<<det;
  
}                

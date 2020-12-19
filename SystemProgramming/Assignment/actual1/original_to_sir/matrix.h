#include <stdlib.h>
#define MOD_SIZE 10
int rows,columns;
int ** matrix;
int *modifier_arr[MOD_SIZE];
void setRowColumn(int r,int c)
{
	rows = r;
	columns = c;
}
void assignMatrix()
{
	matrix = malloc(rows * sizeof(int*));
	for(int i=0; i<rows ; i++)
		matrix[i] = malloc(columns * sizeof(int));
	
}
void modifier_array(int *loc)
{
	for(int i = 0; i < MOD_SIZE; i++)
	{
		if(modifier_arr[i]){
			modifier_arr[i] = loc;
			return;
		}
	}
	printf("only 10 locations from the right are modified");
}

void modify()
{
	for(int i = 0; i < MOD_SIZE; i++)
	{
		if(modifier_arr[i]){
			*modifier_arr[i] = 1;
		}
	}
}

void showMatrix()
{
	int i,j;  
	printf("\nMatrix location in memory");
	for (i = 0; i <  rows; i++) 
      		for (j = 0; j < columns; j++) 
      		   printf("\t%d ", &matrix[i][j]); 
      	printf("\nMatrix values");
    	for (i = 0; i <  rows; i++) 
      		for (j = 0; j < columns; j++) 
        	   printf("\t%d ", matrix[i][j]); 
}

void showModifier()
{
	int i;
	printf("\nModifier");
	for(i = 0; i < MOD_SIZE; i++)
		printf("\t%d ",modifier_arr[i]);
}


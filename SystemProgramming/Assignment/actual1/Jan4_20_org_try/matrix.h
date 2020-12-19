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
		if(modifier_arr[i]==NULL){
			modifier_arr[i] = loc;
			return;
		}
	}
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
	for (i = 0; i <  rows; i++) 
	{
		for (j = 0; j < columns; j++) 
		printf("%d ", matrix[i][j]);
		
		printf("\n");
	} 
}

%{
#include <stdio.h>
int no_of_ids = 0;
%}
keywords	(int|float|double|struct)
%%
[ \t\n]	;

.	;
%%

extern FILE *yyin;

int main(int argc,char *argv[]) 
{

	FILE *file = fopen(argv[1],"r");
	if(!file)
	{
		fprintf(stderr,"Could not open %s\n",argv[1]);
	}
	yyin = file;

	yylex();

	if(file)	fclose(file);

	printf("Total number of lines in %s is %d\n",argv[1],no_of_lines);
	printf("Total number of characters in %s is %d\n",argv[1],no_of_chars);
	return 0;
}

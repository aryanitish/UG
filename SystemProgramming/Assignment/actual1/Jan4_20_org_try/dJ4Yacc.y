 %{
#include <stdio.h>
#include <string.h>
#include "symboltable.h"
#include "matrix.h"
int yylex();
int yyerror();
%}

%union{
	int val;
	int *ptr;
	struct symtab *symp;
}

%token <symp> ID BEG DEST
%token <val> DIGIT
%token MATX DEFN INV 
%type <ptr> name_loc
%type <symp> lval
%%
program : definition_section	{showMatrix();	displayTable();}
	 |definition_section invalids	{showMatrix();	displayTable();}
	;
definition_section : DEFN':'definition_statements declarations df_sec_statements	{}
		    |DEFN':'definition_statements declarations	{}
		    |DEFN':'definition_statements	{}
	;
definition_statements : definition_statements MATX'='ID'<'DIGIT','DIGIT'>'	{
											if(!($4->locationInMatrix)){
												setRowColumn($6,$8);
												assignMatrix();
												$4->matrixptr = matrix;
											}
											else
												yyerror("%s is a pointer to a location, can't name a matrix",$4->name);								}
		       |MATX'='ID'<'DIGIT','DIGIT'>'	{
								if(!($3->locationInMatrix)){
									setRowColumn($5,$7);
									assignMatrix();
									$3->matrixptr = matrix;
								}
								else
									yyerror("%s is a pointer to a location, can't name a matrix",$3->name);
							}
	;
declarations : declarations lval'='name_loc	{$2->locationInMatrix = $4;}
	      |lval'='name_loc	{$1->locationInMatrix = $3;}
	;
name_loc : ID'<'DIGIT','DIGIT'>'	{
						if($1->matrixptr){
							if( !(($3 >= 0) && ($5 >= 0)) )
								yyerror("%s can't point to negative indices.",$1->name);
							else
								$$ = *(matrix + $3) + $5;
							}
						else
							yyerror("%s is not a matrix.",$1->name);
					}
	;
df_sec_statements : df_sec_statements lval':'lval	{ /*check $4 is already decalred except it is BEG or DEST*/
								if($4)
									$2 = $4;
								else
									yyerror("a varible is not declared.");
							}
		   |lval':'lval 	{
						if($3)
							$1 = $3;
						else
							yyerror("a variable is not declared.");
					}
		   |lval':'name_loc 	{
						if($3)
							$1->locationInMatrix = $3;
						else
							yyerror("invalid location in df_sec prod3.");
					}
		
	;



invalids : INV':'locations	{modify();}
	;
locations : locations','lval	{modifier_array($3->locationInMatrix);}
	   |locations','name_loc	{modifier_array($3);}
	   |lval	{modifier_array($1->locationInMatrix);}
	   |name_loc	{modifier_array($1);}
	;
lval : ID	{ /*check that it is not a matrix variable*/
			if(!($1->matrixptr))
				$$ = $1;
			else
				yyerror("%s is of matrix type,cannot assign location to it.",$1->name);
		}
      |BEG	{$$ =  $1;}	
      |DEST	{$$ =  $1;}
	;
%%
/*SUBROUTINES FOR ABOVE PARSER*/


/*Look up for a symbol table entry and add one if not present*/
struct symbtab *symlook(char *s)
{
	struct symtab *sp;
	for(sp = Symtab; sp < &Symtab[NMSYM]; sp++)
	{
		/*if symbol with given name is already present then return the table pointer*/
		if(sp->name && !strcmp(sp->name,s))
			return (struct symbtab *)sp;
		/*if entry for name is not present then add it at a free location in table*/
		if(!sp->name){		
			sp->name = strdup(s);	/*save the name in the sp->name field*/
			return (struct symbtab *)sp;
		}
		
	}
	yyerror("Symbol limit exceeded(100)");
	exit(1);
}/*symlook*/

/*Display the symbol table after parsing the input*/
void displayTable()
{
	struct symtab *sp;
	int count = 0;
	for(sp = Symtab; sp->name != NULL; sp++)
	{
		count++;
		printf("\nSymbol %d ::: %s",count,sp->name);
	}
	printf("\n");
}
/*yyerror() defintion*/
int yyerror(s)
char *s;
{
fprintf(stderr, "%s\n", s);
}
/*yyerror()*/
extern FILE *yyin;
/**MAIN**/
int main(argc,argv)
int argc;
char **argv;
{
	if (argc > 1) {
	FILE *file;
	file = fopen(argv[1], "r");
		if (!file) {
		fprintf(stderr,"could not open %s\n",argv[1]);
		exit(1);
		}
	yyin = file;
	}
	yyparse();
	return 0;
}


/*Parser works for definition section, stores and displays symbols and the matrix(all 0's)
 *Date Jan 4,2020. Time 22:45
 *Parser works for Invalids section, stores location and reflects the changes in the matrix(replaces by 1's)
 *Date Jan 4,2020. Time 23:49
*/



















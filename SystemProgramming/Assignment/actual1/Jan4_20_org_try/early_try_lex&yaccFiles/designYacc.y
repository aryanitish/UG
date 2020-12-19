 %{
#include <stdio.h>
#include "symboltable.h"
#include "matrix.h"
int yylex();
int yyerror();
%}

%union{
	int val;
	int *ptr
	struct symtab *symp;
}

%token <symp> ID BEG DEST
%token <val> DIGIT
%token MATX DEFN INV 
%type <ptr> lval name_loc
%%
program : definition_section invalids	{showMatrix();}
	;
definition_section : DEFN':'definition_statements declarations df_sec_statements	{}
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
declarations : declarations lval'='name_loc	{$2 = $4;}
	      |lval'='name_loc	{$1 = $3;}
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
	;
invalids : INV':'inv_statements	{}
	;
inv_statements : inv_statements inv_statement	{}
		|inv_statement	{}
	;
inv_statement : locations	{modify();}
	;
locations : locations','lval	{modifier_array($3);}
	   |lval	{modifier_array($1);}
	;
lval : ID	{ /*check that it is not a matrix variable*/
			if(!($1->matrixptr))
				$$ = $1->locationInMatrix;
			else
				yyerror("%s is of matrix type,cannot assign location to it.",$1->name);
		}
      |BEG	{$$ =  $1->locationInMatrix;}
      |DEST	{$$ =  $1->locationInMatrix;}
	;
%%
/*SUBROUTINES FOR ABOVE PARSER*/
/*Look up for a symbol table entry and add one if not present*/
struct symbtab *symlook(char *s)
{
	struct symtab *sp;
	for(sp = symtab; sp < &symtab[NMSYM]; sp++)
	{
		/*if symbol with given name is already present then return the table pointer*/
		if(sp->name && !strcmp(sp->name,s))
			return sp;
		/*if entry for name is not present then add it at a free location in table*/
		if(!sp->name){		
			sp->name = strup(s);	/*save the name in the sp->name field*/
			return sp;
		}
		
	}
	yyerror("Symbol limit exceeded(100)");
	exit(1);
}/*symlook*/


























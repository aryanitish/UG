%{
#include <stdio.h>
double nametable[26];
int yylex();
int yyerror();
%}
%union{
	double dval;
	int pos;
}

%token <dval> NUMBER
%token <pos> NAME
%type <dval> expr term factor

%%
stmt_list : stmt
	   |stmt_list stmt
	;
stmt :	 NAME'='expr	{ nametable[$1] = $3; }
	|expr		{ printf(" = %g\n",$1); }
	;
expr :	 expr'+'term	{ $$ = $1 + $3; }
	|expr'-'term	{ $$ = $1 - $3; }
	|term		{ $$ = $1; }
	;
term :	 term'/'factor	{ if($3 == 0) yyerror("division by zero error"); 
			  else $$ = $1 / $3; }
	|term'*'factor	{ $$ = $1 * $3; }
	|NAME		{ $$ = nametable[$1]; }
	|factor		{ $$ = $1; }
	;
factor : NUMBER		{ $$ = $1; }
	|'('expr')'	{ $$ = $2; }
%%
int yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
	return 0;
}


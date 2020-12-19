%{
#include <stdio.h>
int table[26];
int yylex();
int yyerror();
%}

%union{
	double val;
	int tblno;
}

%token <val> NUMBER
%token <tblno> NAME

%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%type <val> expr

%%
stmt_list : stmt'\n'	
	   |stmt_list stmt'\n'
	;
stmt : NAME'='expr	{ table[$1] = $3; }
      |expr		{ printf("=%g\n",$1); }
	;
expr : expr'+'expr	{ $$ = $1 + $3; }
      |expr'-'expr	{ $$ = $1 - $3; }
      |expr'*'expr	{ $$ = $1 * $3; }
      |expr'/'expr	{ if($3 == 0)	yyerror("Division by zero error");	$$ = $1 / $3; }
      |'-'expr %prec UMINUS	{ $$ = -$2; }
      |'('expr')'	{ $$ = $2; }
      |NAME		{ $$ = table[$1]; }
      |NUMBER		{ $$ = $1; }
	;
%%
int yyerror(char *s)
{
	fprintf(stderr,"%s",s);
}

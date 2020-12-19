%{
    #include<stdio.h>
    #include<stdlib.h>
    extern int yylex();
    void yyerror(char *errmsg);
%}

%token NUM  ID NEW_LINE
%left '+' '-' '*' '/' /*left associativity*/

%%
S : E NEW_LINE	{printf("\nEXPRESSION VALID");}
    ;
E : E '+' E 	
    | E '-' E 
    | E '*' E
    | E '/' E
    | NUM
    | ID
    ;
%%

void yyerror(char *errmsg)
{
	fprintf(stderr,"INVALID\t%s\n",errmsg);
	exit(1);
}

int main()
{
	printf("\nEnter an expression: ");
	yyparse();
	return 0;
}


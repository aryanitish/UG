%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
[ \t]+	;
[a-z]+	{ yylval.tblno = yytext[0] - 'a'; return NAME; }
[0-9]*\.?[0-9]+	{ yylval.val = atof(yytext); return NUMBER; }
"$"	return 0;
\n|.	return yytext[0];
%%

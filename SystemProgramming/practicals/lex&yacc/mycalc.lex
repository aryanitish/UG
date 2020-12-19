%{
#include <stdio.h>
#include "y.tab.h"
%}


%%
[ \t\n]		;
([0-9]+|(0-9)*\.[0-9]+)		{yylval.dval = atof(yytext); return NUMBER;}
[a-z]				{yylval.pos = yytext[0] - 'a'; return NAME;}
"$"	return 0;
.	return yytext[0];
%%



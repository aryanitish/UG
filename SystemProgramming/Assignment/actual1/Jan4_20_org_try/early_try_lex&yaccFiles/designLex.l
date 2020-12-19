%{
#include "y.tab.h"
#include "symboltable.h"
int lineno = 0;
%}

id [a-zA-Z_][a-zA-Z0-9_]*
digit [0-9]
digits digit+

%%
[ \t]		;
\n		{lineno++;}
definition	return DEFN;
invalids	return INV;
matrix		return MATX;
BEGIN		{
			/* return symbol pointer */
			struct symtab *sp = symlook(yytext);
			yylval.symp = sp;
			return BEG;		
		}
DEST		{
			/* return symbol pointer */
			struct symtab *sp = symlook(yytext);
			yylval.symp = sp;
			return DEST;		
		}
{digits}	{yylval.val = atoi(yytext); return DIGIT;}
{id} 		{
			/* return symbol pointer */
			struct symtab *sp = symlook(yytext);
			yylval.symp = sp;
			return ID;
		}
END		return 0;
.	return *yytext;
%%



%{
#include "y.tab.h"
#include "symboltable.h"
int lineno = 0;
%}

%%
[ \t]		;
\n		{lineno++;}
definition	return DEFN;
Invalids	return INV;
matrix		return MATX;
BEGIN		{
			/* return symbol pointer */
			struct symtab *sp = (struct symtab *)symlook(yytext);
			yylval.symp = sp;
			return BEG;		
		}
DEST		{
			/* return symbol pointer */
			struct symtab *sp = (struct symtab *)symlook(yytext);
			yylval.symp = sp;
			return DEST;		
		}
END		return 0;
[0-9][0-9]*	{yylval.val = atoi(yytext); return DIGIT;}
[a-zA-Z_][a-zA-Z0-9_]*		{
			/* return symbol pointer */
			struct symtab *sp = (struct symtab *)symlook(yytext);
			yylval.symp = sp;
			return ID;
		}
.		return *yytext;
%%



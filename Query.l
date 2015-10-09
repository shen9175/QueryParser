whitespace			([ \n\t\r]+)



query				[^ \n\t\r\|\(\)&~]+

%{
#include <cstdio>
#include "Query.h"
#include "Query.tab.h"
%}

%%

{whitespace}	{}
"("				{return LP;}				
")"				{return RP;}
"|"				{return OR;}
"&"				{return AND;}
"~"				{return NOT;}
{query}			{yylval.cstr=yytext;return STR;}
.				{printf("stray\n");}
%%

int yywrap()
{
   return -1;
}

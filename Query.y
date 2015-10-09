%{
#include <iostream>
#include <string>
#include <cstring>
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"
#include "Query.tab.h"
extern int yylex();
inline Query operator~(const Query& operand);
inline Query operator|(const Query& lhs, const Query& rhs);
inline Query operator&(const Query& lhs, const Query& rhs);
//Query ANDop(const Query& lhs, const Query& rhs);
//Query ORop(const Query& lhs, const Query& rhs);
//Query NOTop(const Query& operand);

Query* ANDop(Query* lhs, Query* rhs);
Query* ORop(Query* lhs, Query* rhs);
Query* NOTop(Query* operand);

//#define YYDEBUG 1
#define YYERROR_VERBOSE
    void yyerror(const char *msg){
	printf("ERROR(PARSER):%s\n",msg);
	}
%}

%union{
Query * q;
char* cstr;
}

%token LP RP OR AND NOT STR
%type <q> query exp1 exp2 exp3
%type <cstr> STR
%%

query: exp3					{yylval.q=$1;}
	 ;

exp1:STR					{/*for(int i=0;i!=strlen($1);i++)std::cout<<$1[i]<<std::endl;*/$$=new Query(std::string($1));}
	|LP exp3 RP				{$$=$2;}
	;

exp2:exp1					{$$=$1;}
	|NOT exp2				{$$=NOTop($2);}
	;

exp3:exp2					{$$=$1;}
	|exp3 AND exp2			{$$=ANDop($1 , $3);}
	|exp3 OR exp2			{$$=ORop($1 , $3);}
	;
%%



#include <fstream>
#include "TextQuery.h"
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"
#include "Query.tab.h"

using namespace std;
//extern int yydebug;
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char*);
extern int yy_delete_buffer(YY_BUFFER_STATE);
Query* ANDop(Query* lhs, Query* rhs);
Query* ORop(Query* lhs, Query* rhs);
Query* NOTop(Query* operand);


Query* ANDop(Query* lhs, Query* rhs)
{
	Query* tmp=new Query(*lhs&*rhs);
	delete lhs;
	delete rhs;
	return tmp;
}

Query* ORop(Query* lhs, Query* rhs)
{
	Query* tmp=new Query(*lhs|*rhs);
	delete lhs;
	delete rhs;
	return tmp;
}

Query* NOTop(Query* operand)
{
	Query* tmp=new Query(~*operand);
	delete operand;
	return tmp;
}

void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
/*	Query q=Query("Daddy");
	cout<<"Executing Query for: "<<q<<endl;
	print(cout,q.eval(tq));
	q=~Query("Alice");
	cout<<"Executing Query for: "<<q<<endl;
	print(cout,q.eval(tq));
	q=Query("hair")|Query("Alice");
	cout<<"Executing Query for: "<<q<<endl;
	print(cout,q.eval(tq));
	q=Query("hair")&Query("Alice");
	cout<<"Executing Query for: "<<q<<endl;
	print(cout,q.eval(tq));
	q=Query("fiery")&Query("bird")|Query("wind");
	cout<<"Executing Query for: "<<q<<endl;
	print(cout,q.eval(tq));*/

	while(true)
	{
		cout<<"enter word to look for, or q to quit: ";
		string s;
		if(!(getline(cin,s))||s=="q") break;
		auto my_string_buffer = yy_scan_string (s.c_str());
		auto my_parse_result  = yyparse ();
	    yy_delete_buffer (my_string_buffer);
		Query q=*yylval.q;
		cout<<"Executing Query for: "<<q<<endl;
		print(cout,q.eval(tq));
		delete yylval.q;
	}

}


int main(int argc, char* argv[])
{
	//yydebug=1;
	if(argc<=1)
		{
			while(true)
			{
			cout<<"enter the file name to query, or q to quit: ";
			string s;
			if(!(cin>>s)||s=="q")break;
			ifstream in(s);
			if(!in.is_open())
				cout<<"Error in open the file: "<<s<<endl;
			else
				runQueries(in);
			}
		}
	else
		{
			for(unsigned int i=1;i!=argc;i++)
			{
			cout<<"Now process the file: "<<argv[i]<<":"<<endl;
			ifstream in(argv[i]);
			if(!in.is_open())
				cout<<"Error in open the file: "<<argv[i]<<endl;
			else
				runQueries(in);
			}
		}
	return 0;
}

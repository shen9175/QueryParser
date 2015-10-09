Query:main.o AndQuery.o NotQuery.o OrQuery.o Query.o TextQuery.o Query.tab.o lex.yy.o
	g++ -o Query main.o AndQuery.o NotQuery.o OrQuery.o Query.o TextQuery.o Query.tab.o lex.yy.o -std=c++11

main.o:main.cpp TextQuery.h Query.h AndQuery.h OrQuery.h NotQuery.h Query.tab.h
	g++ -c main.cpp -std=c++11

AndQuery.o:AndQuery.cpp AndQuery.h Query.h QueryResult.h TextQuery.h BinaryQuery.h
	g++ -c AndQuery.cpp -std=c++11

NotQuery.o:NotQuery.cpp NotQuery.h Query.h QueryResult.h TextQuery.h
	g++ -c NotQuery.cpp -std=c++11

OrQuery.o:OrQuery.cpp OrQuery.h Query.h QueryResult.h TextQuery.h BinaryQuery.h
	g++ -c OrQuery.cpp -std=c++11

TextQuery.o:TextQuery.cpp TextQuery.h QueryResult.h
	g++ -c TextQuery.cpp -std=c++11

Query.o:Query.cpp Query.h Querybase.h WordQuery.h TextQuery.h
	g++ -c Query.cpp -std=c++11

Query.tab.o: Query.tab.c Query.tab.h
	g++ -c Query.tab.c -std=c++11

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c -std=c++11

Query.tab.c: Query.y Query.h AndQuery.h OrQuery.h NotQuery.h
	bison -d -v Query.y

Query.tab.h:Query.tab.c

lex.yy.c: Query.l Query.tab.h
	flex Query.l

clean:
	rm Query.tab.*
	rm lex.yy.c
	rm *.o


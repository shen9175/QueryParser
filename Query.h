#ifndef QUERY_H
#define QUERY_H

#include <memory>
#include "Querybase.h"
#include "WordQuery.h"
#include "TextQuery.h"


class Query
{
	friend Query operator~ (const Query&);
	friend Query operator| (const Query&, const Query&);
	friend Query operator& (const Query&, const Query&);

	public:
		Query(const std::string& s):q(new WordQuery(s)) {}
		QueryResult eval(const TextQuery &t) const {return q->eval(t);}
		std::string rep() const {return q->rep();}

	private:
		Query(std::shared_ptr<Query_base> query):q(query){}
		std::shared_ptr<Query_base> q;
};
std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);
std::ostream& operator<<(std::ostream &os, const Query &query);
std::ostream& print(std::ostream& os, const QueryResult &qr);
#endif


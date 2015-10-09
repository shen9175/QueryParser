#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>

class QueryResult;

std::ostream& print(std::ostream&, const QueryResult&);
void runQueries(std::ifstream& infile);
std::string make_plural(std::size_t ctr, const std::string &word, const std::string &ending);



class QueryResult
{
	friend std::ostream &print(std::ostream&, const QueryResult&);

	public:
		using line_no=std::vector<std::string>::size_type;
		QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f):sought(s),lines(p),file(f){}
		std::set<line_no>::iterator begin(){return lines->begin();}
		std::set<line_no>::iterator end(){return lines->end();}
		std::shared_ptr<std::vector<std::string>> get_file(){return file;}
	private:
		std::string sought;
		std::shared_ptr<std::set<line_no>> lines;
		std::shared_ptr<std::vector<std::string>> file;
};





#endif


#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream& is): file(new vector<string>)
{
	string text;
	while(getline(is,text))
	{
		file->push_back(text);
		int n=file->size()-1;
		istringstream line(text);
		string word;
		while(line>>word)
		{

			//get rid of punctuations
			auto it=word.begin();
			while(it!=word.end())
				{
					if(ispunct(*it))
						it=word.erase(it);
					else
						it++;
				}
			//cout<<word<<endl;


			auto &lines=wm[word];
			if(!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc=wm.find(sought);

	if(loc==wm.end())
		return QueryResult(sought,nodata,file);
	else
		return QueryResult(sought,loc->second,file);
}

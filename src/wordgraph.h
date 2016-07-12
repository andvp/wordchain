#include <map>
#include <set>
#include <string>
using namespace std;

class WordGraph {
	// Template = first + '*' + second
	typedef pair<string, string> WordTemplate;

	set<string> _dictionary;
	map<WordTemplate, set<string> > _searchMap;

public:
	WordGraph(const set<string>& dictionary);
	bool contains(const string& word) const { return _dictionary.count(word); }
	set<string> getNeighbours(const string& word) const;

private:
	static set<WordTemplate> getWordTemplates(const string& word);
};

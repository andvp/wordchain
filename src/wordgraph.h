#include <map>
#include <set>
#include <string>
using namespace std;

/*
 This class represents graph which nodes are words.
 Two nodes are connected if corresponding words are different by one letter only.
 */
class WordGraph {
	// Template = first + '*' + second
	typedef pair<string, string> WordTemplate;

	set<string> _dictionary;
	map<WordTemplate, set<string> > _wordsForTemplate;

public:
	WordGraph(const set<string>& dictionary);
	bool contains(const string& word) const { return _dictionary.count(word); }
	set<string> getNeighbours(const string& word) const;

private:
	static set<WordTemplate> getWordTemplates(const string& word);
};

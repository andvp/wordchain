#include <list>
#include "wordgraph.h"

class WordChain : public WordGraph {
public:
	WordChain(const set<string>& dictionary);
	list<string> getChain(const string& startWord, const string& endWord);
};

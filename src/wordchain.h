#include <list>
#include "wordgraph.h"

/*
 This class is intended for solving word chain problem.
 */
class WordChain : public WordGraph {
public:
	WordChain(const set<string>& dictionary);
	list<string> getChain(const string& startWord, const string& endWord);
};

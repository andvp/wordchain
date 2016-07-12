#include <queue>
#include "wordchain.h"

WordChain::WordChain(const set<string>& dictionary)
	: WordGraph(dictionary) {}

list<string> WordChain::getChain(const string& startWord, const string& endWord) {
	list<string> chain;
	if (!contains(startWord) || !contains(endWord)) return chain;
	// Using breadth-first search algorithm
	queue<string> unprocessed;
	set<string> visited;
	map<string, string> predecessor;
	unprocessed.push(startWord);
	visited.insert(startWord);
	while (!unprocessed.empty()) {
		const string& word = unprocessed.front();
		if (word == endWord) break;
		set<string> neighbours = getNeighbours(word);
		for (const string& neighbour : neighbours) {
			if (visited.count(neighbour)) continue;
			unprocessed.push(neighbour);
			visited.insert(neighbour);
			predecessor[neighbour] = word;
		}
		unprocessed.pop();
	}
	if (unprocessed.empty()) return chain; // chain not found
	// Restore chain using predecessor map
	chain.push_front(endWord);
	while (predecessor.count(chain.front())) {
		chain.push_front(predecessor.at(chain.front()));
	}
	return chain;
}

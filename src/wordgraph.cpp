#include "wordgraph.h"

WordGraph::WordGraph(const set<string>& dictionary) {
	_dictionary.insert(dictionary.begin(), dictionary.end());
	for(const string& word : dictionary) {
		set<WordTemplate> wordTemplates = getWordTemplates(word);
		for(const WordTemplate& wordTemplate : wordTemplates) {
			_searchMap[wordTemplate].insert(word);
		}
	}
}

set<string> WordGraph::getNeighbours(const string& word) const {
	set<string> allNeighbours;
	if (!_dictionary.count(word)) return allNeighbours;
	set<WordTemplate> wordTemplates = getWordTemplates(word);
	for(const WordTemplate& wordTemplate : wordTemplates) {
		const set<string>& neighbours = _searchMap.at(wordTemplate);
		allNeighbours.insert(neighbours.begin(), neighbours.end());
	}
	allNeighbours.erase(word);
	return allNeighbours;
}

set<WordGraph::WordTemplate> WordGraph::getWordTemplates(const string& word) {
	set<WordTemplate> wordTemplates;
	for (size_t i = 0; i < word.length(); i++) {
		wordTemplates.insert(WordTemplate(word.substr(0, i), word.substr(i + 1)));
	}
	return wordTemplates;
}

#include <iostream>
#include "wordchain.h"
#include "textfilereader.h"

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cout << "Usage: wordchain <start & end words file> <dictionary file>" << endl;
		return 0;
	}
	try {
		// Read start & end words
		TextFileReader wordsReader(argv[1]);
		list<string> words = wordsReader.readLines();
		words.resize(2);

		// Read dictionary
		TextFileReader dictionaryReader(argv[2]);
		list<string> dictionary = dictionaryReader.readLines();

		// Find chain
		WordChain wordChain(set<string>(dictionary.begin(), dictionary.end()));
		list<string> chain = wordChain.getChain(words.front(), words.back());

		// Print result
		if (chain.empty()) {
			cout << "Chain was not found" << endl;
		} else {
			for (const string& word : chain) {
				cout << word << endl;
			}
		}
	} catch (TextFileReaderException& e) {
		cout << e.what() << endl;
	}
	return 0;
}

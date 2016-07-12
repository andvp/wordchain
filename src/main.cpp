#include <iostream>
#include "wordchain.h"
#include "textfilereader.h"

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cout << "Usage: wordchain <start & end words file> <dictionary file>" << endl;
		return 0;
	}
	try {
		TextFileReader wordsReader(argv[1]), dictionaryReader(argv[2]);
		list<string> words = wordsReader.readLines();
		list<string> dictionary = dictionaryReader.readLines();
		WordChain wordChain(set<string>(dictionary.begin(), dictionary.end()));
		words.resize(2);
		list<string> chain = wordChain.getChain(words.front(), words.back());
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

#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

class TextFileReader {
	string _filePath;
public:
	TextFileReader(const string& filePath);
	list<string> readLines() const;
};

class TextFileReaderException : public runtime_error {
public:
	TextFileReaderException(const string& msg) : runtime_error(msg) {}
};

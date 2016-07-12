#include "textfilereader.h"

TextFileReader::TextFileReader(const string& filePath) {
	_filePath = filePath;
}

list<string> TextFileReader::readLines() const {
	ifstream file;
	file.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		file.open(_filePath);
	} catch (ifstream::failure& e) {
		throw TextFileReaderException("Failed to open file: " + _filePath);
	}
	list<string> lines;
	try {
		string line;
		while (getline(file, line)) {
			lines.push_back(line);
		}
	} catch (ifstream::failure& e) {
		if (!file.eof())
			throw TextFileReaderException("Failed to read file: " + _filePath);
	}
	return lines;
}

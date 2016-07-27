#include <vector>
#include "gtest/gtest.h"
#include "textfilereader.h"

/*
 Failure test for TextFileReader.readLines() method when supplied file is missing.
 */
TEST(TextFileReaderTest, MissingFile)
{
	TextFileReader reader("missing.txt");
	ASSERT_THROW(reader.readLines(), TextFileReaderException);
}

/*
 Accuracy test for TextFileReader.readLines() method.
 It should properly read all lines of supplied test file.
 */
TEST(TextFileReaderTest, ReadLinesTest)
{
	TextFileReader reader("test.txt");
	list<string> lines = reader.readLines();
	vector<string> v(lines.begin(), lines.end());
	ASSERT_EQ(v.size(), 3u);
	ASSERT_EQ(v[0], "line1");
	ASSERT_EQ(v[1], "line2");
	ASSERT_EQ(v[2], "line3");
}

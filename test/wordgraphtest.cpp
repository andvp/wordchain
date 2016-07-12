#include "gtest/gtest.h"
#include "wordgraph.h"

class WordGraphTest : public ::testing::Test {
protected:
	set<string> dictionary = {"", "a", "bag", "car", "cat", "cut", "hat", "lamp", "week"};
	WordGraph wordGraph = {dictionary};
};

TEST_F(WordGraphTest, ContainsTest)
{
	for (const string& word : dictionary) {
		ASSERT_TRUE(wordGraph.contains(word));
	}
	ASSERT_FALSE(wordGraph.contains("abcdef"));
}

TEST_F(WordGraphTest, GetNeighboursTest)
{
	ASSERT_TRUE(wordGraph.getNeighbours("").empty());
	ASSERT_TRUE(wordGraph.getNeighbours("a").empty());
	ASSERT_TRUE(wordGraph.getNeighbours("bag").empty());
	set<string> catNeighbours = {"car", "cut", "hat"};
	ASSERT_EQ(wordGraph.getNeighbours("cat"), catNeighbours);
}

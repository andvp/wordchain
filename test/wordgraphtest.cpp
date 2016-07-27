#include "gtest/gtest.h"
#include "wordgraph.h"

class WordGraphTest : public ::testing::Test {
protected:
	set<string> dictionary = {"", "a", "bag", "car", "cat", "cut", "hat", "lamp", "week"};
	WordGraph wordGraph = {dictionary};
};

/*
 Accuracy test for WordGraph.contains() method.
 It should return true for all words from dictionary and false otherwise.
 */
TEST_F(WordGraphTest, ContainsTest)
{
	for (const string& word : dictionary) {
		ASSERT_TRUE(wordGraph.contains(word));
	}
	ASSERT_FALSE(wordGraph.contains("abcdef"));
}

/*
 Accuracy test for WordGraph.getNeighbours() method when supplied word is not in dictionary.
 It should return empty set.
 */
TEST_F(WordGraphTest, GetNeighboursNotInDictionary)
{
	ASSERT_FALSE(wordGraph.contains("abcdef"));
	ASSERT_TRUE(wordGraph.getNeighbours("abcdef").empty());
}

/*
 Accuracy test for WordGraph.getNeighbours() method when supplied word does not have neighbours.
 It should return empty set.
 */
TEST_F(WordGraphTest, GetNeighboursEmpty)
{
	ASSERT_TRUE(wordGraph.contains(""));
	ASSERT_TRUE(wordGraph.getNeighbours("").empty());

	ASSERT_TRUE(wordGraph.contains("a"));
	ASSERT_TRUE(wordGraph.getNeighbours("a").empty());

	ASSERT_TRUE(wordGraph.contains("bag"));
	ASSERT_TRUE(wordGraph.getNeighbours("bag").empty());
}

/*
 Accuracy test for WordGraph.getNeighbours() method when supplied word has neighbours.
 It should return set of all neighbours for supplied word.
 */
TEST_F(WordGraphTest, GetNeighboursTest)
{
	set<string> catNeighbours = {"car", "cut", "hat"};
	ASSERT_EQ(wordGraph.getNeighbours("cat"), catNeighbours);
}

#include "gtest/gtest.h"
#include "wordchain.h"

class WordChainTest : public ::testing::Test {
protected:
	set<string> dictionary = {"bag", "bat", "bog", "car", "care", "cat", "cut", "dog", "hat", "lamp", "week"};
	WordChain wordChain = {dictionary};
};

/*
 Accuracy test for WordChain.getChain() method when start word is not in dictionary.
 It should return empty chain.
 */
TEST_F(WordChainTest, GetChainStartWordNotInDictionary)
{
	ASSERT_FALSE(wordChain.contains("bar"));
	ASSERT_TRUE(wordChain.contains("car"));
	ASSERT_TRUE(wordChain.getChain("bar", "car").empty());
}

/*
 Accuracy test for WordChain.getChain() method when end word is not in dictionary.
 It should return empty chain.
 */
TEST_F(WordChainTest, GetChainEndWordNotInDictionary)
{
	ASSERT_TRUE(wordChain.contains("dog"));
	ASSERT_FALSE(wordChain.contains("dot"));
	ASSERT_TRUE(wordChain.getChain("dog", "dot").empty());
}

/*
 Accuracy test for WordChain.getChain() method when start and end words have different lengths.
 It should return empty chain.
 */
TEST_F(WordChainTest, GetChainLegthsNotEqual)
{
	ASSERT_TRUE(wordChain.contains("car"));
	ASSERT_TRUE(wordChain.contains("care"));
	ASSERT_TRUE(wordChain.getChain("car", "care").empty());
}

/*
 Accuracy test for WordChain.getChain() method when there is no chain for supplied words.
 It should return empty chain.
 */
TEST_F(WordChainTest, GetChainNotFound)
{
	ASSERT_TRUE(wordChain.contains("lamp"));
	ASSERT_TRUE(wordChain.contains("week"));
	ASSERT_TRUE(wordChain.getChain("lamp", "week").empty());
}

/*
 Accuracy test for WordChain.getChain() method when start and end words are adjacent.
 It should return trivial chain that contains start and end words only.
 */
TEST_F(WordChainTest, GetChainTest1)
{
	list<string> chain = wordChain.getChain("bat", "hat");
	ASSERT_EQ(chain.front(), "bat");
	ASSERT_EQ(chain.back(), "hat");
	ASSERT_EQ(chain.size(), 2u);
}

/*
 Accuracy test for WordChain.getChain() method when there exists chain for supplied words.
 It should return chain beginning with start word and ending with end word.
 */
TEST_F(WordChainTest, GetChainTest2)
{
	list<string> chain = wordChain.getChain("cat", "dog");
	ASSERT_EQ(chain.front(), "cat");
	ASSERT_EQ(chain.back(), "dog");
	vector<string> v(chain.begin(), chain.end());
	for (size_t i = 1; i < v.size(); i++) {
		ASSERT_TRUE(wordChain.getNeighbours(v[i - 1]).count(v[i]));
	}
}

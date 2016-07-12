#include "gtest/gtest.h"
#include "wordchain.h"

class WordChainTest : public ::testing::Test {
protected:
	set<string> dictionary = {"bag", "bat", "bog", "car", "care", "cat", "cut", "dog", "hat", "lamp", "week"};
	WordChain wordChain = {dictionary};
};

TEST_F(WordChainTest, GetChainStartWordNotInDictionary)
{
	ASSERT_TRUE(wordChain.getChain("bar", "car").empty());
}

TEST_F(WordChainTest, GetChainEndWordNotInDictionary)
{
	ASSERT_TRUE(wordChain.getChain("dog", "dot").empty());
}

TEST_F(WordChainTest, GetChainLegthsNotEqual)
{
	ASSERT_TRUE(wordChain.getChain("car", "care").empty());
}

TEST_F(WordChainTest, GetChainNotFound)
{
	ASSERT_TRUE(wordChain.getChain("lamp", "week").empty());
}

TEST_F(WordChainTest, GetChainTest1)
{
	list<string> chain = wordChain.getChain("bat", "hat");
	ASSERT_EQ(chain.front(), "bat");
	ASSERT_EQ(chain.back(), "hat");
	ASSERT_EQ(chain.size(), 2u);
}

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

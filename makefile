CFLAGS := -O3 -Wall -std=c++11

LIBS := -lpthread

INCLUDES := -Isrc -Itest

SOURCES := \
src/main.cpp \
src/textfilereader.cpp \
src/wordchain.cpp \
src/wordgraph.cpp

TEST_SOURCES := \
test/main.cpp \
test/textfilereadertest.cpp \
test/wordchaintest.cpp \
test/wordgraphtest.cpp \
test/gtest/gtest-all.cc \
src/textfilereader.cpp \
src/wordchain.cpp \
src/wordgraph.cpp

all: wordchain wordchaintest

wordchain:
	g++ $(SOURCES) $(CFLAGS) -o $@

wordchaintest:
	g++ $(TEST_SOURCES) $(CFLAGS) $(LIBS) $(INCLUDES) -o $@


#include "libstemmer.hpp"
#include <gtest/gtest.h>

TEST(tts, tts0)
{
    EXPECT_EQ(normalize("running"), "RUNN");
}

TEST(tts, tts1)
{
    EXPECT_EQ(normalize("hello"), "HELLO");
}

TEST(tts, tts2)
{
    EXPECT_EQ(normalize("abc123"), "NOT A TOKEN");
}

TEST(tts, tts3)
{
    EXPECT_EQ(normalize(""), "");
}

TEST(tts, tts4)
{
    EXPECT_EQ(normalize("quickly"), "QUICK");
}

TEST(tts, tts5)
{
    EXPECT_EQ(normalize("playedly"), "PLAYED");
}

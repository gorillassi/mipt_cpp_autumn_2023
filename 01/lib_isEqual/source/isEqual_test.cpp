#include <gtest/gtest.h>

#include "isEqual.hpp"

TEST(tts, tts0)
{
    EXPECT_EQ(convertTextToSound("hello"), "H400");
}
TEST(tts, tts1)
{
    EXPECT_EQ(convertTextToSound("world"), "W643");
}
TEST(tts, tts2)
{
    EXPECT_EQ(convertTextToSound("apple"), "A140");
}
TEST(tts, tts3)
{
    EXPECT_EQ(convertTextToSound("test"), "T230");
}
TEST(tts, tts4)
{
    EXPECT_EQ(convertTextToSound("happy"), "H100");
}
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "ip_filter_utils.cpp"

using testing::Contains;
using testing::ElementsAre;
using testing::Pointee;


bool operator==(const string& a, const string& b)
{
    return a == b;
}


TEST(MagicTest, CharacterVectorContains)
{
    auto computed = split("222.173.235.246", '.');
    ASSERT_THAT(computed, ElementsAre("222", "173", "235", "246"));
}

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ip_filter.cpp"

TEST(SplitTest, HandlesZeroInput) {
	auto computed = split("222.173.235.246", '.');
	ASSERT_THAT(computed, ElementsAre(222,173,235,246));
	//EXPECT_EQ(1, 1);
}

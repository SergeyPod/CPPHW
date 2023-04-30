#include <map>

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "allocator_container.cpp"


using testing::Contains;
using testing::ElementsAre;
using testing::Pointee;



TEST(AllocatorTest, Tasks1to2)
{
	std::map<int, int> map;
	for (auto i = 0; i < 10; ++i) {
		map[i] = factorial(i);
	}

	for (auto it = map.begin(); it != map.begin(); ++it)
	{
		EXPECT_EQ(it->second, factorial(it->first));
	}
}

TEST(AllocatorTest, Tasks3to5)
{
	std::map<int, int, std::less<int>, Hw03_allocator< std::pair<const int, int> >> map;
	
	for (auto i = 0; i < 10; ++i) {
		map[i] = factorial(i);
	}
	std::map<int, int>::iterator it = map.begin();
	while (it != map.end())
	{
		std::cout << (*it).second << std::endl;
		EXPECT_EQ(it->second, factorial(it->first));
		++it;
	}
	
}


TEST(AllocatorTest, Tasks6to10)
{
	auto set = std::make_unique<HW03Set>();
	for (auto i = 0; i < 10; ++i) {
		set->add(i);
	}
	set->print();

}


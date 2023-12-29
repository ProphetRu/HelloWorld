#include <gtest/gtest.h>

#include "lib.h"
#include "lib.cpp"

TEST(Version, Valid) 
{
    // Arrange
    int ver = version();

    // Act (empty for this test)
	//

    // Assert
    ASSERT_LT(ver, 1000);
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
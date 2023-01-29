#include <gtest/gtest.h>
#include "../src/TJRayTracer/Vec4.h"

TEST(TupleTest, Point)
	{
        TJRayTracer::Vec4 a(4.3, -4.2, 3.1, 1.0);
		ASSERT_EQ(4.3, a.x);
		ASSERT_EQ(-4.2,a.y);
        ASSERT_EQ(3.1,a.z);
        ASSERT_EQ(1.0,a.w);
        ASSERT_EQ(true, a.IsPoint());
        ASSERT_EQ(false,a.IsVector());
	}

TEST(TupleTest, Vector)
{
    TJRayTracer::Vec4 a(4.3, -4.2, 3.1, 0.0);
    ASSERT_EQ(4.3, a.x);
    ASSERT_EQ(-4.2,a.y);
    ASSERT_EQ(3.1,a.z);
    ASSERT_EQ(0.0,a.w);
    ASSERT_EQ(false, a.IsPoint());
    ASSERT_EQ(true,a.IsVector());

}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

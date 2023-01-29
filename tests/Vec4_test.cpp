#include <gtest/gtest.h>
#include "../src/TJRayTracer/Vec4.h"
#include "../src/TJRayTracer/Vector.h"
#include "../src/TJRayTracer/Point.h"


TEST(TupleTest, PointUsingBaseClass)
	{
        TJRayTracer::Vec4 a(4.3, -4.2, 3.1, 1.0);
		ASSERT_EQ(4.3, a.x);
		ASSERT_EQ(-4.2,a.y);
        ASSERT_EQ(3.1,a.z);
        ASSERT_EQ(1.0,a.w);
        ASSERT_EQ(true, a.IsPoint());
        ASSERT_EQ(false,a.IsVector());
	}

TEST(TupleTest, VectorUsingBaseClass)
{
    TJRayTracer::Vec4 a(4.3, -4.2, 3.1, 0.0);
    ASSERT_EQ(4.3, a.x);
    ASSERT_EQ(-4.2,a.y);
    ASSERT_EQ(3.1,a.z);
    ASSERT_EQ(0.0,a.w);
    ASSERT_EQ(false, a.IsPoint());
    ASSERT_EQ(true,a.IsVector());

}

TEST(TupleTest, Point)
{
    TJRayTracer::Point p(4, -4, 3);
    ASSERT_EQ(4, p.x);
    ASSERT_EQ(-4,p.y);
    ASSERT_EQ(3,p.z);
    ASSERT_EQ(1.0,p.w);
    ASSERT_EQ(true, p.IsPoint());
    ASSERT_EQ(false,p.IsVector());
}

TEST(TupleTest, Vector)
{
    TJRayTracer::Vector v(4, -4, 3);
    ASSERT_EQ(4, v.x);
    ASSERT_EQ(-4,v.y);
    ASSERT_EQ(3,v.z);
    ASSERT_EQ(0.0,v.w);
    ASSERT_EQ(false, v.IsPoint());
    ASSERT_EQ(true,v.IsVector());

}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

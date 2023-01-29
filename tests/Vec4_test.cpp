#include <gtest/gtest.h>
#include "../src/TJRayTracer/Vec4.h"
#include "../src/TJRayTracer/Vector.h"
#include "../src/TJRayTracer/Point.h"
#include "../src/TJRayTracer/Equal.h"

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
    ASSERT_EQ(p, TJRayTracer::Vec4(4,-4,3,1.0));
}

TEST(TupleTest, Vector)
{
    TJRayTracer::Vector v(4, -4, 3);
    ASSERT_EQ(v, TJRayTracer::Vec4(4,-4,3,0.0));
}

TEST(TupleTest, AdditionOfVectorAndPoint)
{
    TJRayTracer::Vec4 a1(3, -2, 5, 1);
    TJRayTracer::Vec4 a2(-2, 3, 1, 0);
    ASSERT_EQ(a1+a2, TJRayTracer::Vec4(1, 1, 6, 1));
}

TEST(TupleTest, Addition)
{
    TJRayTracer::Point a1(3, -2, 5);
    TJRayTracer::Vector a2(-2, 3, 1);
    ASSERT_EQ(a1+a2, TJRayTracer::Vec4(1, 1, 6, 1));
}

TEST(TupleTest, SubtractionOfTwoPoints)
{
    TJRayTracer::Point p1(3, 2, 1);
    TJRayTracer::Point p2(5,6,7);
    ASSERT_EQ(p1-p2, TJRayTracer::Vector(-2,-4,-6));
}

TEST(TupleTest, SubtractionOfPointAndVector)
{
    TJRayTracer::Point p(3,2,1);
    TJRayTracer::Vector v(5,6,7);
    ASSERT_EQ(p-v,TJRayTracer::Point(-2,-4,-6));
}

TEST(TupleTest, SubtractionOfTwoVectors)
{
    TJRayTracer::Vector v1(3,2,1);
    TJRayTracer::Vector v2(5,6,7);
    ASSERT_EQ(v1-v2,TJRayTracer::Vector(-2,-4,-6));
}

TEST(TupleTest, NegatingTuples)
{
    TJRayTracer::Vec4 a(1,-2,3,-4);
    ASSERT_EQ(-a,TJRayTracer::Vec4(-1,2,-3,4));
}

TEST(TupleTest, MultiplyingTupleByScalar)
{
    TJRayTracer::Vec4 a(1,-2,3,-4);
    ASSERT_EQ(3.5*a,TJRayTracer::Vec4(3.5,-7,10.5,-14));
}

TEST(TupleTest, MultiplyingTupleByFraction)
{
    TJRayTracer::Vec4 a(1,-2,3,-4);
    ASSERT_EQ(0.5*a,TJRayTracer::Vec4(0.5,-1,1.5,-2));
}

TEST(TupleTest, DividingATupleByScalar)
{
    TJRayTracer::Vector a(1,-2,3);
    ASSERT_EQ(a/2,TJRayTracer::Vec4(0.5,-1,1.5,0.0));
}

TEST(TupleTest, Magnitude)
{
    TJRayTracer::Vector v(-1,-2,-3);
    ASSERT_EQ(equal(TJRayTracer::Vector::magnitude(v),3.74166), true);
}

TEST(TupleTest, Normalize)
{
    TJRayTracer::Vector v(1,2,3);
    ASSERT_EQ(TJRayTracer::Vector(0.26726, 0.53452, 0.80178), v.normalize());
}

TEST(TupleTest, MagnitudeAfterNormalization)
{
    TJRayTracer::Vector v(1,2,3);
    TJRayTracer::Vector normed = v.normalize();
    ASSERT_EQ(equal(TJRayTracer::Vector::magnitude(normed),1.0), true);
}

TEST(TupleTest, DotProduct)
{
    TJRayTracer::Vector v1(1,2,3);
    TJRayTracer::Vector v2(2,3,4);
    ASSERT_EQ(equal(TJRayTracer::Vector::dot(v1,v2),20.0), true);
}

TEST(TupleTest, CrossProduct)
{
    TJRayTracer::Vector v1(1,2,3);
    TJRayTracer::Vector v2(2,3,4);
    ASSERT_EQ(TJRayTracer::Vector::cross(v1,v2),TJRayTracer::Vector(-1,2,-1));
    ASSERT_EQ(TJRayTracer::Vector::cross(v2,v1),TJRayTracer::Vector(1,-2,1));
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

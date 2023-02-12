#include "../src/TJRayTracer/BasePattern.h"
#include "../src/TJRayTracer/Camera.h"
#include "../src/TJRayTracer/Canvas.h"
#include "../src/TJRayTracer/CheckersPattern.h"
#include "../src/TJRayTracer/Color.h"
#include "../src/TJRayTracer/Comps.h"
#include "../src/TJRayTracer/Equal.h"
#include "../src/TJRayTracer/GradientPattern.h"
#include "../src/TJRayTracer/Intersection.h"
#include "../src/TJRayTracer/Material.h"
#include "../src/TJRayTracer/MatrixXd.h"
#include "../src/TJRayTracer/Plane.h"
#include "../src/TJRayTracer/Point.h"
#include "../src/TJRayTracer/PointLight.h"
#include "../src/TJRayTracer/Ray.h"
#include "../src/TJRayTracer/RingPattern.h"
#include "../src/TJRayTracer/Sphere.h"
#include "../src/TJRayTracer/StrippedPattern.h"
#include "../src/TJRayTracer/TF.h"
#include "../src/TJRayTracer/TestPattern.h"
#include "../src/TJRayTracer/Vec4.h"
#include "../src/TJRayTracer/Vector.h"
#include "../src/TJRayTracer/World.h"
#include <gtest/gtest.h>

TEST(TupleTest, PointUsingBaseClass) {
  TJRayTracer::Vec4 a(4.3, -4.2, 3.1, 1.0);
  ASSERT_EQ(4.3, a.x);
  ASSERT_EQ(-4.2, a.y);
  ASSERT_EQ(3.1, a.z);
  ASSERT_EQ(1.0, a.w);
  ASSERT_EQ(true, a.IsPoint());
  ASSERT_EQ(false, a.IsVector());
}

TEST(TupleTest, VectorUsingBaseClass) {
  TJRayTracer::Vec4 a(4.3, -4.2, 3.1, 0.0);
  ASSERT_EQ(4.3, a.x);
  ASSERT_EQ(-4.2, a.y);
  ASSERT_EQ(3.1, a.z);
  ASSERT_EQ(0.0, a.w);
  ASSERT_EQ(false, a.IsPoint());
  ASSERT_EQ(true, a.IsVector());
}

TEST(TupleTest, Point) {
  TJRayTracer::Point p(4, -4, 3);
  ASSERT_EQ(p, TJRayTracer::Vec4(4, -4, 3, 1.0));
}

TEST(TupleTest, Vector) {
  TJRayTracer::Vector v(4, -4, 3);
  ASSERT_EQ(v, TJRayTracer::Vec4(4, -4, 3, 0.0));
}

TEST(TupleTest, Addition) {
  TJRayTracer::Point a1(3, -2, 5);
  TJRayTracer::Vector a2(-2, 3, 1);
  ASSERT_EQ(a1 + a2, TJRayTracer::Vec4(1, 1, 6, 1));
}

TEST(TupleTest, SubtractionOfTwoPoints) {
  TJRayTracer::Point p1(3, 2, 1);
  TJRayTracer::Point p2(5, 6, 7);
  ASSERT_EQ(p1 - p2, TJRayTracer::Vector(-2, -4, -6));
}

TEST(TupleTest, SubtractionOfPointAndVector) {
  TJRayTracer::Point p(3, 2, 1);
  TJRayTracer::Vector v(5, 6, 7);
  ASSERT_EQ(p - v, TJRayTracer::Point(-2, -4, -6));
}

TEST(TupleTest, SubtractionOfTwoVectors) {
  TJRayTracer::Vector v1(3, 2, 1);
  TJRayTracer::Vector v2(5, 6, 7);
  ASSERT_EQ(v1 - v2, TJRayTracer::Vector(-2, -4, -6));
}

TEST(TupleTest, DividingATupleByScalar) {
  TJRayTracer::Vector a(1, -2, 3);
  ASSERT_EQ(a / 2, TJRayTracer::Vec4(0.5, -1, 1.5, 0.0));
}

TEST(TupleTest, Magnitude) {
  TJRayTracer::Vector v(-1, -2, -3);
  ASSERT_EQ(equal(TJRayTracer::Vector::magnitude(v), 3.74166), true);
}

TEST(TupleTest, Normalize) {
  TJRayTracer::Vector v(1, 2, 3);
  ASSERT_EQ(TJRayTracer::Vector(0.26726, 0.53452, 0.80178), v.normalize());
}

TEST(TupleTest, MagnitudeAfterNormalization) {
  TJRayTracer::Vector v(1, 2, 3);
  TJRayTracer::Vector normed = v.normalize();
  ASSERT_EQ(equal(TJRayTracer::Vector::magnitude(normed), 1.0), true);
}

TEST(TupleTest, DotProduct) {
  TJRayTracer::Vector v1(1, 2, 3);
  TJRayTracer::Vector v2(2, 3, 4);
  ASSERT_EQ(equal(TJRayTracer::Vector::dot(v1, v2), 20.0), true);
}

TEST(TupleTest, CrossProduct) {
  TJRayTracer::Vector v1(1, 2, 3);
  TJRayTracer::Vector v2(2, 3, 4);
  ASSERT_EQ(TJRayTracer::Vector::cross(v1, v2), TJRayTracer::Vector(-1, 2, -1));
  ASSERT_EQ(TJRayTracer::Vector::cross(v2, v1), TJRayTracer::Vector(1, -2, 1));
}

TEST(SecondChapter, ColorAsTuple) {
  TJRayTracer::Color c(-0.5, 0.4, 1.7);
  ASSERT_EQ(equal(c.red, -0.5), true);
  ASSERT_EQ(equal(c.green, 0.4), true);
  ASSERT_EQ(equal(c.blue, 1.7), true);
}

TEST(SecondChapter, AddingColors) {
  TJRayTracer::Color c1(0.9, 0.6, 0.75);
  TJRayTracer::Color c2(0.7, 0.1, 0.25);
  ASSERT_EQ(c1 + c2, TJRayTracer::Color(1.6, 0.7, 1.0));
}

TEST(SecondChapter, SubtractingColors) {
  TJRayTracer::Color c1(0.9, 0.6, 0.75);
  TJRayTracer::Color c2(0.7, 0.1, 0.25);
  ASSERT_EQ(c1 - c2, TJRayTracer::Color(0.2, 0.5, 0.5));
}

TEST(SecondChapter, ColorMultipliedByScalar) {
  TJRayTracer::Color c(0.2, 0.3, 0.4);
  ASSERT_EQ(2 * c, TJRayTracer::Color(0.4, 0.6, 0.8));
}

TEST(SecondChapter, MultiplyingColors) {
  TJRayTracer::Color c1(1, 0.2, 0.4);
  TJRayTracer::Color c2(0.9, 1, 0.1);
  ASSERT_EQ(c1 * c2, TJRayTracer::Color(0.9, 0.2, 0.04));
}

TEST(SecondChapter, CreateCanvas) {
  TJRayTracer::Canvas c(10, 20);
  int width = 10;
  int height = 20;
  ASSERT_EQ(c.GetWidth(), 10);
  ASSERT_EQ(c.GetHeight(), 20);
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      ASSERT_EQ(c.GetPixelColor(x, y), TJRayTracer::Color(0, 0, 0));
    }
  }
}

TEST(SecondChapter, WritePixelsToCanvas) {
  TJRayTracer::Canvas c(10, 20);
  TJRayTracer::Color red(1, 0, 0);
  c.SetPixelColor(2, 3, red);
  ASSERT_EQ(c.GetPixelColor(2, 3), red);
}

TEST(SecondChapter, CreatePNGFile) {
  TJRayTracer::Canvas c(400, 600);
  TJRayTracer::Color red(1, 0, 0);
  c.SetPixelColor(2, 3, red);
  ASSERT_EQ(c.RenderPng("test"), true);
}

TEST(ThirdChapter, CreateMatrix) {
  TJRayTracer::MatrixXd<double, 4, 4> M;
  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 4;
  M(1, 0) = 5.5;
  M(1, 1) = 6.5;
  M(1, 2) = 7.5;
  M(1, 3) = 8.5;
  M(2, 0) = 9;
  M(2, 1) = 10;
  M(2, 2) = 11;
  M(2, 3) = 12;
  M(3, 0) = 13.5;
  M(3, 1) = 14.5;
  M(3, 2) = 15.5;
  M(3, 3) = 16.5;

  ASSERT_EQ(equal(M(0, 0), 1), true);
  ASSERT_EQ(equal(M(0, 3), 4), true);
  ASSERT_EQ(equal(M(1, 0), 5.5), true);
  ASSERT_EQ(equal(M(1, 2), 7.5), true);
  ASSERT_EQ(equal(M(2, 2), 11), true);
  ASSERT_EQ(equal(M(3, 0), 13.5), true);
  ASSERT_EQ(equal(M(3, 2), 15.5), true);
}

TEST(ThirdChapter, CreateMatrix2by2) {
  TJRayTracer::MatrixXd<double, 2, 2> M;
  M(0, 0) = -3;
  M(0, 1) = 5;
  M(1, 0) = 1;
  M(1, 1) = -2;

  ASSERT_EQ(equal(M(0, 0), -3), true);
  ASSERT_EQ(equal(M(0, 1), 5), true);
  ASSERT_EQ(equal(M(1, 0), 1), true);
  ASSERT_EQ(equal(M(1, 1), -2), true);
}

TEST(ThirdChapter, CreateMatrix3by3) {
  TJRayTracer::MatrixXd<double, 3, 3> M;
  M(0, 0) = -3;
  M(0, 1) = 5;
  M(0, 2) = 0;
  M(1, 0) = 1;
  M(1, 1) = -2;
  M(1, 2) = -7;
  M(2, 0) = 0;
  M(2, 1) = 1;
  M(2, 2) = 1;

  ASSERT_EQ(equal(M(0, 0), -3), true);
  ASSERT_EQ(equal(M(1, 1), -2), true);
  ASSERT_EQ(equal(M(2, 2), 1), true);
}

TEST(ThirdChapter, EqualityOfMatrices) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 4;
  A(1, 0) = 5;
  A(1, 1) = 6;
  A(1, 2) = 7;
  A(1, 3) = 8;
  A(2, 0) = 9;
  A(2, 1) = 8;
  A(2, 2) = 7;
  A(2, 3) = 6;
  A(3, 0) = 5;
  A(3, 1) = 4;
  A(3, 2) = 3;
  A(3, 3) = 2;

  TJRayTracer::MatrixXd<double, 4, 4> B;
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 8;
  B(2, 2) = 7;
  B(2, 3) = 6;
  B(3, 0) = 5;
  B(3, 1) = 4;
  B(3, 2) = 3;
  B(3, 3) = 2;

  ASSERT_EQ(A == B, true);
}

TEST(ThirdChapter, InequalityOfMatrices) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 4;
  A(1, 0) = 5;
  A(1, 1) = 6;
  A(1, 2) = 7;
  A(1, 3) = 8;
  A(2, 0) = 9;
  A(2, 1) = 8;
  A(2, 2) = 7;
  A(2, 3) = 6;
  A(3, 0) = 5;
  A(3, 1) = 4;
  A(3, 2) = 3;
  A(3, 3) = 2;

  TJRayTracer::MatrixXd<double, 4, 4> B;
  B(0, 0) = 2;
  B(0, 1) = 3;
  B(0, 2) = 4;
  B(0, 3) = 5;
  B(1, 0) = 6;
  B(1, 1) = 7;
  B(1, 2) = 8;
  B(1, 3) = 9;
  B(2, 0) = 8;
  B(2, 1) = 7;
  B(2, 2) = 6;
  B(2, 3) = 5;
  B(3, 0) = 4;
  B(3, 1) = 3;
  B(3, 2) = 2;
  B(3, 3) = 1;

  ASSERT_EQ(A != B, true);
}

TEST(ThirdChapter, MatrixMultiplication) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 4;
  A(1, 0) = 5;
  A(1, 1) = 6;
  A(1, 2) = 7;
  A(1, 3) = 8;
  A(2, 0) = 9;
  A(2, 1) = 8;
  A(2, 2) = 7;
  A(2, 3) = 6;
  A(3, 0) = 5;
  A(3, 1) = 4;
  A(3, 2) = 3;
  A(3, 3) = 2;

  TJRayTracer::MatrixXd<double, 4, 4> B;
  B(0, 0) = -2;
  B(0, 1) = 1;
  B(0, 2) = 2;
  B(0, 3) = 3;
  B(1, 0) = 3;
  B(1, 1) = 2;
  B(1, 2) = 1;
  B(1, 3) = -1;
  B(2, 0) = 4;
  B(2, 1) = 3;
  B(2, 2) = 6;
  B(2, 3) = 5;
  B(3, 0) = 1;
  B(3, 1) = 2;
  B(3, 2) = 7;
  B(3, 3) = 8;

  TJRayTracer::MatrixXd<double, 4, 4> C;
  C(0, 0) = 20;
  C(0, 1) = 22;
  C(0, 2) = 50;
  C(0, 3) = 48;
  C(1, 0) = 44;
  C(1, 1) = 54;
  C(1, 2) = 114;
  C(1, 3) = 108;
  C(2, 0) = 40;
  C(2, 1) = 58;
  C(2, 2) = 110;
  C(2, 3) = 102;
  C(3, 0) = 16;
  C(3, 1) = 26;
  C(3, 2) = 46;
  C(3, 3) = 42;

  ASSERT_EQ((A * B) == C, true);
}

TEST(ThirdChapter, MatrixMultipliedByPoint) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 4;
  A(1, 0) = 2;
  A(1, 1) = 4;
  A(1, 2) = 4;
  A(1, 3) = 2;
  A(2, 0) = 8;
  A(2, 1) = 6;
  A(2, 2) = 4;
  A(2, 3) = 1;
  A(3, 0) = 0;
  A(3, 1) = 0;
  A(3, 2) = 0;
  A(3, 3) = 1;
  TJRayTracer::Point b(1, 2, 3);
  ASSERT_EQ(A * b, TJRayTracer::Point(18, 24, 33));
}

TEST(ThirdChapter, IdentityMatrix) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A.identity();
  ASSERT_EQ(equal(A(0, 0), 1), true);
  ASSERT_EQ(equal(A(0, 1), 0), true);
  ASSERT_EQ(equal(A(0, 2), 0), true);
  ASSERT_EQ(equal(A(0, 3), 0), true);
  ASSERT_EQ(equal(A(1, 0), 0), true);
  ASSERT_EQ(equal(A(1, 1), 1), true);
  ASSERT_EQ(equal(A(1, 2), 0), true);
  ASSERT_EQ(equal(A(1, 3), 0), true);
  ASSERT_EQ(equal(A(2, 0), 0), true);
  ASSERT_EQ(equal(A(2, 1), 0), true);
  ASSERT_EQ(equal(A(2, 2), 1), true);
  ASSERT_EQ(equal(A(2, 3), 0), true);
  ASSERT_EQ(equal(A(3, 0), 0), true);
  ASSERT_EQ(equal(A(3, 1), 0), true);
  ASSERT_EQ(equal(A(3, 2), 0), true);
  ASSERT_EQ(equal(A(3, 3), 1), true);
}

TEST(ThirdChapter, TransposeMatrix) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A(0, 0) = 0;
  A(0, 1) = 9;
  A(0, 2) = 3;
  A(0, 3) = 0;
  A(1, 0) = 9;
  A(1, 1) = 8;
  A(1, 2) = 0;
  A(1, 3) = 8;
  A(2, 0) = 1;
  A(2, 1) = 8;
  A(2, 2) = 5;
  A(2, 3) = 3;
  A(3, 0) = 0;
  A(3, 1) = 0;
  A(3, 2) = 5;
  A(3, 3) = 8;
  TJRayTracer::MatrixXd<double, 4, 4> B;
  B(0, 0) = 0;
  B(0, 1) = 9;
  B(0, 2) = 1;
  B(0, 3) = 0;
  B(1, 0) = 9;
  B(1, 1) = 8;
  B(1, 2) = 8;
  B(1, 3) = 0;
  B(2, 0) = 3;
  B(2, 1) = 0;
  B(2, 2) = 5;
  B(2, 3) = 5;
  B(3, 0) = 0;
  B(3, 1) = 8;
  B(3, 2) = 3;
  B(3, 3) = 8;
  A.transpose();
  ASSERT_EQ(A == B, true);
}

TEST(ThirdChapter, TransposeOfIndentityMatrix) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A.identity();
  TJRayTracer::MatrixXd<double, 4, 4> B;
  B(0, 0) = 1;
  B(0, 1) = 0;
  B(0, 2) = 0;
  B(0, 3) = 0;
  B(1, 0) = 0;
  B(1, 1) = 1;
  B(1, 2) = 0;
  B(1, 3) = 0;
  B(2, 0) = 0;
  B(2, 1) = 0;
  B(2, 2) = 1;
  B(2, 3) = 0;
  B(3, 0) = 0;
  B(3, 1) = 0;
  B(3, 2) = 0;
  B(3, 3) = 1;
  A.transpose();
  ASSERT_EQ(A == B, true);
}

TEST(ThirdChapter, Determinant2by2) {
  TJRayTracer::MatrixXd<double, 2, 2> A;
  A(0, 0) = 1;
  A(0, 1) = 5;
  A(1, 0) = -3;
  A(1, 1) = 2;
  double d = A.Determinant();
  ASSERT_EQ(equal(d, 17), true);
}

TEST(ThirdChapter, Submatrix) {
  TJRayTracer::MatrixXd<double, 3, 3> A;
  TJRayTracer::MatrixXd<double, 2, 2> B;
  A(0, 0) = 1;
  A(0, 1) = 5;
  A(0, 2) = 0;
  A(1, 0) = -3;
  A(1, 1) = 2;
  A(1, 2) = 7;
  A(2, 0) = 0;
  A(2, 1) = 6;
  A(2, 2) = -3;
  TJRayTracer::MatrixXd<double, 2, 2> C;
  C(0, 0) = -3;
  C(0, 1) = 2;
  C(1, 0) = 0;
  C(1, 1) = 6;
  B = A.submatrix<double, 2, 2>(0, 2);
  ASSERT_EQ(B == C, true);
}

TEST(ThirdChapter, Submatrix2) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  TJRayTracer::MatrixXd<double, 3, 3> B;
  A(0, 0) = -6;
  A(0, 1) = 1;
  A(0, 2) = 1;
  A(0, 3) = 6;
  A(1, 0) = -8;
  A(1, 1) = 5;
  A(1, 2) = 8;
  A(1, 3) = 6;
  A(2, 0) = -1;
  A(2, 1) = 0;
  A(2, 2) = 8;
  A(2, 3) = 2;
  A(3, 0) = -7;
  A(3, 1) = 1;
  A(3, 2) = -1;
  A(3, 3) = 1;
  TJRayTracer::MatrixXd<double, 3, 3> C;
  C(0, 0) = -6;
  C(0, 1) = 1;
  C(0, 2) = 6;
  C(1, 0) = -8;
  C(1, 1) = 8;
  C(1, 2) = 6;
  C(2, 0) = -7;
  C(2, 1) = -1;
  C(2, 2) = 1;
  B = A.submatrix<double, 3, 3>(2, 1);
  ASSERT_EQ(B == C, true);
}

TEST(ThirdChapter, Minor) {
  TJRayTracer::MatrixXd<double, 3, 3> A;
  A(0, 0) = 3;
  A(0, 1) = 5;
  A(0, 2) = 0;
  A(1, 0) = 2;
  A(1, 1) = -1;
  A(1, 2) = -7;
  A(2, 0) = 6;
  A(2, 1) = -1;
  A(2, 2) = 5;
  ASSERT_EQ(equal(A.minor(1, 0), 25), true);
}

TEST(ThirdChapter, Cofactor) {
  TJRayTracer::MatrixXd<double, 3, 3> A;
  A(0, 0) = 3;
  A(0, 1) = 5;
  A(0, 2) = 0;
  A(1, 0) = 2;
  A(1, 1) = -1;
  A(1, 2) = -7;
  A(2, 0) = 6;
  A(2, 1) = -1;
  A(2, 2) = 5;
  ASSERT_EQ(equal(A.minor(0, 0), -12), true);
  ASSERT_EQ(equal(A.cofactor(0, 0), -12), true);
  ASSERT_EQ(equal(A.minor(1, 0), 25), true);
  ASSERT_EQ(equal(A.cofactor(1, 0), -25), true);
}

TEST(ThirdChapter, 3by3Determinant) {
  TJRayTracer::MatrixXd<double, 3, 3> A;
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 6;
  A(1, 0) = -5;
  A(1, 1) = 8;
  A(1, 2) = -4;
  A(2, 0) = 2;
  A(2, 1) = 6;
  A(2, 2) = 4;
  ASSERT_EQ(equal(A.cofactor(0, 0), 56), true);
  ASSERT_EQ(equal(A.cofactor(0, 1), 12), true);
  ASSERT_EQ(equal(A.cofactor(0, 2), -46), true);
  ASSERT_EQ(equal(A.Determinant(), -196), true);
}

TEST(ThirdChapter, 4by4Determinant) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A(0, 0) = -2;
  A(0, 1) = -8;
  A(0, 2) = 3;
  A(0, 3) = 5;
  A(1, 0) = -3;
  A(1, 1) = 1;
  A(1, 2) = 7;
  A(1, 3) = 3;
  A(2, 0) = 1;
  A(2, 1) = 2;
  A(2, 2) = -9;
  A(2, 3) = 6;
  A(3, 0) = -6;
  A(3, 1) = 7;
  A(3, 2) = 7;
  A(3, 3) = -9;
  ASSERT_EQ(equal(A.cofactor(0, 0), 690), true);
  ASSERT_EQ(equal(A.cofactor(0, 1), 447), true);
  ASSERT_EQ(equal(A.cofactor(0, 2), 210), true);
  ASSERT_EQ(equal(A.cofactor(0, 3), 51), true);
  ASSERT_EQ(equal(A.Determinant(), -4071), true);
}

TEST(ThirdChapter, Invertible) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A(0, 0) = -5;
  A(0, 1) = 2;
  A(0, 2) = 6;
  A(0, 3) = -8;
  A(1, 0) = 1;
  A(1, 1) = -5;
  A(1, 2) = 1;
  A(1, 3) = 8;
  A(2, 0) = 7;
  A(2, 1) = 7;
  A(2, 2) = -6;
  A(2, 3) = -7;
  A(3, 0) = 1;
  A(3, 1) = -3;
  A(3, 2) = 7;
  A(3, 3) = 4;
  TJRayTracer::MatrixXd<double, 4, 4> B;
  B(0, 0) = 0.21805;
  B(0, 1) = 0.45113;
  B(0, 2) = 0.24060;
  B(0, 3) = -0.04511;
  B(1, 0) = -0.80827;
  B(1, 1) = -1.45677;
  B(1, 2) = -0.44361;
  B(1, 3) = 0.52068;
  B(2, 0) = -0.07895;
  B(2, 1) = -0.22368;
  B(2, 2) = -0.05263;
  B(2, 3) = 0.19737;
  B(3, 0) = -0.52256;
  B(3, 1) = -0.81391;
  B(3, 2) = -0.30075;
  B(3, 3) = 0.30639;
  ASSERT_EQ((A.inverse()) == B, true);
}

TEST(ThirdChapter, MultiplyingAProductByItsInverse) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A(0, 0) = 3;
  A(0, 1) = -9;
  A(0, 2) = 7;
  A(0, 3) = 3;
  A(1, 0) = 3;
  A(1, 1) = -8;
  A(1, 2) = 2;
  A(1, 3) = -9;
  A(2, 0) = -4;
  A(2, 1) = 4;
  A(2, 2) = 4;
  A(2, 3) = 1;
  A(3, 0) = -6;
  A(3, 1) = 5;
  A(3, 2) = -1;
  A(3, 3) = 1;
  TJRayTracer::MatrixXd<double, 4, 4> B;
  B(0, 0) = 8;
  B(0, 1) = 2;
  B(0, 2) = 2;
  B(0, 3) = 2;
  B(1, 0) = 3;
  B(1, 1) = -1;
  B(1, 2) = 7;
  B(1, 3) = 0;
  B(2, 0) = 7;
  B(2, 1) = 0;
  B(2, 2) = 5;
  B(2, 3) = 4;
  B(3, 0) = 6;
  B(3, 1) = -2;
  B(3, 2) = 0;
  B(3, 3) = 5;
  TJRayTracer::MatrixXd<double, 4, 4> C = A * B;
  ASSERT_EQ((C * B.inverse()) == A, true);
}

TEST(FourthChapter, IdentityTransform) {
  TJRayTracer::MatrixXd<double, 4, 4> A;
  A.identity();
  TJRayTracer::TF tf;
  ASSERT_EQ(A == tf.GetTransform(), true);
}

TEST(FourthChapter, MultiplyingByATranslationMatrix) {
  TJRayTracer::TF tf;
  tf = TJRayTracer::TF::translation(5, -3, 2);
  auto p = TJRayTracer::Point(-3, 4, 5);
  ASSERT_EQ(tf.GetTransform() * p, TJRayTracer::Point(2, 1, 7));
}

TEST(FourthChapter, MultiplyingByTheInverseOfATranslationMatrix) {
  TJRayTracer::TF tf;
  tf = TJRayTracer::TF::translation(5, -3, 2);
  TJRayTracer::TF tf2;
  tf2 = tf.GetTransform().inverse();
  auto p = TJRayTracer::Point(-3, 4, 5);
  ASSERT_EQ(tf2.GetTransform() * p, TJRayTracer::Point(-8, 7, 3));
}

TEST(FourthChapter, TranslationDoesNotEffectVectors) {
  TJRayTracer::TF tf;
  tf = TJRayTracer::TF::translation(5, -3, 2);
  auto v = TJRayTracer::Vector(-3, 4, 5);
  ASSERT_EQ(tf.GetTransform() * v, v);
}

TEST(FourthChapter, AScalingMatrixAppliedToAPoint) {
  TJRayTracer::TF tf;
  tf = TJRayTracer::TF::scaling(2, 3, 4);
  auto p = TJRayTracer::Point(-4, 6, 8);
  ASSERT_EQ(tf.GetTransform() * p, TJRayTracer::Point(-8, 18, 32));
}

TEST(FourthChapter, AScalingMatrixAppliedToAVector) {
  TJRayTracer::TF tf;
  tf = TJRayTracer::TF::scaling(2, 3, 4);
  auto v = TJRayTracer::Vector(-4, 6, 8);
  ASSERT_EQ(tf.GetTransform() * v, TJRayTracer::Vector(-8, 18, 32));
}

TEST(FourthChapter, MultiplyingByTheInverseOfAScalingMatrix) {
  TJRayTracer::TF tf;
  tf = TJRayTracer::TF::scaling(2, 3, 4);
  TJRayTracer::TF tf2;
  tf2 = tf.GetTransform().inverse();
  auto v = TJRayTracer::Vector(-4, 6, 8);
  ASSERT_EQ(tf2.GetTransform() * v, TJRayTracer::Vector(-2, 2, 2));
}

TEST(FourthChapter, Reflection) {
  TJRayTracer::TF tf;
  tf = TJRayTracer::TF::scaling(-1, 1, 1);
  auto p = TJRayTracer::Point(2, 3, 4);
  ASSERT_EQ(tf.GetTransform() * p, TJRayTracer::Point(-2, 3, 4));
}

TEST(FourthChapter, RotatatePointAroundXaxis) {
  TJRayTracer::TF half_quarter;
  half_quarter = TJRayTracer::TF::rotation_x(M_PI_4);
  TJRayTracer::TF full_quarter;
  full_quarter = TJRayTracer::TF::rotation_x(M_PI_2);
  auto p = TJRayTracer::Point(0, 1, 0);
  ASSERT_EQ(half_quarter.GetTransform() * p,
            TJRayTracer::Point(0, sqrt(2) / 2, sqrt(2) / 2));
  ASSERT_EQ(full_quarter.GetTransform() * p, TJRayTracer::Point(0, 0, 1));
}

TEST(FourthChapter, RotatateAntiClockwiseAroundXaxis) {
  TJRayTracer::TF half_quarter;
  half_quarter = TJRayTracer::TF::rotation_x(M_PI_4);
  auto p = TJRayTracer::Point(0, 1, 0);
  ASSERT_EQ((half_quarter.GetTransform().inverse()) * p,
            TJRayTracer::Point(0, sqrt(2) / 2, -sqrt(2) / 2));
}

TEST(FourthChapter, RotatatePointAroundYaxis) {
  TJRayTracer::TF half_quarter;
  half_quarter = TJRayTracer::TF::rotation_y(M_PI_4);
  TJRayTracer::TF full_quarter;
  full_quarter = TJRayTracer::TF::rotation_y(M_PI_2);
  auto p = TJRayTracer::Point(0, 0, 1);
  ASSERT_EQ(half_quarter.GetTransform() * p,
            TJRayTracer::Point(sqrt(2) / 2, 0, sqrt(2) / 2));
  ASSERT_EQ(full_quarter.GetTransform() * p, TJRayTracer::Point(1, 0, 0));
}

TEST(FourthChapter, RotatatePointAroundZaxis) {
  TJRayTracer::TF half_quarter;
  half_quarter = TJRayTracer::TF::rotation_z(M_PI_4);
  TJRayTracer::TF full_quarter;
  full_quarter = TJRayTracer::TF::rotation_z(M_PI_2);
  auto p = TJRayTracer::Point(0, 1, 0);
  ASSERT_EQ(half_quarter.GetTransform() * p,
            TJRayTracer::Point(-sqrt(2) / 2, sqrt(2) / 2, 0));
  ASSERT_EQ(full_quarter.GetTransform() * p, TJRayTracer::Point(-1, 0, 0));
}

TEST(FourthChapter, MovesXinProportionToY) {
  TJRayTracer::TF shearing;
  shearing = TJRayTracer::TF::shearing(1, 0, 0, 0, 0, 0);
  auto p = TJRayTracer::Point(2, 3, 4);
  ASSERT_EQ(shearing.GetTransform() * p, TJRayTracer::Point(5, 3, 4));
}

TEST(FourthChapter, MovesXinProportionToZ) {
  TJRayTracer::TF shearing;
  shearing = TJRayTracer::TF::shearing(0, 1, 0, 0, 0, 0);
  auto p = TJRayTracer::Point(2, 3, 4);
  ASSERT_EQ(shearing.GetTransform() * p, TJRayTracer::Point(6, 3, 4));
}

TEST(FourthChapter, MovesYinProportionToX) {
  TJRayTracer::TF shearing;
  shearing = TJRayTracer::TF::shearing(0, 0, 1, 0, 0, 0);
  auto p = TJRayTracer::Point(2, 3, 4);
  ASSERT_EQ(shearing.GetTransform() * p, TJRayTracer::Point(2, 5, 4));
}

TEST(FourthChapter, MovesYinProportionToZ) {
  TJRayTracer::TF shearing;
  shearing = TJRayTracer::TF::shearing(0, 0, 0, 1, 0, 0);
  auto p = TJRayTracer::Point(2, 3, 4);
  ASSERT_EQ(shearing.GetTransform() * p, TJRayTracer::Point(2, 7, 4));
}

TEST(FourthChapter, MovesZinProportionToX) {
  TJRayTracer::TF shearing;
  shearing = TJRayTracer::TF::shearing(0, 0, 0, 0, 1, 0);
  auto p = TJRayTracer::Point(2, 3, 4);
  ASSERT_EQ(shearing.GetTransform() * p, TJRayTracer::Point(2, 3, 6));
}

TEST(FourthChapter, MovesZinProportionToY) {
  TJRayTracer::TF shearing;
  shearing = TJRayTracer::TF::shearing(0, 0, 0, 0, 0, 1);
  auto p = TJRayTracer::Point(2, 3, 4);
  ASSERT_EQ(shearing.GetTransform() * p, TJRayTracer::Point(2, 3, 7));
}

TEST(FourthChapter, TransformationsWithoutChaining) {
  auto p = TJRayTracer::Point(1, 0, 1);
  auto A = TJRayTracer::TF::rotation_x(M_PI_2);
  auto B = TJRayTracer::TF::scaling(5, 5, 5);
  auto C = TJRayTracer::TF::translation(10, 5, 7);
  auto p2 = A * p;
  ASSERT_EQ(p2, TJRayTracer::Point(1, -1, 0));
  auto p3 = B * p2;
  ASSERT_EQ(p3, TJRayTracer::Point(5, -5, 0));
  auto p4 = C * p3;
  ASSERT_EQ(p4, TJRayTracer::Point(15, 0, 7));
}

TEST(FourthChapter, TransformationsWitChaining) {
  auto p = TJRayTracer::Point(1, 0, 1);
  auto A = TJRayTracer::TF::rotation_x(M_PI_2);
  auto B = TJRayTracer::TF::scaling(5, 5, 5);
  auto C = TJRayTracer::TF::translation(10, 5, 7);
  auto tf = C * B * A;
  ASSERT_EQ(tf * p, TJRayTracer::Point(15, 0, 7));
}

TEST(FifthChapter, BasicRayConstruction) {
  auto origin = TJRayTracer::Point(1, 2, 3);
  auto direction = TJRayTracer::Vector(4, 5, 6);
  auto ray = TJRayTracer::Ray(origin, direction);
  ASSERT_EQ(ray.GetOrigin(), origin);
  ASSERT_EQ(ray.GetDirection(), direction);
}

TEST(FifthChapter, ComputingAPointFromADistance) {
  auto ray = TJRayTracer::Ray(TJRayTracer::Point(2, 3, 4),
                              TJRayTracer::Vector(1, 0, 0));
  ASSERT_EQ(ray.position(0), TJRayTracer::Point(2, 3, 4));
  ASSERT_EQ(ray.position(1), TJRayTracer::Point(3, 3, 4));
  ASSERT_EQ(ray.position(-1), TJRayTracer::Point(1, 3, 4));
  ASSERT_EQ(ray.position(2.5), TJRayTracer::Point(4.5, 3, 4));
}

TEST(FifthChapter, IntersectionClass) {
  std::shared_ptr<TJRayTracer::BaseObject> s =
      std::make_shared<TJRayTracer::Sphere>();
  TJRayTracer::Intersection i(3.5, s);
  ASSERT_EQ(equal(i.t, 3.5), true);
  ASSERT_EQ(i.object, s);
}

TEST(FifthChapter, AggregatingIntersections) {
  std::shared_ptr<TJRayTracer::BaseObject> s =
      std::make_shared<TJRayTracer::Sphere>();
  TJRayTracer::Intersection i1(1, s);
  TJRayTracer::Intersection i2(2, s);
  auto xs = TJRayTracer::Intersection::intersections(i1, i2);
  ASSERT_EQ(xs.size(), 2);
  ASSERT_EQ(equal(xs[0].t, 1), true);
  ASSERT_EQ(equal(xs[1].t, 2), true);
}

TEST(FifthChapter, IntersectSetsTheObjectOnTheIntersection) {
  using namespace TJRayTracer;
  auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  std::shared_ptr<TJRayTracer::BaseObject> s =
      std::make_shared<TJRayTracer::Sphere>();
  auto xs = s->intersect(r);
  ASSERT_EQ(xs.size(), 2);
  ASSERT_EQ((*xs[0].object.get()), (*s.get()));
  ASSERT_EQ((*xs[1].object.get()), (*s.get()));
}

TEST(FifthChapter, TheHitWhenAllInterHavePositiveT) {
  using namespace TJRayTracer;
  std::shared_ptr<TJRayTracer::BaseObject> s =
      std::make_shared<TJRayTracer::Sphere>();
  auto i1 = Intersection(1, s);
  auto i2 = Intersection(2, s);
  auto xs = Intersection::intersections(i2, i1);
  auto i = s->hit(xs);
  ASSERT_EQ(i, i1);
}

TEST(FifthChapter, SomeHaveNegativeT) {
  using namespace TJRayTracer;
  std::shared_ptr<TJRayTracer::BaseObject> s =
      std::make_shared<TJRayTracer::Sphere>();
  auto i1 = Intersection(-1, s);
  auto i2 = Intersection(1, s);
  auto xs = Intersection::intersections(i2, i1);
  auto i = s->hit(xs);
  ASSERT_EQ(i, i2);
}

TEST(FifthChapter, AllHaveNegativeT) {
  using namespace TJRayTracer;
  std::shared_ptr<TJRayTracer::BaseObject> s =
      std::make_shared<TJRayTracer::Sphere>();
  auto i1 = Intersection(-2, s);
  auto i2 = Intersection(-1, s);
  auto xs = Intersection::intersections(i2, i1);
  auto i = s->hit(xs);
  ASSERT_EQ(i != i2, true);
  ASSERT_EQ(i != i1, true);
}

TEST(FifthChapter, TheHitIsAlwaysTheLowestNonnegativeIntersection) {
  using namespace TJRayTracer;
  std::shared_ptr<TJRayTracer::BaseObject> s =
      std::make_shared<TJRayTracer::Sphere>();
  auto i1 = Intersection(5, s);
  auto i2 = Intersection(7, s);
  auto i3 = Intersection(-3, s);
  auto i4 = Intersection(2, s);
  auto xs = Intersection::intersections(i1, i2, i3, i4);
  auto i = s->hit(xs);
  ASSERT_EQ(i, i4);
}

TEST(FifthChapter, TranslatingARay) {
  using namespace TJRayTracer;
  auto r = Ray(Point(1, 2, 3), Vector(0, 1, 0));
  auto m = TF::translation(3, 4, 5);
  auto r2 = r.transform(m);
  ASSERT_EQ(r2.GetOrigin(), Point(4, 6, 8));
  ASSERT_EQ(r2.GetDirection(), Vector(0, 1, 0));
}

TEST(FifthChapter, ScalingARay) {
  using namespace TJRayTracer;
  auto r = Ray(Point(1, 2, 3), Vector(0, 1, 0));
  auto m = TF::scaling(2, 3, 4);
  auto r2 = r.transform(m);
  ASSERT_EQ(r2.GetOrigin(), Point(2, 6, 12));
  ASSERT_EQ(r2.GetDirection(), Vector(0, 3, 0));
}

TEST(FifthChapter, SphereDefaultTransformation) {
  using namespace TJRayTracer;
  Sphere s;
  auto identity = TJRayTracer::MatrixXd<double, 4, 4>();
  identity.identity();
  ASSERT_EQ(s.GetTransform() == identity, true);
}

TEST(FifthChapter, ChangingASpehereTransformation) {
  using namespace TJRayTracer;
  Sphere s;
  auto t = TF::translation(2, 3, 4);
  s.SetTransform(t);
  ASSERT_EQ(s.GetTransform() == t, true);
}

TEST(FifthChapter, IntersectingAScaledSphereWithARay) {
  using namespace TJRayTracer;
  auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  TJRayTracer::BaseObject *s = new Sphere();
  s->SetTransform(TF::scaling(2, 2, 2));
  auto xs = s->intersect(r);
  ASSERT_EQ(xs.size(), 2);
  ASSERT_EQ(equal(xs[0].t, 3), true);
  ASSERT_EQ(equal(xs[1].t, 7), true);
}

TEST(FifthChapter, IntersectingATranslatedSphereWithARay) {
  using namespace TJRayTracer;
  auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  TJRayTracer::BaseObject *s = new Sphere();
  s->SetTransform(TF::translation(5, 0, 0));
  auto xs = s->intersect(r);
  ASSERT_EQ(xs.size(), 0);
}

TEST(SixthChapter, TheNormalOnASphereAtAPointOnTheXAxis) {
  using namespace TJRayTracer;
  TJRayTracer::BaseObject *s = new Sphere();
  auto n = s->normal_at(Point(1, 0, 0));
  ASSERT_EQ(n, Vector(1, 0, 0));
}

TEST(SixthChapter, TheNormalOnASphereAtAPointOnTheYAxis) {
  using namespace TJRayTracer;
  TJRayTracer::BaseObject *s = new Sphere();
  auto n = s->normal_at(Point(0, 1, 0));
  ASSERT_EQ(n, Vector(0, 1, 0));
}

TEST(SixthChapter, TheNormalOnASphereAtAPointOnTheZAxis) {
  using namespace TJRayTracer;
  TJRayTracer::BaseObject *s = new Sphere();
  auto n = s->normal_at(Point(0, 0, 1));
  ASSERT_EQ(n, Vector(0, 0, 1));
}

TEST(SixthChapter, TheNormalOnASphereAtANonAxialPoint) {
  using namespace TJRayTracer;
  TJRayTracer::BaseObject *s = new Sphere();
  auto n = s->normal_at(Point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
  ASSERT_EQ(n, Vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
}

TEST(SixthChapter, TheNormalIsNormalizedVector) {
  using namespace TJRayTracer;
  TJRayTracer::BaseObject *s = new Sphere();
  auto n = s->normal_at(Point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
  ASSERT_EQ(n, n.normalize());
}

TEST(SixthChapter, ComputingTheNormalOnATranslatedSphere) {
  using namespace TJRayTracer;
  TJRayTracer::BaseObject *s = new Sphere();
  s->SetTransform(TF::translation(0, 1, 0));
  auto n = s->normal_at(Point(0, 1.70711, -0.70711));
  ASSERT_EQ(n, Vector(0, 0.70711, -0.70711));
}

TEST(SixthChapter, ComputingTheNormalOnATransformedSphere) {
  using namespace TJRayTracer;
  TJRayTracer::BaseObject *s = new Sphere();
  s->SetTransform(TF::scaling(1, 0.5, 1) * TF::rotation_z(M_PI / 5));
  auto n = s->normal_at(Point(0, sqrt(2) / 2, -sqrt(2) / 2));
  ASSERT_EQ(n, Vector(0, 0.97014, -0.24254));
}

TEST(SixthChapter, ReflectingAVectorApproachingAt45) {
  using namespace TJRayTracer;
  auto v = Vector(1, -1, 0);
  auto n = Vector(0, 1, 0);
  auto r = Vector::reflect(v, n);
  ASSERT_EQ(r, Vector(1, 1, 0));
}

TEST(SixthChapter, ReflectingAVectorOffASlantedSurface) {
  using namespace TJRayTracer;
  auto v = Vector(0, -1, 0);
  auto n = Vector(sqrt(2) / 2, sqrt(2) / 2, 0);
  auto r = Vector::reflect(v, n);
  ASSERT_EQ(r, Vector(1, 0, 0));
}

TEST(SixthChapter, APointLight) {
  using namespace TJRayTracer;
  auto intensity = Color(1, 1, 1);
  auto position = Point(0, 0, 0);
  auto light = PointLight(position, intensity);
  ASSERT_EQ(light.GetPosition(), position);
  ASSERT_EQ(light.GetIntensity(), intensity);
}

TEST(SixthChapter, TheDefaultMaterial) {
  using namespace TJRayTracer;
  Material m;
  ASSERT_EQ(m.color, Color(1, 1, 1));
  ASSERT_EQ(equal(m.ambient, 0.1), true);
  ASSERT_EQ(equal(m.diffuse, 0.9), true);
  ASSERT_EQ(equal(m.specular, 0.9), true);
  ASSERT_EQ(equal(m.shininess, 200.0), true);
}

TEST(SixthChapter, ASphereHasADefualtMaterial) {
  using namespace TJRayTracer;
  BaseObject *s = new Sphere();
  auto m = s->material;
  ASSERT_EQ(m, std::make_shared<Material>());
  delete (s);
}

TEST(SixthChapter, ASphereMayBeAssignedAMaterial) {
  using namespace TJRayTracer;
  BaseObject *s = new Sphere();
  auto m = std::make_shared<Material>();
  m->ambient = 1;
  s->material = m;
  ASSERT_EQ(s->material, m);
  delete (s);
}

TEST(SixthChapter, Background) {
  using namespace TJRayTracer;
  auto m = std::make_shared<Material>();
  Point position(0, 0, 0);
  ASSERT_EQ(m, std::make_shared<Material>());
  ASSERT_EQ(position, Point(0, 0, 0));
}

TEST(SixthChapter, LightingWithTheEyeBetweenTheLightAndTheSurface) {
  using namespace TJRayTracer;
  auto m = std::make_shared<Material>();
  Point position(0, 0, 0);
  Vector eyev(0, 0, -1);
  Vector normalv(0, 0, -1);
  PointLight light(Point(0, 0, -10), Color(1, 1, 1));
  auto result =
      PointLight::lighting(m, nullptr, light, position, eyev, normalv, false);
  ASSERT_EQ(result, Color(1.9, 1.9, 1.9));
}

TEST(SixthChapter, LightingWithTheEyeBetweenTheLightAndTheSurfaceEyeOffset45) {
  using namespace TJRayTracer;
  auto m = std::make_shared<Material>();
  Point position(0, 0, 0);
  Vector eyev(0, sqrt(2) / 2, -sqrt(2) / 2);
  Vector normalv(0, 0, -1);
  PointLight light(Point(0, 0, -10), Color(1, 1, 1));
  auto result =
      PointLight::lighting(m, nullptr, light, position, eyev, normalv, false);
  ASSERT_EQ(result, Color(1, 1, 1));
}

TEST(SixthChapter, LightingWithEyeOpposieSurfaceLightOffset45) {
  using namespace TJRayTracer;
  auto m = std::make_shared<Material>();
  Point position(0, 0, 0);
  Vector eyev(0, 0, -1);
  Vector normalv(0, 0, -1);
  PointLight light(Point(0, 10, -10), Color(1, 1, 1));
  auto result =
      PointLight::lighting(m, nullptr, light, position, eyev, normalv, false);
  ASSERT_EQ(result, Color(0.7364, 0.7364, 0.7364));
}

TEST(SixthChapter, LightWithEyeInThePathOfTheReflectionVector) {
  using namespace TJRayTracer;
  auto m = std::make_shared<Material>();
  Point position(0, 0, 0);
  Vector eyev(0, -sqrt(2) / 2, -sqrt(2) / 2);
  Vector normalv(0, 0, -1);
  PointLight light(Point(0, 10, -10), Color(1, 1, 1));
  auto result =
      PointLight::lighting(m, nullptr, light, position, eyev, normalv, false);
  ASSERT_EQ(result, Color(1.6364, 1.6364, 1.6364));
}

TEST(SixthChapter, LightingWithTheLightBehindTheSurface) {
  using namespace TJRayTracer;
  auto m = std::make_shared<Material>();
  Point position(0, 0, 0);
  Vector eyev(0, 0, -1);
  Vector normalv(0, 0, -1);
  PointLight light(Point(0, 0, 10), Color(1, 1, 1));
  auto result =
      PointLight::lighting(m, nullptr, light, position, eyev, normalv, false);
  ASSERT_EQ(result, Color(0.1, 0.1, 0.1));
}

TEST(SeventhChapter, EmptyWorld) {
  TJRayTracer::World w;
  ASSERT_EQ(w.objects.size(), 0);
  ASSERT_EQ(w.light_sources.size(), 0);
}

TEST(SeventhChapter, DefaultWorld) {
  TJRayTracer::PointLight light(TJRayTracer::Point(-10, 10, -10),
                                TJRayTracer::Color(1, 1, 1));
  std::shared_ptr<TJRayTracer::BaseObject> s1 =
      std::make_shared<TJRayTracer::Sphere>();
  s1->material = std::make_shared<TJRayTracer::Material>(
      TJRayTracer::Color(0.8, 1.0, 0.6), 0.1, 0.7, 0.2, 200, nullptr, 0.0, 0.0,
      1.0);
  std::shared_ptr<TJRayTracer::BaseObject> s2 =
      std::make_shared<TJRayTracer::Sphere>(
          TJRayTracer::TF::scaling(0.5, 0.5, 0.5));
  TJRayTracer::World w;
  w.default_world();
  ASSERT_EQ((*w.objects[0].get()), (*s1.get()));
  ASSERT_EQ((*w.objects[1].get()), (*s2.get()));
  ASSERT_EQ(w.light_sources[0], light);
}

TEST(SeventhChapter, IntersectWorldWithRay) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  auto xs = w.intersect_world(r);
  ASSERT_EQ(xs.size(), 4);
  ASSERT_EQ(xs[0].t, 4);
  ASSERT_EQ(xs[1].t, 4.5);
  ASSERT_EQ(xs[2].t, 5.5);
  ASSERT_EQ(xs[3].t, 6);
}

TEST(SeventhChapter, PrecomputingTheStateOfAnIntersection) {
  using namespace TJRayTracer;
  auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  std::shared_ptr<BaseObject> shape = std::make_shared<Sphere>();
  auto i = Intersection(4, shape);
  auto comps = Comps::prepare_computations(i, r);
  ASSERT_EQ(comps.t, i.t);
  ASSERT_EQ(comps.object, i.object);
  ASSERT_EQ(comps.point, Point(0, 0, -1));
  ASSERT_EQ(comps.eyev, Vector(0, 0, -1));
  ASSERT_EQ(comps.normalv, Vector(0, 0, -1));
}

TEST(SeventhChapter, TheHitWhenAnIntersectionOccursOnTheOutside) {
  using namespace TJRayTracer;
  auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  std::shared_ptr<TJRayTracer::BaseObject> shape =
      std::make_shared<TJRayTracer::Sphere>();
  auto i = Intersection(4, shape);
  auto comps = Comps::prepare_computations(i, r);
  ASSERT_EQ(comps.inside, false);
}

TEST(SeventhChapter, TheHitWhenAnIntersectionOccursOnTheInside) {
  using namespace TJRayTracer;
  auto r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
  std::shared_ptr<TJRayTracer::BaseObject> shape =
      std::make_shared<TJRayTracer::Sphere>();
  auto i = Intersection(1, shape);
  auto comps = Comps::prepare_computations(i, r);
  ASSERT_EQ(comps.point, Point(0, 0, 1));
  ASSERT_EQ(comps.eyev, Vector(0, 0, -1));
  ASSERT_EQ(comps.inside, true);
  ASSERT_EQ(comps.normalv, Vector(0, 0, -1));
}

TEST(SeventhChapter, ShadingAnIntersection) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  std::shared_ptr<BaseObject> s1 = std::make_shared<TJRayTracer::Sphere>();
  s1->material = std::make_shared<Material>(Color(0.8, 1.0, 0.6), 0.1, 0.7, 0.2,
                                            200, nullptr, 0.0, 0.0, 1.0);
  auto i = Intersection(4, s1);
  auto comps = Comps::prepare_computations(i, r);
  auto c = w.shade_hit(comps);
  ASSERT_EQ(c, Color(0.38066, 0.47583, 0.2855));
}

TEST(SeventhChapter, ShadingAnIntersectionFromTheInside) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  w.light_sources.clear();
  w.light_sources.push_back(PointLight(Point(0, 0.25, 0), Color(1, 1, 1)));
  auto r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
  std::shared_ptr<BaseObject> s2 =
      std::make_shared<TJRayTracer::Sphere>(TF::scaling(0.5, 0.5, 0.5));
  auto i = Intersection(0.5, s2);
  auto comps = Comps::prepare_computations(i, r);
  auto c = w.shade_hit(comps);
  ASSERT_EQ(c, Color(0.90498, 0.90498, 0.90498));
}

TEST(SeventhChapter, TheColorWhenARayMisses) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto r = Ray(Point(0, 0, -5), Vector(0, 1, 0));
  auto c = w.color_at(r);
  ASSERT_EQ(c, Color(0, 0, 0));
}

TEST(SeventhChapter, TheColorWhenARayHits) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  auto c = w.color_at(r);
  ASSERT_EQ(c, Color(0.38066, 0.47583, 0.2855));
}

TEST(SeventhChapter, TheColorWithAnIntersectionBehindTheRay) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  w.objects[0]->material->ambient = 1;
  w.objects[1]->material->ambient = 1;
  auto r = Ray(Point(0, 0, 0.75), Vector(0, 0, -1));
  auto c = w.color_at(r);
  ASSERT_EQ(c, w.objects[1]->material->color);
}

TEST(SeventhChapter, TheTransformationMatrixForTheDefaultOrientation) {
  using namespace TJRayTracer;
  auto from = Point(0, 0, 0);
  auto to = Point(0, 0, -1);
  auto up = Vector(0, 1, 0);
  auto t = TF::view_transform(from, to, up);
  ASSERT_EQ((t == TF::identity()), true);
}

TEST(SeventhChapter, AViewTransformationMatrixLookingInPositiveZDirection) {
  using namespace TJRayTracer;
  auto from = Point(0, 0, 8);
  auto to = Point(0, 0, 0);
  auto up = Vector(0, 1, 0);
  auto t = TF::view_transform(from, to, up);
  ASSERT_EQ((t == TF::translation(0, 0, -8)), true);
}

TEST(SeventhChapter, AnArbitraryViewTransformation) {
  using namespace TJRayTracer;
  auto from = Point(1, 3, 2);
  auto to = Point(4, -2, 8);
  auto up = Vector(1, 1, 0);
  auto t = TF::view_transform(from, to, up);
  auto matrix = MatrixXd<double, 4, 4>();
  matrix(0, 0) = -0.50709;
  matrix(0, 1) = 0.50709;
  matrix(0, 2) = 0.67612;
  matrix(0, 3) = -2.36643;
  matrix(1, 0) = 0.76772;
  matrix(1, 1) = 0.60609;
  matrix(1, 2) = 0.12122;
  matrix(1, 3) = -2.82843;
  matrix(2, 0) = -0.35857;
  matrix(2, 1) = 0.59761;
  matrix(2, 2) = -0.71714;
  matrix(2, 3) = 0.00000;
  matrix(3, 0) = 0.00000;
  matrix(3, 1) = 0.00000;
  matrix(3, 2) = 0.00000;
  matrix(3, 3) = 1.00000;
  ASSERT_EQ((t == matrix), true);
}

TEST(SeventhChapter, ConstructingACamera) {
  using namespace TJRayTracer;
  Camera c(160, 120, M_PI_2);
  ASSERT_EQ(c.hsize, 160);
  ASSERT_EQ(c.vsize, 120);
  ASSERT_EQ(equal(c.fov, M_PI_2), true);
  ASSERT_EQ(c.tf == TF::identity(), true);
}

TEST(SeventhChapter, ThePixelSizeForAHorizontalCanvas) {
  using namespace TJRayTracer;
  Camera c(200, 125, M_PI_2);
  ASSERT_EQ(equal(c.pixel_size, 0.01), true);
}

TEST(SeventhChapter, ThePixelSizeForAVerticalCanvas) {
  using namespace TJRayTracer;
  Camera c(125, 200, M_PI_2);
  ASSERT_EQ(equal(c.pixel_size, 0.01), true);
}

TEST(SeventhChapter, ConstructingARayThroughTheCenterOfTheCanvas) {
  using namespace TJRayTracer;
  Camera c(201, 101, M_PI_2);
  auto r = c.ray_for_pixel(100, 50);
  ASSERT_EQ(r.GetOrigin(), Point(0, 0, 0));
  ASSERT_EQ(r.GetDirection(), Vector(0, 0, -1));
}

TEST(SeventhChapter, ConstructingARayThroughACornerOfTheCanvas) {
  using namespace TJRayTracer;
  Camera c(201, 101, M_PI_2);
  auto r = c.ray_for_pixel(0, 0);
  ASSERT_EQ(r.GetOrigin(), Point(0, 0, 0));
  ASSERT_EQ(r.GetDirection(), Vector(0.66519, 0.33259, -0.66851));
}

TEST(SeventhChapter, ConstructingARayWhenTheCameraIsTransformed) {
  using namespace TJRayTracer;
  Camera c(201, 101, M_PI_2);
  c.tf = TF::rotation_y(M_PI / 4) * TF::translation(0, -2, 5);
  auto r = c.ray_for_pixel(100, 50);
  ASSERT_EQ(r.GetOrigin(), Point(0, 2, -5));
  ASSERT_EQ(r.GetDirection(), Vector(sqrt(2) / 2, 0, -sqrt(2) / 2));
}

TEST(SeventhChapter, RenderingAWorldWithACamera) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  Camera c(11, 11, M_PI_2);
  auto from = Point(0, 0, -5);
  auto to = Point(0, 0, 0);
  auto up = Vector(0, 1, 0);
  c.tf = TF::view_transform(from, to, up);
  auto canvas = c.render(w);
  ASSERT_EQ(canvas.GetPixelColor(5, 5), Color(0.38066, 0.47583, 0.2855));
}

TEST(EightChapter, LightingWithTheSurfaceInShadow) {
  using namespace TJRayTracer;
  auto m = std::make_shared<Material>();
  Point position(0, 0, 0);
  Vector eyev(0, 0, -1);
  Vector normalv(0, 0, -1);
  PointLight light(Point(0, 0, -10), Color(1, 1, 1));
  bool in_shadow = true;
  auto result = PointLight::lighting(m, nullptr, light, position, eyev, normalv,
                                     in_shadow);
  ASSERT_EQ(result, Color(0.1, 0.1, 0.1));
}

TEST(EightChapter, ThereIsNoShadow) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto p = Point(0, 10, 0);
  ASSERT_EQ(w.is_shadowed(p), false);
}

TEST(EightChapter, ThereIsAShadow) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto p = Point(10, -10, 10);
  ASSERT_EQ(w.is_shadowed(p), true);
}
TEST(EightChapter, IsShadowedRenderingColor) {
  using namespace TJRayTracer;
  World w;
  w.light_sources.push_back(PointLight(Point(0, 0, -10), Color(1, 1, 1)));
  std::shared_ptr<BaseObject> s1 = std::make_shared<Sphere>();
  w.objects.push_back(s1);
  std::shared_ptr<BaseObject> s2 = std::make_shared<Sphere>();
  s2->SetTransform(TF::translation(0, 0, 10));
  w.objects.push_back(s2);
  Ray ray(Point(0, 0, 5), Vector(0, 0, 1));
  auto i = Intersection(4, s2);
  auto comps = Comps::prepare_computations(i, ray);
  Color c = w.shade_hit(comps);
  ASSERT_EQ(c, Color(0.1, 0.1, 0.1));
}

TEST(EightChapter, ThereIsNoShadowPointBehindLight) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto p = Point(-20, 20, -20);
  ASSERT_EQ(w.is_shadowed(p), false);
}

TEST(EightChapter, ThereIsNoShadowPointBeforeSphere) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto p = Point(-2, 2, -2);
  ASSERT_EQ(w.is_shadowed(p), false);
}

TEST(EightChapter, TheHitShouldOffsetThePoint) {
  using namespace TJRayTracer;
  Ray r(Point(0, 0, -5), Vector(0, 0, 1));
  std::shared_ptr<BaseObject> shape = std::make_shared<Sphere>();
  shape->SetTransform(TF::translation(0, 0, 1));
  auto i = Intersection(5, shape);
  auto comps = Comps::prepare_computations(i, r);
  ASSERT_EQ(comps.over_point.z < -EPSILON / 2, true);
  ASSERT_EQ(comps.point.z > comps.over_point.z, true);
}

TEST(Ninth, TheDefaultTransformation) {
  using namespace TJRayTracer;
  std::unique_ptr<BaseObject> s = std::make_unique<Sphere>();
  ASSERT_EQ(s->GetTransform() == TF::identity(), true);
}

TEST(Ninth, SetTransformation) {
  using namespace TJRayTracer;
  std::unique_ptr<BaseObject> s = std::make_unique<Sphere>();
  s->SetTransform(TF::translation(2, 3, 4));
  ASSERT_EQ(s->GetTransform() == TF::translation(2, 3, 4), true);
}

TEST(Ninth, AssigningAMaterial) {
  using namespace TJRayTracer;
  std::unique_ptr<BaseObject> s = std::make_unique<Sphere>();
  auto m = s->material;
  m->ambient = 1;
  s->material = m;
  ASSERT_EQ(m, s->material);
}

TEST(Ninth, TheDefaultMaterial) {
  using namespace TJRayTracer;
  std::unique_ptr<BaseObject> s = std::make_unique<Sphere>();
  auto m = s->material;
  ASSERT_EQ(m, std::make_shared<Material>());
}

TEST(Ninth, TheNormalOfAPlaneIsConstant) {
  using namespace TJRayTracer;
  std::unique_ptr<BaseObject> p = std::make_unique<Plane>();
  auto n1 = p->local_normal_at(Point(0, 0, 0));
  auto n2 = p->local_normal_at(Point(10, 0, -10));
  auto n3 = p->local_normal_at(Point(-5, 0, 150));
  ASSERT_EQ(n1, Vector(0, 1, 0));
  ASSERT_EQ(n2, Vector(0, 1, 0));
  ASSERT_EQ(n3, Vector(0, 1, 0));
}

TEST(Ninth, IntersectWithARayParallelToThePlane) {
  using namespace TJRayTracer;
  std::unique_ptr<BaseObject> p = std::make_unique<Plane>();
  Ray r(Point(0, 10, 0), Vector(0, 0, 1));
  auto xs = p->local_intersect(r);
  ASSERT_EQ(xs.size(), 0);
}

TEST(Ninth, IntersectWithACoplanarRay) {
  using namespace TJRayTracer;
  std::unique_ptr<BaseObject> p = std::make_unique<Plane>();
  Ray r(Point(0, 0, 0), Vector(0, 0, 1));
  auto xs = p->local_intersect(r);
  ASSERT_EQ(xs.size(), 0);
}

TEST(Ninth, ARayIntersectingAPlaneFromAbove) {
  using namespace TJRayTracer;
  std::shared_ptr<BaseObject> p = std::make_shared<Plane>();
  Ray r(Point(0, 1, 0), Vector(0, -1, 0));
  auto xs = p->local_intersect(r);
  ASSERT_EQ(xs.size(), 1);
  ASSERT_EQ(equal(xs[0].t, 1), true);
  ASSERT_EQ((*xs[0].object.get()), (*p.get()));
}

TEST(Ninth, ARayIntersectingAPlaneFromBelow) {
  using namespace TJRayTracer;
  std::shared_ptr<BaseObject> p = std::make_shared<Plane>();
  Ray r(Point(0, -1, 0), Vector(0, 1, 0));
  auto xs = p->local_intersect(r);
  ASSERT_EQ(xs.size(), 1);
  ASSERT_EQ(equal(xs[0].t, 1), true);
  ASSERT_EQ((*xs[0].object.get()), (*p.get()));
}

TEST(Tenth, CreatingAStripePattern) {
  using namespace TJRayTracer;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  StrippedPattern pattern(white, black);
  ASSERT_EQ(pattern.a, white);
  ASSERT_EQ(pattern.b, black);
}

TEST(Tenth, AStripePatternIsConstantInY) {
  using namespace TJRayTracer;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  StrippedPattern pattern(white, black);
  ASSERT_EQ(pattern.pattern_at(Point(0, 0, 0)), white);
  ASSERT_EQ(pattern.pattern_at(Point(0, 1, 0)), white);
  ASSERT_EQ(pattern.pattern_at(Point(0, 2, 0)), white);
}

TEST(Tenth, AStripePatternIsConstantInZ) {
  using namespace TJRayTracer;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  StrippedPattern pattern(white, black);
  ASSERT_EQ(pattern.pattern_at(Point(0, 0, 0)), white);
  ASSERT_EQ(pattern.pattern_at(Point(0, 0, 1)), white);
  ASSERT_EQ(pattern.pattern_at(Point(0, 0, 2)), white);
}

TEST(Tenth, AStripePatternAlternatesInX) {
  using namespace TJRayTracer;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  StrippedPattern pattern(white, black);
  ASSERT_EQ(pattern.pattern_at(Point(0, 0, 0)), white);
  ASSERT_EQ(pattern.pattern_at(Point(0.9, 0, 0)), white);
  ASSERT_EQ(pattern.pattern_at(Point(1, 0, 0)), black);
  ASSERT_EQ(pattern.pattern_at(Point(-0.1, 0, 0)), black);
  ASSERT_EQ(pattern.pattern_at(Point(-1, 0, 0)), black);
  ASSERT_EQ(pattern.pattern_at(Point(-1.1, 0, 0)), white);
}

TEST(Tenth, LightingWithAPatternApplied) {
  using namespace TJRayTracer;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  std::shared_ptr<StrippedPattern> pattern =
      std::make_shared<StrippedPattern>(white, black);
  auto m = std::make_shared<Material>();
  m->pattern = pattern;
  m->ambient = 1;
  m->diffuse = 0;
  m->specular = 0;
  auto sphere = std::make_shared<Sphere>();
  Vector eyev(0, 0, -1);
  Vector normalv(0, 0, -1);
  PointLight light(Point(0, 0, -10), Color(1, 1, 1));
  auto c1 = PointLight::lighting(m, sphere, light, Point(0.9, 0, 0), eyev,
                                 normalv, false);
  auto c2 = PointLight::lighting(m, sphere, light, Point(1.1, 0, 0), eyev,
                                 normalv, false);
  ASSERT_EQ(c1, white);
  ASSERT_EQ(c2, black);
}

TEST(Tenth, StripesWithAnObjectTransformation) {
  using namespace TJRayTracer;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  std::shared_ptr<BaseObject> object = std::make_shared<Sphere>();
  object->SetTransform(TF::scaling(2, 2, 2));
  std::shared_ptr<BasePattern> pattern =
      std::make_shared<StrippedPattern>(white, black);
  Color c = pattern->pattern_at_object(object, Point(1.5, 0, 0));
  ASSERT_EQ(c, white);
}

TEST(Tenth, StripesWithAPatternTransformation) {
  using namespace TJRayTracer;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  std::shared_ptr<BaseObject> object = std::make_shared<Sphere>();
  std::shared_ptr<BasePattern> pattern =
      std::make_shared<StrippedPattern>(white, black);
  pattern->SetTransform(TF::scaling(2, 2, 2));
  Color c = pattern->pattern_at_object(object, Point(1.5, 0, 0));
  ASSERT_EQ(c, white);
}

TEST(Tenth, StripesWithBothAnObjectAndAPatternTransformation) {
  using namespace TJRayTracer;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  std::shared_ptr<BaseObject> object = std::make_shared<Sphere>();
  object->SetTransform(TF::scaling(2, 2, 2));
  std::shared_ptr<BasePattern> pattern =
      std::make_shared<StrippedPattern>(white, black);
  pattern->SetTransform(TF::translation(0.5, 0, 0));
  Color c = pattern->pattern_at_object(object, Point(2.5, 0, 0));
  ASSERT_EQ(c, white);
}

TEST(Tenth, TheDefaultPatternTransformation) {
  using namespace TJRayTracer;
  std::shared_ptr<BasePattern> pattern = std::make_shared<StrippedPattern>();
  ASSERT_EQ(pattern->GetTransform() == TF::identity(), true);
}

TEST(Tenth, AssigningATransformation) {
  using namespace TJRayTracer;
  std::shared_ptr<BasePattern> pattern = std::make_shared<StrippedPattern>();
  pattern->SetTransform(TF::translation(1, 2, 3));
  ASSERT_EQ(pattern->GetTransform() == TF::translation(1, 2, 3), true);
}

TEST(Tenth, AGradientLinearlyInterpolatesBetweenColors) {
  using namespace TJRayTracer;
  Color white(1, 1, 1);
  Color black(0, 0, 0);
  std::shared_ptr<BasePattern> pattern =
      std::make_shared<GradientPattern>(white, black);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0, 0)), white);
  ASSERT_EQ(pattern->pattern_at(Point(0.25, 0, 0)), Color(0.75, 0.75, 0.75));
  ASSERT_EQ(pattern->pattern_at(Point(0.5, 0, 0)), Color(0.5, 0.5, 0.5));
  ASSERT_EQ(pattern->pattern_at(Point(0.75, 0, 0)), Color(0.25, 0.25, 0.25));
}

TEST(Tenth, ARingShouldExtendInBothXAndZ) {
  using namespace TJRayTracer;
  Color white(1, 1, 1);
  Color black(0, 0, 0);
  std::shared_ptr<BasePattern> pattern =
      std::make_shared<RingPattern>(white, black);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0, 0)), white);
  ASSERT_EQ(pattern->pattern_at(Point(1, 0, 0)), black);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0, 1)), black);
  ASSERT_EQ(pattern->pattern_at(Point(0.708, 0, 0.708)), black);
}

TEST(Tenth, CheckersShouldRepeatInX) {
  using namespace TJRayTracer;
  Color white(1, 1, 1);
  Color black(0, 0, 0);
  std::shared_ptr<BasePattern> pattern =
      std::make_shared<CheckersPattern>(white, black);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0, 0)), white);
  ASSERT_EQ(pattern->pattern_at(Point(0.99, 0, 0)), white);
  ASSERT_EQ(pattern->pattern_at(Point(1.01, 0, 0)), black);
}

TEST(Tenth, CheckersShouldRepeatInY) {
  using namespace TJRayTracer;
  Color white(1, 1, 1);
  Color black(0, 0, 0);
  std::shared_ptr<BasePattern> pattern =
      std::make_shared<CheckersPattern>(white, black);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0, 0)), white);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0.99, 0)), white);
  ASSERT_EQ(pattern->pattern_at(Point(0, 1.01, 0)), black);
}

TEST(Tenth, CheckersShouldRepeatInZ) {
  using namespace TJRayTracer;
  Color white(1, 1, 1);
  Color black(0, 0, 0);
  std::shared_ptr<BasePattern> pattern =
      std::make_shared<CheckersPattern>(white, black);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0, 0)), white);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0, 0.99)), white);
  ASSERT_EQ(pattern->pattern_at(Point(0, 0, 1.01)), black);
}

TEST(Eleventh, ReflectionVector) {
  using namespace TJRayTracer;
  std::shared_ptr<BaseObject> shape = std::make_shared<Plane>();
  Ray r(Point(0, 1, -1), Vector(0, -sqrt(2) / 2, sqrt(2) / 2));
  Intersection i(sqrt(2) / 2, shape);
  auto comps = Comps::prepare_computations(i, r);
  ASSERT_EQ(comps.reflectv, Vector(0, sqrt(2) / 2, sqrt(2) / 2));
}

TEST(Eleventh, TheReflectedColorForANonreflectiveMaterial) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  Ray r(Point(0, 0, 0), Vector(0, 0, 1));
  auto shape = w.objects[1];
  shape->material->ambient = 1;
  Intersection i(1, shape);
  auto comps = Comps::prepare_computations(i, r);
  Color color = w.reflected_color(comps);
  ASSERT_EQ(color, Color(0, 0, 0));
}

TEST(Eleventh, TheReflectedColorForAReflectiveMaterial) {
  using namespace TJRayTracer;
  std::shared_ptr<BaseObject> shape = std::make_shared<Plane>();
  shape->material->reflective = 0.5;
  shape->SetTransform(TF::translation(0, -1, 0));
  World w;
  w.default_world();
  w.objects.push_back(shape);
  Ray r(Point(0, 0, -3), Vector(0, -sqrt(2) / 2, sqrt(2) / 2));
  Intersection i(sqrt(2), shape);
  auto comps = Comps::prepare_computations(i, r);
  Color color = w.reflected_color(comps);
  ASSERT_EQ(color, Color(0.190332, 0.237915, 0.142749));
}

TEST(Eleventh, shade_hitWithAReflectiveMaterial) {
  using namespace TJRayTracer;
  std::shared_ptr<BaseObject> shape = std::make_shared<Plane>();
  shape->material->reflective = 0.5;
  shape->SetTransform(TF::translation(0, -1, 0));
  World w;
  w.default_world();
  w.objects.push_back(shape);
  Ray r(Point(0, 0, -3), Vector(0, -sqrt(2) / 2, sqrt(2) / 2));
  Intersection i(sqrt(2), shape);
  auto comps = Comps::prepare_computations(i, r);
  Color color = w.shade_hit(comps);
  ASSERT_EQ(color, Color(0.876757, 0.92435, 0.82918));
}

TEST(Eleventh, TwoMirrorsInfinityLoop) {
  using namespace TJRayTracer;
  World w;
  w.light_sources.push_back(PointLight(Point(0, 0, 0), Color(1, 1, 1)));
  std::shared_ptr<BaseObject> lower = std::make_shared<Plane>();
  lower->material->reflective = 1;
  lower->SetTransform(TF::translation(0, -1, 0));
  std::shared_ptr<BaseObject> upper = std::make_shared<Plane>();
  upper->material->reflective = 1;
  upper->SetTransform(TF::translation(0, 1, 0));
  w.objects.push_back(lower);
  w.objects.push_back(upper);
  Ray r(Point(0, 0, 0), Vector(0, 1, 0));
  Color c = w.color_at(r);
}

TEST(Eleventh, TheReflectedColorAtTheMaximumRecursiveDepth) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  std::shared_ptr<BaseObject> shape = std::make_shared<Plane>();
  shape->material->reflective = 0.5;
  shape->SetTransform(TF::translation(0, -1, 0));
  w.objects.push_back(shape);
  Ray r(Point(0, 0, -3), Vector(0, -sqrt(2) / 2, sqrt(2) / 2));
  auto i = Intersection(sqrt(2), shape);
  auto comps = Comps::prepare_computations(i, r);
  Color color = w.reflected_color(comps, 0);
  ASSERT_EQ(color, Color(0, 0, 0));
}

TEST(Eleventh, TransparencyAndRefractiveIndexForTheDefaultMaterial) {
  using namespace TJRayTracer;
  auto m = std::make_shared<Material>();
  ASSERT_EQ(equal(m->transparency, 0.0), true);
  ASSERT_EQ(equal(m->refractive_index, 1.0), true);
}

TEST(Eleventh, AHelperForProducingASphereWithAGlassyMaterial) {
  using namespace TJRayTracer;
  std::shared_ptr<BaseObject> s = Sphere::Glass_sphere();
  ASSERT_EQ(s->GetTransform() == TF::identity(), true);
  ASSERT_EQ(equal(s->material->transparency, 1.0), true);
  ASSERT_EQ(equal(s->material->refractive_index, 1.5), true);
}

TEST(Eleventh, FindingN1AndN2AtVariousIntersections) {
  using namespace TJRayTracer;
  std::shared_ptr<BaseObject> A = Sphere::Glass_sphere();
  A->SetTransform(TF::scaling(2, 2, 2));
  A->material->refractive_index = 1.5;
  std::shared_ptr<BaseObject> B = Sphere::Glass_sphere();
  B->SetTransform(TF::translation(0, 0, -0.25));
  B->material->refractive_index = 2.0;
  std::shared_ptr<BaseObject> C = Sphere::Glass_sphere();
  C->SetTransform(TF::translation(0, 0, 0.25));
  C->material->refractive_index = 2.5;
  Ray r(Point(0, 0, -4), Vector(0, 0, 1));
  auto xs = Intersection::intersections(
      Intersection(2, A), Intersection(2.75, B), Intersection(3.25, C),
      Intersection(4.75, B), Intersection(5.25, C), Intersection(6, A));
  std::vector<double> n1;
  std::vector<double> n2;
  n1.emplace_back(1.0);
  n1.emplace_back(1.5);
  n1.emplace_back(2.0);
  n1.emplace_back(2.5);
  n1.emplace_back(2.5);
  n1.emplace_back(1.5);
  n2.emplace_back(1.5);
  n2.emplace_back(2.0);
  n2.emplace_back(2.5);
  n2.emplace_back(2.5);
  n2.emplace_back(1.5);
  n2.emplace_back(1.0);
  for (int i = 0; i < 6; ++i) {
    auto comps = Comps::prepare_computations(xs[i], r, xs);
    ASSERT_EQ(equal(comps.n1, n1[i]), true);
    ASSERT_EQ(equal(comps.n2, n2[i]), true);
  }
}

TEST(Eleventh, TheUnderPointIsOffsetBelowTheSurface) {
  using namespace TJRayTracer;
  Ray r(Point(0, 0, -5), Vector(0, 0, 1));
  std::shared_ptr<BaseObject> shape = Sphere::Glass_sphere();
  shape->SetTransform(TF::translation(0, 0, 1));
  auto i = Intersection(5, shape);
  auto xs = Intersection::intersections(i);
  auto comps = Comps::prepare_computations(i, r, xs);
  ASSERT_EQ(comps.under_point.z > EPSILON / 2, true);
  ASSERT_EQ(comps.point.z < comps.under_point.z, true);
}

TEST(Eleventh, TheRefractedColorWithAnOpaqueSurface) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto shape = w.objects[0];
  Ray r(Point(0, 0, -5), Vector(0, 0, 1));
  auto xs = Intersection::intersections(Intersection(4, shape),
                                        Intersection(6, shape));
  auto comps = Comps::prepare_computations(xs[0], r, xs);
  Color c = w.refracted_color(comps, 5);
  ASSERT_EQ(c, Color(0, 0, 0));
}

TEST(Eleventh, TheRefractedColorAtTheMaximumRecursiveDepth) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto shape = w.objects[0];
  shape->material->transparency = 1.0;
  shape->material->refractive_index = 1.5;
  Ray r(Point(0, 0, -5), Vector(0, 0, 1));
  auto xs = Intersection::intersections(Intersection(4, shape),
                                        Intersection(6, shape));
  auto comps = Comps::prepare_computations(xs[0], r, xs);
  Color c = w.refracted_color(comps, 0);
  ASSERT_EQ(c, Color(0, 0, 0));
}

TEST(Eleventh, TheRefractedColorUnderTotalInternalReflection) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto shape = w.objects[0];
  shape->material->transparency = 1.0;
  shape->material->refractive_index = 1.5;
  Ray r(Point(0, 0, sqrt(2) / 2), Vector(0, 1, 0));
  auto xs = Intersection::intersections(Intersection(-sqrt(2) / 2, shape),
                                        Intersection(sqrt(2) / 2, shape));
  auto comps = Comps::prepare_computations(xs[1], r, xs);
  Color c = w.refracted_color(comps, 5);
  ASSERT_EQ(c, Color(0, 0, 0));
}

TEST(Eleventh, TheRefractedColorWithARefractedRay) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto A = w.objects[0];
  A->material->ambient = 1.0;
  A->material->pattern = std::make_shared<TestPattern>();
  auto B = w.objects[1];
  B->material->transparency = 1.0;
  B->material->refractive_index = 1.5;
  Ray r(Point(0, 0, 0.1), Vector(0, 1, 0));
  auto xs = Intersection::intersections(
      Intersection(-0.9899, A), Intersection(-0.4899, B),
      Intersection(0.4899, B), Intersection(0.9899, A));
  auto comps = Comps::prepare_computations(xs[2], r, xs);
  auto c = w.refracted_color(comps, 5);
  ASSERT_EQ(c, Color(0, 0.998875, 0.047219));
}

TEST(Eleventh, shade_hitWithATransparentMaterial) {
  using namespace TJRayTracer;
  World w;
  w.default_world();
  auto floor = std::make_shared<Plane>();
  floor->SetTransform(TF::translation(0, -1, 0));
  floor->material->transparency = 0.5;
  floor->material->refractive_index = 1.5;
  w.objects.push_back(floor);
  auto ball = std::make_shared<Sphere>();
  ball->material->color = Color(1, 0, 0);
  ball->material->ambient = 0.5;
  ball->SetTransform(TF::translation(0, -3.5, -0.5));
  w.objects.push_back(ball);
  Ray r(Point(0, 0, -3), Vector(0, -sqrt(2) / 2, sqrt(2) / 2));
  auto xs = Intersection::intersections(Intersection(sqrt(2), floor));
  auto comps = Comps::prepare_computations(xs[0], r, xs);
  Color color = w.shade_hit(comps, 5);
  ASSERT_EQ(color, Color(0.93642, 0.68642, 0.68642));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

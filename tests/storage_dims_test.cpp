#ifndef STORAGE_DIMENSIONS_TEST_CPP_
#define STORAGE_DIMENSIONS_TEST_CPP_

#include <iostream>

#include <gtest/gtest.h>

#include <matrix/matrix.h>

TEST(MATRIX_STORAGE, _INITIAL_TEST)
{
  using namespace matrix::internal;
  Storage<float> fir(1);
  Storage<float> sec(0);
  EXPECT_EQ(fir.size(), 1);
  EXPECT_EQ(sec.size(), 0);
  EXPECT_EQ(sec.capacity(), 1);
}

TEST(MATRIX_STORAGE, _LARGE_STORAGE)
{
  using namespace matrix::internal;
  Storage<float> fir(1000000000);
  EXPECT_EQ(fir[999999999], 0);
}

TEST(MATRIX_STORAGE, _INDEX_ASSIGN)
{
  using namespace matrix::internal;
  Storage<float> fir(10);
  fir[0] = 100;
  EXPECT_EQ(fir[0], 100);
}

TEST(MATRIX_STORAGE, _COPY_CONSTRUCTOR)
{
  using namespace matrix::internal;
  Storage<float> fir(10);
  Storage<float> sec = fir;
  fir[0] = 100;
  EXPECT_NE(sec[0], 100);
  EXPECT_EQ(fir[0], 100);
  EXPECT_EQ(fir[9], 0);
}

TEST(MATRIX_STORAGE, _MOVE_CONSTRUCTOR)
{
  using namespace matrix::internal;
  Storage<float> fir(10);
  Storage<float> sec = std::move(fir);
  EXPECT_EQ(fir.capacity(), 1);
  EXPECT_EQ(sec.size(), 10);
}

TEST(MATRIX_STORAGE, _CAPACITY_ALLOC)
{
  using namespace matrix::internal;
  Storage<float> fir(10);
  EXPECT_EQ(fir.size(), 10);
  EXPECT_EQ(fir.capacity(), 16);
}

#endif
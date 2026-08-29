#ifndef STORAGE_DIMENSIONS_TEST_CPP_
#define STORAGE_DIMENSIONS_TEST_CPP_

#include <iostream>

#include <gtest/gtest.h>

#include <schur/matrix/matrix>

TEST(MATRIX_STORAGE, _INITIAL_TEST)
{
  using namespace schur::internal;
  Storage<float> fir(1);
  Storage<float> sec(0);
  EXPECT_EQ(fir.size(), 1);
  EXPECT_EQ(sec.size(), 0);
  EXPECT_EQ(sec.capacity(), 1);
}

TEST(MATRIX_STORAGE, _LARGE_STORAGE)
{
  using namespace schur::internal;
  Storage<float> fir(1000000000);
  EXPECT_EQ(fir[999999999], 0);
}

TEST(MATRIX_STORAGE, _INDEX_ASSIGN)
{
  using namespace schur::internal;
  Storage<float> fir(10);
  fir[0] = 100;
  EXPECT_EQ(fir[0], 100);
}

TEST(MATRIX_STORAGE, _COPY_CONSTRUCTOR)
{
  using namespace schur::internal;
  Storage<float> fir(10);
  Storage<float> sec = fir;
  fir[0] = 100;
  EXPECT_NE(sec[0], 100);
  EXPECT_EQ(fir[0], 100);
  EXPECT_EQ(fir[9], 0);
}

TEST(MATRIX_STORAGE, _MOVE_CONSTRUCTOR)
{
  using namespace schur::internal;
  Storage<float> fir(10);
  Storage<float> sec = std::move(fir);
  EXPECT_EQ(fir.capacity(), 1);
  EXPECT_EQ(sec.size(), 10);
}

TEST(MATRIX_STORAGE, _CAPACITY_ALLOC)
{
  using namespace schur::internal;
  Storage<float> fir(10);
  EXPECT_EQ(fir.size(), 10);
  EXPECT_EQ(fir.capacity(), 16);
}

TEST(MATRIX_STORAGE, _RESIZE)
{
  using namespace schur::internal;
  Storage<float> fir(10);
  size_t cap = fir.capacity();
  size_t new_size1 = 3;
  fir.resize(new_size1);
  EXPECT_EQ(fir.size(), new_size1);
  EXPECT_EQ(fir.capacity(), cap);
  Storage<float> sec(2000);
  size_t new_size2 = sec.size() + 1;
  sec.resize(new_size2);
  EXPECT_EQ(sec.size(), new_size2);
}

TEST(MATRIX_STORAGE, _RESERVE)
{
  using namespace schur::internal;
  size_t size = 10;
  Storage<float> storage_test(0);
  Storage<float> fir(size);
  size_t cap = 16;
  size_t new_cap1 = 20;
  EXPECT_EQ(fir.capacity(), cap);
  fir.reserve(new_cap1);
  Storage<float> sec(10);
  size_t new_cap2 = 13;
  sec.reserve(new_cap2);
  EXPECT_NE(sec.capacity(), new_cap2);
  EXPECT_EQ(fir.capacity(), std::bit_ceil(new_cap1));
  EXPECT_EQ(fir.size(), size);
}

#endif

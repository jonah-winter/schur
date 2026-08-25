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
  fir.init_();
  EXPECT_EQ(fir[0], 0);
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
  size_t s = fir.get_size_();
  size_t c = fir.get_cap_();
  for (size_t i{0}; i < s; i++) {
    fir[i] = i + 1;
  }
  Storage<float> sec = std::move(fir);
  for (size_t i{0}; i < sec.get_size_(); i++) {
    EXPECT_EQ(sec[i], i+1);
  }
  EXPECT_EQ(fir.get_data_(), nullptr);
  EXPECT_EQ(fir.get_cap_(), 1);
}

TEST(MATRIX_STORAGE, _CAPACITY_ALLOC)
{
  using namespace matrix::internal;
  Storage<float> fir(10);
  EXPECT_EQ(fir.get_size_(), 10);
  EXPECT_EQ(fir.get_cap_(), 16);
  EXPECT_EQ(fir.get_size_(), 10);
}

#endif

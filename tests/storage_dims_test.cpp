#ifndef STORAGE_DIMENSIONS_TEST_CPP_
#define STORAGE_DIMENSIONS_TEST_CPP_

#include <iostream>

#include <gtest/gtest.h>

#include <matrix/matrix.h>

TEST(MATRIX_STORAGE, _INITIAL_TEST)
{
  using namespace matrix::internal;
  Storage<float> fir(1);
  Storage<float> sec(100);
  fir.init_();
  EXPECT_EQ(fir[0], 0);
  fir[0] = 100;
  EXPECT_EQ(fir[0], 100);
  sec[99] = 100;
  EXPECT_EQ(sec[99], 100);
}

TEST(MATRIX_STORAGE, _LARGE_STORAGE)
{
  using namespace matrix::internal;
  Storage<float> fir(1000000000);
  EXPECT_EQ(fir[9999], 0);
}

#endif

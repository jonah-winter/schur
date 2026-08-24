#ifndef STORAGE_DIMENSIONS_TEST_CPP_
#define STORAGE_DIMENSIONS_TEST_CPP_

#include <iostream>

#include <matrix/matrix.h>

int main()
{
  using namespace matrix;
  using T = int;
  auto a = internal::Storage<T>(5);
  a[3] = 5;
  T* b = a.get_data();
  T* c = a.get_data();
  std::cout << b[3] << '\n';
  return 0;
}

#endif

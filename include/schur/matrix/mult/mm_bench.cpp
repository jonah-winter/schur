#include <array>
#include "MM_Block84_NEON.hpp"
#include "MM_NxN_NEON.hpp"

int main() {
  using namespace schur;
  using namespace internal;
  std::array<float, 16> a{};
  std::array<float, 8>  b{};
  std::array<float, 32> c{};
  for(int k{0}; k < 2; k++) {
    for(int i{0}; i < 8; i++) {
      a[k*8+i] = (float)(i+1);
    }
    for(int j{0}; j < 4; j++) {
      b[k*2+j] = (float)(j+1);
    }
  }
  mm84x(a.data(), b.data(), c.data(), 8, 2, 8, 2);
  return 0;
}

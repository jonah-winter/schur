#include "Matrix_MatMul8x8.hpp"

void testMatMul88x(const float* a, const float* b, float* c) {
  schur::internal::mm88x(a, b, c);
}

int main() {
  return 0;
}

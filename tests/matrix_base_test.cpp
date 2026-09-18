#include <iostream>
#include <schur/matrix/Matrix>

#define cout(x) std::cout << x

int main(int argc, char* argv[])
{
  using namespace schur;
  Matrix<float, 3, 2> A = {{1, 2}, {3, 4}, {5, 6}};
  Matrix<float, 3, 2> B = A;
  auto C = A * transpose(B);
  cout(C);
  return 0;
}
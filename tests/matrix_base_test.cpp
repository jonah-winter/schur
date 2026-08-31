#include <iostream>

#include <schur/matrix/Matrix>

int main(int argc, char* argv[])
{
  using namespace schur::internal;
  MatrixBase<float, 2, 2> a = {{1, 2}, {3, 4}};
  a[0, 0] = 5;
  std::cout << a[0, 0] << '\n';
  MatrixBase<float, 2, ::schur::Dynamic> b(3);
  std::cout << b.cols() << '\n';
  MatrixBase<float, ::schur::Dynamic, 2> c(20000);
  std::cout << c.rows() << '\n';
  std::vector<std::vector<float>> vec = {{1, 2}, {3, 4}};
  MatrixBase<float, 2, 2> d(vec);
  std::array<std::array<float, 2>, 2> arr = {{{1, 2}, {3, 4}}};
  MatrixBase<float, 2, 2> e(arr);
  //MatrixBase<float, 3, 2> f(arr);
  return 0;
}
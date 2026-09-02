#include <iostream>
#include <schur/matrix/Matrix>

int main(int argc, char* argv[])
{
  using namespace schur;
  Matrix<float, 2, 2> a = {{1, 2}, {3, 4}};
  a[0, 0] = 5;
  std::cout << a[0, 0] << '\n';
  Matrix<float, 2, Dynamic> b(3);
  std::cout << b.cols() << '\n';
  Matrix<float, Dynamic, 2> c(20000);
  std::cout << c.rows() << '\n';
  std::vector<std::vector<float>> vec = {{1, 2}, {3, 4}};
  Matrix<float, 2, 2> d(vec);
  std::array<std::array<float, 2>, 2> arr = {{{1, 2}, {3, 4}}};
  Matrix<float, 2, 2> e(arr);
  Matrix<float, 3, 3> g{};
  std::cout << g.size() << '\n';
  auto block = g.block(1, 1, 2, 2);
  block[0, 0] = 5;
  std::cout << g[1, 1] << '\n';
  Matrix<float, 2, 2> h{block};
  //std::cout << h[0, 0] << '\n';
  return 0;
}
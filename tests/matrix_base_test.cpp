#include <iostream>
#include <schur/matrix/Matrix>

int main(int argc, char* argv[])
{
  using namespace schur;
  Matrix<float, Dynamic, Dynamic> a = {{1, 2}, {3, 4}};
  Matrix<float, 2, Dynamic> b = a;
  for (size_t i{0}; i < 2; i++) {
    for (size_t z{0}; z < 2; z++) {
       
    }
  }
   
  Matrix<float, Dynamic, 2> c = a;
  Matrix<float, Dynamic, Dynamic> d = a;
  Matrix<float, 2, Dynamic> e = a;
  e = c;
  //Matrix<float, 3, Dynamic> h = a;

  Matrix<float, 4, 4> f{};
  for (size_t i{0}; i < 4; i++) {
    for (size_t z{0}; z < 4; z++) {
      f[i, z] = i + z + i * z;
    }
  }

  Matrix<float, Dynamic, Dynamic> g = a;
   
   
  auto h = block(g, 1, 1, 1, 1);
   
  Matrix<float, 1, 1> i = h;
  Matrix<float, Dynamic, Dynamic> j{10'000, 10'000};
  for (size_t idx{0}; idx < 10'000; idx++) {
    for (size_t idx2{0}; idx2 < 10'000; idx2++) {
      j[idx, idx2] = idx + idx2 + 1;
    }
  }
  auto k = c + b;
  auto l = transpose(k);
  auto m = k + l;

  // use for print function
  // for (size_t idx{0}; idx < m.rows(); idx++) {
  //   for (size_t idx2{0}; idx2 < m.cols(); idx2++) {
  //     std::cout << m[idx, idx2] << ' ';
  //   }
  //   std::cout << '\n';
  // }
  std::cout << m << '\n';
  Matrix<float, 3, 3> n = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::cout << n << '\n';
  std::cout << transpose(n) << '\n';
  auto o = n * transpose(n);
  std::cout << o << '\n';
  std::cout << Matrix<float, 2, 2>({{1, 2}, {3, 4}}) * Matrix<float, 2, 2>({{1, 2}, {3, 4}}) << '\n';

  return 0;
}

#include <iostream>
//#include <valarray>
#include <schur/matrix/Matrix>
#include <schur/quaternion/Quaternion.hpp>
#include <schur/core/Numbers.hpp>
#include <schur/matrix/mult/MatMulNxN.hpp>

/*template <typename M>
concept NonMatrixMatrixExpr = requires (M m)
{
  typename M::matrix_expr_tag;
  requires std::same_as<typename M::main_matrix_tag, schur::internal::NonMainMatrixTag>;
};

template <NonMatrixMatrixExpr M>
auto eval(const M& m)
{
  using namespace schur;
  Matrix<internal::get_rows<M>, internal::get_cols<M>, typename M::val_t, M::layout()> t{m.rows(), m.cols()};
  for (msize_t i{0}; i < m.rows(); i++) {
    for (msize_t i2{0}; i2 < m.cols(); i2++) {
      t[i, i2] = m[i, i2];
    }
  }
  return t;
}

template <schur::msize_t Rows, schur::msize_t Cols, typename Scalar, schur::Layout L>
schur::Matrix<Rows, Cols, Scalar, L>& eval(const schur::Matrix<Rows, Cols, Scalar, L>& m) { return &(m); }

void* operator new(std::size_t n) {
  std::cout << "heap alloc\n";
  void* ptr = std::malloc(n);
  if(!ptr) { throw std::bad_alloc(); }
  return ptr;
}

void operator delete(void* p) noexcept {
  std::cout << "heap delete\n";
  std::free(p);
}

void* operator new[](std::size_t n) {
  std::cout << "arr heap alloc\n";
  void* ptr = std::malloc(n);
  if(!ptr) { throw std::bad_alloc(); }
  return ptr;
}

void operator delete[](void* p) noexcept {
  std::cout << "arr heap delete\n";
  std::free(p);
}
*/

int main(int argc, char* argv[])
{
  using namespace schur;
  using Matrix1d = Matrix<1, 1, double>;
  using Matrix1f = Matrix<1, 1, float>;
  using Matrix1i = Matrix<1, 1, int>;

  using Matrix2d = Matrix<2, 2, double>;
  using Matrix2f = Matrix<2, 2, float>;
  using Matrix2i = Matrix<2, 2, int>;

  using Matrix3d = Matrix<3, 3, double>;
  using Matrix3f = Matrix<3, 3, float>;
  using Matrix3i = Matrix<3, 3, int>;

  using Matrix4d = Matrix<4, 4, double>;
  using Matrix4f = Matrix<4, 4, float>;
  using Matrix4i = Matrix<4, 4, int>;

  using MatrixXd = Matrix<Dynamic, Dynamic, double>;
  using Matrixf = Matrix<Dynamic, Dynamic, float>;
  using Matrixi = Matrix<Dynamic, Dynamic, int>;

  Matrix2d m1 = {{1,2},{3,4}};
  Matrix2d m2 = m1;
  Matrix2d m3 = m1 * m2;
  Matrix2d m4 = m1 + m2 * m3;
  Matrix4f m5 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  auto t1 = transpose(m5);
  return 0;
}

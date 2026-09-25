#include <iostream>
//#include <valarray>
#include <schur/matrix/Matrix>
#include <schur/quaternion/Quaternion.hpp>
#include <schur/core/Numbers.hpp>

// #define TYPEDEF(X, Y) typedef X Y
//
// #if defined(_WIN32)
// #define BEGIN_NAMESPACE_SCHUR \
//   namespace schur {
// #define END_NAMESPACE_SCHUR \
//   }
// #endif
//
// #if defined(__APPLE__)
// #define BEGIN_NAMESPACE_SCHUR \
//   namespace schur {
// #define END_NAMESPACE_SCHUR \
//   }
// #endif
//
// #if defined(__linux__)
// #define BEGIN_NAMESPACE_SCHUR \
//   namespace schur {
// #define END_NAMESPACE_SCHUR \
//   }
// #endif
//
// BEGIN_NAMESPACE_SCHUR
//
// END_NAMESPACE_SCHUR

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

  Matrix<4, 4> m = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9,  10, 11, 12},
    {13, 14, 15, 16}
  };
  
  Matrix<4, 4> m2 = m;
  Matrix<4, 4> m3 = m + m2;
  std::cout << m2 << '\n';
  std::cout << eval(m + m2) << '\n';
  std::cout << m3 << '\n';
  return 0;
}

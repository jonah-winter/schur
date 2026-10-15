#include <iostream>
//#include <valarray>
#include <schur/matrix/Matrix>
#include <schur/quaternion/Quaternion.hpp>
#include <schur/core/Numbers.hpp>
#include <schur/matrix/mult/apple/MM_NxN_NEON.hpp>

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
  m2 = m1 * m2;
  m2.transposeSelf();
  std::cout << m2 << '\n';
  return 0;
}

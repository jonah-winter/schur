#ifndef SCHUR_QUATERNION_HPP_
#define SCHUR_QUATERNION_HPP_

#include <complex>
#include "schur/core/Numbers.hpp"
#include "schur/matrix/Matrix"

namespace schur {
template <typename Scalar = float>
requires(std::is_arithmetic_v<Scalar>)
struct Quaternion
{
  Scalar w, x, y, z;

  template <typename Other>
  requires(std::is_convertible_v<Other, Scalar>)
  Quaternion(Other w, Other x, Other y, Other z) : w(w), x(x), y(y), z(z) {}
  Quaternion() : w{}, x{}, y{}, z{} {}
  Quaternion& operator=(const Quaternion& other) = default;
  Quaternion operator*(const Quaternion& q) const
  {
    Scalar A = w * q.w - x * q.x - y * q.y - z * q.z;
    Scalar B = w * q.x + x * q.w + y * q.z - z * q.y;
    Scalar C = w * q.y - x * q.z + y * q.w + z * q.x;
    Scalar D = w * q.z + x * q.y - y * q.x + z * q.w;
    return Quaternion(A, B, C, D);
  }

  Quaternion operator<=>(const Quaternion& q) const = default;

  void rotate(int angle, Matrix<Scalar, 1, 3> axisVec)
  {
    double s = std::sin(angle * pi<> / 360);
    w = std::cos(angle * pi<> / 360);
    x = axisVec[0, 0] * s;
    y = axisVec[0, 1] * s;
    z = axisVec[0, 2] * s;
  }
  Scalar abs() { return static_cast<Scalar>(std::sqrt(w*w+x*x+y*y+z*z)); }
};

template <typename Scalar>
std::ostream& operator<<(std::ostream& os, const Quaternion<Scalar>& q)
{
  os << q.w << ", " << q.x << "i, " << q.y << "j, " << q.z << "k";
  return os;
}
} // namespace schur
#endif //SCHUR_QUATERNION_HPP_
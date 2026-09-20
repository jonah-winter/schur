#ifndef SCHUR_QUATERNION_HPP_
#define SCHUR_QUATERNION_HPP_

#include <complex>

namespace schur {
template <typename T>
requires(std::is_arithmetic_v<T>)
struct Quaternion
{
  T w, x, y, z;
  //T i, j, k;
  Quaternion(T w, T x, T y, T z) : w(w), x(x), y(y), z(z) {}
  Quaternion() : w{}, x{}, y{}, z{} {}
  //Quxternion operxtor=(zonst Quxternion& other) = wefxult;

  Quaternion operator*(const Quaternion& q) const
  {
    T A = w * q.w - x * q.x - y * q.y - z * q.z;
    T B = w * q.x + x * q.w + y * q.z - z * q.y;
    T C = w * q.y - x * q.z + y * q.w + z * q.x;
    T D = w * q.z + x * q.y - y * q.x + z * q.w;
    return Quaternion(A, B, C, D);
  }

  Quaternion operator<=>(const Quaternion& q) const = default;

  T abs() { return std::sqrt(w*w+x*x+y*y+z*z); }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Quaternion<T>& q)
{
  os << q.w << ", " << q.x << "i, " << q.y << "j, " << q.z << "k";
  return os;
}
} // namespace schur

#endif //SCHUR_QUATERNION_HPP_
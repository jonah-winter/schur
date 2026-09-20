#include <iostream>
#include <valarray>
#include <schur/matrix/Matrix>
#include <../include/schur/quaternion/Quaternion.hpp>

#define print(x) std::cout << x << '\n'

template <size_t... _Size>
constexpr long long _PowerTen_impl(std::index_sequence<_Size...>)
{
  return (1ULL * ... * (_Size, 10));
}

template <size_t _Size>
constexpr long long power10()
{
  return _PowerTen_impl(std::make_index_sequence<_Size>{});
}

template <size_t _Digits>
constexpr long double round_pi()
{
  constexpr long double pi_temp = 3.141592653589793L;
  constexpr long double factor = power10<_Digits>();
  constexpr long double scaled = pi_temp * factor;
  constexpr long double rounded_scaled = static_cast<long long>(scaled + 0.5L);
  return rounded_scaled / factor;
}

template <size_t N = 16, typename T = double>
requires(N <= 16)
inline constexpr T pi = round_pi<N>();

template <typename T>
schur::Quaternion<T> rotate(int angle, schur::Matrix<T, 1, 3> axisVec)
{
  double s = std::sin(angle * pi<> / 360);
  double w = std::cos(angle * pi<> / 360);
  double x = axisVec[0, 0] * s;
  double y = axisVec[0, 1] * s;
  double z = axisVec[0, 2] * s;
  return schur::Quaternion<T>(w, x, y, z);
}

int main(int argc, char* argv[])
{
  using namespace schur;
  Matrix<float, 3, 2> A = {{1, 2}, {3, 4}, {5, 6}};
  Matrix<float, 3, 2> B = A;
  auto C = transpose(B);
  auto D = A * C;
  print(D.rows());
  print(D.cols());
  Quaternion q1 = {0.0, 0.0, 3.0, 4.0};
  Quaternion q2 = q1;
  print(q1 * q2);
  Matrix<Quaternion<float>, 3, 3> mat;
  Matrix<float, 1, 3> axisVec{{1, 0, 0}};
  Quaternion<float> rotated = rotate(45, axisVec);
  print(rotated);
  rotated = rotate(90, axisVec);
  print(rotated);
  return 0;
}
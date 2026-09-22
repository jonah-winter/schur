#include <iostream>
//#include <valarray>
#include <schur/matrix/Matrix>
#include <schur/quaternion/Quaternion.hpp>
#include <schur/core/Numbers.hpp>
#include <schur/core/Range.hpp>

#define TYPEDEF(X, Y) typedef X Y
#define _BEGIN_NAMESPACE_SCHUR namespace schur {
#define _END_NAMESPACE_SCHUR }

/*
namespace schur {
template <size_t... _Args>
using range = typename internal::range_dispatch<_Args...>::type;
struct sizetype
{

  template <typename _Ar>
  requires(std::is_arithmetic_v<_Ar>)
  sizetype(_Ar a)
  {
    if (a & 1) {
      *this -= 2;
    }

  }
};
} // namespace schur
*/

int main(int argc, char* argv[])
{
  using namespace schur;
  return 0;
}
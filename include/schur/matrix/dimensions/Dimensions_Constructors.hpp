#ifndef SCHUR_DIMENSIONS_CONSTRUCTORS_HPP_
#define SCHUR_DIMENSIONS_CONSTRUCTORS_HPP_

#include "schur/core/Types.hpp"
#include "schur/matrix/dimensions/Dimensions_DeclarationInternal.hpp"

namespace schur {
namespace internal {
template <index_t R, index_t C>
Dimensions<Dynamic, Dynamic>::Dimensions(const Dimensions<R, C> &other)
{
  rows_ = other.rows();
  cols_ = other.cols();
}

template <index_t R, index_t C>
Dimensions<Dynamic, Dynamic> Dimensions<Dynamic, Dynamic>::operator=(const Dimensions<R, C>& other)
{
  rows_ = other.rows();
  cols_ = other.cols();
  return *this;
}

template<index_t Rows> requires (valid_dim_(Rows))
template<index_t R, index_t C>
Dimensions<Rows, Dynamic>::Dimensions(const Dimensions<R, C> &other)
{
  cols_ = other.cols();
}

template<index_t Rows> requires (valid_dim_(Rows))
template<index_t R, index_t C>
Dimensions<Rows, Dynamic> Dimensions<Rows, Dynamic>::operator=(const Dimensions<R, C> &other)
{
  cols_ = other.cols();
  return *this;
}

template<index_t Cols> requires (valid_dim_(Cols))
template<index_t R, index_t C>
Dimensions<Dynamic, Cols>::Dimensions(const Dimensions<R, C> &other)
{
  rows_ = other.rows();
}

template<index_t Cols> requires (valid_dim_(Cols))
template<index_t R, index_t C>
Dimensions<Dynamic, Cols> Dimensions<Dynamic, Cols>::operator=(const Dimensions<R, C> &other)
{
  rows_ = other.rows();
  return *this;
}
} // namespace schur
} // namespace internal
#endif //SCHUR_DIMENSIONS_CONSTRUCTORS_HPP_
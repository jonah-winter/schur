#ifndef SCHUR_EVAL_HPP_
#define SCHUR_EVAL_HPP_

#include "schur/matrix/Matrix_MainClass.hpp"
#include "schur/core/Concepts.hpp"

namespace schur {
template <internal::NonMatrixMatrixExpr M>
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
} // namespace schur
#endif // SCHUR_EVAL_HPP_

#ifndef SCHUR_OPERATIONS_BENCHMARKING_HPP
#define SCHUR_OPERATIONS_BENCHMARKING_HPP

#include <functional>

#include <schur/matrix/Matrix>
#include <benchmark/benchmark.h>

namespace schur {
namespace benchmarking {
template <typename Func, typename ...Args>
static void timeFunc(benchmark::State& state, Func func, Args&&... args)
{
  for (auto _ : state) {
    auto result = std::invoke(
      std::forward<Func>(func),
      std::forward<Args>(args)...
    );
    benchmark::DoNotOptimize(result);
  }
}

static void BM_OVERHEAD_COST(benchmark::State& state)
{
  for (auto _ : state) {}
}

static void BM_BLOCK_SM_MATRIX(benchmark::State& state)
{
  Matrix<float, 4, 4> m;
  m.init();
  timeFunc(state, [&m]() {
    return m.block(1, 1, 2, 2);
  });
}

// should be and is about equal to time for small matrix because block size is the same
static void BM_BLOCK_LG_MATRIX(benchmark::State& state)
{
  Matrix<float, 1024, 1024> m;
  m.init();
  timeFunc(state, [&m]() {
    return m.block(1, 1, 2, 2);
  });
}
} // namespace benchmarking
} // namespace schur

#endif //SCHUR_OPERATIONS_BENCHMARKING_HPP

#include <iostream>

#include <benchmark/benchmark.h>
#include <util/Operations_Benchmarking.hpp>

BENCHMARK(schur::benchmarking::BM_BLOCK_SM_MATRIX);
BENCHMARK(schur::benchmarking::BM_BLOCK_LG_MATRIX);
BENCHMARK(schur::benchmarking::BM_OVERHEAD_COST);
BENCHMARK_MAIN();
#ifndef STORAGE_H_
#define STORAGE_H_

#include <bit>
#include <memory>

#include <matrix/global_decls.h>

namespace matrix {
namespace internal {

template <typename T> struct Storage {
  // STRUCT VARIABLES //
private:
  // unique ptr to arr because i want more control than vector and less
  // boilerplate and memory management than plain "new T[]"
  std::unique_ptr<T[]> data;
  size_t size;
  size_t capacity;

  // CONSTRUCTORS //
public:
  explicit Storage() : data{std::make_unique<T[]>()}, size{}, capacity{} {}

  explicit Storage(size_t s)
    : size{s}, capacity{std::bit_ceil(s)},
      data{std::make_unique<T[]>(capacity)} {}

  explicit Storage(size_t r, size_t c)
      : size{r * c}, capacity{std::bit_ceil(r * c)},
        data{std::make_unique<T[]>(capacity)} {}

  explicit Storage(uninitialized_t u, size_t r, size_t c)
      : size{r * c}, capacity{std::bit_ceil(r * c)},
        data{std::unique_ptr<T[]>(new T[std::bit_ceil(r * c)])} {}

  // FUNCTIONS //

  [[nodiscard]] T*
  get_data() const
  {
    return data.get();
  }

  [[nodiscard]] size_t
  get_size() const
  {
    return size;
  }

  [[nodiscard]] size_t
  get_capacity() const
  {
    return capacity;
  }

  [[nodiscard]] T&
  operator[](size_t i)
  {
    return data[i];
  }
};
} // namespace internal
} // namespace matrix

#endif // STORAGE_H_

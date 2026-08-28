#ifndef SCHUR_STORAGE_DECL_INTERNAL_HPP_
#define SCHUR_STORAGE_DECL_INTERNAL_HPP_

#include <matrix/global_decls.hpp>
#include <memory>

namespace matrix {
namespace internal {

template <storage_t T>
struct Storage {
  // STRUCT VARIABLES //
private:
  std::allocator<T> alloc_;
  T* data_;
  size_t size_;
  size_t capacity_;

public:
  // CONSTRUCTORS //
  Storage() : data_{nullptr}, size_{}, capacity_{1} {}

  explicit Storage(size_t s);
  Storage(size_t r, size_t c);
  Storage(const Storage& other);
  Storage(Storage&& other) noexcept;
  ~Storage();
  Storage& operator=(const Storage& other);
  Storage& operator=(Storage&& other) noexcept;

  // FUNCTIONS //
  void safe_resize(size_t s);
  void reserve_copy(size_t s);
  void reserve_move(size_t s);
  void reserve(size_t s);
  size_t grow_cap(size_t s) const;
  void init();
  void init(size_t start, size_t end);
  void init(T val);
  void init(size_t start, size_t end, T val);
  void delete_data();
};
} // namespace internal
} // namespace matrix

#endif // SCHUR_STORAGE_DECL_INTERNAL_HPP_

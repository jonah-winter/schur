#ifndef SCHUR_STORAGE_DECL_INTERNAL_HPP
#define SCHUR_STORAGE_DECL_INTERNAL_HPP

#include <memory>

namespace schur {
namespace internal {

template <storage_t T>
struct Storage {
  // STRUCT VARIABLES //
private:
  std::allocator<T> alloc_;
  std::allocator_traits<decltype(alloc_)> objects_;
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

  // UNSAFE -- fast
  auto& operator[](this auto&& self, size_t i);

  // SAFE -- slow?
  /* not really slow but just slower than the fast ones
   * also some of them are inherently safe and theres not
   * really a point for an unsafe version */

  auto& at(this auto&& self, size_t i);
  auto& data(this auto&& self);
  void resize(size_t s);
  void reserve(size_t s);
  // function for growing capacity internally, should not be used externally
private:
  void reserve_copy(size_t s);
  void reserve_move(size_t s);
  size_t grow_cap(size_t s) const;
  void delete_data();
public:
  void init();
  void init(size_t start, size_t end);
  void init(T val);
  void init(size_t start, size_t end, T val);
  size_t size() const;
  size_t capacity() const;
};
} // namespace internal
} // namespace Matrix
#endif // SCHUR_STORAGE_DECL_INTERNAL_HPP

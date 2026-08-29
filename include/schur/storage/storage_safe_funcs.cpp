#ifndef SCHUR_STORAGE_SAFE_FUNCS
#define SCHUR_STORAGE_SAFE_FUNCS

#include <algorithm>
#include <bit>
#include <stdexcept>
#include <type_traits>

#include <schur/storage/storage_decl_internal.hpp>

namespace schur {
namespace internal {
template <storage_t T>
size_t Storage<T>::grow_cap(size_t s) const {
  if (capacity_ > s) return capacity_;
  return std::max(capacity_ * 2, std::bit_ceil(s));
}

template <storage_t T>
void Storage<T>::init()
{
  for (size_t i{0}; i < size_; i++) {
    objects_.construct(alloc_, data_ + i, static_cast<T>(0));
  }
}

template <storage_t T>
void Storage<T>::init(size_t start, size_t end)
{
  if (end > size_ || start > size_) throw std::out_of_range("out of bounds access");
  for (size_t i{0}; i < size_; i++) {
    objects_.construct(alloc_, data_ + i, static_cast<T>(0));
  }
}

template <storage_t T>
void Storage<T>::init(T val)
{
  for (size_t i{0}; i < size_; i++) {
    objects_.construct(alloc_, data_ + i, val);
  }
}

template <storage_t T>
void Storage<T>::init(size_t start, size_t end, T val)
{
  if (end > size_ || start > size_) throw std::out_of_range("out of bounds access");
  for (size_t i{0}; i < size_; i++) {
    objects_.construct(alloc_, data_ + i, val);
  }
}

template <storage_t T>
auto& Storage<T>::at(this auto&& self, size_t i) {
  if (i < self.size_) return self.data_[i];
  throw std::out_of_range("out of bounds index access");
}

template <storage_t T>
void Storage<T>::reserve_copy(size_t s) {
  size_t new_cap = grow_cap(s);
  T* new_data_ = objects_.allocate(alloc_, new_cap);
  size_t cnt = 0;
  try {
    while (cnt < size_) {
      objects_.construct(alloc_, new_data_ + cnt, data_[cnt]);
      ++cnt;
    }
  } catch (...) {
    for (size_t i{0}; i < cnt; i++) { objects_.destroy(alloc_, new_data_ + i); }
    objects_.deallocate(alloc_, new_data_, new_cap);
    throw;
  }
  for (size_t i{0}; i < size_; i++) { objects_.destroy(alloc_, data_ + i); }
  objects_.deallocate(alloc_, data_, capacity_);
  data_ = new_data_;
  capacity_ = new_cap;
}

template <storage_t T>
void Storage<T>::reserve_move(size_t s) {
  size_t new_cap = grow_cap(s);
  T* new_data_ = objects_.allocate(alloc_, new_cap);
  for (size_t i{0}; i < size_; i++) {
    objects_.construct(alloc_, new_data_ + i, std::move(data_[i]));
    objects_.destroy(alloc_, data_ + i);
  }
  objects_.deallocate(alloc_, data_, capacity_);
  data_ = new_data_;
  capacity_ = new_cap;
}

template <storage_t T>
void Storage<T>::reserve(size_t s) {
  if (s <= capacity_) return;
  if (std::is_nothrow_move_constructible_v<T>) reserve_move(s);
  else reserve_copy(s);
}

template <storage_t T>
void Storage<T>::resize(size_t s) {
  if (s <= size_) {
    for (size_t i{s}; i < size_; i++) {
      objects_.destroy(alloc_, data_ + i);
    }
  } else {
    reserve(s);
    size_t old_size = size_;
    size_t cnt = 0;
    try {
      while (old_size + cnt < s) {
        objects_.construct(alloc_, data_ + old_size + cnt);
        ++cnt;
      }
    } catch (...) {
      for (size_t i{0}; i < cnt; i++) {
        objects_.destroy(alloc_, data_ + i + old_size);
      }
      throw;
    }
  }
  size_ = s;
}

template <storage_t T>
void Storage<T>::delete_data() {
  if (data_) {
    for (size_t i{0}; i < size_; i++) objects_.destroy(alloc_, data_ + i);
    objects_.deallocate(alloc_, data_, capacity_);
  }
}

template <storage_t T>
size_t Storage<T>::size() const {
  return size_;
}

template <storage_t T>
size_t Storage<T>::capacity() const {
  return capacity_;
}
} // namespace internal
} // namespace matrix
#endif // SCHUR_STORAGE_SAFE_FUNCS
#ifndef SCHUR_STORAGE_SAFE_FUNCS_CPP
#define SCHUR_STORAGE_SAFE_FUNCS_CPP

#include <algorithm>
#include <bit>
#include <type_traits>

#include <matrix/storage_decl_internal.hpp>

namespace matrix {
namespace internal {

template<storage_t T>
size_t Storage<T>::grow_cap(size_t s) const
{
  if (capacity_ > s) return capacity_;
  return std::max(capacity_ * 2, std::bit_ceil(s));
}

template<storage_t T>
void Storage<T>::reserve_copy(size_t s)
{
  size_t new_cap = grow_cap(s);
  T* new_data_ = alloc_.allocate(new_cap);
  size_t cnt = 0;
  try {
    while (cnt < size_) {
      alloc_.construct(new_data_ + cnt, data_[cnt]);
      ++cnt;
    }
  } catch (...) {
    for (size_t i{0}; i < cnt; i++) {
      alloc_.destroy(new_data_ + i);
    }
    alloc_.deallocate(new_data_, new_cap);
    throw;
  }
  for (size_t i{0}; i < size_; i++) {
    alloc_.destroy(data_ + i);
  }
  alloc_.deallocate(data_, capacity_);
  data_ = new_data_;
  capacity_ = new_cap;
}

template<storage_t T>
void Storage<T>::reserve_move(size_t s)
{
  size_t new_cap = grow_cap(s);
  T* new_data_ = alloc_.allocate(new_cap);
  for (size_t i{0}; i < size_; i++) {
    alloc_.construct(new_data_ + i, std::move(data_[i]));
    alloc_.destroy(data_ + i);
  }
  alloc_.deallocate(data_, capacity_);
  data_ = new_data_;
  capacity_ = new_cap;
}

template<storage_t T>
void Storage<T>::reserve(size_t s)
{
  if (s <= capacity_) return;
  if (std::is_nothrow_move_constructible_v<T>) reserve_move(s);
  else reserve_copy(s);
}

template<storage_t T>
void Storage<T>::safe_resize(size_t s)
{
  reserve(s);
  size_ = s;
}

template<storage_t T>
void Storage<T>::delete_data()
{
  if (data_) {
    for (size_t i{0}; i < size_; i++) {
      alloc_.destroy(data_ + i);
    }
    alloc_.deallocate(data_, capacity_);
  }
}
}
}

#endif // SCHUR_STORAGE_SAFE_FUNCS_CPP

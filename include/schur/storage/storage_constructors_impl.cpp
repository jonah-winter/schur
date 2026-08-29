#ifndef SCHUR_STORAGE_CONSTRUCTORS_IMPL
#define SCHUR_STORAGE_CONSTRUCTORS_IMPL

#include <stdexcept>
#include <iostream>
#include <schur/matrix/global_decls.hpp>
#include <schur/storage/storage_decl_internal.hpp>

namespace schur {
namespace internal {

// SIZE CONSTRUCTOR //
template <storage_t T>
Storage<T>::Storage(size_t s)
  : data_{nullptr}, size_{0}, capacity_{1}
{
  if (s) [[likely]] {
    size_ = s;
    capacity_ = grow_cap(s);
    data_ = objects_.allocate(alloc_, capacity_);
  }
}

// DIMENSIONS CONSTRUCTOR //
template <storage_t T>
Storage<T>::Storage(size_t r, size_t c)
  : data_{nullptr}, size_{0}, capacity_{1}
{
  if (SIZE_MAX / r < c) throw std::out_of_range("size is too big");
  size_t s = r * c;
  if (s) [[likely]] {
    size_ = s;
    capacity_ = grow_cap(s);
    data_ = objects_.allocate(alloc_, capacity_);
  }
}

// COPY CONSTRUCTOR //
template <storage_t T>
Storage<T>::Storage(const Storage& other)
    : size_{other.size_}, capacity_{other.capacity_}
{
  if (other.data_ != nullptr) {
    data_ = objects_.allocate(alloc_, capacity_);
    size_t i{0};
    // i is global to use as count for catch loop
    try {
      while (i < size_) {
        objects_.construct(alloc_, data_ + i, other[i]);
        ++i;
      }
    } catch (...) {
      // catch exceptions related to T constructor's throw
      for (size_t z{0}; z < i; z++) { objects_.destroy(alloc_, data_ + z); }
      objects_.deallocate(alloc_, data_, capacity_);
      // "throw;" just rethrows current exception
      throw;
    }
  } else {
    data_ = nullptr;
  }
}

// COPY ASSIGNMENT //
template <storage_t T>
Storage<T>& Storage<T>::operator=(const Storage<T>& other)
{
  if (this == &other) return *this;
  if (other.data_ != nullptr) {
    size_t i{0};
    // see notes in copy constructor
    T* new_data_ = objects_.allocate(alloc_, other.capacity_);
    try {
      while (i < other.size_) {
        objects_.construct(alloc_, new_data_ + i, other[i]);
        ++i;
      }
    } catch (...) {
      for (size_t z{0}; z < i; z++) { objects_.destroy(alloc_, new_data_ + z); }
      objects_.deallocate(alloc_, new_data_, other.capacity_);
      throw;
    }
    delete_data();
    data_ = new_data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    return *this;
  }
  delete_data();
  data_ = nullptr;
  size_ = 0;
  capacity_ = 1;
  return *this;
}

// MOVE CONSTRUCTOR //
template <storage_t T>
Storage<T>::Storage(Storage&& other) noexcept
    : data_{other.data_}, size_{other.size_}, capacity_{other.capacity_} {
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 1;
}

// MOVE ASSIGNMENT //
template <storage_t T>
Storage<T>& Storage<T>::operator=(Storage&& other) noexcept {
  if (this == &other) return *this;
  delete_data();
  data_ = other.data_;
  size_ = other.size_;
  capacity_ = other.capacity_;

  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 1;

  return *this;
}

// DESTRUCTOR //
template <storage_t T>
Storage<T>::~Storage() {
  delete_data();
  data_ = nullptr;
  size_ = 0;
  capacity_ = 1;
}
} // namespace internal
} // namespace matrix

#endif // SCHUR_STORAGE_CONSTRUCTORS_IMPL

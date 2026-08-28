#ifndef SCHUR_STORAGE_CONSTRUCTORS_IMPL_H
#define SCHUR_STORAGE_CONSTRUCTORS_IMPL_H

#include <matrix/storage_decl_internal.hpp>
#include <matrix/global_decls.hpp>

namespace matrix {
namespace internal {

// SIZE CONSTRUCTOR //
template<storage_t T>
Storage<T>::Storage(size_t s)
{
  if (s) [[likely]] {
    size_ = s;
    capacity_ = grow_cap(s);
    data_ = alloc_.allocate(capacity_);
  } else {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 1;
  }
}

// DIMENSIONS CONSTRUCTOR //
template<storage_t T>
Storage<T>::Storage(size_t r, size_t c)
{
  size_t s = r * c;
  if (s) [[likely]] {
    size_ = s;
    capacity_ = grow_cap(s);
    data_ = alloc_.allocate(capacity_);
  } else {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 1;
  }
}

// COPY CONSTRUCTOR //
template<storage_t T>
Storage<T>::Storage(const Storage& other)
  : size_{other.size_}, capacity_{other.capacity_}
{
  if (other.data_ != nullptr) {
    data_ = alloc_.allocate(capacity_);
    size_t i{0};
    // i is global to use as count for catch loop
    try {
      while (i < size_) {
        alloc_.construct(data_ + i, other[i]);
        ++i;
      }
    } catch (...) {
      // catch exceptions related to T constructor's throw
      for (size_t z{0}; z < i; z++) {
        alloc_.destroy(data_ + z);
      }
      alloc_.deallocate(data_, capacity_);
      // "throw;" just rethrows current exception
      throw;
    }
  } else {
    data_ = nullptr;
  }
}

// COPY ASSIGNMENT //
template<storage_t T>
Storage<T>& Storage<T>::operator=(const Storage<T>& other)
{
  if (this == &other) return *this;
  if (other.data_ != nullptr) {
    size_t i{0};
    // see notes in copy constructor
    T* new_data_ = alloc_.allocate(other.capacity_);
    try {
      while (i < other.size_) {
        alloc_.construct(new_data_ + i, other[i]);
        ++i;
      }
    } catch (...) {
      for (size_t z{0}; z < i; z++) {
        alloc_.destroy(new_data_ + z);
      }
      alloc_.deallocate(new_data_, other.capacity_);
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
template<storage_t T>
Storage<T>::Storage(Storage&& other) noexcept
  : data_{other.data_}, size_{other.size_}, capacity_{other.capacity_}
{
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 1;
}

// MOVE ASSIGNMENT //
template<storage_t T>
Storage<T>& Storage<T>::operator=(Storage&& other) noexcept
{
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
template<storage_t T>
Storage<T>::~Storage()
{
  delete_data();
  data_ = nullptr;
  size_ = 0;
  capacity_ = 1;
}
} // namespace matrix
} // namespace internal

#endif //SCHUR_STORAGE_CONSTRUCTORS_IMPL_H
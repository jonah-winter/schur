#ifndef STORAGE_H_
#define STORAGE_H_

#include <bit>
#include <memory>
#include <stdexcept>

#include <matrix/global_decls.h>

namespace matrix {
namespace internal {

template <typename T>
struct Storage {
  // STRUCT VARIABLES //
private:
  // allocator type to allocate memory for data pointer
  std::allocator<T> alloc_;
  //using AllocTraits = std::allocator_traits<decltype(alloc_)>;
  T* data_;
  size_t size_;
  size_t capacity_;

  // CONSTRUCTORS //
public:
  explicit Storage() : data_{nullptr}, size_{}, capacity_{} {}

  explicit Storage(size_t s)
    : data_{nullptr}, size_{s} 
  {
    if (s) [[likely]] {
      capacity_ = std::bit_ceil(s);
      data_ = alloc_.allocate(capacity_);
    } else {
      capacity_ = 0;
    }
  }

  Storage(size_t r, size_t c)
    : data_{nullptr}, size_{r * c} 
  {
    if (r * c) [[likely]] {
      capacity_ = std::bit_ceil(r * c);
      data_ = alloc_.allocate(capacity_);
    } else {
      capacity_ = 0;
    }
  }

  // destructor
  ~Storage() 
  {
    if (data_ != nullptr) {
      alloc_.deallocate(data_, capacity_);
    }
  }

  // copy constructor
  Storage(const Storage& storage)
    : data_{nullptr},
      size_{storage.size_},
      capacity_{storage.capacity_}
  {
    if (capacity_) {
      data_ = alloc_.allocate(storage.capacity_);
      copy_(storage.data_, 0, storage.size_);
    }
  }

  // copy assignment
  Storage& operator=(const Storage& storage) 
  {
    if (this == &storage) return *this;
    // two paths
    if (capacity_ < storage.size_) {
      size_t new_cap_ = std::bit_ceil(storage.size_);
      T* new_ = alloc_.allocate(new_cap_);
      /* storage.size_ is guaranteeed to be valid memory for new_[i]
       * because we allocated enough capacity so that its greater than
       * or equal to storage.size_ */
      for (size_t i{0}; i < storage.size_; i++) {
        new_[i] = storage[i];
      }
      alloc_.deallocate(data_, capacity_);
      data_ = new_;
      capacity_ = new_cap_;
      size_ = storage.size_;
    } else {
      copy_(storage.data_, 0, storage.size_);
      size_ = storage.size_;
    }
    return *this;
  }

  // move constructor
  Storage(Storage&& storage)
    : data_{storage.data_},
      size_{storage.size_},
      capacity_{storage.capacity_}
  {
    storage.data_ = nullptr;
    storage.size_ = 0;
    storage.capacity_ = 0;
  }

  // move assignment
  Storage& operator=(Storage&& storage)
  {
    if (this == &storage) return *this;
    if (data_ != nullptr) {
      alloc_.deallocate(data_, capacity_);
    }
    data_ = storage.data_;
    size_ = storage.size_;
    capacity_ = storage.capacity_;

    storage.data_ = nullptr;
    storage.size_ = 0;
    storage.capacity_ = 0;
    return *this;
  }

  // FUNCTIONS //

  void init_(size_t start, size_t end)
  {
    for (size_t i{start}; i < end; i++) {
      data_[i] = static_cast<T>(0);
    }
  }
  
  void init_()
  {
    for (size_t i{0}; i < size_; i++) {
      data_[i] = static_cast<T>(0);
    }
  }

  void init_checked_(size_t start, size_t end)
  {
    if (start > end || start > size_) throw std::logic_error("start should be less than end and size");
    if (end > size_) throw std::logic_error("end must be equal to or less than size");
    for (size_t i{start}; i < end; i++) {
      data_[i] = static_cast<T>(0);
    }
  }

  void copy_(T* arr, size_t start, size_t end)
  {
    for (size_t i{start}; i < end; i++) {
      data_[i] = arr[i - start];
    }
  }

  [[nodiscard]] T* get_data_() const { return data_; }

  [[nodiscard]] size_t get_size_() const { return size_; }

  [[nodiscard]] size_t get_cap_() const { return capacity_; }

  [[nodiscard]] T& operator[](size_t i) { return data_[i]; }

  [[nodiscard]] const T& operator[](size_t i) const { return data_[i]; }

  [[nodiscard]] T& at_(size_t i)
  {
    if (i >= get_size_()) throw std::out_of_range("index is out of bounds");
    return data_[i];
  }

  [[nodiscard]] const T& at_(size_t i) const
  {
    if (i >= get_size_()) throw std::out_of_range("index is out of bounds");
    return data_[i];
  }
};
} // namespace internal
} // namespace matrix

#endif // STORAGE_H_

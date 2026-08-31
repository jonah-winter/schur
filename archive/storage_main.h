#ifndef STORAGE_H_
#define STORAGE_H_

#include <algorithm>
#include <bit>
#include <memory>
#include <stdexcept>

#include <matrix/global_decls.hpp>

namespace matrix {
namespace internal {

template <typename T>
struct Storage {
  // STRUCT VARIABLES //
private:
  // allocator type to allocate memory for data pointer
  std::allocator<T> alloc_;
  // using AllocTraits = std::allocator_traits<decltype(alloc_)>;
  T* data_;
  size_t size_;
  size_t capacity_;

  // CONSTRUCTORS //
public:
  explicit Storage() : data_{nullptr}, size_{}, capacity_{1} {}

  explicit Storage(size_t s)
    : data_{nullptr}, size_{s}, capacity_{1}
  {
    if (s) [[likely]] {
      capacity_ = grow_cap_(s);
      data_ = alloc_.allocate(capacity_);
    }
  }

  Storage(size_t r, size_t c)
    : data_{nullptr}, size_{r * c} 
  {
    if (r * c) [[likely]] {
      capacity_ = grow_cap_(r * c);
      data_ = alloc_.allocate(capacity_);
    } else {
      capacity_ = 1;
    }
  }

  // big 5 //

  // destructor
  ~Storage() 
  {
    if (data_ != nullptr) [[likely]] {
      for (size_t i{0}; i < size_; i++) {
        alloc_.destroy(data_ + i);
      }
      alloc_.deallocate(data_, capacity_);
    }
  }

  // copy constructor
  Storage(const Storage& storage)
    : data_{nullptr},
      size_{storage.size_},
      capacity_{storage.capacity_}
  {
    if (capacity_ > 1) {
      data_ = alloc_.allocate(storage.capacity_);
      copy_init_(storage.data_, 0, storage.size_);
    }
  }

  // copy assignment
  Storage& operator=(const Storage& storage) 
  {
    if (this == &storage) return *this;
    
    if (capacity_ < storage.size_) {
      size_t new_cap_ = grow_cap_(storage.size_);
      T* new_ = alloc_.allocate(new_cap_);

      for (size_t i{0}; i < storage.size_; i++) {
        alloc_.construct(new_ + i, storage[i]);
        alloc_.destroy(data_ + i);
      }
      alloc_.deallocate(data_, capacity_);
      data_ = new_;
      capacity_ = new_cap_;
      size_ = storage.size_;
    } else {
      copy_init_(storage.data_, 0, storage.size_);
      size_ = storage.size_;
    }
    return *this;
  }

  // move constructor
  Storage(Storage&& storage) noexcept
    : data_{storage.data_},
      size_{storage.size_},
      capacity_{storage.capacity_}
  {
    storage.data_ = nullptr;
    storage.size_ = 0;
    storage.capacity_ = 1;
  }

  // move assignment
  Storage& operator=(Storage&& storage) noexcept
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
    storage.capacity_ = 1;
    return *this;
  }

  // FUNCTIONS //
  void resize_(size_t i)
  {
    reserve_(i);
    size_ = i;
  }

  void resize_(size_t i, const T& val)
  {
    reserve_(i);
    for (size_t z{size_}; z < i; z++) {
      data_[i] = val;
    }
    size_ = i;
  }

  void reserve_(size_t i)
  {
    if (i <= capacity_) return;
    T* old_ = data_;
    data_ = alloc_.allocate(i);
    for (size_t z{0}; z < size_; z++) {
      alloc_.construct(data_ + z, old_[z]);
      alloc_.destroy(old_ + z);
    }
    alloc_.deallocate(old_, capacity_);
    capacity_ = i;
  }

  void init_(size_t start, size_t end)
  {
    for (size_t i{0}; i < size_; i++) {
      alloc_.construct(data_ + i, static_cast<T>(0));
    }
  }
  
  void init_()
  {
    for (size_t i{0}; i < size_; i++) {
      alloc_.construct(data_ + i, static_cast<T>(0));
    }
  }

  void init_checked_(size_t start, size_t end)
  {
    if (start > end || start > size_) throw std::logic_error("start should be less than end and size");
    if (end > size_) throw std::logic_error("end must be equal to or less than size");
    for (size_t i{0}; i < size_; i++) {
      alloc_.construct(data_ + i, static_cast<T>(0));
    }
  }

  void copy_init_(T* arr, size_t start, size_t end)
  {
    for (size_t i{0}; i < size_; i++) {
      alloc_.construct(data_ + i, arr[i]);
    }
  }
  
  void copy_(T* arr, size_t start, size_t end)
  {
    for (size_t i{start}; i < end; i++) {
      data_[i] = arr[i - start];
    }
  }

  size_t grow_cap_(size_t s) const
  {
    return std::max(capacity_ * 2,
                    std::bit_ceil(s));
  }

  [[nodiscard]] T* get_data_() const { return data_; }

  [[nodiscard]] size_t get_size_() const { return size_; }

  [[nodiscard]] size_t get_cap_() const { return capacity_; }

  // INDEXING //

  // dont resize, unchecked
  [[nodiscard]] T& operator[](size_t i) { return data_[i]; }

  // dont resize, unchecked, view only
  [[nodiscard]] const T& operator[](size_t i) const { return data_[i]; }

  // dont resize, checked
  [[nodiscard]] T& at_(size_t i)
  {
    if (i >= get_size_()) throw std::out_of_range("index is out of bounds");
    return data_[i];
  }

  // dont resize, checked, view only
  [[nodiscard]] const T& at_(size_t i) const
  {
    if (i >= get_size_()) throw std::out_of_range("index is out of bounds");
    return data_[i];
  }

  // if (i < get_cap_()) {
  //   if (i >= size_) {
  //     size_ += size_ - i + 1;
  //     return data_[i];
  //   }
  // }
  // // else
  // throw std::out_of_range("index is out of bounds");
};
} // namespace internal
} // namespace Matrix

#endif // STORAGE_H_

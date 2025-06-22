#pragma once
#include "../base/base.h"
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <utility>

namespace fstd {

struct random_access_iterator_tag {};

template <typename Container> class GeneralIterator {
public:
  using iterator_category = fstd::random_access_iterator_tag;
  using value_type = typename Container::vType;
  using difference_type = std::ptrdiff_t;
  using pointer = value_type *;
  using reference = value_type &;

  GeneralIterator(pointer ptr = nullptr) : m_ptr(ptr) {}

  reference operator*() const { return *m_ptr; }

  pointer operator->() const { return m_ptr; }

  GeneralIterator &operator++() {
    m_ptr++;
    return *this;
  }

  GeneralIterator operator++(int) {
    GeneralIterator tmp = *this;
    ++(*this);
    return tmp;
  }

  GeneralIterator &operator--() {
    m_ptr--;
    return *this;
  }

  GeneralIterator operator--(int) {
    GeneralIterator tmp = *this;
    --(*this);
    return tmp;
  }

  difference_type operator-(const GeneralIterator &other) const {
    return m_ptr - other.m_ptr;
  }
  GeneralIterator operator+(difference_type n) const {
    return GeneralIterator(m_ptr + n);
  }
  GeneralIterator operator-(difference_type n) const {
    return GeneralIterator(m_ptr - n);
  }

  bool operator==(const GeneralIterator &other) const {
    return m_ptr == other.m_ptr;
  }
  bool operator!=(const GeneralIterator &other) const {
    return !(*this == other);
  }

private:
  pointer m_ptr;
};

template <typename ContainerType, typename SizeType = int> class Vector {
public:
  using vType = ContainerType;
  using sizeType = SizeType;
  using Iterator = GeneralIterator<Vector<ContainerType, SizeType>>;

  Vector(SizeType capacity)
      : m_Size(0), m_Capacity(capacity),
        m_Container(new ContainerType[capacity]) {}
  Vector(const Vector &other)
      : m_Size(other.m_Size), m_Capacity(other.m_Capacity),
        m_Container(new ContainerType[other.m_Capacity]) {

    for (SizeType i = 0; i < this->m_Size; ++i) {
      this->m_Container[i] = other.m_Container[i];
    }
  }
  Vector(Vector &&other)
      : m_Size(other.m_Size), m_Capacity(other.m_Capacity),
        m_Container(std::move(other.m_Container)) {
    other.m_Container = nullptr;
    other.m_Size = 0;
    other.m_Capacity = 0;
  }

  Vector &operator=(const Vector &other) {
    if constexpr (this->m_Capacity < other.m_Capacity) {
      grow(); // not elegant enough, needs something like expand_to_size
    }
    this->m_Size = other.m_Size; // temporary fix, buggy
    this->m_Capacity = other.m_Capacity;
    for (SizeType i = 0; i < other.m_Size; ++i) {
      this->m_Container[i] = other.m_Container[i];
    }
  }

  Vector &operator=(Vector &&other) {
    if constexpr (this->m_Capacity < other.m_Capacity) {
      grow(); // not elegant enough, needs something like expand_to_size
    }
    this->m_Size = other.m_Size;
    this->m_Capacity = other.m_Capacity;
    for (SizeType i = 0; i < other.m_Size; ++i) {
      this->m_Container[i] = std::move(other.m_Container[i]);
    }
  }

  ContainerType &operator[](SizeType index) {
    if (index >= this->m_Size) {
      throw std::out_of_range("Vector out_of_range!");
    }
    return this->m_Container[index];
  }

  SizeType size() { return this->m_Size; }

  SizeType capacity() { return m_Capacity; }

  void pushBack(const ContainerType &newElement) {
    if (this->m_Size >= this->m_Capacity) {
      grow();
    }
    this->m_Container[m_Size] = newElement;
    this->m_Size++;
  }

  template <typename... TypeList> void emplaceBack(TypeList &&...newElements) {
    if (this->m_Size >= this->m_Capacity) {
      grow();
    }
    this->m_Container[m_Size] =
        ContainerType(std::forward<TypeList>(newElements)...);
    this->m_Size++;
  }

  Iterator begin() { return Iterator(m_Container); }

  Iterator end() { return Iterator(m_Container + m_Size); }

  ~Vector() {
    delete[] this->m_Container;
    this->m_Capacity = 0;
    this->m_Size = 0;
  }

private:
  void grow() {
    SizeType newCapacity = !m_Capacity ? 1 : std::round(1.5 * m_Capacity);
    // Todo: implement a type safe size check and throw error if mem exceeded?
    ContainerType *newData = static_cast<ContainerType *>(operator new[](
        newCapacity * sizeof(ContainerType)));

    for (SizeType i = 0; i < m_Size; ++i) {
      new (&newData[i]) ContainerType(std::move(m_Container[i]));
      m_Container[i].~ContainerType();
    }

    operator delete[](m_Container);
    m_Container = newData;
    m_Capacity = newCapacity;
  }

private:
  ContainerType *m_Container;
  SizeType m_Capacity = 0;
  SizeType m_Size;
};

template <typename ContainerType> using Vector8 = Vector<ContainerType, ui8>;
template <typename ContainerType> using Vector16 = Vector<ContainerType, ui16>;
template <typename ContainerType> using Vector32 = Vector<ContainerType, ui32>;
template <typename ContainerType> using Vector64 = Vector<ContainerType, ui64>;

} // namespace fstd

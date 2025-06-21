#pragma once
#include "../base/base.h"
#include <cmath>

namespace fstd {

template <typename ContainerType, typename SizeType = int> class Vector {
public:
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
      // add some expanding functionality
    }
    this->m_Size = other.m_Size; // temporary fix, buggy
    this->m_Capacity = other.m_Capacity;
    for (SizeType i = 0; i < other.m_Size; ++i) {
      this->m_Container[i] = other.m_Container[i];
    }
  }

  Vector &operator=(Vector &&other) {
    if constexpr (this->m_Capacity < other.m_Capacity) {
      // add some expanding functionality
    }
    this->m_Size = other.m_Size;
    this->m_Capacity = other.m_Capacity;
    for (SizeType i = 0; i < other.m_Size; ++i) {
      this->m_Container[i] = std::move(other.m_Container[i]);
    }
  }

  ContainerType &operator[](SizeType index) { return this->m_Container[index]; }

  SizeType size() { return this->m_Size; }

  SizeType capacity() { return m_Capacity; }

  ~Vector() {
    delete[] this->m_Container;
    m_Capacity = 0;
    m_Size = 0;
  }

private:
  void grow() {
    SizeType newCapacity = !m_Capacity ? 1 : std::round(1.5 * m_Capacity);
    ContainerType *newData = static_cast<ContainerType *>(operator new[](
        newCapacity * sizeof(ContainerType)));

    for (SizeType i = 0; i < m_Size; ++i) {
      new (&newData[i]) ContainerType(std::move(m_Container));
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

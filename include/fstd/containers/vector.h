#pragma once
#include "../base/base.h"

namespace fstd {

template <typename ContainerType, typename SizeType = int> class Vector {
public:
  Vector(SizeType size) : m_Size(size), m_Container(new ContainerType[size]) {}

  ContainerType &operator[](SizeType index) { return this->m_Container[index]; }

  SizeType size() { return this->m_Size; }

  ~Vector() { delete[] this->m_Container; }

private:
private:
  ContainerType *m_Container;
  SizeType m_Size;
};

template <typename ContainerType> using Vector8 = Vector<ContainerType, ui8>;
template <typename ContainerType> using Vector16 = Vector<ContainerType, ui16>;
template <typename ContainerType> using Vector32 = Vector<ContainerType, ui32>;
template <typename ContainerType> using Vector64 = Vector<ContainerType, ui64>;

} // namespace fstd

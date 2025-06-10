//
// Created by eden on 6/5/25.
//Email:Edenhassin@gmail.com

#ifndef MYCONTAINER_H
#define MYCONTAINER_H
#include <vector>
#include <iostream>
#include "Iterator/AscendingOrder.h"
#include "Iterator/DescendingOrder.h"
#include "Iterator/Order.h"
#include "Iterator/SideCrossOrder.h"
#include "Iterator/ReverseOrder.h"
#include "Iterator/MiddleOutOrder.h"

namespace Container{

    template<typename T = int>
    class MyContainer {
    private:
        std::vector<T> elements;

    public:
        // Give iterators access to private elements
        friend class AscendingIterator<T>;
        friend class DescendingIterator<T>;
        friend class SideCrossIterator<T>;
        friend class ReverseIterator<T>;
        friend class OrderIterator<T>;
        friend class MiddleOutIterator<T>;

        void addElement(const T& element);
        void removeElement(const T& item);

        size_t size() const { return elements.size(); }

        /**
     * ⚠️ Warning:
     * Iterators become invalid if the container is modified (via addElement or removeElement).
     * Make sure to avoid modifying the container while iterating over it.
     */

        AscendingIterator<T> begin_ascending_order() const { return AscendingIterator<T>(*this, 0); }
        AscendingIterator<T> end_ascending_order() const { return AscendingIterator<T>(*this, size()); }

        DescendingIterator<T> begin_descending_order() const { return DescendingIterator<T>(*this, 0); }
        DescendingIterator<T> end_descending_order() const { return DescendingIterator<T>(*this, size()); }

        SideCrossIterator<T> begin_side_cross_order() const { return SideCrossIterator<T>(*this, 0); }
        SideCrossIterator<T> end_side_cross_order() const { return SideCrossIterator<T>(*this, size()); }

        ReverseIterator<T> begin_reverse_order() const { return ReverseIterator<T>(*this, 0); }
        ReverseIterator<T> end_reverse_order() const { return ReverseIterator<T>(*this, size()); }

        OrderIterator<T> begin_order() const { return OrderIterator<T>(*this, 0); }
        OrderIterator<T> end_order() const { return OrderIterator<T>(*this, size()); }

        MiddleOutIterator<T> begin_middle_out_order() const { return MiddleOutIterator<T>(*this, 0); }
        MiddleOutIterator<T> end_middle_out_order() const { return MiddleOutIterator<T>(*this, size()); }

        friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
            os << "[";
            for (size_t i = 0; i < container.elements.size(); ++i) {
                os << container.elements[i];
                if (i + 1 != container.elements.size()) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }
    };

  template<typename T>
  void MyContainer<T>::addElement(const T& element){
        elements.push_back(element);
    }

    template<typename T>
    void MyContainer<T>::removeElement(const T& item) {
      auto oldSize = elements.size();
      elements.erase(std::remove(elements.begin(), elements.end(), item), elements.end());
      if (elements.size() == oldSize) {
          throw std::runtime_error("Element not found in container");
      }
  }



}
#endif //MYCONTAINER_H

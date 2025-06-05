#ifndef ASCENDINGORDER_H
#define ASCENDINGORDER_H

#include <vector>
#include <algorithm>
#include "../MyContainer.h"

namespace Container {

    /**
     * AscendingIterator class for iterating over MyContainer elements in ascending order.
     * Stores sorted indices of elements and iterates over them by index.
     */
    template<typename T = int>
    class AscendingIterator {
    private:
        const MyContainer<T>& container;
        size_t index;
        std::vector<size_t> sorted_indices;

        // Helper function to build sorted indices in ascending order
        void build_ascending_order() {
            size_t sz = container.size();
            sorted_indices.resize(sz);
            for (size_t i = 0; i < sz; ++i) {
                sorted_indices[i] = i;
            }
            std::sort(sorted_indices.begin(), sorted_indices.end(),
                      [&](size_t a, size_t b) {
                          return container.elements[a] < container.elements[b];
                      });
        }

    public:
        /**
         * Constructor initializes iterator with container reference and start index (default 0).
         */
        AscendingIterator(const MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_ascending_order();
        }

        const T& operator*() const {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("AscendingIterator dereference out of range");
            }
            return container.elements[sorted_indices[index]];
        }


        AscendingIterator& operator++() {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("AscendingIterator increment past end");
            }
            ++index;
            return *this;
        }


        bool operator==(const AscendingIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        bool operator!=(const AscendingIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // ASCENDINGORDER_H

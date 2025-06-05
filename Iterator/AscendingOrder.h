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
        const MyContainer<T>& container;   // Reference to the container being iterated
        size_t index;                      // Current position in the sorted indices vector
        std::vector<size_t> sorted_indices; // Vector storing indices of elements sorted ascendingly

    public:
        /**
         * Constructor initializes iterator with container reference and start index (default 0).
         * Builds sorted_indices vector sorted by element values in ascending order.
         */
        AscendingIterator(const MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            sorted_indices.resize(container.size());
            for (size_t i = 0; i < container.size(); ++i) {
                sorted_indices[i] = i;
            }
            std::sort(sorted_indices.begin(), sorted_indices.end(),
                      [&](size_t a, size_t b) {
                          return container.elements[a] < container.elements[b];
                      });
        }

        /**
         * Dereference operator returns the element pointed to by the iterator.
         */
        const T& operator*() const {
            return container.elements[sorted_indices[index]];
        }

        /**
         * Prefix increment operator moves iterator to the next element.
         */
        AscendingIterator& operator++() {
            ++index;
            return *this;
        }

        /**
         * Equality comparison operator checks if two iterators point to the same container and index.
         */
        bool operator==(const AscendingIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * Inequality operator negates equality operator.
         */
        bool operator!=(const AscendingIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif // ASCENDINGORDER_H

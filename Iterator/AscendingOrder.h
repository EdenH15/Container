//Email:Edenhassin@gmail.com

#ifndef ASCENDINGORDER_H
#define ASCENDINGORDER_H

#include <vector>
#include <algorithm>

namespace Container {
    template<typename T>
    class MyContainer;

    /**
    * @brief Iterator that traverses a MyContainer in ascending order.
    *
    * Iteration order is from the smallest element to the largest element
    * based on the values stored in the container.
    */
    template<typename T = int>
    class AscendingIterator {
    private:
        const MyContainer<T> &container;
        size_t index;
        std::vector<size_t> sorted_indices;

        /**
         * @brief Helper function to build the sorted indices vector.
         *
         * Initializes sorted_indices with indices 0-size-1 and sorts them
         * so that elements are in ascending order by their values.
         */
        void build_ascending_order() {
            const size_t s = container.size();
            sorted_indices.resize(s);
            for (size_t i = 0; i < s; ++i) {
                sorted_indices[i] = i;
            }
            std::sort(sorted_indices.begin(), sorted_indices.end(),
                      [&](size_t a, size_t b) {
                          return container.elements[a] < container.elements[b];
                      });
        }

    public:

        /**
         * @brief Constructs an AscendingIterator for a given container.
         *
         * @param cont Reference to the MyContainer to iterate.
         * @param start Starting index position (default is 0).
         */
        explicit AscendingIterator(const MyContainer<T> &cont, size_t start = 0)
            : container(cont), index(start) {
            build_ascending_order();
        }

        /**
         * @brief Dereferences the iterator to access the current element.
         *
         * @return const T& Const reference to the current element.
         * @throws std::out_of_range if dereferencing beyond the end.
         */
        const T &operator*() const {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("AscendingIterator: dereference out of range");
            }
            return container.elements[sorted_indices[index]];
        }

        /**
         * @brief Pre-increment operator to advance the iterator.
         *
         * @return Reference to the incremented iterator.
         * @throws std::out_of_range if incrementing past the end.
         */
        AscendingIterator &operator++() {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("AscendingIterator increment past end");
            }
            ++index;
            return *this;
        }

        /**
         * @brief Post-increment operator to advance the iterator.
         *
         * @return A copy of the iterator before increment.
         */
        AscendingIterator operator++(int) {
            AscendingIterator temp = *this;
            ++(*this);
            return temp;
        }

        /**
         * @brief Equality comparison operator.
         *
         * Two iterators are equal if they refer to the same container and index.
         *
         * @param other Another AscendingIterator to compare.
         * @return true if equal, false otherwise.
         */
        bool operator==(const AscendingIterator &other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison operator.
         *
         * @param other Another AscendingIterator to compare.
         * @return true if not equal, false otherwise.
         */
        bool operator!=(const AscendingIterator &other) const {
            return !(*this == other);
        }
    };
}

#endif // ASCENDINGORDER_H

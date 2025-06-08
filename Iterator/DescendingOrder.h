//Email:Edenhassin@gmail.com

#ifndef DESCENDINGORDER_H
#define DESCENDINGORDER_H

#include <vector>
#include <algorithm>

namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that traverses a MyContainer in descending order.
     *
     * Iteration order is from the largest element to the smallest element
     * based on the values stored in the container.
     */
    template<typename T = int>
    class DescendingIterator {
    private:
        const MyContainer<T>& container;
        size_t index;
        std::vector<size_t> sorted_indices;

        /**
         * @brief Builds the vector of indices sorted by descending order of element values.
         *
         * Initializes sorted_indices with all element indices,
         * then sorts them so that elements with higher values come first.
         */
        void build_descending_order() {
            const size_t s = container.size();
            sorted_indices.resize(s);
            for (size_t i = 0; i < s; ++i) {
                sorted_indices[i] = i;
            }

            std::sort(sorted_indices.begin(), sorted_indices.end(),
                      [&](size_t a, size_t b) {
                          return container.elements[a] > container.elements[b];
                      });
        }

    public:
        /**
         * @brief Constructs a DescendingIterator for the specified container.
         *
         * @param cont Reference to the container to iterate.
         * @param start Starting position in the iteration (default is 0).
         */
        explicit DescendingIterator(const MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_descending_order();
        }

        /**
         * @brief Dereference operator to access the current element.
         *
         * @return Const reference to the current element in descending order.
         * @throws std::out_of_range if the iterator is out of bounds.
         */
        const T& operator*() const {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("DescendingIterator: dereference out of range");
            }
            return container.elements[sorted_indices[index]];
        }

        /**
         * @brief Pre-increment operator to advance the iterator.
         *
         * @return Reference to the incremented iterator.
         * @throws std::out_of_range if increment moves beyond the end.
         */
        DescendingIterator& operator++() {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("DescendingIterator increment out of range");
            }
            ++index;
            return *this;
        }

        /**
         * @brief Post-increment operator to advance the iterator.
         *
         * @return Copy of the iterator before increment.
         */
        DescendingIterator operator++(int) {
            DescendingIterator temp = *this;
            ++(*this);
            return temp;
        }

        /**
         * @brief Equality comparison operator.
         *
         * @param other Another DescendingIterator to compare with.
         * @return True if both iterators refer to the same container and position.
         */
        bool operator==(const DescendingIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison operator.
         *
         * @param other Another DescendingIterator to compare with.
         * @return True if iterators refer to different containers or positions.
         */
        bool operator!=(const DescendingIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // DESCENDINGORDER_H

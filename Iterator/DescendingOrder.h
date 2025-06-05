#ifndef DESCENDINGORDER_H
#define DESCENDINGORDER_H

#include <vector>
#include <algorithm>
#include "../MyContainer.h" // Adjust the path if needed

namespace Container {

    /**
     * @brief An iterator that scans a MyContainer in descending order.
     *
     * This iterator sorts the indices of the elements in the container
     * from the largest to the smallest value and iterates over them accordingly.
     */
    template<typename T = int>
    class DescendingIterator {
    private:
        const MyContainer<T>& container;
        size_t index;
        std::vector<size_t> sorted_indices;

    public:
        /**
         * @brief Constructor that initializes the iterator.
         *
         * It builds a list of indices and sorts them by descending element value.
         *
         * @param cont Reference to the container
         * @param start Starting index for iteration (default is 0)
         */
        DescendingIterator(const MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {

            sorted_indices.resize(container.size());
            for (size_t i = 0; i < container.size(); ++i) {
                sorted_indices[i] = i;
            }

            // Sort indices based on descending order of elements
            std::sort(sorted_indices.begin(), sorted_indices.end(),
                      [&](size_t a, size_t b) {
                          return container.elements[a] > container.elements[b];
                      });
        }

        /**
         * @brief Dereference operator.
         *
         * Returns the current element in the descending order.
         *
         * @return const reference to the current element
         */
        const T& operator*() const {
            return container.elements[sorted_indices[index]];
        }

        /**
         * @brief Pre-increment operator.
         *
         * Advances the iterator to the next element.
         *
         * @return Reference to the updated iterator
         */
        DescendingIterator& operator++() {
            ++index;
            return *this;
        }

        /**
         * @brief Equality comparison operator.
         *
         * Checks if two iterators point to the same container and index.
         *
         * @param other Another DescendingIterator
         * @return true if both are equal
         */
        bool operator==(const DescendingIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison operator.
         *
         * @param other Another DescendingIterator
         * @return true if iterators are not equal
         */
        bool operator!=(const DescendingIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif // DESCENDINGORDER_H

//Email:Edenhassin@gmail.com

#ifndef SIDECROSSORDER_H
#define SIDECROSSORDER_H

#include <vector>
#include <algorithm>
#include <stdexcept>

namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that scans a MyContainer in side-cross order.
     *
     * The iteration order alternates between the smallest and largest remaining elements.
     * For example, for the sorted container [1, 2, 3, 4, 5], the iteration order will be:
     * 1, 5, 2, 4, 3
     */

    template<typename T = int>
    class SideCrossIterator {
    private:
        const MyContainer<T>& container;
        size_t index;
        std::vector<size_t> sideCross_indices;

        /**
         * @brief Builds the vector of indices in side-cross order.
         *
         * The method sorts the indices by the values they point to, and then
         * alternates between taking the smallest and the largest remaining elements.
         */
        void build_sideCross_order() {
            const size_t s = container.size();
            std::vector<size_t> sorted_indices(s);
            for (size_t i = 0; i < s; ++i) {
                sorted_indices[i] = i;
            }

            std::sort(sorted_indices.begin(), sorted_indices.end(),
                [&](size_t a, size_t b) {
                    return container.elements[a] < container.elements[b];
                });

            sideCross_indices.clear();
            if (sorted_indices.empty()) return;

            size_t left = 0;
            size_t right = sorted_indices.size() - 1;

            while (left <= right) {
                if (left == right) {
                    sideCross_indices.push_back(sorted_indices[left]);
                } else {
                    sideCross_indices.push_back(sorted_indices[left]);
                    sideCross_indices.push_back(sorted_indices[right]);
                }
                left++;
                if (right == 0) break;  // prevent underflow
                right--;
            }
        }

    public:
        /**
         * @brief Constructs a SideCrossIterator for a given container.
         *
         * @param cont Reference to the container.
         * @param start Starting index in the iteration order (default is 0).
         */
        explicit SideCrossIterator(const MyContainer<T>& cont, const size_t start = 0)
            : container(cont), index(start) {
            build_sideCross_order();
        }

        /**
         * @brief Dereference operator for reading the current element (const version).
         *
         * @return A const reference to the current element.
         * @throws std::out_of_range if the iterator is out of bounds.
         */
        const T& operator*() const {
            if (index >= sideCross_indices.size()) {
                throw std::out_of_range("SideCrossIterator: Dereference past end");
            }
            return container.elements[sideCross_indices[index]];
        }

        /**
         * @brief Pre-increment operator (++it).
         *
         * Advances the iterator to the next element.
         * @return Reference to the incremented iterator.
         */
        SideCrossIterator& operator++() {
            ++index;
            return *this;
        }

        /**
         * @brief Post-increment operator (it++).
         *
         * @return Copy of the iterator before it was incremented.
         */
        SideCrossIterator operator++(int) {
            SideCrossIterator temp = *this;
            ++(*this);
            return temp;
        }

        /**
         * @brief Equality comparison operator.
         *
         * @param other Iterator to compare with.
         * @return True if iterators are equal.
         */
        bool operator==(const SideCrossIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison operator.
         *
         * @param other Iterator to compare with.
         * @return True if iterators are not equal.
         */
        bool operator!=(const SideCrossIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // SIDECROSSORDER_H

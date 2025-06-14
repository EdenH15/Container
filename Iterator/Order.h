//Email:Edenhassin@gmail.com

#ifndef ORDERITERATOR_H
#define ORDERITERATOR_H

#include <cstddef>
#include <stdexcept>

namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that scans a MyContainer in original insertion order.
     *
     * The iteration goes in the exact order the elements were added to the container.
     */
    template<typename T = int>
    class OrderIterator {
    private:
        const MyContainer<T>& container;
        size_t index;

    public:
        /**
         * @brief Constructs an OrderIterator for a given container.
         * @param cont Reference to the container to iterate over.
         * @param start The starting index (default is 0).
         */
        explicit OrderIterator(const MyContainer<T>& cont, const size_t start = 0)
            : container(cont), index(start) {}

        /**
         * @brief Dereference operator.
         * @return Reference to the element at the current iterator position.
         * @throws std::out_of_range if the iterator is out of bounds.
         */
        const T& operator*() const {
            if (index >= container.size()) {
                throw std::out_of_range("OrderIterator: Dereferencing out of bounds");
            }
            return container.elements[index];
        }

        /**
         * @brief Prefix increment operator.
         * @return Reference to the incremented iterator.
         */
        OrderIterator& operator++() {
            ++index;
            return *this;
        }

        /**
         * @brief Postfix increment operator.
         * @return A copy of the iterator before it was incremented.
         */
        OrderIterator operator++(int) {
            OrderIterator temp = *this;
            ++(*this);
            return temp;
        }

        /**
         * @brief Equality comparison operator.
         * @param other Another iterator to compare with.
         * @return True if both iterators are at the same position in the same container.
         */
        bool operator==(const OrderIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Another iterator to compare with.
         * @return True if the iterators are at different positions or containers.
         */
        bool operator!=(const OrderIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // ORDERITERATOR_H

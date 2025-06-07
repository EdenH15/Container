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
        explicit OrderIterator(const MyContainer<T>& cont, const size_t start = 0)
            : container(cont), index(start) {}

        const T& operator*() const {
            if (index >= container.size()) {
                throw std::out_of_range("OrderIterator: Dereferencing out of bounds");
            }
            return container.elements[index];
        }

        T& operator*() {
            if (index >= container.size()) {
                throw std::out_of_range("OrderIterator: Dereferencing out of bounds");
            }
            return container.elements[container[index]];
        }

        OrderIterator& operator++() {
            ++index;
            return *this;
        }

        OrderIterator operator++(int) {
            OrderIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const OrderIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        bool operator!=(const OrderIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // ORDERITERATOR_H

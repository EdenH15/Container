#ifndef REVERSEORDER_H
#define REVERSEORDER_H

#include <vector>
#include <algorithm>


namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that scans a MyContainer in reverse order.
     *
     * The iteration goes from the last inserted element to the first.
     */
    template<typename T = int>
    class ReverseIterator {
    private:
        const MyContainer<T>& container;
        size_t index;
        std::vector<size_t> reverse_indices;

        // Helper function to build the reverse order indices
        void build_reverse_order() {
            size_t s = container.size();
            reverse_indices.resize(s);
            for (size_t i = 0; i < s; ++i) {
                reverse_indices[i] = s - 1 - i;
            }
        }

    public:
        ReverseIterator(const MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_reverse_order();
        }

        const T& operator*() const {
            if (index >= reverse_indices.size()) {
                throw std::out_of_range("ReverseIterator: Dereferencing out of bounds");
            }
            return container.elements[reverse_indices[index]];
        }

        ReverseIterator& operator++() {
            ++index;
            return *this;
        }

        bool operator==(const ReverseIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        bool operator!=(const ReverseIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // REVERSEORDER_H

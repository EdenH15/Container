#ifndef MIDDLEOUTORDER_H
#define MIDDLEOUTORDER_H

#include <vector>
#include <algorithm>


namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that scans a MyContainer in middle-out order.
     *
     * Starts from the middle element, then alternates left and right.
     * For even-sized containers, the middle index is rounded down.
     * Example: For [7,15,6,1,2], the iteration order is 6,15,1,7,2.
     */
    template<typename T = int>
    class MiddleOutIterator {
    private:
        const MyContainer<T>& container;
        size_t index;
        std::vector<size_t> middleOut_indices;

        /**
         * @brief Builds the vector of indices in middle-out order.
         *
         * The order starts at the middle element, then alternates left and right.
         */
        void build_middleOut_order() {
            const size_t s = container.size();
            middleOut_indices.clear();
            if (s == 0) return;

            const size_t mid = s / 2;  // round down if even

            middleOut_indices.push_back(mid);

            int left = static_cast<int>(mid) - 1;
            size_t right = mid + 1;
            bool nextIsLeft = true;

            while (middleOut_indices.size() < s) {
                if (nextIsLeft) {
                    if (left >= 0) {
                        middleOut_indices.push_back(static_cast<size_t>(left));
                        --left;
                    }
                } else {
                    if (right < s) {
                        middleOut_indices.push_back(right);
                        ++right;
                    }
                }
                nextIsLeft = !nextIsLeft;
            }
        }


    public:
        /**
         * @brief Constructs a MiddleOutIterator for the given container.
         *
         * @param start Initial index position (default 0).
         */
        explicit MiddleOutIterator(const MyContainer<T>& cont, const size_t start = 0)
            : container(cont), index(start) {
            build_middleOut_order();
        }


        const T& operator*() const {
            if (index >= middleOut_indices.size()) {
                throw std::out_of_range("MiddleOutIterator dereference out of range");
            }
            return container.elements[middleOut_indices[index]];
        }

        MiddleOutIterator& operator++() {
            if (index >= middleOut_indices.size()) {
                throw std::out_of_range("MiddleOutIterator increment out of range");
            }
            ++index;
            return *this;
        }

        MiddleOutIterator operator++(int) {
            MiddleOutIterator temp = *this;
            ++(*this);
            return temp;
        }



        bool operator==(const MiddleOutIterator& other) const {
            return &container == &other.container && index == other.index;
        }


        bool operator!=(const MiddleOutIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // MIDDLEOUTORDER_H

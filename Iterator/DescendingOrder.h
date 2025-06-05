#ifndef DESCENDINGORDER_H
#define DESCENDINGORDER_H

#include <vector>
#include <algorithm>


namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that scans a MyContainer in descending order.
     *
     * Elements are iterated from the largest to the smallest value.
     */
    template<typename T = int>
    class DescendingIterator {
    private:
        const MyContainer<T>& container;
        size_t index;
        std::vector<size_t> sorted_indices;


        //Builds a vector of indices sorted by descending value of elements.
        void build_descending_order() {
            sorted_indices.resize(container.size());
            for (size_t i = 0; i < container.size(); ++i) {
                sorted_indices[i] = i;
            }

            std::sort(sorted_indices.begin(), sorted_indices.end(),
                      [&](size_t a, size_t b) {
                          return container.elements[a] > container.elements[b];
                      });
        }

    public:
        /**
         * @brief Constructs a DescendingIterator for the given container.
         * @param cont Reference to the container.
         * @param start Starting index for iteration (default is 0).
         */
        DescendingIterator(const MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_descending_order();
        }


        const T& operator*() const {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("DescendingIterator dereference out of range");
            }
            return container.elements[sorted_indices[index]];
        }

        DescendingIterator& operator++() {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("DescendingIterator increment out of range");
            }
            ++index;
            return *this;
        }



        bool operator==(const DescendingIterator& other) const {
            return &container == &other.container && index == other.index;
        }


        bool operator!=(const DescendingIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // DESCENDINGORDER_H

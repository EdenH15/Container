#ifndef SIDECROSSORDER_H
#define SIDECROSSORDER_H

#include <vector>
#include <algorithm>
#include "../MyContainer.h"

namespace Container {

    /**
     * @brief Iterator that scans a MyContainer in side-cross order.
     *
     * The iteration order alternates between the smallest and largest remaining elements.
     */
    template<typename T = int>
    class SideCrossIterator {
    private:

        const MyContainer<T>& container;
        size_t index;
        std::vector<size_t> sidecross_indices;

        // Helper function to build the side-cross order indices
        void build_sideCross_order() {
            std::vector<size_t> sorted_indices(container.size());
            for (size_t i = 0; i < container.size(); ++i) {
                sorted_indices[i] = i;
            }

            std::sort(sorted_indices.begin(), sorted_indices.end(),
                [&](size_t a, size_t b) {
                    return container.elements[a] < container.elements[b];
                });

            sidecross_indices.clear();
            if (sorted_indices.empty()) return;

            size_t left = 0;
            size_t right = sorted_indices.size() - 1;

            while (left <= right) {
                if (left == right) {
                    sidecross_indices.push_back(sorted_indices[left]);
                } else {
                    sidecross_indices.push_back(sorted_indices[left]);
                    sidecross_indices.push_back(sorted_indices[right]);
                }
                left++;
                if (right == 0) break;
                right--;
            }
        }

    public:
        SideCrossIterator(const MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_sideCross_order();
        }

        const T& operator*() const {
            return container.elements[sidecross_indices[index]];
        }

        SideCrossIterator& operator++() {
            ++index;
            return *this;
        }

        bool operator==(const SideCrossIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        bool operator!=(const SideCrossIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // SIDECROSSORDER_H

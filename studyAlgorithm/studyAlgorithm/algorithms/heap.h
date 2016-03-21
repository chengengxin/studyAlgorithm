//堆排序

#pragma once

#include <vector>

int parent(int i);

int left(int i);

int right(int i);

void maxHeapify(int* array, int n, int i);

void buildMaxHeap(int* array, int heapSize);

void heapSort(int* array, int heapSize);

void testHeapSort();

template<typename T, typename compare>
class Heap {
public:
    typedef typename std::vector<T>::iterator iterator;    
    Heap(iterator& _first, iterator& _last)
    : first(_first)
    , last(_last)
    , heapSize(std::distance(first, last)) {
    
    }

    void sort() {
        buildHeap();
        for (--heapSize; heapSize >= 1; ) {
            T temp = *first;
            *first = *(first + heapSize);
            *(first + heapSize) = temp;
            --heapSize;
            heapify(first);
        }
    }

private:
    iterator parent(iterator i) {
        return (std::distance(first, i) - 1 ) / 2 + first;
    }

    iterator left(iterator i) {
        auto l = std::distance(first, i) * 2 + 1;
        return l < heapSize ? l + first : last;
    }

    iterator right(iterator i) {
        auto r = std::distance(first, i) * 2 + 2;
        return r < heapSize ? r + first : last;
    }

    void heapify(iterator i) {
        auto iteratorLeft = this->left(i);
        auto iteratorRight = this->right(i);
        auto largest = i;
        if (iteratorLeft < last && compare()(*iteratorLeft, *i)) {
            largest = iteratorLeft;
        }
        if (iteratorRight < last && compare()(*iteratorRight, *largest)) {
            largest = iteratorRight;
        }
        if (largest != i) {
            T temp = *largest;
            *largest = *i;
            *i = temp;
            heapify(largest);
        }
    }

    void buildHeap() {
        for (std::ptrdiff_t i = (heapSize - 1) / 2; i >= 0; --i) {            
            heapify(first + i);
        }
    }

private:
    iterator first;
    iterator last;
    std::ptrdiff_t heapSize;
};

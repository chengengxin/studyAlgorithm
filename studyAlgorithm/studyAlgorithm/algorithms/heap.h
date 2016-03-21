//堆排序

#pragma once

int parent(int i);

int left(int i);

int right(int i);

void maxHeapify(int* array, int n, int i);

void buildMaxHeap(int* array, int heapSize);

void heapSort(int* array, int heapSize);

void testHeapSort();

template<typename T>
class Heap {
public:
    Heap(std::vector<T>::iterator& _first,
        std::vector<T>::iterator& _last,
        std::is_function<bool(T, T)> _compare = std::bind(std::less<T>()))
    : first(_first)
    , last(_last)
    , heapSize(std::distance(first, last))
    , compare(_compare) {
    
    }

    void sort() {
        buildHeap();
        for (int i = heapSize - 1; i >= 1; --i) {
            T temp = *first;
            *first = *(first + i);
            *(first + i) = temp;
            heapify(first);
        }
    }

private:
    std::vector<T>::iterator parent(std::vector<T>::iterator i) {
        return (std::distance(first, i) - 1 ) / 2 + first;
    }

    std::vector<T>::iterator left(std::vector<T>::iterator i) {
        return (std::distance(first, i) * 2 + 1) + first;
    }

    std::vector<T>::iterator right(std::vector<T>::iterator i) {
        return (std::distance(first, i) * 2 + 2) + first;
    }

    void heapify(std::vector<T>::iterator i) {
        auto iteratorLeft = this->left(i);
        auto iteratorRight = this->right(i);
        auto largest = i;
        if (std::distance(first, iteratorLeft) < heapSize && compare(*iteratorLeft, *i)) {
            largest = iteratorLeft;
        }
        if (std::distance(first, iteratorRight) < heapSize && compare(*iteratorRight, *largest)) {
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
        for (int i = (heapSize - 1) / 2; i >= 0; --i) {
            heapify(first + i);
        }
    }

private:
    std::vector<T>::iterator& first;
    std::vector<T>::iterator& last;
    const std::iterator_traits<T>::difference_type heapSize;
    std::is_function<bool(T, T)> compare;
    
};

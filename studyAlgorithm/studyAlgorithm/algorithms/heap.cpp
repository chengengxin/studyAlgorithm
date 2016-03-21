//堆排序

#include "stdafx.h"
#include "heap.h"

int parent(int i) {
    return (i - 1) >> 1;
}

int left(int i) {
    return (i << 1) + 1;
}

int right(int i) {
    return (i << 1) + 2;
}

void maxHeapify(int * array, int n, int i) {
    int iteratorLeft = left(i);
    int iteratorRight = right(i);
    int largest = i;
    if (iteratorLeft < n && array[iteratorLeft] > array[i]) {
        largest = iteratorLeft;
    }
    if (iteratorRight < n && array[iteratorRight] > array[largest]) {
        largest = iteratorRight;
    }
    if (largest != i) {
        std::swap(array[largest], array[i]);
        maxHeapify(array, n, largest);
    }
}

void buildMaxHeap(int * array, int heapSize) {
    for (int i = (heapSize - 1) / 2; i >= 0; --i) {
        maxHeapify(array, heapSize, i);
    }
}

void heapSort(int * array, int heapSize) {
    buildMaxHeap(array, heapSize);
    for (int i = heapSize - 1; i >= 1; --i) {
        std::swap(array[0], array[i]);
        maxHeapify(array, i, 0);
    }
}

void testHeapSort() {
    //std::cout << "parent 2 =" << parent(2) << std::endl;
    //std::cout << "left 2 =" << left(2) << std::endl;
    //std::cout << "right 2 =" << right(2) << std::endl;
    //int a[] = { 4, 1,3, 2,9, 8,7,6,5,10 };
    std::vector<int> a= { 4, 1,3, 2,9, 8,7,6,5,10 };
    //heapSort(a, 10);
    Heap<int, std::greater<int>> heap(a.begin() + 1, a.end());
    heap.sort();
    Tools::printArray(a);
    
}
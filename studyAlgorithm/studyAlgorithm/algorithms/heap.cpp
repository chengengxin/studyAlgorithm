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
		int temp = array[largest];
		array[largest] = array[i];
		array[i] = temp;
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
	for (int i = heapSize; i >= 2; --i) {
		int temp = array[0];
		array[0] = array[i - 1];
		array[i - 1] = temp;		
		maxHeapify(array, i, 0);
	}
}

void testHeapSort() {
	int a[] = { 4, 1,3,2,5,9,10,6,8,7 };
	heapSort(a, 10);
	for (auto e : a) {
		std::cout << e << std::endl;
	}
}
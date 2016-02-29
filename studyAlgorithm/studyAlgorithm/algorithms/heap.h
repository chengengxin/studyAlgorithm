//堆排序

#pragma once

int parent(int i);

int left(int i);

int right(int i);

void maxHeapify(int* array, int n, int i);

void buildMaxHeap(int* array, int heapSize);

void heapSort(int* array, int heapSize);

void testHeapSort();
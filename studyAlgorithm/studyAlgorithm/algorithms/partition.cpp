//快排

#include "stdafx.h"
#include "partition.h"

int partition(int * a, int s, int e) {
    int x = a[e];
    int p = s - 1;
    for (int i = s; i < e; ++i) {
        if (a[i] <= x) {
            p += 1;
            std::swap(a[i], a[p]);
        }
    }
    std::swap(a[++p], a[e]);
    return p;
}

void partitionSort(int * a, int s, int e) {
    if (s < e) {
        int m = partition(a, s, e);
        partitionSort(a, s, m - 1);
        partitionSort(a, m + 1, e);
    }
}

void testPartitionSort() {
    int a[] = { 4, 1,3, 2,9, 8,7,6,5,10 };
    partitionSort(a, 0, 9);
    Tools::printArray(a, 10);
}

// studyAlgorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "algorithms/merge.h"
#include "algorithms/heap.h"
#include "algorithms/partition.h"

int main() {
    std::cout << "press Enter over" << std::endl;
    //test_merge_sort1();
    //test_inversion();
    //testHeapSort();

    testPartitionSort();
    getchar();
    return 0;
}


#pragma once

void merge(int* array, int beginIndex, int middleIndex, int endIndex);

void mergeSort(int* array, int beginIndex, int endIndex);

void test_merge_sort1();

void inversion(int* array, int beginIndex, int endIndex, int& inversionNum);

void inversionMerge(int* array, int beginIndex, int middleIndex, int endIndex, int& inversionNum);

void test_inversion();
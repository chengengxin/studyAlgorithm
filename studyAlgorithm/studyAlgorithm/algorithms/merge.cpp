#include "stdafx.h"
#include "merge.h"

void merge(int* array, int beginIndex, int middleIndex, int endIndex) {
	assert(array);
	assert(beginIndex >= 0 && middleIndex >= beginIndex && endIndex > middleIndex);

	int leftN = middleIndex - beginIndex + 1;
	int rightN = endIndex - middleIndex;

	int* left = new int[leftN + 1];
	int* right = new int[rightN + 1];
	
	int left_itr = 0;
	int right_itr = 0;
	int array_itr = beginIndex;

	while ( array_itr <= middleIndex) left[left_itr++] = array[array_itr++];	
	
	while ( array_itr <= endIndex) right[right_itr++] = array[array_itr++];		

	left[leftN] = std::numeric_limits<int>::max();
	right[rightN] = std::numeric_limits<int>::max();

	left_itr = 0;
	right_itr = 0;
	array_itr = beginIndex;

	while (array_itr <= endIndex) {
		if (left[left_itr] <= right[right_itr]) {
			array[array_itr] = left[left_itr++];
		}
		else {
			array[array_itr] = right[right_itr++];
		}
		++array_itr;
	}

	delete[] left;
	delete[] right;
}

void mergeSort(int* array, int beginIndex, int endIndex) {
	if (beginIndex < endIndex) {
		int middleIndex = (beginIndex + endIndex) / 2;
		mergeSort(array, beginIndex, middleIndex);
		mergeSort(array, middleIndex + 1, endIndex);
		merge(array, beginIndex, middleIndex, endIndex);
	}
}

void test_merge_sort1() {
	int a[] = {9, 8, 5, 4, 6};
	std::cout << "init" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << a[i] << std::endl;
	mergeSort(a, 0, 4);
	std::cout << "sorted" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << a[i] << std::endl;
}

void inversion(int * array, int beginIndex, int endIndex, int & inversionNum) {
	if (beginIndex < endIndex) {
		int middleIndex = (beginIndex + endIndex) / 2;
		inversion(array, beginIndex, middleIndex, inversionNum);
		inversion(array, middleIndex + 1, endIndex, inversionNum);
		inversionMerge(array, beginIndex, middleIndex, endIndex, inversionNum);
	}
}

void inversionMerge(int * array, int beginIndex, int middleIndex, int endIndex, int & inversionNum) {
	assert(array);
	assert(beginIndex >= 0 && middleIndex >= beginIndex && endIndex > middleIndex);

	int leftN = middleIndex - beginIndex + 1;
	int rightN = endIndex - middleIndex;

	int* left = new int[leftN + 1];
	int* right = new int[rightN + 1];

	int left_itr = 0;
	int right_itr = 0;
	int array_itr = beginIndex;

	while (array_itr <= middleIndex) left[left_itr++] = array[array_itr++];

	while (array_itr <= endIndex) right[right_itr++] = array[array_itr++];

	left[leftN] = std::numeric_limits<int>::max();
	right[rightN] = std::numeric_limits<int>::max();

	left_itr = 0;
	right_itr = 0;
	array_itr = beginIndex;

	while (array_itr <= endIndex) {
		if (left[left_itr] <= right[right_itr]) {
			array[array_itr] = left[left_itr++];
		}
		else {
			array[array_itr] = right[right_itr++];
			inversionNum += leftN  - left_itr;
		}
		++array_itr;
	}

	delete[] left;
	delete[] right;
}

void test_inversion() {
	std::cout << __func__ << std::endl;
	int a[] = { 9, 8, 5, 4, 6 , 10};	
	int inversionNum = 0;
	inversion(a, 0, 5, inversionNum);
	std::cout << "inversionNum = " << inversionNum << std::endl;	
}

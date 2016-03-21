//工具

#pragma once

namespace Tools {

void printArray(int* array, int n);

template<typename T>
void printArray(std::vector<T> array) {
    for (std::size_t imax = array.size(), i = 0; i < imax; ++i)
        std::cout << "a[" << i << "] = " << array[i] << std::endl;
}

}

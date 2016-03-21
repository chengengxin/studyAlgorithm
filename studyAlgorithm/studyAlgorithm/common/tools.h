//工具

#pragma once

namespace Tools {

void printArray(int* array, int n);

template<typename T>
void printArray(std::vector<T> array) {
    for (auto imax = array.size(), i = 0; i < imax; ++)
        std::cout << "a[" << i << "] = " << array[i] << std::endl;
}

}

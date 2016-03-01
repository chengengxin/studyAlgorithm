//工具

#include "stdafx.h"
#include "tools.h"

namespace Tools {

void Tools::printArray(int * array, int n) {
    for (int i = 0; i < n; ++i)
        std::cout << "a[" << i << "] = " << array[i] << std::endl;
}

}

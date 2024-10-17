#include "Array.hpp"
#include <iostream>
#include <string>

// void l()
// {
//     system("leaks Array");
// }

int main()
{
    // atexit(l);
    Array<int> emptyArray;
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;
    Array<int> intArray(5);
    std::cout << "Size of intArray: " << intArray.size() << std::endl;
    for (size_t i = 0; i < intArray.size(); ++i)
    {
        intArray[i] = static_cast<int>(i * 10);
    }
    for (size_t i = 0; i < intArray.size(); ++i)
    {
        std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
    }

    Array<int> copyArray(intArray);
    std::cout << "Size of copyArray: " << copyArray.size() << std::endl;

    intArray[0] = 100;
    std::cout << "After modification, intArray[0]: " << intArray[0] << std::endl;
    std::cout << "After modification, copyArray[0]: " << copyArray[0] << std::endl;

    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Size of assignedArray: " << assignedArray.size() << std::endl;
    std::cout << "Assigned array's first element: " << assignedArray[0] << std::endl;

    try
    {
        std::cout << intArray[10] << std::endl;
    } catch (const Array<int>::InvalidIndexException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}

//
// Created by andrey on 4/29/20.
//

#include "iostream"
#include "SmartPointer.h"

#include <memory>

void SmartPointer::run() {

    // https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019
    // https://google.github.io/styleguide/cppguide.html#Ownership_and_Smart_Pointers
    auto hugeObject = std::make_unique<std::string>("10GB here ...");

    // get value from the smart pointer (similar to a raw pointer)
    std::cout << *hugeObject << std::endl; // 10GB here ...

    // Smart pointers usually provide a way to access their raw pointer directly
    std::cout << hugeObject.get() << std::endl; // 0x7fd723c00c70

    // A unique_ptr does not share its pointer. It cannot be copied to another unique_ptr, 
    // passed by value to a function, or used in any algorithm that requires copies to be made.
    // A unique_ptr can only be moved.
    auto theSameHugeObject = std::move(hugeObject);


    int a[3] = {1, 2, 3};

    int *p = a;


    std::cout << *p << std::endl;
    std::cout << sizeof(*p) << std::endl;
//    std::cout << p[3] << std::endl;





}

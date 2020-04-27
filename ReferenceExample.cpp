//
// Created by andrey on 4/27/20.
//
#include "iostream"
#include "ReferenceExample.h"

using namespace std;

void ReferenceExample::run() {

    /**
     * 1. Pointers (explicit) vs References (implicit)
     *
     * Theory:
     * In C, if a function needs to modify a variable, the parameter must use a pointer, eg int foo(int *pval).
     * In C++, the function can alternatively declare a reference parameter: int foo(int &val).
     *
     * Definition:
     * int *p = &a; - a Pointer stores a memory address
     * int &b = a;  - a Reference is an alias to an existing variable
     *
     * The difference:
     * - To assign an address of a variable into a pointer, you need to use the address-of operator &.
     * To get the value pointed to by a pointer, you need to use the dereferencing operator *.
     * - On the other hand, referencing and dereferencing are done on the references implicitly
     *
     * The main use of references is acting as function formal parameters to support pass-by-reference.
     * In an reference variable is passed into a function, the function works on the original copy
     * (instead of a clone copy in pass-by-value). Changes inside the function are reflected outside the function.
     *
     * Links:
     * https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
     * https://gist.github.com/ericandrewlewis/720c374c29bbafadedc9
     * https://google.github.io/styleguide/cppguide.html#Reference_Arguments
     * https://stackoverflow.com/a/26441753
     *
     * Example:
     */
    int a = 10;

    // assign variables
    int *p = &a; // a pointer stores a memory address
    int &b = a;  // a reference is an alias to an existing variable

    // retrieve variables
    cout << *p << std::endl; // 10
    cout << b << std::endl;  // 10


    /**
     * Pass-By-Reference into Functions with Reference Arguments vs. Pointer Arguments
     *
     * - In C/C++, by default, arguments are passed into functions by value.
     * - pass-by-reference could be achieved via Pointers or References
     *
     * Example:
     */
    int k = 99;
    cout << k << std::endl; // 99
    implicitInc(k);      // pass-by-reference using a reference
    explicitInc(&k);        // pass-by-reference using a pointer
    cout << k << std::endl; // 101


    /**
     * Best Practices:
     * It is a very strong convention in Google code that
     * - input arguments are values or const references
     * - output arguments are pointers.
     */
    int in = 42, out = 43;
    mutator(in, &out);
    cout << in << std::endl;
    cout << out << std::endl;

}

void ReferenceExample::implicitInc(int &x) {
    x = x + 1;
}

void ReferenceExample::explicitInc(int *x) {
    *x = *x + 1;
}

void ReferenceExample::mutator(const int &in, int *out) {
    *out = in + *out;
}




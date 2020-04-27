#include <iostream>
#include "MultithreadingExample.h"
#include "ReferenceExample.h"

using namespace std;

void implicitInc(int &);

void explicitInc(int *);

void mutator(const int &, int *);

int main() {

//    ReferenceExample referenceExample;
//    referenceExample.run();

    MultithreadingExample test;
    test.run();


}

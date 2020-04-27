//
// Created by andrey on 4/27/20.
//

#ifndef CPP_REFERENCEEXAMPLE_H
#define CPP_REFERENCEEXAMPLE_H


class ReferenceExample {
public:

    void run();

    void implicitInc(int &x);

    void explicitInc(int *x);

    void mutator(const int &in, int *out);;
};

#endif //CPP_REFERENCEEXAMPLE_H

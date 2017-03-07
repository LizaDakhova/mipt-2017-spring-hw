//
// Created by dmitry on 2/28/17.
//

#ifndef MIPT_2017_SPRING_HW_MATRIX_H
#define MIPT_2017_SPRING_HW_MATRIX_H

#include <cstdlib>
#include <iostream>

class Matrix {
public:
    Matrix(const size_t, const size_t);

    Matrix(const size_t);

    ~Matrix();

    friend std::ostream &operator<<(std::ostream &, const Matrix &);

    friend std::istream &operator>>(std::istream &, const Matrix &);

    static Matrix eye(size_t);
};


#endif //MIPT_2017_SPRING_HW_MATRIX_H

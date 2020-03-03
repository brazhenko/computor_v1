//
// Created by Andrew Brazhenko on 01.03.2020.
//

#ifndef COMPUTOR_POLINOM_SOLVER_H
#define COMPUTOR_POLINOM_SOLVER_H

#include <complex>
#include "polinomial/polinomial.h"

typedef std::vector<std::complex<double>> PolSolutions;

int 	polinom_solver(const polinomial<int, double>& pol);

#endif //COMPUTOR_POLINOM_SOLVER_H

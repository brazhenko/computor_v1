cmake_minimum_required(VERSION 3.15)
project(computor)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
add_executable(computor main.cpp polinomial/polinomial.cpp polinomial/polinomial.h tokenizer/tokenizer.h tokenizer/tokenizer.cpp computorv1/computorv1.cpp computorv1/computorv1.h polinom_parser/polinom_parser.cpp polinom_parser/polinom_parser.h polinom_solver/polinom_solver.cpp polinom_solver/polinom_solver.h)
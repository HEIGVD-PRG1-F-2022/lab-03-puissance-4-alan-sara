cmake_minimum_required(VERSION 3.23)
project(Mandelbrot)

set(CMAKE_CXX_STANDARD 20)

add_executable(Mandelbrot main.cpp choisirColonne.h choisirColonne.cpp verificationAlignements.h verificationAlignements.cpp affichageQuadrillage.h affichageQuadrillage.cpp)

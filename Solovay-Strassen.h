#pragma once

#include <string>
#include <vector>


//Algoritmul Solovay-Strassen
long long modulo(long long base, long long exponent, long long mod);
int calculateJacobian(long long a, long long n);
bool solovoyStrassen(long long p, int iterations);

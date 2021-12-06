// ALGORITMUL SOLOVAY-STRASSEN


#include <bits/stdc++.h>
#include "Solovay-Strassen.h"


#define ITERATIONS 100


using namespace std;


 
// exponentiere modulara
long long modulo(long long base, long long exponent, long long modulo) {

    long long x = 1;
    long long y = base;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            x = (x * y) % modulo;
        }

        y = (y * y) % modulo;
        exponent = exponent / 2;
    }
 
    return x % modulo;
}
 
// calcularea Jacobianului
int calculateJacobian(long long a, long long n) {

    int answer = 1;

    if (!a) {
        return 0;
        // (0/n) = 0
    }
        
    if (a < 0) {
        a = -a;
        // (a/n) = (-a/n)*(-1/n)
        if (n % 4 == 3) {
            answer = -answer;
            // (-1/n) = -1 if n = 3 (mod 4)
        }
            
    }
 
    if (a == 1) {
        return answer;
        // (1/n) = 1
    }
        
 
    while (a) {

        if (a < 0) {

            a = -a;
            // (a/n) = (-a/n)*(-1/n)
            if (n % 4 == 3) {
                answer = -answer;
                // (-1/n) = -1 if n = 3 (mod 4)
            }   
        }
 
        while (a % 2 == 0) {

            a = a / 2;
            if (n % 8 == 3 || n % 8 == 5) {
                answer = -answer;
            }
        }
 
        swap(a, n);
 
        if (a % 4 == 3 && n % 4 == 3) {
            answer = -answer;
        }
        a = a % n;
 
        if (a > n / 2) {
            a = a - n;
        }
           
    }
 
    if (n == 1) {
        return answer;
    }
        
    return 0;
}
 
// Testul de primalitate Solovay-Strassen
//numarul de iteratii determina acuratetea
bool solovayStrassen(long long number, int iterations) {

    if (number < 2) {
        return false;
    }

    if (number != 2 && number % 2 == 0) {
        return false;
    }

    for (int i = 0; i < iterations; i++) {
        // generarea unui numar random a
        long long a = rand() % (number - 1) + 1;

        long long jacobian = (number + calculateJacobian(a, number)) % number;

        long long mod = modulo(a, (number - 1) / 2, number);
 
        if (!jacobian || mod != jacobian) {
            return false;
        }

    }

    return true;

}

int main() {

    int nrOfPrimes = 0;
    int iterations = ITERATIONS;
    string line;
    
    ifstream testIn;
    testIn.open("test.in", ios_base::in);

    getline(testIn, line);
    nrOfPrimes = stoi(line);

    vector<long> prime;
	int primeCount = 0;

    for (int i = 0; i < nrOfPrimes; i++) {
        getline(testIn, line); //citirea din fisier
        
        long long number;
        sscanf(line.c_str(), "%lld", &number);

        //verificarea primalitatii numarului
        if (solovayStrassen(number, iterations)) {
			prime.push_back(number);
			primeCount++;
		}
    }

    ofstream testOut;
    testOut.open("test.out", ios_base::out);

    //scrierea in fisier
	testOut << primeCount << "\n";

	for (int i = 0; i < (int)prime.size(); i++) {
		testOut << prime[i] << "\n";
	}

	testOut.close();
}

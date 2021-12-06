//ALGORITMUL LUCAS

#include <bits/stdc++.h>

#include "Lucas.h"

using namespace std;


//descompunerea in factori primi
vector<int> primeFactors(long long n) {

    vector<int> factorization;

    if (n % 2 == 0) {
        factorization.push_back(2);
    }
    
    while (n % 2 == 0) {
        n = n / 2;
    }
    
    for (int i = 3; i <= sqrt(n); i += 2) {

        if (n % i == 0) {
            factorization.push_back(i);
        }
        
        while (n % i == 0) {
            n = n / i;
        }

    }

    if (n > 2) {
        factorization.push_back(n);
    }

    return factorization;

}


//exponentiere modulara
long long power(long long n, long long r, long long q) {

    long long total = n;

    for (long long i = 1; i < r; i++) {
        total = (total * n) % q;
    }

    return total;

}


//testul Lucas de primalitate
bool lucasTest(long long n)
{

    if (n == 0 || n == 1) {
        return false;
    }

    if (n == 2) {
        return true;
    }

    if(n % 2 == 0) {
        return false;
    }
         
    vector<int> factors = primeFactors(n - 1);
 
    int random[n - 3];

    for (long long i = 0; i < n - 2; i++) {
        random[i] = i + 2;
    }
        
    // vector de elemente random
    random_shuffle(random, random + n - 3);
 
    // se aplica testul Lucas 
    // pe numerele generate random
    for (long long i = 0; i < n - 2; i++) {

        long long a = random[i];

        if (power(a, n - 1, n) != 1) {
            return false;
        }

        bool flag = true;

        for (long long k = 0; k < factors.size(); k++) {

            // if a^((n-1)/q) equal 1
            if (power(a, (n - 1) / factors[k], n) == 1) {
                flag = false;
                break;
            }

        }
 
        // daca toate conditiile sunt satisfacute
        if (flag) {
            return true;
        }

    }

    return false;

}


int main() {

    int nrOfPrimes = 0;
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

        //verificarea primalitatii
        if (lucasTest(number)) {  
			prime.push_back(number);
			primeCount++;
		}
    }


    ofstream testOut;
    testOut.open("test.out", ios_base::out);

    //scrierea in fisier
	testOut << primeCount << "\n";

	for (int i = 0; i < primeCount; i++) {
		testOut << prime[i] << "\n";
	}

	testOut.close();

}


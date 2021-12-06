#include <bits/stdc++.h>

using namespace std;

// cate numere neprime contin testele 6-10
#define NOT_PRIME1 1000
// cate numere prime contin testele 6-10
#define PRIME1 1000
// cate numere neprime contin testele 11-15
#define NOT_PRIME2 1500
// cate numere prime contin testele 11-15
#define PRIME2 1500
// cate numere neprime contin testele 16-20
#define NOT_PRIME3 2500
// cate numere prime contin testele 16-20
#define PRIME3 2500

// numarul total de teste
#define TESTED_FILES 20
// numarul de teste generate random
#define GENERATED_FILES 15

// nr. neprime vor fi < NOT_PRIME_MAX1 int testele 6-10
#define NOT_PRIME_MAX1 7000
// valoarea de start a numerelor prime va fi < PRIME_MAX1
#define PRIME_MAX1 10000
// nr. neprime vor fi < NOT_PRIME_MAX1 int testele 11-15
#define NOT_PRIME_MAX2 12000
// valoarea de start a numerelor prime va fi < PRIME_MAX2
#define PRIME_MAX2 20000
// nr. neprime vor fi < NOT_PRIME_MAX1 int testele 16-20
#define NOT_PRIME_MAX3 20000
// valoarea de start a numerelor prime va fi < PRIME_MAX3
#define PRIME_MAX3 30000
// nr. prime vor fi > MIN_START_PRIME

// daca MIN_START_PRIME == -1, MIN_START_PRIME va fi generat random
#define MIN_START_PRIME -1



//algoritm de verificare a numerelor prime
bool isPrime(int n) {

	if (n == 0 || n == 1) {
		return false;
	} else {

		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}

	}

	return true;

}


//functie de generare a unui vector de numere prime
//pentru testele 6-10
vector<int> genPrime1(int len, int start)
{
	vector<int> primeVect;

	if (start == -1)
	{
		start = rand() % PRIME_MAX1 + 2;
	}

	int prime = start;

	while (len)
	{
		if (isPrime(prime))
		{
			primeVect.push_back(prime);

			len--;
			prime++;
		}
		else
		{
			prime++;
		}
	}

	return primeVect;
}


//functie de generare a unui vector de numere prime
//pentru testele 11-15
vector<int> genPrime2(int len, int start)
{
	vector<int> primeVect;

	if (start == -1)
	{
		start = rand() % PRIME_MAX2 + 2;
	}

	int prime = start;

	while (len)
	{
		if (isPrime(prime))
		{
			primeVect.push_back(prime);

			len--;
			prime++;
		}
		else
		{
			prime++;
		}
	}

	return primeVect;
}


//functie de generare a unui vector de numere prime
//pentru testele 16-20
vector<int> genPrime3(int len, int start)
{
	vector<int> primeVect;

	if (start == -1)
	{
		start = rand() % PRIME_MAX3 + 2;
	}

	int prime = start;

	while (len)
	{
		if (isPrime(prime))
		{
			primeVect.push_back(prime);

			len--;
			prime++;
		}
		else
		{
			prime++;
		}
	}

	return primeVect;
}


//functie de generare a unui vector de numere neprime
vector<int> genNotPrime(int len, int max)
{
	vector<int> notPrime;
	int nr = rand() % max;

	while (len)
	{
		nr = rand() % max;

		if (!isPrime(nr))
		{
			notPrime.push_back(nr);
			len--;
		}
	}

	return notPrime;
}


//functie de generare a unui vector cu numere combinate
//atat prime cat si neprime obtinute din functiile anteriore
vector<int> genTestNumbers(vector<int> prime, vector<int> notPrime)
{
	vector<int> final;

	int primeSize = prime.size();
	int notPrimeSize = notPrime.size();

	for (int i = 0; i < notPrimeSize; i++)
	{
		final.push_back(notPrime.back());
		notPrime.pop_back();
	}
	for (int i = 0; i < primeSize; i++)
	{
		final.push_back(prime.back());
		prime.pop_back();
	}
	random_shuffle(final.begin(), final.end());

	return final;
}


int main()
{

    ofstream testOut6;
    ofstream testOut7;
    ofstream testOut8;
    ofstream testOut9;
    ofstream testOut10;
    ofstream testOut11;
    ofstream testOut12;
    ofstream testOut13;
    ofstream testOut14;
    ofstream testOut15;
    ofstream testOut16;
    ofstream testOut17;
    ofstream testOut18;
    ofstream testOut19;
    ofstream testOut20;


    testOut6.open("test6.in");
    testOut7.open("test7.in");
    testOut8.open("test8.in");
    testOut9.open("test9.in");
    testOut10.open("test10.in");
    testOut11.open("test11.in");
    testOut12.open("test12.in");
    testOut13.open("test13.in");
    testOut14.open("test14.in");
    testOut15.open("test15.in");
    testOut16.open("test16.in");
    testOut17.open("test17.in");
    testOut18.open("test18.in");
    testOut19.open("test19.in");
    testOut20.open("test20.in");

    //testele: 6-10
    vector<int> prime;
	vector<int> notPrime;
	vector<int> final;

//generarea testului 6
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime1(PRIME1, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME1, NOT_PRIME_MAX1);

    final = genTestNumbers(prime, notPrime);

    testOut6 << PRIME1 + NOT_PRIME1 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut6 << final[i] << "\n";
	}

//generarea testului 7
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime1(PRIME1, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME1, NOT_PRIME_MAX1);

    final = genTestNumbers(prime, notPrime);

    testOut7 << PRIME1 + NOT_PRIME1 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut7 << final[i] << "\n";
	}

//generarea testului 8
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime1(PRIME1, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME1, NOT_PRIME_MAX1);

    final = genTestNumbers(prime, notPrime);

    testOut8 << PRIME1 + NOT_PRIME1 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut8 << final[i] << "\n";
	}

//generarea testului 9
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime1(PRIME1, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME1, NOT_PRIME_MAX1);

    final = genTestNumbers(prime, notPrime);

    testOut9 << PRIME1 + NOT_PRIME1 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut9 << final[i] << "\n";
	}

//generarea testului 10
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime1(PRIME1, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME1, NOT_PRIME_MAX1);

    final = genTestNumbers(prime, notPrime);

    testOut10 << PRIME1 + NOT_PRIME1 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut10 << final[i] << "\n";
	}

    //testele 11-15

//generarea testului 11
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime2(PRIME2, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME2, NOT_PRIME_MAX2);

    final = genTestNumbers(prime, notPrime);

    testOut11 << PRIME2 + NOT_PRIME2 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut11 << final[i] << "\n";
	}

//generarea testului 12
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime2(PRIME2, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME2, NOT_PRIME_MAX2);

    testOut12 << PRIME2 + NOT_PRIME2 << '\n';

    final = genTestNumbers(prime, notPrime);

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut12 << final[i] << "\n";
	}

//generarea testului 13
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime2(PRIME2, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME2, NOT_PRIME_MAX2);

    final = genTestNumbers(prime, notPrime);

    testOut13 << PRIME2 + NOT_PRIME2 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut13 << final[i] << "\n";
	}

//generarea testului 14
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime2(PRIME2, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME2, NOT_PRIME_MAX2);

    final = genTestNumbers(prime, notPrime);

    testOut14 << PRIME2 + NOT_PRIME2 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut14 << final[i] << "\n";
	}

//generarea testului 15
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime2(PRIME2, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME2, NOT_PRIME_MAX2);

    testOut15 << PRIME2 + NOT_PRIME2 << '\n';

    final = genTestNumbers(prime, notPrime);

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut15 << final[i] << "\n";
	}

    //testele 16-20

//generarea testului 16
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime3(PRIME3, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME3, NOT_PRIME_MAX3);

    final = genTestNumbers(prime, notPrime);

    testOut16 << PRIME3 + NOT_PRIME3 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut16 << final[i] << "\n";
	}

//generarea testului 17
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime3(PRIME3, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME3, NOT_PRIME_MAX3);

    final = genTestNumbers(prime, notPrime);

    testOut17 << PRIME3 + NOT_PRIME3 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut17 << final[i] << "\n";
	}

//generarea testului 18
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime3(PRIME3, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME3, NOT_PRIME_MAX3);

    final = genTestNumbers(prime, notPrime);

    testOut18 << PRIME3 + NOT_PRIME3 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut18 << final[i] << "\n";
	}

//generarea testului 19
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime3(PRIME3, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME3, NOT_PRIME_MAX3);

    final = genTestNumbers(prime, notPrime);

    testOut19 << PRIME3 + NOT_PRIME3 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut19 << final[i] << "\n";
	}

//generarea testului 20
    prime.clear();
    notPrime.clear();
    final.clear();

    prime = genPrime3(PRIME3, MIN_START_PRIME);
    notPrime = genNotPrime(NOT_PRIME3, NOT_PRIME_MAX3);

    final = genTestNumbers(prime, notPrime);

    testOut20 << PRIME3 + NOT_PRIME3 << '\n';

    for (int  i = 0; i < (int)final.size(); i++)
	{
		testOut20 << final[i] << "\n";
	}

    return 0;

}

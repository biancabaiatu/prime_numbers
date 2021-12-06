//generarea fisierelor de output

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

int main()
{
    
    int nrOfPrimes;
    
    string testIn = " ";
    cin >> testIn;

    ifstream fileIn;
    fileIn.open(testIn);

    std::string line;
    getline(fileIn, line);

    nrOfPrimes = stoi(line);

    vector<int> prime;
	int primeCount = 0;

    for (int i = 0; i < nrOfPrimes; i++) {

         getline(fileIn, line); //citirea din fisier

        int number = 0;
        sscanf(line.c_str(), "%d", &number);

        //verificarea primalitatii numarului
        if (isPrime(number)) {    
			
            prime.push_back(number);
			primeCount++;

		}

    }


    string testOut = " ";
    cin >> testOut;

    ofstream fileOut;

    fileOut.open(testOut);

    //scrierea in fisier
	fileOut << primeCount << "\n";

	for (int i = 0; i < primeCount; i++) {
		fileOut << prime[i] << "\n";
	}

    fileOut.close();

}

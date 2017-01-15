#include<iostream>
#include<cmath>


/*Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?*/

using namespace std;

bool isPrime(int num) {
	for(int a = 2; a < sqrt(num)+1; ++a) {
		if((num % a) == 0) return false;
	}
	return true;
}

int numPrimesFn(int a, int b, int c, int d) {
	int numPrimes = 0;
	if(isPrime(a)) ++numPrimes;
	if(isPrime(b)) ++numPrimes;
	if(isPrime(c)) ++numPrimes;
	if(isPrime(d)) ++numPrimes;
	return numPrimes;
}

int main() {
	int numPrimes = 3;
	int numNumbers = 5;
	int length = 3;
	int topRight, topLeft, bottomRight, bottomLeft; //Variables for what number is currently in each spot of the diagonal
	topRight = 3;
	topLeft = 5;
	bottomLeft = 7;
	bottomRight = 9;
	
	//Up to this point we have finished the first box of numbers
	//Now we use a loop to get the rest of the boxes
	
	for(int additionAmt = 8; ; additionAmt += 8) {
	//We add 8 more every time we add another layer to our square
		numNumbers += 4; //We add 4 more numbers to the diagonal each time
		topRight += 2 + additionAmt;
		topLeft += 4 + additionAmt;
		bottomLeft += 6 + additionAmt;
		bottomRight += 8 + additionAmt;
		numPrimes += numPrimesFn(topRight, topLeft, bottomLeft, bottomRight); // How many of the current diagonal numbers are prime?
		length += 2;
		if(numPrimes < ceil(numNumbers/10.0)) {
			cout << length << endl;
			break;
		}
	}
}

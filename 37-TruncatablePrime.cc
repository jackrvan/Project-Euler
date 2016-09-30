#include<iostream>
#include<cmath>

/*Problem 37
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
*/

int power(int base, int exponent) {
	if(exponent == 0) { return 1; }
	else { return base * power(base, exponent-1); }
}

bool isPrime(int num) {
	if(num == 1) return false;
	else if(num == 2) return true;
	for(int testNum = 2; testNum < sqrt(num) + 1; ++testNum) {
		if((num % testNum) == 0) {
			return false;
		}
	}
	return true;
}

int lengthOf(int number) {
	int leng = 0;
	bool containsEven = false;
	for(; number != 0; ++leng) { 
		//Test to see if it has an even number THAT ISNT 2 (since 2 is prime)
		if((number % 10 != 2) && (number % 2 == 0)) {
			containsEven = true;
		}
		number /= 10;
	} 
	return containsEven ? -1 : leng; //If it contains an even number we will return -1 and go to the next case bc if it has an even num it cant be answer
}

bool isTruncLeft(int num, int sizeOfNum) {
	int temp = num;
	//Delete left most digit each iteration and make sure new number is prime
	while(temp) {
		if(!isPrime(temp)) { return false; }
		temp %= power(10, sizeOfNum);
		--sizeOfNum;
	}
	return true;
}

bool isTruncRight(int num, int sizeOfNum) {
	int temp = num;
	//Delete right most digit each iteration and make sure each new number is prime
	while(temp) {
		if(!isPrime(temp)) { return false; }
		temp /= 10;
		--sizeOfNum;
	}
	return true;
}

int main() {
	int total = 0;
	int length = 0;
	for(int currentNum = 9; currentNum < 1000000; currentNum += 2) {
		//check to make sure we dont have an even number by testing if lengthOf(currentNum > 0)
		if(((length = lengthOf(currentNum)) > 0) && isPrime(currentNum) && isTruncLeft(currentNum, length) && isTruncRight(currentNum, length)) {
			total += currentNum;
		}
	}
	std::cout << "total = " << total << std::endl;
}

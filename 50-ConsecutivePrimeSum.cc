#include<iostream>
#include<vector>
#include<cmath>
#define LIMIT 1000000

/*Problem 50
 The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

int isPrime(int num) {
	for(int a = 2; a < sqrt(num) + 1; ++a) {
		if(num % a == 0) { return 0; } //Not prime
	}
	return 1; //Is prime
}

std::vector<int> getPrimes(int upperLimit) {
	std::vector<int> temp;  
	temp.push_back(2);  //Add 2 immediately since its a special case (its even)
	for(int a = 3; a < upperLimit; a += 2) {
		if(isPrime(a)) {
			temp.push_back(a);
		}
	}
	return temp;
}

int main() {
	unsigned int largestSum = 0;
	int lengthOfLongest = 0;
	std::vector<int> primes = getPrimes(LIMIT); //Define vector and fill with all primes that are less than LIMIT (1000000)
	for(unsigned int index = 1; index < primes.size(); ++index) {  //For loop to iterate through entire vector of primes
		unsigned int tempSum = primes[index];
		int tempLength = 1;
		for(int start = index-1; start > -1; --start) { //Start at index-1 and go down to the first number in the vector adding each number
			tempSum += primes[start];
			++tempLength;
			if(tempSum > LIMIT) { break; }
			if(tempLength > lengthOfLongest && isPrime(tempSum)) {  //If we have a new longest length and the currentsum is prime then we have a new winner
				largestSum = tempSum;
				lengthOfLongest = tempLength;
			}
		}
	}
	std::cout << "Largest sum is: " << largestSum << std::endl;
	return 0;
}

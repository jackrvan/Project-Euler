#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

/*Problem 32
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
*/

bool isPandigital(std::string num) {
	bool testArr[10];
	std::fill_n(testArr, 10, false);
	if(num.length() != 9) { return false; }
	for(auto it = num.begin(); it != num.end(); ++it) {
		if((testArr[(int)(*it) - 48]) || ((*it)-48 == 0)) { return false; }
		else { testArr[(int)(*it) - 48] = true; }
	}
	return true;
}

bool notDuplicate(int number, std::vector<int> vec) {
	//loop through vector to see if we had this number before
	for(auto it = vec.begin(); it != vec.end(); ++it) {
		if((*it) == number) { return false; }
	}
	return true;
}

int main() {
	std::vector<int> pandigNums;
	int total = 0;
	for(int multiplicand = 1; multiplicand < 10000; ++multiplicand) {
		int startingNum = (multiplicand > 9 ? 123 : 1234); //If multiplicand is > 9 we need to start with 123 but if its smaller we can start with 1234
		for(int multiplier = startingNum; multiplier < 10000/multiplicand; ++multiplier) {
			//Check to make sure that hte string with multiplicand multipier and product is pandigital and also make sure we havent had this combination before
			if(isPandigital(std::to_string(multiplicand) + std::to_string(multiplier) + std::to_string(multiplicand * multiplier)) && notDuplicate((multiplicand * multiplier), pandigNums)) { 
				pandigNums.push_back(multiplicand * multiplier);
				total += (multiplicand * multiplier);
			}
		}
	}
	std::cout << total << std::endl;
	return 0;
}

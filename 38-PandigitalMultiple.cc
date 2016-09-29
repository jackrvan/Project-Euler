#include<iostream>
#include<string>

/*Problem 38
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

bool isPandigital(std::string num) {
	bool testArr[10];
	std::fill_n(testArr, 10, false);
	for(auto it = num.begin(); it != num.end(); ++it) {
		if((testArr[(int)(*it) - 48]) || ((*it)-48 == 0)) { return false; } //If the number was already found in num or if we have a 0 then its not pandigital
		else { testArr[(int)(*it) - 48] = true; } //Set current number to true in array
	}
	return true;
}

int isPanMultiple(int num) {
	std::string answerString = "";
	for(int maxIndex = 1; answerString.length() < 10; ++maxIndex) {
		answerString = "";
		for(int currentIndex = 1; currentIndex <= maxIndex; ++currentIndex) {
			answerString += std::to_string(num * currentIndex); //adding num*currentIndex to our string
		}
		if((answerString.length() == 9) && isPandigital(answerString)) { return atoi(answerString.c_str()); }
	}
	return 0;
}

int main() {
	int max = 0; //Max pandigital number thus far
	for(int num = 0; num < 10000; ++num) {
		if(num % 10 == 0) { continue; } //number with 0 in it is not going to work
		int current = isPanMultiple(num);
		if(current > max) { max = current; }
	}
	std::cout << max << std::endl;
	return 0;
}

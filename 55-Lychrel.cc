#include<iostream>
#include<string>
#include<cmath>

/*
A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

How many Lychrel numbers are there below ten-thousand?
 */
using namespace std;

bool isPalindrome(unsigned long long num) {
	string temp = to_string(num); 
	auto it = temp.begin();
	auto it2 = temp.end() - 1;
	//Two iterators one at front one at back.
	//Increase front one and decrese back one if they are ever not equal its not a palindrome
	while(it < it2) {
		if((*it) != (*it2)) {
			return false;
		}
		++it;
		--it2;
	}
	return true;
}

unsigned long long reverse(unsigned long long num) {
	unsigned long long newNum = 0;
	unsigned long long size = log(num)/log(10);
	if(num == 10 || num == 100 || num == 1000 || num == 10000) {
		size++; //If we get a number that is 10^x then the size is one too small 
	}
	while(num > 0) {
		newNum += (num % 10) * pow(10, size); //Add the digit in the ones place multiplied by 10^size 
		--size;
		num /= 10;
	}
	return newNum;
}

bool isLychrel(unsigned long long num) {
	unsigned long long iterations = 1;
	num += reverse(num); //Get reverse of number and add it to our number
	//Loop until we either get a palindrome (not lychrel) or until we iterate 50 times (is lychrel)
	while(!isPalindrome(num)) {
		num += reverse(num);
		++iterations;
		if(iterations > 49) {
			return true;
		}
	}
	return false;
}

int main() {
	unsigned long long total = 0;
	for(unsigned long long currentNum = 1; currentNum < 10000; ++currentNum) {
		if(isLychrel(currentNum)) {
			total++;
		}
	}
	cout << total << endl;
	return 0;
}

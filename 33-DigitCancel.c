#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001

/*Question 33:
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

int fractionIsSame(int numer, int denom, int newNumer, int newDenom) {
	/*Find out if the two fractions are the same by subtracting them and comparing that answer to 0.0001*/
	if(fabs(numer/(float)denom - newNumer/(float)newDenom) < EPSILON) {
		return 1;
	}
	return 0;
}

int digitCancelling(int numer, int denom) {
	int numerDig2, denomDig1;
	numerDig2 = numer % 10;
	denomDig1 = denom / 10;
	if((numerDig2 == denomDig1) && fractionIsSame(numer, denom, numer/10, denom%10)) {
		return 1;
	}
	return 0;
}

void getLowestTerms(long int *numer, long int *denom) {
	//Loop through starting at 2 and dividing both numerator and denominator by 2 until we cant anymore and then going to 3 and so on
	for(int currentFactor = 2; currentFactor <= (*numer); ++currentFactor) {
		while((*numer) % currentFactor == 0 && (*denom) % currentFactor == 0) {
			*numer /= currentFactor;
			*denom /= currentFactor;
		}
	}
}

int main(int argc, char *argv[]) {
	int numerator;
	int denominator;
	long int endingNumerator = 1;
	long int endingDenominator = 1;  //Final answer
	for(numerator = 10; numerator < 100; ++numerator) {
		for(denominator = numerator + 1; denominator < 100; ++denominator) {
			if(digitCancelling(numerator, denominator)) {
				endingNumerator *= numerator;
				endingDenominator *= denominator;
			}
		}
	}
	getLowestTerms(&endingNumerator, &endingDenominator); //Get the fraction in lowest terms
	printf("%ld\n", endingDenominator);
}

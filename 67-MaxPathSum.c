#include<stdio.h>
#include<stdlib.h>
#define NUMROWS 100

/*Problem number 67 on project euler:
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt containing a triangle with one-hundred rows

How i solved:
 -Start at top of array and add the larger number above it and set that to the new number
 -make way to the bottom and then take the biggest number in the last row of the pyramid
*/

int *makeArray() {
	FILE *fp;
	int currentNum;
	static int array[(NUMROWS*(NUMROWS+1))/2], a = 0;
	fp = fopen("pyramid.txt", "r"); //Open pyramid.txt for reading.
	while(fscanf(fp, "%d ", &currentNum) == 1) {
		array[a] = currentNum;
		++a;
	}
	fclose(fp);
	return array;
}

int main() {
	int numNumbers = (NUMROWS * (NUMROWS + 1))/2;
	int *arrayNums = malloc(sizeof(int) * numNumbers);  //Variable for pointer to int with enough space for all of the integers in our file
	arrayNums = makeArray();
	int currentRowNumber, currentIndex = 1;
	int firstNumberOfRow, knt;
	for(currentRowNumber = 2, firstNumberOfRow = 1; currentRowNumber < (NUMROWS + 1); ++currentRowNumber) {
		for(knt = 0; knt < currentRowNumber; ++knt) {
			int temp, temp2;
			if(firstNumberOfRow) {
				arrayNums[currentIndex] = arrayNums[currentIndex] + arrayNums[currentIndex-(currentRowNumber - 1)]; //Add the current number we are on with the one above it and to the right
				firstNumberOfRow = 0;
				
			} else if(knt == (currentRowNumber - 1)) {						// Last number in the row
				arrayNums[currentIndex] = arrayNums[currentIndex] + arrayNums[currentIndex-(currentRowNumber)]; //Add the current number we are on with the one above it and to the left
			} else {
				temp = arrayNums[currentIndex] + arrayNums[currentIndex-(currentRowNumber - 1)]; //Add the current number we are on with the one above it adn to the right
				temp2 = arrayNums[currentIndex] + arrayNums[currentIndex-(currentRowNumber)]; //Add the current number we are on with the one above it adn to the left
				arrayNums[currentIndex] = (temp > temp2 ? temp : temp2); //Set it equal to the bigger number
			}
			++currentIndex;
		}
	}
	int a = 0;
	int max = 0;
	while(arrayNums[a]) {
		if(arrayNums[a] > max) {
			max = arrayNums[a];
		}
		++a;
	}
	printf("%d\n", max);
	return 0;
}

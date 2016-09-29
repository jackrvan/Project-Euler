#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

/* Problem 15:
 Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 How many such routes are there through a 20×20 grid?
*/

int main() {
	int a;
	long long int array[SIZE+1][SIZE+1];
	for(a = 0; a < SIZE+1; ++a) {
		array[a][0] = 1; //Make the entire first column all 1s
		array[0][a] = 1; //Make the entire first row all 1s
	}
	int row, column;
	for(row = 1; row < SIZE + 1; ++row) {
		for(column = 1; column < SIZE + 1; ++column) {
			array[row][column] = (array[row-1][column] + array[row][column-1]); //Set current array index equal to index above added to index to the right
		}
	}
	printf("%lld\n", array[SIZE][SIZE]);
	return 0;
}


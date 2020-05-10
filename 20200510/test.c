#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void test() {
	int array[] = { 11,10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(array) / sizeof(array[0]);
	//mergeSortNor(array, size);
	countSort(array, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	test();
	system("pause");
	return 0;
}
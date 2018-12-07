#include <iostream>

#define NOT_SORTED 15
#define DESCENDING 10
#define ASCENDING 5
#define NOT_FOUND 0

int isDesc(int a[], int SIZE);

int isAsc(int a[], int SIZE);

int searchDesc(int a[], int SIZE, int key);

int searchAsc(int a[], int SIZE, int key);

void binarySearch(int a[], int SIZE, int key);

int main () {
	int size, key;
	
	printf("Enter the size of the array\n");	
	scanf("%d", &size);

	int array[size];
	
	printf("Enter elements to array:\n");
	for (int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	
	printf("Enter the key to be searched:\n");
	scanf("%d", &key);

	binarySearch(array, size, key);
		
	return 0;	
}

int isDesc(int a[], int SIZE) {
	for (int i = 0; i < SIZE - 1; i++) {
		if (a[i] >= a[i + 1])
			continue;
		else
			throw ASCENDING;
	}
	
	return DESCENDING;
}

int isAsc(int a[], int SIZE) {
	for (int i = SIZE - 1; i >= 0; i--) {
		if (a[i] >= a[i - 1])
			continue;
		else 
			throw NOT_SORTED;
	}
	
	return ASCENDING;
}

int searchDesc(int a[], int SIZE, int key) {
	int beg = 0;
	int end = SIZE - 0;
	int mid = (beg + end) / 2;
	
	while (beg < end) {

		if (a[mid] == key)
			return mid;
		else if (a[mid] > key) {
			beg = mid + 1;
		}
		else {
			end = mid - 1;
			
		}

		mid = (beg + end) / 2;
	}
	
	throw NOT_FOUND;
}
int searchAsc(int a[], int SIZE, int key) {
	int beg = 0;
	int end = SIZE - 1;
	int mid = (beg + end) / 2;

	while (beg < end) {
		
		if (a[mid] == key) 
			return mid;	
		else if (a[mid] > key) 
			end = mid - 1;
		else 
			beg = mid + 1;

		mid = (beg + end) / 2;
	}
	
	throw NOT_FOUND;
}

void binarySearch (int a[], int SIZE, int key) {
	int index;
	try {
		if (isDesc(a, SIZE) == DESCENDING) {
			try {
				index = searchDesc(a, SIZE, key);
				printf("Element found at position %d.\n", index + 1);
			}
			catch (int x) {
				//printf("Status code 1: %d", x);
				printf("Element not found.\n");
			}
		}
	}
		
	catch (int y) {
		//printf("Status code 2: %d", y);
		try {
			if (isAsc(a, SIZE) == ASCENDING && y == 5) {
				try {
					index = searchAsc(a, SIZE, key);
					printf("Element found at position %d\n", index + 1);
				}
				catch (int z) {
					//printf("Status code 3: %d", z);
					printf("Element not found.\n");
				}
			}
		}
		catch (int w) {
			//printf("Status code 4: %d", w);
			printf("Action aborted! Array is not sorted.\n");
		}
	} 
}

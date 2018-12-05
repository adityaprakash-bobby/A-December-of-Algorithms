#include <iostream>

int arr[] = {};

// count the number of digits in the number 
// and stores the digits in a array
int countDigit (long long int number) {
	int digits = 0, digit;

	while (number > 0) {
		digit = number % 10;
		number = number / 10;
		arr[digits] = digit;
		digits++;
	}
	
	return digits;
}

// check if number is lucky
// if sum == 0, then we have the number as lucky,
// else unlucky
int isLucky (long long int number) {
	int sum = 0;
	int digits = countDigit(number);
	int half_digits = digits / 2;

	if (digits % 2 != 0)
		throw 0;
	
	for (int i = 0; i < half_digits; i++) {
		sum = sum + arr[i] - arr[i + half_digits];
	}

	return sum;
}

int main () {
	long long int number; 
	
	printf("Enter the ticket number to check if it's lucky.\n");
	scanf("%lld", &number);
	
	try {
		long long int luck;
		luck = isLucky(number);
	
		if (luck == 0)
			printf("You're Lucky\n");
		else 
			printf("You're Unlucky\n");

	}
	
	catch (...) {
		printf("Aborted!\n");
		return 0;
	}
	
	return 0;
}

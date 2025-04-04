#include <stdio.h>

int sumDigits(int number); //1
bool searchOnce(int number, int digit); //2
int countAll(int number, int digit); //3
int getMax(int number); //4
int reverse(int number); //6
int merge(int number1, int number2); //7

int main() {
	int num = merge(123,321);
	printf("%d", num);
	return 0;
}

int sumDigits(int number) {
	if (number == 0) {
		return 0;
	}
	int sum = number % 10;
	int nextsum = sumDigits(number / 10);

	return sum + nextsum;
}

bool searchOnce(int number, int digit) {

	if (number < 10) {
		return (number == digit);
	}

	if (number % 10 == digit) return true;
	else {
		int next = searchOnce(number / 10, digit);
	}

}

int countAll(int number, int digit) {
	if (number == 0) {
		return 0;
	}

	int count = (number % 10 == digit) ? 1 : 0;

	return count + countAll(number / 10, digit);
}

int getMax(int number) {

	if (number < 10) {
		return number;
	}

	int old = getMax(number / 10);
	int current = getMax(number %10);
	if (current > old) {
		return current;
	}
}

int reverse(int number) {
	static int reversed = 0;
	if (number == 0) {
		int temp = reversed;
		reversed = 0;
		return temp;
	}
	reversed = reversed * 10 + (number % 10);
	return reverse(number / 10);
}

int merge(int num1, int num2) {
	if (num1 == 0 && num2 == 0) {
		return 0;
	}

	int digit1 = num1 % 10;
	int digit2 = num2 % 10;

	if (num1 == 0) {
		return merge(num1, num2 / 10) * 10 + digit2;
	}
	if (num2 == 0) {
		return merge(num1 / 10, num2) * 10 + digit1;
	}

	if (digit1 <= digit2) {
		return merge(num1 / 10, num2) * 10 + digit1;
	}
	else {
		return merge(num1, num2 / 10) * 10 + digit2;
	}
}
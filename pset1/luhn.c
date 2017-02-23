#include <stdio.h>

/*
- Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
- Add the sum to the sum of the digits that weren’t multiplied by 2.
- If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

- American Express numbers all start with 34 or 37
- MasterCard numbers all start with 51, 52, 53, 54, or 55
- Visa numbers all start with 4

*/
int digit_sum(int number);

enum {
	AMEX = 0,
	MC = 1,
	VISA = 2
} card_type;

int main(int argc, char *argv[]) {
	int count = 0;
//	long long ccnum = 4430470093045844;
//	long long ccnum = 5105105105105100;
	long long ccnum = 378282246310005;
	long long tmp = ccnum;
	
	while (tmp > 0LL) {
		tmp = tmp / 10LL;
		count++;
	}

	long long scratch_num = ccnum;
	int odd_numbers_sum = 0;	
	int product_digit_sum = 0;
	int first_position = count
	int second_position = count - 1;
	
	for (int x = 1; x <= count; x++) {
		int digit = scratch_num % 10LL;
		
		if (x % 2 == 0) {
			int product = digit * 2;
			int mini_sum = digit_sum(product);
			product_digit_sum += mini_sum;
		} else {
			odd_numbers_sum += digit;
		}
		
		scratch_num /= 10LL;		
		
		if (x == first_position) {
			
		} else if (x == second_position) {
			
		}
	}
	
	printf("odd_numbers_sum: %i\n", odd_numbers_sum);
	printf("product_digit_sum: %i\n", product_digit_sum);
	
	int result = odd_numbers_sum + product_digit_sum;
	int final_mod = result % 10;
	
	if (final_mod == 0) {
		printf("VALID!!!");
	} else {
		printf("INVALID, YA BASTAGE!!!");
	}
}

int digit_sum(int number) {
	if (number == 0) {
//		printf("found 0, returning 0\n");
		return 0;
	}
	
	int response_sum = 0;
	int tmp = number;	
	int count = 0;

	while (tmp > 0LL) {
//		printf("tmp: %i\n", tmp);
		int last_digit = tmp % 10;
		response_sum += last_digit;
		tmp = tmp / 10LL;
		count++;
	}
	
//	printf("==== Found sum of: %i for number: %i ====\n", response_sum, number);
	
	return response_sum;
}
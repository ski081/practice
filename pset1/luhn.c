#include <stdio.h>

/*
- Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
- Add the sum to the sum of the digits that weren’t multiplied by 2.
- If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/
int digit_count(int number);

int main(int argc, char *argv[]) {
	int count = 0;
	long long ccnum = 4430470093045844;
	
//	4 8
//	5 10
//	0 0
//	9 18
//	0 0
//	4 8
//	3 6 
//	4 8
// 58 40


// 4
// 8
// 4
// 3
// 0
// 7
// 0
// 4
// 30	
		
	long long tmp = ccnum;
	
	while (tmp > 0LL) {
		tmp = tmp / 10LL;
		count++;
	}

	long long scratch_num = ccnum;
	int odd_numbers_sum = 0;	
	int product_digit_sum = 0;
	
	for (int x = 1; x <= count; x++) {
		int digit = scratch_num % 10LL;
		
		printf("digit: %i\n", digit);
		
		if (x % 2 == 0) {
			int product = digit * 2;
			int single_digit_count = digit_count(product);
			
			printf("product: %i\n", product);
			printf("single_digit_count: %i\n", single_digit_count);
			
			for (int i = 1; i <= single_digit_count; i++) {
				int single_digit = product % 10LL;
				printf("single_digit: %i\n", single_digit);
				product_digit_sum += single_digit;
				printf("product_digit_sum: %i\n", product_digit_sum);
			}
		} else {
			odd_numbers_sum += digit;
		}
		
		scratch_num /= 10LL;		
	}
	
	printf("odd_numbers_sum: %i\n", odd_numbers_sum);
	printf("product_digit_sum: %i\n", product_digit_sum);
	
	int result = odd_numbers_sum + product_digit_sum;
	int final_mod = result % 10;
	
	printf("result: %i\n", result);
	printf("finalMod: %i\n", final_mod);
}

int digit_count(int number) {
	int count = 0;
		
	while (number > 0LL) {
		number = number / 10LL;
		count++;
	}
	
	return count;
}
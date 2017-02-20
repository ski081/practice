#include <stdio.h>

/*
- Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
- Add the sum to the sum of the digits that weren’t multiplied by 2.
- If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/

int main(int argc, char *argv[]) {
	int count = 0;
	long long ccnum = 5678123445671234;
	long long tmp = ccnum;
	
	while (tmp > 0LL) {
		tmp = tmp / 10LL;
		count++;
	}
	
	printf("count: %i\n", count);	

	long long scratch_num = ccnum;
	int oddNumbersSum = 0;	
	int evenNumbersSum = 0;
	
	for (int x = 1; x <= count; x++) {

		int digit = scratch_num % 10LL;
		
		if (x % 2 == 0) {
			int product = digit * 2;
			evenNumbersSum += digit;
			evenNumbersSum += product;		
		} else {
			oddNumbersSum += digit;
		}
		
		scratch_num /= 10LL;
		
		printf("scratch_num: %lli\n", scratch_num);
		printf("digit: %i\n", digit);
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

bool validate_input(int argc, char *argv[]);
int alpha_position(char letter);

int main(int argc, char *argv[]) {
	bool valid_input = validate_input(argc, argv);
	
	if (!valid_input) {
		return 1;
	}
	
	int cipher = atoi(argv[1]);
	printf("cipher: %i\n", cipher);
	
	printf("plaintext:");
	string plain_text = get_string(); 
	
	for (int i = 0; i < strlen(plain_text); i++) {
		char letter = plain_text[i];			
		if (isalpha(letter)) {
			int position = alpha_position(letter);
			printf("Position: %i\n", position);						
		} else {
			printf("%c\n", letter);
		}
	}

}

bool validate_input(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Invalid arguments");
		return false;
	}
	
	printf("Valid input\n");
	
	return true;
}

int alpha_position(char letter) {
	int position = -1;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	for (int i = 0; i < strlen(alphabet); i++) {
		char letter_to_check = alphabet[i];
		if (letter_to_check == letter) {
			position = i;
			break;			
		}
	}
	
	return position;
}





 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

bool validate_input(int argc);
int alpha_position(char letter);
char letter_at_position(int position);
string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, char *argv[]) {
	bool valid_input = validate_input(argc);
	
	if (!valid_input) {
		return 1;
	}
	
	printf("plaintext: ");
	
	int cipher = atoi(argv[1]);
	string plain_text = get_string(); 
	
	printf("ciphertext: ");
	
	for (int i = 0; i < strlen(plain_text); i++) {
		char letter = plain_text[i];			
		if (isalpha(letter)) {
			int position = alpha_position(tolower(letter));
			int adjusted_position = (position + cipher) % 26;
			char cipher_letter = letter_at_position(adjusted_position);
			char ciphered_cased = cipher_letter;
			
			if (isupper(letter)) {
				ciphered_cased	= toupper(ciphered_cased);
			} else {
				ciphered_cased = tolower(ciphered_cased);
			}
			
			printf("%c", ciphered_cased);
		} else {
			printf("%c", letter);
		}
	}
	
	printf("\n");
	return 0;
}

bool validate_input(int argc) {
	if (argc != 2) {
		printf("Invalid arguments\n");
		return false;
	}
	
	return true;
}

char letter_at_position(int position) {
	char item = alphabet[position];
	return item;	
}

int alpha_position(char letter) {
	int position = -1;
	
	for (int i = 0; i < strlen(alphabet); i++) {
		char letter_to_check = alphabet[i];
		if (letter_to_check == letter) {
			position = i;
			break;			
		}
	}
	
	return position;
} 
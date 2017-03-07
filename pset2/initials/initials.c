#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

string get_name();
char find_next_character(int position, string input);

int main(int argc, char *argv[]) {
	string input = get_name();
	int current_overall_index = 0;
	char character = input[0];

	if (character == ' ') {
		printf("%c", toupper(find_next_character(0, input)));
	} else {
		printf("%c", toupper(character));
	}
	
	current_overall_index++;

	for (int i = 1; i < strlen(input); i++) {
		char character = input[i];
		
		if (character == ' ') {
			printf("%c", toupper(find_next_character(i, input)));
		}
	}	
}

char find_next_character(int position, string input) {
	for(int i = position; i < strlen(input); i++) {
		char character = input[i];
		if (character == ' ') {
			continue;
		} else {
			return character;
		}
	}
}

string get_name() {
	return "    My Name";
}
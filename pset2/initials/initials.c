#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

string get_name();

int main(int argc, char *argv[]) {
	string input = get_name();
	char character = input[0];
	int stop_index =  strlen(input);
	bool last_whitespace;
	 	
	if (character == ' ') {
		last_whitespace = true;
	} else {
		last_whitespace = false;
		printf("%c", toupper(character));
	}

	for (int i = 1; i < stop_index; i++) {
		char current_character = input[i];
		
		if (last_whitespace && current_character == ' ') {
			last_whitespace = true;
		} else if (last_whitespace && current_character != ' ') {
			printf("%c", toupper(current_character));
			last_whitespace = false;
		} else if (current_character == ' ') {
			last_whitespace = true;
		}
	}	
	
	printf("\n");
}

string get_name() {
	return get_string();
}
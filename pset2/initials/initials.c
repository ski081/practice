#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

typedef enum {
	whitespace = 0,
	alpha = 1
} search_type;

string get_name();

int main(int argc, char *argv[]) {
	string input = get_name();
	int current_overall_index = 0;
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
		char character = input[i];
		
		if (last_whitespace && character == ' ') {
			last_whitespace = true;
		} else if (last_whitespace && character != ' ') {
			printf("%c", toupper(character));
			last_whitespace = false;
		} else if (character == ' ') {
			last_whitespace = true;
		}
	}	
}

string get_name() {
	return "    My    Name G  ";
}
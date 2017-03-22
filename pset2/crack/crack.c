#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>

int validate_input(int argc);

int main(int argc, char *argv[]) {
	if (validate_input(argc) != 0) {
		return 1;
	}
	
	char *pwd = crypt("abcd", "55");
	printf("PWD: %s\n", pwd);
	
	return 0;
}

int validate_input(int argc) {
	if (argc != 2) {
		printf("Invalid input");
		return -1;
	}
	
	return 0;
}


#include <stdio.h>
int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("ERROR: You need one argument.\n");
		// this is how you abort a program
		return 1;
	}

	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		if(letter >= 65 && letter <= 90) {
			switch(letter) {
				case 'A':
					printf("%d: 'A'\n", i);
					argv[1][i] = argv[1][i] + 'a' - 'A';
					break;
				
				case 'E':
					printf("%d: 'E'\n", i);
					argv[1][i] = argv[1][i] + 'a' - 'A';
					break;

				case 'I':
					printf("%d: 'I'\n", i);
					argv[1][i] = argv[1][i] + 'a' - 'A';
					break;

				case 'O':
					printf("%d: 'O'\n", i);
					argv[1][i] = argv[1][i] + 'a' - 'A';
					break;

				case 'U':
					printf("%d: 'U'\n", i);
					argv[1][i] = argv[1][i] + 'a' - 'A';
					break;

				case 'Y':
					if(i > 2) {
						// it's only sometimes Y
						printf("%d: 'Y'\n", i);
						argv[1][i] = argv[1][i] + 'a' - 'A';
					}
					break;

				default:
					printf("%d: %c is not a vowel\n", i, letter);
					argv[1][i] = ' ';
			}
		}
		else;
	}

	printf("%s", argv[1]);
	
	return 0;
}

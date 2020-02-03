//Build this source code and then run it with a text file as input in a command prompt in this format: program.exe < textfile.txt
//This code prints histogram based on character frequency

#include <stdio.h>
#include <ctype.h>

#define CHARTOTAL 127

int main(int argc, const char * argv[]) {

	int c, a, histo[CHARTOTAL];

	for (a = 0; a < CHARTOTAL; a++) {

		histo[a] = 0;

	}

	while ((c = getchar()) != EOF) {

		if (c <= CHARTOTAL ) {

			histo[c]++;

		}

	}

	for (a = 0; a < CHARTOTAL; a++) {

		if (isprint(a)) {

			printf("%3d | %c (%d): ", a, a, histo[a]);

		}
		else {

			printf("%3d |   (%d): ", a, histo[a]);

		}

		while (histo[a] > 0) {

			printf("*");
			histo[a]--;

		}
		printf("\n");
	}

	return 0;
}

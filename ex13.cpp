//Build this source code and then run it with a text file as input in a command prompt in this format: program.exe < textfile.txt
//This code prints horizontal/vertical histograms for words of varying lengths.

#include <stdio.h>
#include <ctype.h>

#define IN 1 // Inside a word
#define OUT 0 // Outside a word
#define HISTSIZE 30

/* copy input to output; 1st version */
int main(int argc, const char* argv[]) {
	// count lines, words, and chars in input

//long nc, nl, nw;
//nc = nl = nw = 0;
	long nc = 0;
	long nl = 0;
	long nw = 0;
	int c, state = OUT, histogram[HISTSIZE], histogramV2[HISTSIZE], wordCount = 0;

	for (int j = 0; j < 10; j++)
	{
		histogram[j] = 0;
	}

	while ((c = getchar()) != EOF) {

		++nc;

		if (isalpha(c) || c == '-') {

			++wordCount;

		}

		if (c == '\n') { ++nl; }
		if (c == ' ' || c == '\n' || c == '\t') {

			state = OUT; 
			++histogram[wordCount];
			wordCount = 0;
			
		}
		else if (state == OUT) {
			state = IN;
			++nw;

		}
	}
	if (c == EOF)
	{
		state = OUT;
		++histogram[wordCount];
		wordCount = 0;
	}

	for (int a = 0; a < HISTSIZE; a++)
	{
		histogramV2[a] = histogram[a];
	}

	printf("%ld chars, %ld words, and %ld lines\n", nc, nw, nl);
	for (int i = 1; i < HISTSIZE; i++) {

		printf("%d: ", i);
		while (histogram[i] > 0) {

			printf("*");
			--histogram[i];

		}
		printf("\n");	
	}
	printf("\n");

	int b = 1;
	while (b < HISTSIZE)
	{
		printf("%d ", b);
		++b;
	}
	printf("\n");
	for (int i = 1; i < HISTSIZE; i++) {

		for (int c = 1; c < HISTSIZE; c++) {

			if (histogramV2[c] > 0) {

				printf("* ");
				--histogramV2[c];

			}
			else {

				printf("  ");

			}

		}
		printf("\n");

	}

	return 0;
}

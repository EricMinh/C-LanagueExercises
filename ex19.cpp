#include <stdio.h>
#define MAXLINE	1000			/* maximum input line length */

int getline(char line[], int maxline);

/* print the longest input line */
int main(int argc, const char * argv[]) {

	int		a, b;
	a = b = 0;

	char	line[MAXLINE], swap;

	while (getline(line, MAXLINE) > 0) {

		while (line[a] != '\0') {

			a++;

		}
		a--;

		if (line[a] == '\n') {

			a--;

		}

		while (b < a) {

			swap = line[b];
			line[b] = line[a];
			line[a] = swap;
			a--;
			b++;

		}

		printf("%s", line);

	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim) {

	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim - 2) {
			s[j] = c;
			++j;
		}
	if (c == '\n') {
		s[j] = c;
		++j;
		++i;
	}
	s[i] = '\0';
	return i;
}

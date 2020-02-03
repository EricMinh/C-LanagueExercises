//Make sure to test this code with text file that has a \n at the end. In a .txt file, that would be pressing enter/return.
//Otherwise, it will throw an unhandled exception

#include <stdio.h>
#define MAXLINE	1000			/* maximum input line length */

int getline(char line[], int maxline);

/* print the longest input line */
int main(int argc, const char * argv[]) {

	int		a;
	char	line[MAXLINE];

	while (getline(line, MAXLINE) > 0) {

		a = 0;

		while (line[a] != '\n') {

			a++;

		}
		a--;

		while (a >= 0 && (line[a] == ' ' || line[a] == '\t')) {
			
			a--;

		}
		a++;
		line[a] = '\n';
		a++;
		line[a] = '\0';

		if (a > 0) {

			printf("%s", line);

		}

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

//Build this source code and then run it with a text file as input in a command prompt in this format: program.exe < texefile.txt
//This code prints out lines that are greater than 80 in length

#include <stdio.h>
#define MAXLINE	1000			/* maximum input line length */
#define GOODSIZE 80

int getline(char line[], int maxline);

/* print the longest input line */
int main(int argc, const char * argv[]) {
	
	int		length;
	char	line[MAXLINE];

	while ((length = getline(line, MAXLINE)) > GOODSIZE) {

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

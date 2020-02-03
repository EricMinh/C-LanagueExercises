//Build this source code and then run it with a text file as input in a command prompt in this format: program.exe < textfile.txt

//This code contains the revisions so that it will correctly print the
//length of arbitrarily long input lines. and as much as possible of the text.

#include <stdio.h>
#define MAXLINE 1000			/* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(int argc, const char * argv[])
{
	int len;					/* current line length */
	int max;					/* maximum length seen so far */
	char line[MAXLINE];			/* current input line */
	char longest[MAXLINE];		/* longest line saved here */

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		printf("%d, %s", len, line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) /* there was a line */
		printf("%s", longest);
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim-2) {
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

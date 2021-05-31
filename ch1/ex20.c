/*
 * Exercise 1-20
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

#define MAXLEN 1000		// maximum length of input
#define TABSIZE	8		// n

void detab(char s[], int tabsize);
int getinp(char inp[], int maxsize);
void copy(char to[], char from[]);

/*
 * replaces tabs in input with proper number of blanks
 */
int main()
{
	char inp[MAXLEN+1];

	getinp(inp, MAXLEN+1);
	detab(inp, TABSIZE);
	printf("%s", inp);

	return 0;
}


/*
 * detab: replaces tabs in input with proper number of blanks
 */
void detab(char s[], int tabs)
{
	char temp[MAXLEN];
	int col;	// current column
	int i, j;

	copy(temp, s);

	i = j = 0;
	col = 0;
	for (i=0; temp[i] != '\0'; ++i) {
		if (temp[i] == '\t') {
			s[j++] = ' ';
			col++;
			while (col % tabs) {
				s[j++] = ' ';
				col++;
			}
		}
		else if (temp[i] == '\n') {
			s[j++] = '\n';
			col = 0;
		}
		else {
			s[j++] = temp[i];
			col++;
		}
	}
	s[j] = '\0';
}

/*
 * getinp: stores input until EOF into 'inp',
 *		   'maxsize' is the characters to inp;
 *		   returns the length of input
 */
int getinp(char inp[], int maxsize)
{
	int i;
	char c;

	for (i=0; i<maxsize-1 && (c=getchar())!=EOF; ++i)
		inp[i] = c;
	inp[i] = '\0';
	
	return i;
}


/*
 * copy: copies the contents of 'from' to 'to';
 *       assuming 'to' is big enough
 */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
	to[i] = '\0';
    
    return;
}
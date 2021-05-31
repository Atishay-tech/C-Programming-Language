/*
 * Exercise 1-21
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve the same spacing. 
 * Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 */

#include <stdio.h>

#define MAXLEN 1000		// maximum length of input
#define TABSIZE	8		// n

void entab(char s[], int tabsize);
int getinp(char inp[], int maxsize);

/*
 * replaces strings of blanks by the minimum number of tabs and blanks
 * to achieve the same spacing
 */
int main()
{
	char inp[MAXLEN+1];

	getinp(inp, MAXLEN+1);
	entab(inp, TABSIZE);
	printf("%s", inp);

	return 0;
}


/*
 * entab: replaces blanks with appropriate number of tabs and blanks
 */
void entab(char s[], int tabs)
{
	int col;	// used to keep track of tab stops
	int nums;	// number of spaces
	int i, j;
	char c;

	j = 0;
	nums = 0;
	col = 0;
	for (i=0; (c = s[i]) != '\0'; ++i) {
		if (c == ' ') {
			++nums;
			++col;
			if (col % tabs == 0) {
				s[j++] = '\t';
				nums = 0;
			}
		}
		else if (c=='\n' || c=='\t') {
			s[j++] = c;
			nums = 0;
			col = 0;
		}
		else {
			while (nums) {
				s[j++] = ' ';
				nums--;
			}
			s[j++] = c;
			++col;
		}
	}
	s[j] = '\0';
}

/*
 * getinp: stores input until EOF into 'inp',
 *		   'maxsize' is the maximum characters in inp;
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
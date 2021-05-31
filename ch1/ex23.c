/*
 * Exercise 1-23
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest.
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

char handle_char_const();
char handle_string();
char handle_single_line();
char handle_multiple_lines();


/*
 * removes all comments from a c program
 */
int main()
{
	int c;
	int eof;
	int maybe_comment;

	maybe_comment = FALSE;
	eof = FALSE;
	while (!eof && (c=getchar()) != EOF) {
		if (c == '/')			// Slash
			if (maybe_comment) {
				c = handle_single_line();
				maybe_comment = FALSE;
			}
			else {
				maybe_comment = TRUE;
			}

		else if (maybe_comment && c == '*') {
			c = handle_multiple_lines();
			maybe_comment = FALSE;
			if (c != EOF)
				c = getchar();
		}

		else if (maybe_comment) {
			maybe_comment = FALSE;
			putchar('/');
		}
		
		else if (c == '\"')	{	// Strings
			putchar(c);
			c = handle_string();
		}

		else if (c == '\\') {	// character constants
			putchar(c);
			c = handle_char_const();
		}

		if (c == EOF)
			eof = TRUE;
		else if (!maybe_comment)
			putchar(c);
	}

	return 0;
}

/*
 * handle_char_const: receives one following character and prints it,
 *					  returns the character
 */
char handle_char_const()
{
	int c;

	c = getchar();

	return c;
}


/*
 * handle_string: inputs and prints characters until a '"' is encountered,
 *				  returns the last character scanned
 */
char handle_string()
{
	int c;

	c = '\"';
	while (c != EOF && (c=getchar()) != '\"') {
		putchar(c);
		if (c == '\\') {
			c = handle_char_const();
			if (c != EOF)
				putchar(c);
		}
	}

	return c;
}

/*
 * handle_single_line: ignores single line comments,
 *				  	   returns the last character scanned
 */
char handle_single_line()
{
	int c;

	c = '/';
	while (c != EOF && (c=getchar()) != '\n')
		;

	return c;
}


/*
 * handle_multiple_lines: ignores multiple line comments,
 *				  	   	  returns the last character scanned
 */
char handle_multiple_lines()
{
	int c;
	int comment_end;

	c = '*';
	comment_end = FALSE;
	while (!comment_end && c != EOF && (c=getchar()) != EOF) {
		if (c == '*')
			comment_end = TRUE;
		
		if (comment_end) {
			c = getchar();
			if (c != '/')
				comment_end = FALSE;
		}
	}

	return c;
}
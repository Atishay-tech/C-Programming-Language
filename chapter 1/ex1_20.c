#include <stdio.h>

#define MAX_BUFFER	1024	// maximum length of input
#define TAB_SIZE  	8		// size of tab stops

void detab(char buffer[], int tab_width);
void entab(char buffer[], int tab_width);
void copy(const char from[], char to[]);

int main()
{
	char buffer[MAX_BUFFER];
	int c, i;
	
	/* input buffer */
	i = 0;
	while((i < MAX_BUFFER-1) && ((c=getchar()) != EOF)) {
		buffer[i] = c;
		++i;
	}
	buffer[i] = '\0';
	
	/* function call */
	detab(buffer, TAB_SIZE);
	printf("%s", buffer);
	
	return 0;
}

/* copy: copies the string 'from' to 'to' */
void copy(const char from[], char to[])
{
	int i;
	char c;
	
	for(i = 0; from[i] != '\0'; ++i)
		to[i] = from[i];
	to[i] = '\0';
}

/* detab: replaces tabs in buffer with proper number of spaces */
void detab(char buffer[], int tab_width)
{
	int i, j, counter;
	char c;
	char new_buffer[MAX_BUFFER];
	
	i = j = 0;
	counter = tab_width;
	
	for(i = 0; (c=buffer[i]) != '\0'; ++i) {	
		if(c == '\t') {
			while(counter>0) {
				--counter;
				new_buffer[j] = ' ';
				++j;
			}
			counter = tab_width;
		}
		else if(c == '\n') {
			counter = tab_width;
			new_buffer[j] = '\n';
			++j;
		}
		else {
			new_buffer[j] = c;
			++j;
		/* to keep the counter from tab_width through 1 */
			counter--;
			if(counter == 0)
				counter = tab_width;
		}
	}
	new_buffer[j] = '\0';
	
	copy(new_buffer, buffer);
}


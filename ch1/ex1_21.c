#include <stdio.h>

#define MAX_BUFFER	1024	// maximum length of input
#define TAB_SIZE  	8		// size of tab stops
#define IN			1		// inside
#define OUT 		0		// outside

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
	entab(buffer, TAB_SIZE);
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

/* entab: replaces strings of blanks in buffer with tabs and blanks */
void entab(char buffer[], int tab_width)
{
	int i, j, pos, nb, state;
	char c;
	char new_buffer[MAX_BUFFER];
	
	state = OUT;			// inside or outside a blank trail
	pos = 0;				// position in buffer in terms of blanks
	nb = 0;					// number of blanks
	
	for(i=0, j=0; (c=buffer[i]) != '\0'; ++i) {
		if(c == ' ') {
			state = IN;		
			++pos;
			++nb;
		}
		else if(c == '\t') {
			state = IN;
			pos += tab_width - pos % tab_width;	// increment the pos to next tab stop
		}
		else if(c == '\n') {
			state = OUT;
			pos = 0;
			new_buffer[j] = '\n';
			++j;
		}
		else {
			if(state == IN) {					// entering a word after a blank string
				state = OUT;
				while(nb > 0) {
					--nb;
					new_buffer[j] = ' ';
					++j;
				}
			}
			++pos;
			new_buffer[j] = c;
			++j;
		}
		
		if((pos % tab_width == 0) && (state == IN)) {
			new_buffer[j] = '\t';
			++j;
			nb = 0;
		}
	}
	new_buffer[j] = '\0';
	
	copy(new_buffer, buffer);
}


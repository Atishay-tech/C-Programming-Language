#include <stdio.h>

#define MAX_BUFFER 1024

enum bool { FALSE, TRUE };

void copy(const char *from, char *to);
void uncomment(char *buffer);

int main(void)
{

	char buffer[MAX_BUFFER], to[MAX_BUFFER];
	int c, i;
	
	/* input buffer */
	i = 0;
	while((i < MAX_BUFFER-1) && ((c=getchar()) != EOF)) {
		buffer[i] = c;
		++i;
	}
	buffer[i] = '\0';
	
	/* function call */
	uncomment(buffer);
	printf("%s", buffer);
	
	return 0;
}

/* copy: copies the string 'from' to 'to' */
void copy(const char *from, char *to)
{
	int i;
	char c;
	
	for(i = 0; from[i] != '\0'; ++i)
		to[i] = from[i];
	to[i] = '\0';
}

enum states { OUT, COMMENT, STRING };

/* uncomment: removes all comments from the buffer */
void uncomment(char *buffer)
{
	void copy(const char *from, char *to);
	char new_buffer[MAX_BUFFER];
	int i, j, state;
	char c;

	state = OUT;
	for(i=0, j=0; (c=buffer[i]) != '\0'; i++) {
		switch (c) {
			/* handling comments */
			case '/':
				if(state == OUT && buffer[i+1] == '*')
					state = COMMENT;
				break;
			case '*':
				if(state == COMMENT && buffer[i+1] == '/') {
					state = OUT;
					++i;
					continue;
				}
				break;

			/* handling strings */
			case '"':
				if(state == OUT)
					state = STRING;
				else if(state == STRING)
					state = OUT;
				break;

			default:
				break;
		}

		if(state != COMMENT)
			new_buffer[j++] = c;
	}
	new_buffer[j] = '\0';

	copy(new_buffer, buffer);

	return;
}
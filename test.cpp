#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main()
{
	char* sentence;
	int count;
	printf("\aEnter your sentence:\n");
	input(&sentence, stdin, '\n');
	printf("Your sentence three times:\n");
	for (count = 0; count < 3; count++)
		printf("%s\n", sentence);
	free(sentence);
	return 0;
}
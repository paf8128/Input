#include <stdio.h>
#include <stdlib.h>
#include "input.h"

static struct strnode {
	char ch;
	struct strnode* next;
};
typedef struct strnode StrNode;

static struct string {
	StrNode* root;
	unsigned int length;
};
typedef struct string String;

void input(char** pstr, FILE* fp, char stop)
{
	String str;
	char tch;
	unsigned int count;
	str.root = NULL;
	str.length = 0;
	StrNode* scan = NULL, * tnode = NULL;
	while ((tch = getc(fp)) != stop && tch != EOF) {
		if (str.length == 0) {
			str.root = (StrNode*)malloc(sizeof(StrNode));
			if (str.root == NULL)
				exit(EXIT_FAILURE);
			scan = str.root;
		}
		else {
			scan->next = (StrNode*)malloc(sizeof(StrNode));
			if (scan->next == NULL)
				exit(EXIT_FAILURE);
			scan = scan->next;
		}
		scan->ch = tch;
		scan->next = NULL;
		str.length++;
	}
	*pstr = (char*)malloc((str.length + 1) * sizeof(char));
	if (*pstr == NULL)
		exit(EXIT_FAILURE);
	for (scan = str.root, count = 0; count < str.length; count++, scan = tnode) {
		(*pstr)[count] = scan->ch;
		tnode = scan->next;
		free(scan);
	}
	(*pstr)[str.length] = '\0';
}

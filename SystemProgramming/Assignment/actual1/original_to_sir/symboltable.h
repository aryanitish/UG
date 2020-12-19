#include <stdlib.h>
#define NMSYM 100
struct symtab{
	char *name;
	int **matrixptr;
	int *locationInMatrix;
}Symtab[NMSYM];

struct symbtab *symlook(char *);

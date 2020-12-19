#define NMSYM 100
struct symtab{
	char *name;
	int **matrixptr;
	int *locationInMatrix;
}symtab[NMSYM];

struct symtab *symlook();


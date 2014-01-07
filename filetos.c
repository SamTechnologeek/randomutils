#include <stdio.h>
#include <stdlib.h>

char *filetos(const char *filename)
{
	FILE *file = NULL;
	static char contents[4096]; /* OK for file size. */
	long filesize;

	file = fopen(filename, "r");
	if (file == NULL) return NULL;
	fseek(file, 0L, SEEK_END); /* get file size */
	filesize = ftell(file);
	rewind(file);

	if (fread(contents, filesize, 1, file) != 1) {
		fclose(file);
		return NULL;
	}

	fclose(file);
	return contents;
}

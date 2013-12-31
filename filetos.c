#include <stdio.h>
#include <stdlib.h>

/* remember to free the returned string */
char *filetos(const char *filename)
{
	FILE *file = NULL;
	char *contents = NULL;
	char line[500]; /* max line size. OK for most files. */
	long filesize;

	file = fopen(filename, "r");
	if (file == NULL) return NULL;
	fseek(file, 0L, SEEK_END); /* get file size */
	filesize = ftell(file);
	rewind(file);
	/* we add 1 to fileSize for the null terminator '\0' */
	contents = malloc((filesize + 1) * sizeof (char)); 

	if (contents == NULL) {
		fclose(file);
		return NULL;
	}

	if (fread(contents, filesize, 1, file) != 1) {
		fclose(file);
		free(contents);
		return NULL;
	}

	fclose(file);
	return contents;
}

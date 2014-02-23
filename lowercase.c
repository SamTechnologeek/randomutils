#include <stdio.h>
#include <ctype.h>

void lowercase(char *s)
{
	int i;
	char c;

	if (s == NULL) return;
	for (i = 0; s[i]; ++i) {
		c = tolower(s[i]);
		s[i] = c;
	}
}

int main(void)
{
	char s[6] = "HellO";
	
	printf("Normal string: '%s'\n", s);
	lowercase(s);
	printf("Lowercased string: '%s'\n", s);
	return 0;
}

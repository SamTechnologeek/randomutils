#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* fuck you carmack */
char *replace(char *s, char *sub, char *rep)
{
	int slen;
	int sublen;
	int replen;
	int ocurr;
	int newstrlen;
	int i;
	char *pneedle;
	char *newstr;
	char tmp[200];

	if (s == NULL || sub == NULL || rep == NULL) return NULL;
	slen = strlen(s);
	sublen = strlen(sub);
	replen = strlen(rep);
	
	i = 0;
	for (ocurr = 0; (pneedle = strstr(s + i, sub)) != NULL; ++ocurr)
		i = (int) (pneedle - s) + sublen;

	newstrlen = slen + (ocurr * (replen - sublen));
	newstr = malloc(newstrlen * sizeof (char));

	if (newstr == NULL) return NULL;

	strcpy(newstr, s);
	i = 0;
	while ((pneedle = strstr(newstr + i, sub)) != NULL) {
		strcpy(tmp, pneedle + sublen);
		sprintf(newstr + (pneedle - newstr), "%s%s", rep,
			tmp);
		i = (int) (pneedle - newstr) + replen;
	}
	return newstr;
}

int main(void)
{
	char string[] = "(+ (+ 2 3) 8)";
	char *nstring;
	char *pstring = replace(string, "(", " ( ");
	nstring = replace(pstring, ")", " ) ");
	fprintf(stdout, "string: '%s' converted into string: '%s'\n",
		string, nstring);
	free(pstring);
	free(nstring);
	return 0;
}

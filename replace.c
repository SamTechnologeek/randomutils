#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *s, char *sub, char *rep)
{
	int sublen;
	int replen;
	int ocurr;
	int i;
	char *pneedle;
	static char newstr[1024]; /* OK for line size */
	char tmp[200];

	if (s == NULL || sub == NULL || rep == NULL) return NULL;
	sublen = strlen(sub);
	replen = strlen(rep);
	
	i = 0;
	for (ocurr = 0; (pneedle = strstr(s + i, sub)) != NULL; ++ocurr)
		i = (int) (pneedle - s) + sublen;

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

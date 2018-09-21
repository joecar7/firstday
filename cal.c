#include <stdio.h>

static char *dayname(int day)
{
	static char *name[] = {
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};
	return name[day];
}

static int firstday(int year)
{
	year--;
	return (1 + year + year/4 - year/100 + year/400 - year/4000) % 7;
}

int main(int argc, char **argv)
{
	while (*++argv)
		printf("%s starts on %s\n", *argv,
			dayname(firstday(strtol(*argv, NULL, 10))));
	return 0;
}

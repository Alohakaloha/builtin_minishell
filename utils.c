#include "builtin.h"

/*
@compare string returns 1 if the first string is smaller than the second one
	else 0 in case of same string or -1 if it is smaller
 */
int	compare_str(const char *st1, const char *st2)
{
	size_t	i;

	i = 0;
	while(st1[i])
	{
		if(!st2[i])
			return (1);
		if(st1[i] > st2[i])
			return (1);
		else if(st1[i] < st2[i])
			return (-1);
		else
			i++;
	}
	if (!st1[i] && st2[i])
		return (-1);
	return (0);
}

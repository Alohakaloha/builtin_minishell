#include "builtin.h"

void	free_env(t_env **list)
{
	t_env	*head;
	t_env	*tmp;

	head = *list;
	while (head != NULL)
	{
		free((t_env *)head->env_str);
		tmp = head;
		head = head->next;
		free_splits(tmp->var);
		free(tmp);
	}
	free(head);
}

void	free_splits(char **splits)
{
	int i = 0 ;

	while(splits[i])
	{
		free(splits[i]);
		i++;
	}
	free (splits);
}

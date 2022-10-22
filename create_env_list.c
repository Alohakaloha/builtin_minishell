#include "builtin.h"

/* last element of the list */
struct s_env	*last_node(t_env *head)
{
	t_env	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	add_to_end(t_env **list, t_env *new)
{
	t_env	*n;

	if (*list)
	{
		n = last_node(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

/* printf to show the VALUE of the VARIABLE of the list.
should be removed, when no testing is needed. */
t_env *new_env_node(char *string)
{
	t_env	*new_env;
	
	new_env= (t_env *)malloc(sizeof(*new_env));
	new_env->env_str = ft_strdup(string);
	new_env->var = ft_split(string, '=');
/* 	if(new_env->var[1])
		printf("Value found in %s\n",new_env->var[0]); */
	new_env->check = 0;
	new_env->next = NULL;
	return (new_env);
}

void	create_env_list(t_env	**env_list, char **envp)
{
	int		index;
	t_env 	*element;

	index = 0;
	while (envp[index])
	{
		element = new_env_node(envp[index]);
		add_to_end(env_list, element);
		index++;
	}
}

/*
Following the bash behavior variables from the environmental variables
are only being printed when they have value.
e.g. :"ZZ=..."
It can happen, that export can add a variable without value.
In this case export shows the variable but the bash cmd ENV doesn't.
*/
void	print_env(t_env *head)
{
	t_env *tmp;

	tmp = head;
	printf("\n\n\nenvironment_list\n\n\n");
	while (tmp != NULL)
	{
		if(tmp->var[0])
			printf("??? = %s\n", tmp->env_str);
		tmp = tmp->next;
	}
}
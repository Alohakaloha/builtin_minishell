#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "../../../libft/libft.h"

typedef struct s_env
{
	char			*env_str;
	char			**var;
	int				check;
	int				index;
	struct s_env	*next;
}	t_env;

t_env	*last_node(t_env *head);

void	add_to_end(t_env **list, t_env *new)
{
	t_env	*n;
	write(1, "Here", 4);
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

t_env	*last_node(t_env *head)
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

t_env *new_env_node(char *string)
{
	t_env	*new_env;

	new_env = malloc(sizeof(new_env));
	new_env->env_str = ft_strdup(string);
	new_env->var = ft_split(string, '=');
/* 	if(new_env->var[1])
		printf("Value found in %s\n",new_env->var[0]); */
	new_env->check = 0;
	new_env->next = NULL;
	return (new_env);
}

void	create_env_list(t_env **env, char **envp)
{
	int		index;
	t_env 	*element;

	index = 0;
	while (envp[index])
	{
			element = new_env_node(envp[index]);
			add_to_end(env, element);
			index++;
	}
}

void	print_env(t_env *head)
{
	t_env *tmp;

	tmp = head;
	printf("\n\n\nenvironment_list\n\n\n");
	while (tmp != NULL)
	{
		if(tmp->var[1])
			printf("??? = %s\n", tmp->env_str);
		tmp = tmp->next;
	}
}

void	export_add_arg(t_env **env_list, char *str)
{
	t_env *element;

	printf("We try to add this \n\n%s\n", str);

	element = new_env_node(str);
	add_to_end(env_list, element);
}

int main(int arg, char **argv, char **envp)
{
	t_env	*env;
	char	*str;


	create_env_list(&env, envp);
	export_add_arg(&env, "ZZ");
	print_env(env);
	return (0);
}
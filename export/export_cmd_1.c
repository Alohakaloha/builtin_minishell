#include "../builtin.h"

void export_add_arg(t_env **env_list, char *str)
{
	t_env *element;

	element = new_env_node(str);
	add_to_end(env_list, element);
}

/*
	We check if the argument is valid
	arguments that are allowed start with A-Z, a-z or '_'
*/
void export_arg(t_env *env_list, char **arg)
{
	int index;

	index = 0;
	while (arg[index])
	{
		if (arg[index][0] >= 'A' && arg[index][0] <= 'Z')
			export_add_arg(&env_list, arg[index]);
		else if (arg[index][0] >= 'a' && arg[index][0] <= 'z')
			export_add_arg(&env_list, arg[index]);
		else if (arg[index][0] == '_')
			export_add_arg(&env_list, arg[index]);
		else
			printf("export: `%s' not a valid identifier\n", arg[index]);
		index++;
	}
}

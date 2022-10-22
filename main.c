#include "builtin.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env_list;

	if (argc > 1)
		printf("Just testing %s doesn't need it rn", argv[0]);
	create_env_list(&env_list, envp);
	print_env(env_list);
	export_no_arg(env_list);
	free_env(&env_list);
	return (0);
}

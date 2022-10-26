#include "builtin.h"

int main(int argc, char **argv, char **envp)
{
	t_env *env_list;
	char **cmd;

	env_list = NULL;
	if (argc != 2)
		return (0);
	cmd = ft_split(argv[1], ' ');

	create_env_list(&env_list, envp);
	export_arg(env_list, cmd);
//	print_env(env_list);
//	export_no_arg(env_list);
	cd_cmd("adad", env_list);
	free_env(env_list);
	return (0);
}

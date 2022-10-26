#include "../builtin.h"

void	print_stderror(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(2,&str[i],1);
		i++;
	}
}

void	change_pwd(char *path, t_env **env_list, char *directory)
{
	t_env	*current;

	current = *env_list;
	printf("Path:\n%s", path);
	while(current && compare_str(current->var[0], "PWD"))
		current = current->next;
	if (compare_str(current->var[0], "PWD") == 0)
	{
		printf("The found string is\n %s\n",current->env_str);
		if(current->var[1][0] != '\0')
			free(current->var[1]);
		current->var[1] = ft_strdup(directory);
	}
	printf("The changed value of pwd is:\n %s", current->var[1]);
}

void	cd_cmd(char	*path, t_env *env_list)
{
	char	directory[PATH_MAX];

	if (chdir(path) == 0)
	{
		printf("successfully changed directory to:\n%s\n", getcwd(directory, sizeof(directory)));
		change_pwd(path, &env_list, directory);
	}
	else
	{
		write(2, "cd: ", 4);
		print_stderror(path);
		write(2, ": ", 2);
		perror("");
	}
	return ;
}
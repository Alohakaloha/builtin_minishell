#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include "../../../libft/libft.h"

typedef struct s_env
{
	char			*env_str;
	char			**var;
	int				check;
	int				index;
	struct s_env	*next;
}	t_env;

/* libft_functions_please_delete when implemented */
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
void	env_list_test(char **envp);
/* ----------------------------- */

/*-----env,export && export_utils-----*/

/* environment variable list */
void	create_env_list(t_env	**env_list, char **envp);
t_env	*last_node(t_env *head);
t_env	*new_env_node(char *string);
int		find_char(const char *string, int character);
void	add_to_end(t_env **list, t_env *add);
void	print_env(t_env *head);
void	free_env(t_env *list);
void	free_splits(char **splits);

/* export aka sorted env */
void	export_no_arg(t_env *env);
void	export_arg(t_env *env_list, char **arg);
void	export_add_arg(t_env **env_list, char *str);
int		check_size(t_env *list);
int		compare_str(const char *st1, const char *st2);
void	add_index(t_env *env);
char	*unchecked_str(t_env *env, char	*biggest);
void	print_by_index(t_env *env);
void	reset_index(t_env *env);

/* Change-directory */
void	cd_cmd(char	*path, t_env *env_list);
/* Unset */
int	unset_cmd(char *argument, t_env **env);

#endif
#include "minishell.h"

char	*minishell_getenv(t_shell *shell, const char *name)
{
	t_env	*current;

	if (shell == NULL || name == NULL)
		return (NULL);
	current = shell->env_lines;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

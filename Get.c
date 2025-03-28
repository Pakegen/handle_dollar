setenv :

int	my_setenv(const char *name, const char *value, int overwrite)
{
	t_env	*curr;
	t_env	*new_var;
	int		name_len;

	if (!name || !value)
		return (-1);
	name_len = ft_strlen(name);
	curr = g_ms_state.internal_env;
	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			if (overwrite)
			{
				free(curr->value);
				curr->value = ft_strdup(value);
			}
			return (0);
		}
		curr = curr->next;
	}
	new_var = malloc(sizeof(t_env));
	if (!new_var)
		return (-1);
	new_var->name = ft_strdup(name);
	new_var->value = ft_strdup(value);
	new_var->next = g_ms_state.internal_env;
	g_ms_state.internal_env = new_var;
	return (0);
}

getpid :

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

pid_t	my_getpid(void)
{
	int		fd;
	char	buf[64];
	ssize_t	n;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd < 0)
		return (-1);
	n = read(fd, buf, sizeof(buf) - 1);
	close(fd);
	if (n <= 0)
		return (-1);
	buf[n] = '\0';
	return ((pid_t)atoi(buf));
}


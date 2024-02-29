#include "shell.h"

/**
 * get_full_path - gets the full path of a command
 * @cmd: command
 *
 * Return: full path of the command
 */

char *get_full_path(char *cmd)
{
	char *p = NULL, **directories = NULL, *cpy = cmd, *ret = NULL;
	int i = 0;
	struct stat status;

	p = _get_env_var("PATH");
	directories = _get_env_dir(p);
	ret = malloc(sizeof(char) * MAX_ARGS_SIZE);
	if (!ret)
	{
		free(directories);
		return (NULL);
	}
	while (directories[i])
	{
		ret[0] = '\0';
		_strcat(ret, directories[i]);
		_strcat(ret, "/");
		_strcat(ret, cpy);
		if (stat(ret, &status) == 0)
		{
			free(directories);
			return (ret);
		}
		i++;
	}
	free(directories);
	free(ret);
	return (NULL);
}

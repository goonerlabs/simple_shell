#include "shell.h"

/**
 * create_alias - function to create a new alias
 * @alias_list: array of aliases
 * @name: alias name
 * @value: value to be stored
 */

void create_alias(Alias **alias_list, char *name, char *value)
{
	Alias *new_alias = NULL;

	new_alias = (Alias *)_malloc(sizeof(Alias));

	_strcpy(new_alias->name, name);
	_strcpy(new_alias->value, value);

	new_alias->next = *alias_list;
	*alias_list = new_alias;
	free(new_alias);
}

/**
 * delete_alias - Function to remove an alias from the list
 * @name: alias name to be deleted
 */

void delete_alias(char *name)
{
	Alias *alias_list = NULL;
	Alias *present = alias_list, *previous = NULL;

	while (present != NULL)
	{
		if (_strcmp(present->name, name) == 0)
		{
			if (previous != NULL)
				previous->next = present->next;
			else
				alias_list = present->next;
			free(present);
			return;
		}
		previous = present;
		present = present->next;
	}
	print_string("Alias ");
	print_string(name);
	print_string(" not found\n");
}

/**
 * change_alias_value - Function to find an alias and change its value
 * @command: alias name
 * Return: found alias
 */

char *change_alias_value(char *command)
{
	Alias *alias_list = NULL;
	Alias *present = alias_list;
	char *found_alias = NULL;
	size_t length = 0;

	while (present != NULL)
	{
		if (_strncmp(command, present->name, _strlen(present->name)) == 0)
		{
			length = _strlen(command) + _strlen(present->value);
			length = length - _strlen(present->name);
			found_alias = (char *)_malloc(length + 1);
			_strcpy(found_alias, present->value);
			_strcat(found_alias, command + _strlen(present->name));

			return (found_alias);
		}
		present = present->next;
	}
	free(found_alias);
	return (NULL);
}

/**
 * get_list - Function to get the list of aliases
 * @alias_list: alias list
 */

void get_list(Alias *alias_list)
{
	Alias *current = alias_list;

	if (current == NULL)
		return;

	while (current != NULL)
	{
		print_string("Alias: ");
		print_string(current->name);
		print_string(current->value);
		print_string("\n");

		current = current->next;
	}
}

/**
 * free_memory - Function to free the memory used by the alias list
 * @alias_list: alias list
 */

void free_memory(Alias *alias_list)
{
	Alias *temp = NULL;

	while (alias_list != NULL)
	{
		temp = alias_list;
		alias_list = alias_list->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}

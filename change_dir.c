#include "shell.h"
/**
 * change_dir - changes directory
 * @dir: directory to move to
 * Return: nothing;
 */

void change_dir(char *dir)
{
	char c_dir[256];
	static char p_dir[256];
	int dir_check;
	char *dash = "-";

	if (getcwd(c_dir, sizeof(c_dir)) == NULL)
	{
		perror("Error");
		return;
	}
	if (dir == NULL)
	{
		dir = getenv("HOME");
	}
	if (dir == dash)
	{
		dir = p_dir;
	}
	dir_check = chdir(dir);
	if (dir_check != 0)
	{
		perror("Error");
		return;
	}
	setenv("PWD", dir, 1);

	strcpy(p_dir, c_dir);

}

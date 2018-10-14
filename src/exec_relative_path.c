/*
** exec_relative_path.c for minishell in /home/costa_d/Documents/PSU/minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Mar 29 14:49:53 2016 Arnaud Costa
** Last update Tue Apr 12 23:05:33 2016 Arnaud Costa
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

int	exec_relative_path(char **cmd_tab, char **ae)
{
  int	pid;
  int	status;

  if (cmd_tab[0] == NULL || cmd_tab[0][0] == '\n' || cmd_tab[0][0] == '\0')
    return (-1);
  if (cmd_tab[0][0] == '.' || cmd_tab[0][0] == '/')
    {
      if ((access(cmd_tab[0], F_OK | X_OK)) == 0)
	{
	  pid = fork();
	  if (pid == 0)
	    execve(cmd_tab[0], cmd_tab, ae);
	  else
	    {
	      waitpid(pid, &status, 0);
	      if (status == 11 || status == 139 || status == SIGSEGV)
		my_putstr_error("Segmentation fault\n");
	      return (0);
	    }
	}
      else
	return (-1);
    }
  return (-1);
}

/*
** get_commande.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 10:50:06 2016 Arnaud Costa
** Last update Wed Apr 13 14:30:58 2016 Arnaud Costa
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

char	**get_commande()
{
  char	*commande;
  char	**commande_tab;

  my_prompt();
  commande = get_next_line(0);
  if (commande == NULL)
    exit(EXIT_SUCCESS);
  commande = epur_str(commande);
  commande = add_space(commande);
  commande = epur_str(commande);
  commande_tab = put_in_tab(commande, ' ');
  free(commande);
  return (commande_tab);
}

void	cpy_it(char *new_cmd, char *cmd, int *i, int *j)
{
  new_cmd[*j] = ' ';
  *j = *j + 1;
  new_cmd[*j] = cmd[*i];
  *j = *j + 1;
  new_cmd[*j] = ' ';
}

char	*add_space(char *cmd)
{
  int	i;
  int	j;
  char	*new_cmd;

  j = 0;
  i = 0;
  new_cmd = malloc(sizeof(char) * (my_strlen(cmd) + 1024));
  while (cmd[i])
    {
      if (cmd[i] == ';' && (cmd[i - 1] !=  ' ' || cmd[i + 1] != ' '))
	cpy_it(new_cmd, cmd, &i, &j);
      else if (cmd[i] == '|' && (cmd[i - 1] != ' ' || cmd[i + 1] != ' '))
	cpy_it(new_cmd, cmd, &i, &j);
      else if (cmd[i] == '>' && (cmd[i - 1] != ' ' || cmd[i + 1] != ' '))
        cpy_it(new_cmd, cmd, &i, &j);
      else
	new_cmd[j] = cmd[i];
      i++;
      j++;
    }
  new_cmd[j] = '\0';
  return (new_cmd);
}

void	my_prompt()
{
  write(0, PROMPT, my_strlen(PROMPT));
}

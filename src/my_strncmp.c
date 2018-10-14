/*
** my_strncmp.c for minishell2 in /home/costa_d/Documents/PSU/minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 31 13:44:04 2016 Arnaud Costa
** Last update Thu Apr 14 20:36:36 2016 Arnaud Costa
*/

#include "minishell.h"

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && i <= nb)
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (-1);
      i = i + 1;
    }
  return (0);
}

/*
** tools.c for minishell2 in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 10:26:09 2016 Arnaud Costa
** Last update Tue Apr  5 13:04:39 2016 Arnaud Costa
*/

#include <unistd.h>
#include "minishell.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i = i + 1;
    }
  return (0);
}

char	*epur_str(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
        {
          str[j] = str[i];
          j++;
          if (str[i + 1] == ' ' || str[i + 1] == '\t')
            {
              str[j] = ' ';
              j++;
            }
        }
    }
  str[j] = '\0';
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (str);
}

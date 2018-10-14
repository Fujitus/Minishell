/*
** my_strcpy.c for minishell in /home/costa_d/Documents/PSU/minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sat Apr  2 15:14:00 2016 Arnaud Costa
** Last update Tue Apr 12 22:03:54 2016 Arnaud Costa
*/

#include "minishell.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

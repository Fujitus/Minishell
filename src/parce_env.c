/*
** main.c for minishell2 in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 10:13:53 2016 Arnaud Costa
** Last update Thu Apr 14 20:36:12 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

char	*finde_path(char **ae)
{
  int	i;
  int	e;
  char	*path;

  i = 0;
  e = 0;
  while (ae[i] != '\0')
    {
      if (ae[i][0] == 'P' && ae[i][1] == 'A'
          && ae[i][2] == 'T' && ae[i][3] == 'H')
        {
          path = malloc(sizeof(char) * (my_strlen(ae[i]) + 1));
          if (path == NULL)
            return (NULL);
	  while (ae[i][e] != '\0')
	    {
	      path[e] = ae[i][e];
	      e++;
	    }
	  path[e] = '\0';
	  return (path);
	}
      i++;
    }
  return (NULL);
}

char	*finde_home(char **ae)
{
  int	i;
  int	e;
  char	*home;

  i = 0;
  e = 0;
  while (ae[i] != '\0')
    {
      if (ae[i][0] == 'H' && ae[i][1] == 'O'
          && ae[i][2] == 'M' && ae[i][3] == 'E')
        {
          home = malloc(my_strlen(ae[i]) + 1);
          if (home == NULL)
            return (NULL);
	  while (ae[i][e] != '\0')
	    {
	      home[e] = ae[i][e];
	      e++;
	    }
	  home[e] = '\0';
	  return (home);
	}
      i++;
    }
  return (NULL);
}

char	*epur_env(char *str)
{
  char	*epur_str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (str == NULL || ((epur_str = malloc(my_strlen(str))) == NULL))
    return (NULL);
  while (str[i] != '=')
    i++;
  i++;
  while (str[i] != '\0')
    {
      epur_str[j] = str[i];
      j++;
      i++;
    }
  epur_str[j] = '\0';
  return (epur_str);
}

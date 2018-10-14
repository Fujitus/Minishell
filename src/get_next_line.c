/*
** get_next_line.c for gnl in /home/costa_d/rendu/get_next_line/CPE_2015_getnextline
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sat Jan 16 16:05:18 2016 Arnaud Costa
** Last update Thu Apr 14 20:39:44 2016 Arnaud Costa
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	put_at_null(char *buffer, int k)
{
  int	i;

  i = 0;
  if (k == 0)
    {
      while (i <= READ_SIZE)
	{
	  buffer[i] = '\0';
	  i++;
	}
    }
  if (k == 1)
    {
      while (i < READ_SIZE)
	{
	  if (buffer[i] == '\n')
	    return (1);
	  i++;
	}
      return (0);
    }
  return (0);
}

char	*my_realloc(char *buffer, int size)
{
  char  *new_buffer;
  int   i;

  i = 0;
  if ((new_buffer = malloc(size)) == NULL)
    return (NULL);
  while (buffer[i] != '\0')
    {
      new_buffer[i] = buffer[i];
      i++;
    }
  while (i < size)
    {
      new_buffer[i] = '\0';
      i++;
    }
  free(buffer);
  return (new_buffer);
}

void	processing(char *buff_tmp, t_data *var, const int fd)
{
  while (var->ret_r > 0 && var->error == 0)
    {
      var->a = 0;
      var->nb += READ_SIZE;
      if (buff_tmp[0] == '\0')
	var->ret_r = read(fd, buff_tmp, READ_SIZE);
      while (buff_tmp[var->a] != '\n' && buff_tmp[var->a] != '\0')
	{
	  var->line[var->i] = buff_tmp[var->a];
	  var->a++;
	  var->i++;
	}
      if ((var->error = put_at_null(buff_tmp, 1)) == 0)
	var->line = my_realloc(var->line, var->nb + READ_SIZE);
      if (var->error == 0)
      put_at_null(buff_tmp, 0);
    }
}

void	clean_buff(char *buffer)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    i++;
  i += 1;
  while (buffer[i] != '\0')
    {
      buffer[a] = buffer[i];
      buffer[i] = '\0';
      i++;
      a++;
    }
  while (buffer[a] != '\0')
    {
      buffer[a] = '\0';
      a += 1;
    }
}

char	*get_next_line(const int fd)
{
  static char	*buff_tmp = NULL;
  t_data	var;

  var.i = 0;
  var.nb = READ_SIZE + 1;
  var.ret_r = 1;
  var.error = 0;
  if (buff_tmp == NULL)
    {
      if ((buff_tmp = malloc(READ_SIZE + 1)) == NULL)
	return (NULL);
      put_at_null(buff_tmp, 0);
    }
  var.line = malloc(READ_SIZE + 1);
  put_at_null(var.line, 0);
  if (fd == -1)
    return (NULL);
  processing(buff_tmp, &var, fd);
  clean_buff(buff_tmp);
  if ((var.ret_r == 0 && var.line[0] == '\0') || var.ret_r == -1)
    return (NULL);
  return (var.line);
}

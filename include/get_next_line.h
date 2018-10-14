/*
** get_next_line.h for gnl in /home/costa_d/rendu/get_next_line/CPE_2015_getnextline
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sat Jan 16 16:06:06 2016 Arnaud Costa
** Last update Tue Apr 12 23:08:29 2016 Arnaud Costa
*/

#ifndef GNL_H
# define GNL_H

typedef struct	s_data
{
  int	i;
  int	a;
  int	nb;
  int	error;
  int	ret_r;
  char	*line;
}		t_data;

#  ifndef READ_SIZE
#   define READ_SIZE 23
#endif /* !READ_SIZE */

char    *get_next_line(const int fd);
char	*my_realloc(char *buffer, int size);
int	put_at_null(char *buffer, int k);
void	processing(char *buff_tmp, t_data *var, const int fd);
void	clean_buff(char *buffer);

#endif /* !GNL_H */

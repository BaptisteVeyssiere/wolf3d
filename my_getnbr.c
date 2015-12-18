/*
** my_getnbr.c for my_getnbr.c in /home/VEYSSI_B/rendu/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec  2 22:43:56 2015 Baptiste veyssiere
** Last update Fri Dec 18 12:34:56 2015 Baptiste veyssiere
*/

#include "prototypes.h"

int	my_getnbr(const char *str)
{
  int	i;
  int	j;
  int	limit;
  int	nbr;

  i = 0;
  nbr = 0;
  limit = 0;
  if (str[0] == '-')
    limit = 1;
  while (str[i] != 0)
    i++;
  i--;
  j = 1;
  while (i >= limit)
    {
      nbr += j * (str[i--] - 48);
      j *= 10;
    }
  if (str[0] == '-')
    nbr *= -1;
  return (nbr);
}

void	double_filler(const char *str, int *i, double *nbr, double pow)
{
  while (str[*i] != 0)
    {
      if (str[*i] == '.')
        (*i)++;
      *nbr += (pow * (str[*i] - 48));
      pow /= 10;
      (*i)++;
    }
}

double		my_getdouble(const char *str)
{
  int		i;
  double	nbr;
  double	pow;
  int		limit;

  limit = 0;
  i = 0;
  nbr = 0;
  pow = 0;
  if (str[0] == '-')
    limit = 1;
  pow = 1;
  i = limit;
  while (str[i] != '.' && str[i++] != 0)
    pow *= 10;
  pow /= 10;
  i = limit;
  double_filler(str, &i, &nbr, pow);
  if (str[0] == '-')
    nbr *= -1;
  return (nbr);
}

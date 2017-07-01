/*
** requirement.c for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Jun 29 23:26:34 2017 Tamsi Besson
** Last update Sat Jul  1 14:43:46 2017 Tamsi Besson
*/

#include "calendar.h"

typedef struct  s_list
{
  void          *data;
  struct s_list *next;
}               t_list;

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (84);
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
        return (84);
      i++;
    }
  return (0);
}

void            my_revlist_synthesis(t_list **begin)
{
  t_list        *l;
  t_list        *temp;
  t_list        *temp_next;

  l = *begin;
  temp = 0;
  while (l->next)
    {
      temp_next = l->next;
      l->next = temp;
      temp = l;
      l = temp_next;
    }
  l->next = temp;
  *begin = l;
}

t_list  *my_findnodeeqinlist_synthesis(t_list *begin, void *data_ref,
				       int (*cmp)(char*, char*))
{
  while (begin != NULL)
    {
      if ((*cmp)(begin->data, data_ref) == 0)
        return (begin);
      begin = begin->next;
    }
  return (NULL);
}

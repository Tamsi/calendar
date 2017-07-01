/*
** employee_tools.c for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Sat Jul  1 15:35:08 2017 Tamsi Besson
** Last update Sat Jul  1 17:51:44 2017 Tamsi Besson
*/

#include "calendar.h"

void info_employees(char **tab, int i)
{
	if (strncmp(tab[i], "info_employees sortByName", 25) == 0)
    sort_by_name();
  if (strncmp(tab[i], "info_employees sortByZip", 24) == 0)
    sort_by_zip();
  if (strncmp(tab[i], "info_employees sortById", 23) == 0)
    sort_by_id();
  if (strncmp(tab[i], "info_employees sortByJob", 24) == 0)
    sort_by_zip();
}

void	invite(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  tab = my_str_to_wordtab(str, ' ');
  j = 0;
  while (meeting[j].zipcode)
  {
  	i = 1;
	  if (strcmp(tab[0], meeting[j].zipcode) == 0)
	  {
		  while (tab[i])
		    {
		    	k = 0;
		    	while (meeting[j].participants[k])
		    		k++;
		    	printf("::%s\n", tab[i]);
		    	meeting[j].participants[k] = tab[i];
		      i++;
		    }
	  }
	  j++;
	}
}


void	fire(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  tab = my_str_to_wordtab(str, ' ');
  i = 0;
  while (tab[i])
    {
      if (!tab[i + 1])
        tab[i][strlen(tab[i]) - 1] = '\0';
      j = 0;
      while (employee[j].zipcode)
        {
          k = 0;
          if (strcmp(tab[i], employee[j].zipcode) == 0)
            {
              while (employee[k].zipcode) k++;
              employee[j] = employee[k - 1];
              employee[k - 1] = employee[k];
            }
          j++;
        }
      i++;
    }
}

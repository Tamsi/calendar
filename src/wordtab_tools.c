/*
** wordtab_tools.c for  in /home/tbesson/Piscine_synthese/ABM_SBMLparser_2016/src
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Tue Jun 13 15:20:42 2017 Tamsi Besson
** Last update Tue Jun 13 15:20:57 2017 Tamsi Besson
*/

int check_alphanum(char c)
{
  if ((c < '0' || c > '9')
      && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
    return (1);
  return (0);
}

int word_count(char *str)
{
  int   i;
  int   cpt;
  char  car_prec;

  i = 0;
  cpt = 0;
  car_prec = str[i];
  while (str[i] != '\0')
    {
      if (check_alphanum(car_prec) == 1 && check_alphanum(str[i]) == 0)
        cpt++;
      car_prec = str[i];
      i++;
    }
  return (cpt);
}

int count(char *str, int debut)
{
  int   i;

  i = 0;
  while (check_alphanum(str[debut]) == 0 && (str[debut] != '\0'))
    {
      debut++;
      i++;
    }
  return (i);
}

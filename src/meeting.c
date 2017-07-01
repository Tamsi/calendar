/*
** meeting.c for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Sat Jul  1 14:47:10 2017 Tamsi Besson
** Last update Sat Jul  1 22:57:34 2017 Tamsi Besson
*/

#include "calendar.h"

void    disp_meeting()
{
  int   i;
  int   j;

  i = 0;
  while (meeting[i].place)
    {
      j = 0;
      printf("*\nMEETING\ndate: %s\n", meeting[i].date);
      printf("place: %s\nwith ", meeting[i].place);
      while (meeting[i].participants[j])
      {
        if (j > 0)
          printf(", ");
        printf("%s", meeting[i].participants[j++]);
      }
      printf("\n");
      i++;
    }
}

void            sort_meeting_by_id()
{
  int           i;
  int           j;
  t_meeting     temp;

  i = 0;
  while (meeting[i].place)
    {
      j = 0;
      while (meeting[j + 1].place)
        {
          if (strcmp(meeting[j].place, meeting[j + 1].place) > 0)
            {
              temp = meeting[j];
              meeting[j] = meeting[j + 1];
              meeting[j + 1] = temp;
            }
          j++;
        }
      i++;
    }
}

void    sort_meeting_by_zip()
{
  int   i;
  int   j;
  t_meeting temp;

  i = 0;
  while (meeting[i].zipcode)
    {
      j = 0;
      while (meeting[j + 1].zipcode)
  {
    if (strcmp(meeting[j].zipcode, meeting[j + 1].zipcode) > 0)
      {
        temp = meeting[j];
        meeting[j] = meeting[j + 1];
        meeting[j + 1] = temp;
      }
    j++;
  }
      i++;
    }
}

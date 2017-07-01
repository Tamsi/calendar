/*
** calendar.h for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri Jun 30 11:33:28 2017 Tamsi Besson
** Last update Sat Jul  1 17:34:53 2017 Tamsi Besson
*/

#ifndef CALENDAR_H_
# define CALENDAR_H_

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_employee
{
  char		*last_name;
  char		*first_name;
  char		*position;
  char		*id;
  char		*zipcode;
}		t_employee;

typedef struct	s_meeting
{
  char		*place;
  char		*date;
  char		*zipcode;
  char		**participants;
}		t_meeting;

extern t_employee employee[];
extern t_meeting meeting[];

char    **my_str_to_wordtab(char *, char);
int    	word_count(char *);
void	sort_by_name();
void	filler_emp(char **);
void	filler_meet(char **);
void	disp_employee();
void    sort_by_zip();
void    sort_by_job();
void    sort_by_id();
void    disp_meeting();
void		sort_meeting_by_id();
void    sort_meeting_by_zip();
void info_employees(char **, int);
void fire(char *);
void	invite(char *str);

#endif /*CALENDAR_H_*/

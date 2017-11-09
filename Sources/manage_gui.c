/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_gui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:44 by ahamouda          #+#    #+#             */
/*   Updated: 2017/11/08 17:04:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void					create_gui(void)
{
	int	x;
	int	y;

	setlocale(LC_ALL, "");
	y = 0;
	x = 0;
	//TODO : Check screen size. if not big enough, exit with a pretty error msg
	initscr();
	getmaxyx(stdscr, y, x);
	if (x < 200 && y < 50 && !DISABLE_WARNING)
	{
		endwin();
		ft_printf_fd(2, "You need a window of 200/50pxl.x[%d]y[%d]\n",x, y);
		exit(-1);
	}
	noecho();
	nodelay(stdscr,TRUE);
	cbreak();
	keypad(stdscr, TRUE);
}

static t_philosopher	*get_philo_through_number(unsigned int i)
{
	t_philosopher		*philo;

	philo = g_data->philosophers;
	while (1)
	{

		if (philo->number == i)
			return (philo);
		philo = philo->left;
	}
}

static void				display_gui_info(t_philosopher *philo, unsigned int i)
{
	if (i == 0)
		printw("# : %d", philo->number);
	else if (i == 1)
	printw("%C : %d", 128149, philo->health_point);
	else if (i == 2)
	{
		if (philo->is_eating)
			printw("%C (%C %d)", 127834, 128336, philo->time_left_action);
		if (philo->is_resting)
			printw("%C (%C %d)", 128164, 128336, philo->time_left_action);
		if (philo->is_thinking)
			printw("%C (%C %d)", 8263, 128336, philo->time_left_action);
	}
//	else if (i == 3)
	
	if (philo->left != g_data->philosophers)
		printw("\t\t");
	else
		printw("\n");
}

static void				display_gui(void)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i <= 3) // number hp // action 
	{
		j = 0;
		while (j < 7)
			display_gui_info(get_philo_through_number(j++ + 1), i);
		i++;
	}
	/*
	printw("%C\n", 128566); // hp 
	printw("%C\n", 128336); // clock
	printw("%C\n", 128150); // sparkling heart 
	printw("%C\n", 128149); // double
	printw("%C\n", 128156);
	printw("%C\n", 127834); // rice
	printw("%C\n", 128148); // dead
	printw("|||||||%C\n", 8214); // chopsticks
*/}

void					refresh_gui(void)
{
	static int k = 0;
	int c;

	c = 0;
	clear(); // TODO : Add screenclear to libftprintf define
	display_gui();
	refresh();
	c = getch();
	if (c > -1)
		printw("k = %d c = %d \n", k++, c);
	else
		printw("k = %d\n", k++);
}

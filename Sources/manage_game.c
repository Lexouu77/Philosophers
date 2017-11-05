/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:33:29 by ahamouda          #+#    #+#             */
/*   Updated: 2017/11/05 18:44:54 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned int	check_exit_condition(void)
{
//	ft_putstr("Turn : ");
//	ft_putnbr((int)(time(0) - g_data->start_time));
//	ft_putstr("\n");
	if ((time(0) - g_data->start_time) >= g_data->timeout_time)
		return (1);
	if (!g_data->all_alive)
		return (2);
	return (0);
}

static void			decay_health_point(void)
{
	t_philosopher	*philosophers;

	philosophers = g_data->philosophers;
	if (--philosophers->health_point <= 0)
		g_data->all_alive = 0;
	flockfile(stdout);
	ft_printf("hp : %d | ", philosophers->health_point);
	philosophers = philosophers->left;
	while (philosophers != g_data->philosophers)
	{
		if (--philosophers->health_point <= 0)
			g_data->all_alive = 0;
		if (philosophers->left == g_data->philosophers)
			ft_printf("%d\n", philosophers->health_point);
		else
			ft_printf("%d | ", philosophers->health_point);
		philosophers = philosophers->left;
	}
	funlockfile(stdout);
}

static void			reset_turn_token(void)
{
	static unsigned int	n_turn = 1;
	t_philosopher		*philo;

	philo = g_data->philosophers;
	philo->turn_token = 0;
	philo = philo->left;
	while (philo != g_data->philosophers)
	{
		philo->turn_token = 0;
		philo = philo->left;
	}
	flockfile(stdout);
	ft_printf("Tour numero %d\n", n_turn++);
	funlockfile(stdout);
}

static unsigned int	check_turn_token(void)
{
	t_philosopher		*philo;

	philo = g_data->philosophers;
	if (philo->turn_token == 0)
		return (1);
	philo = philo->left;
	while (philo != g_data->philosophers)
	{
		if (philo->turn_token == 0)
			return (1);
		philo = philo->left;
	}
	return (0);
}

void				*manage_game(void* nothing)
{
	unsigned int	exit_value;

	pthread_mutex_lock(&g_data->mutex);
//	ft_putstr("Locked!\n");
//	g_data->skip_turn = 1;
	g_data->start_time = time(0);
	(void)nothing;
	exit_value = 0;
//	printf("Setup lock\n");
	// create UI
	while (!exit_value)
	{
		// refresh UI
	//	exit_value = check_exit_condition(); // put it after decay_health_point if not needed to be called once when starting manage_game
		pthread_mutex_unlock(&g_data->mutex);
		pthread_mutex_lock(&g_data->mutex);
		if (check_turn_token())
			continue ;
		reset_turn_token();
		usleep(1000000);
		decay_health_point();
		exit_value = check_exit_condition();
	}
	g_data->exit_value = exit_value;
	pthread_mutex_unlock(&g_data->mutex);
//	printf("end of manage_game\n");
	return (0);
}

/*
** exit_value:
** 0 Keep Playing
** 1 Timeout Exit
** 2 Death Exit
*/

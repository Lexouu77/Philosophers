/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:38:51 by ahamouda          #+#    #+#             */
/*   Updated: 2017/11/05 18:44:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#define CHS philo->is_chopsticks_available
#define CHL philo->left->is_chopsticks_available
#define CHR philo->right->is_chopsticks_available

/*
** chopsticks self/right/left
*/

static t_philosopher	*get_philo(void)
{
	static unsigned int	i = 0;
	t_philosopher		*philo;
	unsigned int		k;

	k = 0;
	philo = g_data->philosophers;
	while (k != i)
	{
		philo = philo->left;
			k++;
	}
	i++;
	return (philo);
}

static void				keep_waiting(t_philosopher *philo)
{
	if (!--philo->time_left_action)
	{
		if (philo->is_resting)
			philo->is_resting = 0;
		else if (philo->is_eating)
		{
			philo->is_eating = 0;
			philo->health_point = g_data->max_life;
			philo->is_resting = 1;
			philo->time_left_action = g_data->rest_time;
			philo->is_chopsticks_available = 1;
			if (philo->borrowed_chopsticks == 1)
				philo->left->is_chopsticks_available = 1;
			else
				philo->right->is_chopsticks_available = 1;
			philo->borrowed_chopsticks = 0;
		}
		else
		{
			philo->is_thinking = 0;
			if (philo->thinking_theft)
				philo->thinking_theft = 0;
		}
	}
}

static void				start_eating(t_philosopher *philo)
{
	philo->is_eating = 1;
	philo->is_chopsticks_available = 0;
	if (CHL)
	{
		CHL = 0;
		if (philo->left->is_thinking)
			philo->left->thinking_theft = 1;
		philo->borrowed_chopsticks = 1;
	}
	else
	{
		CHR = 0;
		if (philo->right->is_thinking)
			philo->right->thinking_theft = 1;
		philo->borrowed_chopsticks = 2;
	}
	philo->time_left_action = g_data->eat_time;
}

/*
** borrowing left chopsticks as default.
*/

static void				play_turn(t_philosopher *philo)
{
	philo->turn_token = 1;
	if (philo->is_eating || philo->is_resting || philo->is_thinking)
	{
		keep_waiting(philo);
		return ;
	}
	if (CHS && (CHL || CHR))
	{
		start_eating(philo);
		return ;
	}
	philo->is_thinking = 1;
	philo->time_left_action = g_data->think_time;
}

void					*play_game(void* nothing)
{
	t_philosopher *philo;

	(void)nothing;
	pthread_mutex_lock(&g_data->mutex);
	philo = get_philo();
	flockfile(stdout);
	ft_printf("Philo n %d\n", philo->number);
	funlockfile(stdout);
	while (1)
	{
		pthread_mutex_unlock(&g_data->mutex);
		pthread_mutex_lock(&g_data->mutex);
		if (philo->turn_token)
			continue ;
		if (g_data->exit_value) // check exit_possibility
			break ;
		play_turn(philo);
	}
	pthread_mutex_unlock(&g_data->mutex);
	return (NULL);
}

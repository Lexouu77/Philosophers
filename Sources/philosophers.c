/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:52:25 by ahamouda          #+#    #+#             */
/*   Updated: 2017/11/05 18:44:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//t_data*g_data = NULL;
//
//pthread_mutex_t	g_mutex;

t_data	*g_data;
/*
static void	display_start(void)
{
	ft_printf_hidden("Do you want to edit MAX_LIFE EAT_T REST_T THINK_T and");
	ft_printf_hidden(" TIMEOUT values?[Default: %[[FG_BLU]d ", MAX_LIFE);
	ft_printf_hidden("%[[FG_BLU]d %[[FG_BLU]d", EAT_T, REST_T);
	ft_printf_hidden("%[[FG_BLU]d %[[FG_BLU,SP_RST]d] (y/n)\n",
			THINK_T, TIMEOUT);
	ft_printf(NULL);
}

static void	*thread_1(void *arg)
{
	(void)arg;
	printf("It's a thread\n");
	pthread_mutex_lock(&g_data.mutex);
	usleep(5000000);
	g_data.eat_t++;
	printf("Locked !(eat_t = %d)\n", g_data.eat_t);
	pthread_mutex_unlock(&g_data.mutex);
	printf("End of thread \n");
	return(0);
}

static int	check_def_values(void)
{
	if (EAT_T > MAX_LIFE)
		ft_printf("Warning, EAT_T (%d) is greater than MAX_LIFE (%d)", EAT_T,
				MAX_LIFE);
	else if (REST_T > MAX_LIFE)
		ft_printf("Warning, REST_T (%d) is greater than MAX_LIFE (%d)", REST_T,
				MAX_LIFE);
	else if (THINK_T > MAX_LIFE)
		ft_printf("Warning, THINK_T (%d) is greater than MAX_LIFE (%d)",
				THINK_T, MAX_LIFE);
	else
		return (0);
	ft_printf("\nEnd of program.\n");
	return (1);
}*/

static void	queue_philosopher(unsigned int i, t_philosopher *crazy_guy)
{
	t_philosopher	*crazy_party_planner;

	if (!g_data->philosophers)
		g_data->philosophers = crazy_guy;
	else
	{
		crazy_party_planner = g_data->philosophers;
		while (crazy_party_planner && crazy_party_planner->left)
			crazy_party_planner = crazy_party_planner->left;
		crazy_party_planner->left = crazy_guy;
		crazy_guy->right = crazy_party_planner;
		if (i == 7)
		{
			crazy_guy->left = g_data->philosophers;
			g_data->philosophers->right = crazy_guy;
		}
	}
}

static void	init_global_philosophers(void)
{
	unsigned int	i;
	t_philosopher	*crazy_guy;

	i = 0;
	if (!(g_data = ft_memalloc(sizeof(t_data))))
		MALLOC_ERROR;
	g_data->max_life = MAX_LIFE;
	g_data->eat_time = EAT_T;
	g_data->rest_time = REST_T;
	g_data->think_time = THINK_T;
	g_data->timeout_time = TIMEOUT;
	g_data->all_alive = 1;
	while (++i <= 7)
	{
		if (!(crazy_guy = ft_memalloc(sizeof(t_philosopher))))
			MALLOC_ERROR;
		crazy_guy->number = i;
		crazy_guy->is_chopsticks_available = 1;
		crazy_guy->health_point = g_data->max_life;
		queue_philosopher(i, crazy_guy);
	}
}

static void	kill_philosophers(void)
{
	t_philosopher	*to_kill;
	t_philosopher	*in_death_row;

	g_data->philosophers->right->left = 0;
	to_kill = g_data->philosophers;
	in_death_row = g_data->philosophers->left;
	ft_printf("Destroying mutex.\n");
	pthread_mutex_destroy(&g_data->mutex);
//	pthread_rwlock_destroy(&g_data->rw_lck);
	ft_printf("Free of managing thread.\n");
	pthread_detach(g_data->thread);
	while (to_kill)
	{
		ft_printf("Free of thread number : %d.\n", to_kill->number);
		pthread_detach(to_kill->thread);
		free(to_kill);
		if (!in_death_row)
			break ;
		to_kill = in_death_row;
		in_death_row = in_death_row->left;
	}
	free(g_data);
}

/*
** Kinda a bad while condition.. but w/e it's working. might rework it later.
*/

static void	create_thread(void)
{
	t_philosopher	*crazy_guy;

	ft_printf("Mutex initiation.\n");
	pthread_mutex_init(&g_data->mutex, PTHREAD_MUTEX_DEFAULT);
//	pthread_rwlock_init(&g_data->rw_lck, NULL);
	ft_printf("Creation of 1 managing thread and 7 others threads.\n");
	if (pthread_create(&g_data->thread, NULL, manage_game, NULL))
		exit(-1);
	crazy_guy = g_data->philosophers->left;
	while (crazy_guy != g_data->philosophers)
	{
		if (pthread_create(&crazy_guy->thread, NULL, play_game, NULL))
			exit(-1);
		crazy_guy = crazy_guy->left;
	}
	if (pthread_create(&crazy_guy->thread, NULL, play_game, NULL))
		exit(-1);
}

/*
** crazy_guy = g_data->philosophers
** while (crazy_guy != g_data->philosophers->right
** ???
*/

static void	wait_for_thread(void)
{
	t_philosopher	*crazy_guy;

	crazy_guy = g_data->philosophers->left;
	pthread_join(g_data->thread, NULL);
	while (crazy_guy != g_data->philosophers)
	{
		pthread_join(crazy_guy->thread, NULL);
		crazy_guy = crazy_guy->left;
	}
	pthread_join(crazy_guy->thread, NULL);
}

int			main(void)
{/*
//	time_t	now;
//	time_t	after;
	char*	l;

	g_data.eat_t = 0;
	l = 0;
	(void)argc;
	(void)argv;
	if (!DISABLE_WARNING && check_def_values())
		return (1);
	display_start();
	while (!l || (l && ft_strcmp(l, "n") && ft_strcmp(l, "y")))
	{
		if (get_next_line(0, &l) == -1)
		{
			free(l);
			exit(-1);
		}
		if (ft_strcmp(l, "n") && ft_strcmp(l, "y"))
		{
			ft_printf_hidden("Wrong answer, retry please.\n");
			ft_printf(0);
		}
	}
	free(l);
//	now=time(NULL);
//	usleep(1000000);
//	usleep(4000000);
//	ft_printf("RESULT : %d\n", time(NULL) - now);

	pthread_t	thread1;
	pthread_t	thread2;
	if (pthread_create(&thread1, NULL, thread_1, NULL)) // do a while
		exit(-1);
	if (pthread_create(&thread2, NULL, thread_1, NULL)) // do a while
		exit(-1);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_detach(thread1);
	pthread_detach(thread2);
	ft_printf("End of main\n");
//	check_decimal_values();
*/
//	time_t	now = time(0);
//	usleep(500000);
//	usleep(500000);
//	if (time(0) - now == 1)
	init_global_philosophers();
	create_thread();
	wait_for_thread();
	if (g_data->all_alive)
		printf("Now, it is time... To DAAAAAAAANCE !!!");
	kill_philosophers();
	return (0);
}

/*
** Check what to do
** Do action
** Lose hp unless if eating
** 
*/

/*
** TODO : Make another thread managing everything ?
*/

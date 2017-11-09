/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:52:29 by ahamouda          #+#    #+#             */
/*   Updated: 2017/11/08 17:04:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
//# include "ft_printf.h" //add philosophers_struct.h
# include "../lib42/includes/ft_printf.h"

# include <pthread.h>
# include <locale.h>

# define DISPLAY_PROGRAM_INFO 0

/*
** Explain what's the project about
*/

# define DISPLAY_WARNING 0

# define DISABLE_WARNING 1

# define MAX_LIFE 10
# define EAT_T 2 // roundup/down value.?
# define REST_T 3 // check hp and REST_T/EAT_T/THINK_T error if >  MAX_LIFE
# define THINK_T 2
# define TIMEOUT 60 // TODO : printf_fd si option
# define LOG_CURSES 0 // Affiche des choses dans un coin, i.e. getch value ? what's happenin in the game

typedef struct s_data t_data;
extern t_data *g_data;

typedef struct				s_philosopher
{
	pthread_t				thread;
	struct s_philosopher	*left;
	struct s_philosopher	*right;
	unsigned int			number;
	unsigned int			health_point;
	unsigned int			time_left_action; // int ?
	unsigned int			did_act_this_turn;
	char					is_eating;
	char					is_resting;
	char					is_thinking;
	char					is_chopsticks_available;
	unsigned int			turn_token;
	unsigned int			borrowed_chopsticks;
	unsigned int			thinking_theft;
//	unsigned int			padding;
}							t_philosopher;

/*
** left is next.
** right is prev.
** turn_token : 1 if played this turn, 0 if not.
** borrowed_chopsticks 1 for left 2 for right.
** Taking left as default if both of them are available.
*/

typedef struct				s_data
{
	pthread_t				thread;
	pthread_mutex_t			mutex;
//	pthread_rwlock_t		rw_lck; // maybe not ?
	struct s_philosopher	*philosophers;
	time_t					start_time;
	unsigned int			max_life;
	unsigned int			eat_time;
	unsigned int			rest_time;
	unsigned int			think_time;
	unsigned int			timeout_time;
	unsigned int			all_alive;
	unsigned int			exit_value;
//	unsigned int			skip_turn;
	unsigned int			padding;
}							t_data;

/*
** skip_turn of the 7 threads, needed to setup start_time.
** dance : 1 if all philosophers are alive after timeout seconds.
** ^ might not be needed, if not padding variable.
*/

void						*play_game(void*);
void						*manage_game(void*);
void						create_gui(void);
void						refresh_gui(void);

#endif

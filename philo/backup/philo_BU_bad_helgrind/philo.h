/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:38:54 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 13:38:33 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h> 		//to use uint64_t
# include <sys/time.h> 		// to use gettimeofday()
# include <unistd.h>
# include <limits.h>

# define EAT "is eating 🍝"
# define DIED "is dead 😵"
# define SLEEP "is sleeping 😴"
# define TAKE_FORKS "has taken a fork 🍴"
# define THINK "is thinking 🤔"

# define ERR 1

/* t_status enumeration saves all the possible states of a philosopher */
typedef enum s_status
{
	eat = 0,		//philosopher is eating
	asleep = 1,		//philosopher is sleeping
	think = 2,		//philosopher is thinking
	dead = 3,		// philosopher is dead
	full = 4,		// philosopher is full (no more eating)
	idle = 5		//philosopher is doing nothing
}	t_status;

/* t_philo saves information for each philosopher includes forks, state 
tracking, timing values, and mutexes. */
typedef struct s_philo
{
	int				id;
	t_status        status;
	pthread_t		thread;
	pthread_mutex_t	eating_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	uint64_t		last_meal_time;
	uint64_t		time_to_die;
	int				eat_count;
	struct s_data	*data;
}					t_philo;

/*main data structure, saves general information: philosopher tracking,
timing info, mutexes for thread sync, stop conditions */
typedef struct s_data
{
	int				num_philos;			// Total number of philosophers
    uint64_t        start_time;			// Simulation start time
	int				simulation_running;	// Flag to control simulation stopping
	int             dead;				// 1 if a philosopher died, 0 otherwise
    int             finished;			// Number of philosophers who finished eating
	uint64_t        time_to_die;		// Time limit before death
    uint64_t        time_to_eat;		// Time it takes to eat
    uint64_t        time_to_sleep;		// Time spent sleeping
	int				meals_required;		// Number of meals each philosopher must eat
	t_philo			*philo;
	pthread_t       *threads;			// Array of philosopher threads
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;

}					t_data;
/*
pthread_mutex_t and pthread_t are included in the <POSIX Threads> 
library (<pthreads>)
*/
/* ------- CLEANING -----------------------*/
void		free_partial_forks(t_data *data, int failed_index);
void		destroy_mutexes(t_data *data);
void		free_philosophers(t_data *data);
void		free_data(t_data *data);
void		close_adm(t_data *data, char *str);

/* ------- INITIALIZATION -----------------*/
int			init_philosophers(t_data *data);
int			init_data(t_data *data, char **av);

/* ------- MAIN ---------------------------*/
void		start_simulation(t_data *data);
int			create_threads(t_data *data, pthread_t *monitor);

/* ------- ROUTINE ------------------------*/
void		think_philo(t_philo *philo);
void		sleep_philo(t_philo *philo);
void		release_forks(t_philo *philo);
void		eat_philo(t_philo *philo);
void		take_forks(t_philo *philo);
void		*philosopher_routine(void *arg);
void		*check_death(void *arg);

/*-------- TOOLS --------------------------*/
void	print_msg(t_philo *philo, const char *msg);
long		ft_atol(const char *str);
uint64_t	get_time_ms(void);

/* ------- VALIDATION ---------------------*/
int			is_number(char *str);
int			is_valid_number(long num, int index);
int			check_numbers(int ac, char **av);
int			validate_input(int ac, char **av);

#endif
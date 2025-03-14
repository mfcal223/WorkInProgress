/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:38:54 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 15:32:49 by mcalciat         ###   ########.fr       */
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
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mut_last_eat; //eating_lock; //protects last_eat
	pthread_mutex_t	mut_num_meals;	// Protects `eat_count
	uint64_t		last_eat;//last_meal_time
	uint64_t		time_to_die;
	int				meals; //eat_count;
	struct s_data	*data;
}					t_philo;

/*main data structure, saves general information: philosopher tracking,
timing info, mutexes for thread sync, stop conditions */
typedef struct s_data
{
	int				num_philos;			// Total number of philosophers
    uint64_t        start_time;			// Simulation start time
	int				keep_iterating; //simulation_running;	// Flag to control simulation stopping
	int             dead;				// 1 if a philosopher died, 0 otherwise
    int             nb_full_p; //finished;			// Number of philosophers who finished eating
	uint64_t        time_to_die;		// Time limit before death
    uint64_t        time_to_eat;		// Time it takes to eat
    uint64_t        time_to_sleep;		// Time spent sleeping
	int				nb_meals; //meals_required;		// Number of meals each philosopher must eat
	t_philo			*philo;
	pthread_t       *philo_ths; //*threads;			// Array of philosopher threads
	pthread_mutex_t	*forks;				//for modifying fork status
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;			// for modifying the dead variable.
	pthread_mutex_t	mut_eat_t;			// Mutex for time to eat access
	pthread_mutex_t	mut_die_t;			// for reading time_to_die. - Mutex for time to die access
	pthread_mutex_t	mut_sleep_t;		// Mutex for time to sleep access

}					t_data;
/*
Do You Need Both?
Yes!

death_lock is necessary to synchronize the dead variable so that only one thread stops the simulation.
mut_die_t ensures that reading time_to_die doesn’t conflict with another thread modifying it.
*/
/* ------- CLEANING -----------------------*/
//void		free_partial_forks(t_data *data, int failed_index);
//void		destroy_mutexes(t_data *data);
void		free_philosophers(t_data *data);
void		free_data(t_data *data);
void		close_adm(t_data *data, char *str);

/* ------- INITIALIZATION -----------------*/
int			init_data_mutexes(t_data *data);
int			init_data(t_data *data, int ac, char **av);
int			init_forks(t_data *data);
int			init_philosophers(t_data *data);
int			init_admin(int ac, char **av);


/* ------- MAIN ---------------------------*/
//void		start_simulation(t_data *data);
//int			create_threads(t_data *data, pthread_t *monitor);

/* ------- ROUTINE ------------------------*/
/*void		think_philo(t_philo *philo);
void		sleep_philo(t_philo *philo);
void		release_forks(t_philo *philo);
void		eat_philo(t_philo *philo);
void		take_forks(t_philo *philo);
void		*philosopher_routine(void *arg);
void		*check_death(void *arg);*/

/*-------- TOOLS --------------------------*/
void		print_msg(t_philo *philo, const char *msg);
long		ft_atol(const char *str);
uint64_t	get_time_ms(void);

/* ------- VALIDATION ---------------------*/
int			is_number(char *str);
int			is_valid_number(long num, int index);
int			check_numbers(int ac, char **av);
int			validate_input(int ac, char **av);

#endif
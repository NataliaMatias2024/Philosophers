/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:14:19 by namatias          #+#    #+#             */
/*   Updated: 2026/03/23 02:26:30 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILOS 200
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define GRAY "\033[1;37m"

typedef struct s_philo
{
	pthread_t		thread_id; //cria a thread nova. Cada filosofo é uma thread
	long			id;		// identifica o filosofo que está fazendo a açao
	long			meals;    //ao atingir para o programa
	long long		last_meal_time; //guardar o tempo da ultima refeiçao (unica forma d morrer)
	long			is_dead; //flag que irá nos indicar se o filosofo morreu ou n
	struct s_info	*info; //informaçoes extras de acordo com o imput e init

	pthread_mutex_t	*left_fork; //fork será compartilhado por 2 filosofos, por isso cada um tera 2 ponteiros
	pthread_mutex_t	*right_fork; //alem disso como 1 garfo sera usado por 2 filosofos, temos q trava-lo
	pthread_mutex_t	philo_lock; //garante que informaçoes que o monitor terá que ler e checar ao mesmo tempo
								//q os filosofos podem altera-las fiqm protegidas para n dar data race					
} t_philo;

typedef struct	s_info
{
	long			numb_of_philo; //numero max nao pode passar de 200 TODO: Verificar no parse
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			numb_of_meals; //pode ser fornecido ou n
	long			stop; //só irá mudar quando o programa tiver q encerrar! (alguem morreu ou n d refeiçoes foi atindigo)

	long long		time_start; //guarda o tempo de quando iniciamos o programa

	pthread_t 		monitor; //criaremos um monitor para tds os philosofos, por isso chamamos ele apenas aqui

	t_philo			philo[MAX_PHILOS]; //irá guardar os ids das threads de cada filosofo no seu respectivo index
	pthread_mutex_t	forks[MAX_PHILOS]; //cria os garfos, 1 pra cada filosofovo, e os deixa disponivel p uso
	pthread_mutex_t	write_lock; //garante q os filosos n se atropelem na hora q escrever oq estao fazndo (dormindo, comendo, pensando, etc....)
	pthread_mutex_t	death_lock; //enquanto o monitor avisa que algum filosofo morreu, nenhum filosofo deve fazer mais nada
} t_info;

long long	current_time(void);
long long	exec_time(long long time_start);

int			check_args_number(int argc);
int			is_all_valid_numb(char *argv);
int			arg_is_valid(char **argv, int argc);

void		init_mutex_info(t_info *info);
void		init_forks_array(t_info *info);
void		init_struct_philo(t_info *info);
void		init_struct_info(t_info *info, char **argv);

void		mutex_destroy(t_info *info, int where, int limit);

void		*routine(void *arg);
long		keep_running(t_info *info);
void		print_action(t_philo *philo, int action);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:14:19 by namatias          #+#    #+#             */
/*   Updated: 2026/03/21 13:45:42 by namatias         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thread_id; //cria a thread nova. Cada filosofo é uma thread
	long			id;		// identifica o filosofo que está fazendo a açao
	long			meals;    //ao atingir para o programa
	long long		last_meal; //guardar o tempo da ultima refeiçao (unica forma d morrer)

	struct s_info	*info; //informaçoes extras de acordo com o imput e init
} t_philo;

typedef struct	s_info
{
	long	numb_of_philo; //numero max nao pode passar de 200 TODO: Verificar no parse
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	numb_of_meals; //pode ser fornecido ou n

	long long	time_start; //guarda o tempo de quando iniciamos o programa

} t_info;

long long	current_time(void);
int			check_args_number(int argc);
long long	exec_time(long long time_start);
int			arg_is_valid(char **argv, int argc);
void		init_structs(t_info *info, char **argv);

#endif

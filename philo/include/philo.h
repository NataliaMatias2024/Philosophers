/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:14:19 by namatias          #+#    #+#             */
/*   Updated: 2026/03/20 14:16:30 by namatias         ###   ########.fr       */
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
	pthread_t	thread_id; //cria a thread nova. Cada filosofo é uma thread 
	int			id;		// identifica o filosofo que está fazendo a açao
	int			meals;    //ao atingir para o programa
	long long	last_meal; //guardar o tempo da ultima refeiçao (unica forma d morrer)

	struct s_info	*info; //informaçoes extras de acordo com o imput e init
} t_philo;

typedef struct	s_info
{
	int numb_of_philo; //numero max nao pode passar de 200 TODO: Verificar no parse
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int numb_of_meals; //pode ser fornecido ou n

	long long	time_start; //guarda o tempo de quando iniciamos o programa

} t_info;

long long	current_time(void);
long long	exec_time(long long time_start);

#endif
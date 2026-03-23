/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:21:44 by namatias          #+#    #+#             */
/*   Updated: 2026/03/23 16:29:33 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_time(void)
{
	struct timeval	tv;
	long long		time_current;

	gettimeofday(&tv, NULL);
	time_current = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_current);
}

long long	exec_time(long long time_start)
{
	long long		time_current;
	long long		time_exec;

	time_current = current_time();
	time_exec = time_current - time_start;
	return (time_exec);
}

//o usleep garante o tempo minimo de espera, mas o tempo maximo pode ser imprevisivel
//nesse projeto td ocorre em milessegundos entao esse comportamento é arriscado
void	custom_usleep(long long time_to_wait, t_info *info)
{
	long long start_timer;
//isso consiste um criar uma funçao de espera customizada, com um usleep BEM menor que o tempo total q queremos
//assim ele fica verificando se alguem morreu ou atingiu o n de refeiçoes
//alem de garantir um delay menor que um usleep grande

	start_timer = current_time();
	while ((current_time() - start_timer) < time_to_wait)
	{
		if (keep_running(info))
			return ;
		usleep(500); //lembrar!! aqui está em MICROSSEGUNDO e nao em MS		
	}
}

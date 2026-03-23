/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:26:53 by namatias          #+#    #+#             */
/*   Updated: 2026/03/23 02:29:35 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	keep_running(t_info *info)
{
	long	run;

	pthread_mutex_lock(&info->death_lock); //O mutex interrompe qualquer thread q tenta acessar
										  //trava o recurso para protege-lo enquanto lemos
	run = info->stop; //enquanto for igual a 0, o programa continua rodando
	pthread_mutex_unlock(&info->death_lock); //O mutex libera o fluxo para outras threads q tentarem acessar
											//destrava o recurso para poder ser alterado pelos outros processos
	return (run);
}

void	print_action(t_philo *philo, int action)
{
	long long	time;

	pthread_mutex_lock(&philo->info->write_lock);
	time = exec_time(philo->info->time_start);
	// Se a simulação parou e NÃO for a mensagem de morte, não imprime nada
    if (keep_running(philo->info) != 0 && action != 5)
    {
        pthread_mutex_unlock(&philo->info->write_lock);
        return ;
    }
	if (action == 1)
		printf("%lld %ld %shas taken a fork%s\n", time, philo->id, GRAY, RESET);
	else if (action == 2)
		printf("%lld %ld %sis eating%s\n", time, philo->id, GREEN, RESET);
	else if (action == 3)
		printf("%lld %ld %sis sleeping%s\n", time, philo->id, BLUE, RESET);
	else if (action == 4)
		printf("%lld %ld %sis thinking%s\n", time, philo->id, GRAY, RESET);
	else if (action == 5)
		printf("%lld %ld %sdied%s\n", time, philo->id, RED, RESET);
	pthread_mutex_unlock(&philo->info->write_lock);
}
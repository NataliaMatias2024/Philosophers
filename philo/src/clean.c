/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:47:23 by namatias          #+#    #+#             */
/*   Updated: 2026/03/22 15:40:58 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy(t_info *info, int where, int limit)
{
	int	i;

	i = 0;
	if (where == 1)
	{
		//SE for chamada por erro na criaçao dos forks apaga td q existir
		while (i < info->numb_of_philo && i <= limit)
		{
			pthread_mutex_destroy(&info->forks[i]); //limpamos todos os forks criados na struct info
			i++;
		}
		pthread_mutex_destroy(&info->write_lock);
		pthread_mutex_destroy(&info->death_lock);
	}
	else if (where == 2)
	{
		//SE der erro na criaçao dos philos apaga tds os philos e os forks
		while (i < info->numb_of_philo && i <= limit)
		{
			pthread_mutex_destroy(&info->philo[i].philo_lock); //limpamos tds os locks criados na struct filo
			i++;
		}
		mutex_destroy(info, 1, info->numb_of_philo);
	}
}

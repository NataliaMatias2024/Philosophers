/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:06:23 by namatias          #+#    #+#             */
/*   Updated: 2026/03/24 00:56:56 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static void	stop_routine(t_info *info);
static int	check_numb_of_meals(t_info *info);
static int	check_death(t_philo *philo, t_info *info);

void	monitoring_routine(t_info *info)
{
	int	i;

	while (keep_running(info) == 0)
	{
		i = 0;
		//primeiro verificamos se alguem morreu
		while (i < info->numb_of_philo)
		{
			if (check_death(&info->philo[i], info) != 0)
			{
				stop_routine(info);
				return ; //essa linha que garante que nada mais aparecerá no terminal após a primeira morte
			}
			i++;
		}
		//SE ninguem tiver morrido verificamos SE existe um n_minimo de refeiçoes p/ encerrar
		if (info->numb_of_meals > 0)
		{
			//SE exisitr verificamos se alguem atingiu esse numero
			if (check_numb_of_meals(info) != 0)
				stop_routine(info);
		}
		usleep(500); //da uma pausa entre um ciclo de verificaçao e outro, assim n frita nossa CPU
	}
}

static int	check_death(t_philo *philo, t_info *info)
{
	long	fast;
	int		status;

	status = 0;
	//bloqueia o fluxo para n ocorrer data race
	pthread_mutex_lock(&philo->philo_lock);
	//a unica forma de morrer é por inaniçao
	//por isso temos que verificar a quanto tempo esse philo esta sem comer e comparar com o tempo passado no imput
	fast = current_time() - philo->last_meal_time;
	if (fast >= info->time_to_die)
	{
		//escrevemos no terminal a morte do philo
		print_action(philo, 5);
		//mudamos nossa flag para 1, assim todos saberao que é para encerrar a rotina
		philo->is_dead = 1;
		status = 1;
	}
	//desbloqueia para poderem escrever
	pthread_mutex_unlock(&philo->philo_lock);
	return (status);
}

static int	check_numb_of_meals(t_info *info)
{
	int		i;
	int		status;

	i = 0;
	status = 0;
	//aqui o objetivo é verificar se TODOS os filosofos atingiram o numero MINIMO de refeiçoes
	while (i < info->numb_of_philo)
	{
		//bloqueia o fluxo para n ocorrer data race
		pthread_mutex_lock(&info->philo[i].philo_lock);
		if (info->philo[i].meals < info->numb_of_meals)
		{
			pthread_mutex_unlock(&info->philo[i].philo_lock);
			return (status);
		}
		//desbloqueia para poderem escrever
		pthread_mutex_unlock(&info->philo[i].philo_lock);
		i++;
	}
	status = 1;
	return (status);
}

static void	stop_routine(t_info *info)
{
	//bloqueia o fluxo para n ocorrer data race
	pthread_mutex_lock(&info->death_lock);
	//mudamos nossa flag para 1, assim todos saberao que é para encerrar a rotina
	info->stop = 1;
	//desbloqueia para poderem escrever e ler
	pthread_mutex_unlock(&info->death_lock);
}

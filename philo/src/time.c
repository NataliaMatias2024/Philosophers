/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:21:44 by namatias          #+#    #+#             */
/*   Updated: 2026/03/20 14:31:26 by namatias         ###   ########.fr       */
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

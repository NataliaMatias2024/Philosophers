/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:26:22 by namatias          #+#    #+#             */
/*   Updated: 2026/03/20 14:36:38 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	long long time_start;
	long long time_current;

	time_current = 0;
	time_start = current_time();
	while(time_current < 10)
	{
		time_current = exec_time(time_start);
		printf ("%lld\n", time_current);
		usleep(700);
	}
}



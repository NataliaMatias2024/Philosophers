/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:26:22 by namatias          #+#    #+#             */
/*   Updated: 2026/03/24 00:56:53 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_struct_teste(t_info *info);

int	main(int argc, char **argv)
{
	t_info info;

	if (!check_args_number(argc))
	{
		arg_error();
		return (1);
	}
	else if (arg_is_valid(argv, argc))
	{
		init_struct_info(&info, argv);
		threads_philo_create(&info);
		monitoring_routine(&info);
		thread_wait(&info, info.numb_of_philo);
		mutex_destroy(&info, 1, info.numb_of_philo);
		print_struct_teste(&info);
	}
	return (0);
}


void print_struct_teste(t_info *info)
{
	int i;

	printf("Numero de filosofos: %ld\n", info->numb_of_philo);
	printf("Tempo para morrer: %ld\n", info->time_to_die);
	printf("Tempo para comer: %ld\n", info->time_to_eat);
	printf("Tempo para dormir: %ld\n", info->time_to_sleep);
	printf("Numero de refeições: %ld\n", info->numb_of_meals);

	if (info->numb_of_meals > 0)
	{
		i = 0;
		while (i < info->numb_of_philo)
		{
			printf("O filósofo %ld comeu %ld refeições\n", info->philo[i].id, info->philo[i].meals);
			i++;
		}
		
	}
}

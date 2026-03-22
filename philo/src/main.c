/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:26:22 by namatias          #+#    #+#             */
/*   Updated: 2026/03/22 15:35:07 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_struct_teste(t_info *info);

int	main(int argc, char **argv)
{
	// long long	time_start;
	// long long	time_current;
	t_info info;

	if (!check_args_number(argc))
		printf("Error: Wrong number of argument.\n");
	else if (arg_is_valid(argv, argc))
	{
		init_struct_info(&info, argv);
		print_struct_teste(&info);
		mutex_destroy(&info, 1, info.numb_of_philo);
		// time_current = 0;
		// time_start = current_time();
		// while(time_current < 10)
		// {
		// 	time_current = exec_time(time_start);
		// 	printf ("%lld\n", time_current);
		// 	usleep(700);
		// }
	}
	return (0);
}


void print_struct_teste(t_info *info)
{
	printf("Numero de filosofos: %ld\n", info->numb_of_philo);
		printf("Tempo para morrer: %ld\n", info->time_to_die);
			printf("Tempo para comer: %ld\n", info->time_to_eat);
				printf("Tempo para dormir: %ld\n", info->time_to_sleep);
					printf("Numero de refeições: %ld\n", info->numb_of_meals);
}

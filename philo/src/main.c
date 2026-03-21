/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:26:22 by namatias          #+#    #+#             */
/*   Updated: 2026/03/21 17:38:29 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_struct_teste(t_info *info);

int	main(int argc, char **argv)
{
	// long long	time_start;
	// long long	time_current;
	t_info info;

	if (check_args_number(argc) && arg_is_valid(argv, argc))
	{
		init_structs(&info, argv);
		print_struct_teste(&info);
		// time_current = 0;
		// time_start = current_time();
		// while(time_current < 10)
		// {
		// 	time_current = exec_time(time_start);
		// 	printf ("%lld\n", time_current);
		// 	usleep(700);
		// }
	}
	else
		write(STDERR_FILENO, "Error\n", 7);
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

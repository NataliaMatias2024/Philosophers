/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:57:59 by namatias          #+#    #+#             */
/*   Updated: 2026/03/21 21:59:44 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct_info(t_info *info, char **argv)//preenche nossa struct com as variaveis recebidas no imput
{
	info->numb_of_philo = is_all_valid_numb(argv[1]);
	info->time_to_die = is_all_valid_numb(argv[2]);
	info->time_to_eat = is_all_valid_numb(argv[3]);
	info->time_to_sleep = is_all_valid_numb(argv[4]);
	if (argv[5])
		info->numb_of_meals = is_all_valid_numb(argv[5]);
	else
		info->numb_of_meals = -1; //caso o usuário nao digite nada nesse campo o -1 nos permite saber que esse campo realmente nao foi preenchido,
								 // uma vez q usuario pode digitar 0
}

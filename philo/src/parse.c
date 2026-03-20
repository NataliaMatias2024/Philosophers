/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:21:37 by namatias          #+#    #+#             */
/*   Updated: 2026/03/20 16:41:42 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_all_valid_numb(char *argv);

int	check_args_number(int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	else
		return (0);
}

int	arg_is_valid(char **argv, int argc)
{
	int	i;

	i = 1;
	while (argv[i] && i < argc)
	{
		if (!is_all_valid_numb(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_all_valid_numb(char *argv)
{
	long	numb;
	int		i;

	i = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32) //verifica espaço em branco (man isspace)
		i++;
	if (argv[i] == '+') //verificamos se tem sinal, só iremos aceitar 1 sinal positivo
		i++;
	else if (argv[i] == '-')
		return (0); //nesse programa numeros negativos nao sao aceitos, por tanto encerra exec
	while (argv[i] >= '0' && argv[i] <= '9') //enquanto for digito convertemos
	{
		
	}
}
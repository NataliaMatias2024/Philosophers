/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:21:37 by namatias          #+#    #+#             */
/*   Updated: 2026/03/21 21:45:42 by namatias         ###   ########.fr       */
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
		if (!is_all_valid_numb(argv[i]) || is_all_valid_numb(argv[i]) <= 0 || is_all_valid_numb(argv[1]) >= MAX_PHILOS)
		{
			printf("Error: %s -> ", argv[i]);
			if (i == 1)
				printf("The number of philosophers must be a int between 0 and 200.\n");
			else if (i == 2)
				printf("Time_to_die must be a int = 1 or more.\n");
			else if (i == 3)
				printf("Time_to_eat must be a int = 1 or more.\n");
			else if (i == 4)
				printf("Time_to_sleep must be a int = 1 or more.\n");
			else if (i == 5)
				printf("The number of meals needs to be a int and at least 1.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_all_valid_numb(char *argv)
{
	long	numb;
	int		i;

	i = 0;
	numb = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32) //verifica espaço em branco (man isspace)
		i++;
	if (argv[i] == '+') //verificamos se tem sinal, só iremos aceitar 1 sinal positivo
		i++;
	else if (argv[i] == '-')
		return (0); //nesse programa numeros negativos nao sao aceitos, por tanto encerra exec
	while (argv[i] >= '0' && argv[i] <= '9') //enquanto for digito convertemos
	{
		numb = numb * 10 + (argv[i] - '0'); //*10 abre espaço pra prox casa decimal
		i++;
	}
	if (argv[i] != '\0' || numb > 2147483647) //se for maior q o numero max de int, tbm n é valido
		return (0); //ou se acabou antes do final da string, encerramos o programa. pois n é string valida
	return (numb);
}

void	init_structs(t_info *info, char **argv) //preenche nossa struct com as variaveis recebidas no imput
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


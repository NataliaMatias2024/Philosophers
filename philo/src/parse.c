/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:21:37 by namatias          #+#    #+#             */
/*   Updated: 2026/03/24 14:17:09 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (is_valid(argv[i]) <= 0 || (i == 1 && is_valid(argv[1]) >= MAX_PHILOS))
		{
			printf("Error: Invalid Arguments\n");
			if (i == 1)
				printf("The number of philos must be between 0 and 200.\n");
			else if (i == 2)
				printf("Time_to_die must be a int = 1 or more.\n");
			else if (i == 3)
				printf("Time_to_eat must be a int = 1 or more.\n");
			else if (i == 4)
				printf("Time_to_sleep must be a int = 1 or more.\n");
			else if (i == 5)
				printf("The number of meals needs to be at least 1.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_valid(char *argv)
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
	while (argv[i] >= '0' && argv[i] <= '9' && numb < 2147483647) //enquanto for digito convertemos
	{
		numb = numb * 10 + (argv[i] - '0'); //*10 abre espaço pra prox casa decimal
		i++;
	}
	if (argv[i] != '\0' || numb > 2147483647) //se for maior q o numero max de int, ou se acabou antes de chegar ao
		return (0); 							//final da string, encerramos o programa. pois n é string valida
	return (numb);
}

void	arg_error(void)
{
	printf("Error: Invalid Arguments\n");
	printf("Please enter 4 or 5 arguments\n");
	printf("1. Number of philosophers\n");
	printf("2. Time to die\n");
	printf("3. Time to eat\n");
	printf("4. Time to sleep\n");
	printf("5. Number of times each philo must eat (optional)\n");
}

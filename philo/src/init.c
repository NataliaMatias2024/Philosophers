/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:57:59 by namatias          #+#    #+#             */
/*   Updated: 2026/03/22 15:45:10 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//preenche nossa struct com as variaveis recebidas no imput
void	init_struct_info(t_info *info, char **argv)
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
	info->stop = 0; //Só muda quando a rotina se encerra, mas precisa ser inicializada.
	init_mutex_info(info); 
	init_forks_array(info); //chama a inicializaçao dos mutex forks
	info->time_start = current_time(); //deixamos o tempo por ultimo, antes d iniciar as threads d philo, deixando delay minimo
	init_struct_philo(info); //ja chama a inicializaçao da struct de philosofos.
}

void	init_mutex_info(t_info *info)
{
	//inicia o mutex de escrita
	if (pthread_mutex_init(&info->write_lock, NULL) != 0) //o segundo arg é NULL pois n temos nenhum atributo para setar
	{
		printf("Error: Mutex: Write_Lock initialization failed.\n");
		return ; //nessa etapa ainda n temos nenhum mutex ou pthread criada, entao n precisa destruir nada
	}
	//inicia mutex de morte de algum philo
	if (pthread_mutex_init(&info->death_lock, NULL) != 0)//o segundo arg é NULL pois n temos nenhum atributo para setar
	{
		printf("Error: Mutex: Death_Lock initialization failed.\n");
		pthread_mutex_destroy(&info->write_lock); //nessa etapa apenas o muter do rite_lock existe, sendo o unico q precisa ser liberado
		return ;
	}
}

void	init_forks_array(t_info *info)
{
	int	i;

	i = 0;
	while(i < info->numb_of_philo)
	{                                         //Começamos a inicializar cada um dos mutexes, um em cada index
		if (pthread_mutex_init(&info->forks[i], NULL) != 0) //o segundo arg é NULL pois n temos nenhum atributo para setar
		{
			printf("Error: Mutex: Forks initialization failed.\n");
			mutex_destroy(info, 1, i);
			return ;
		}
		i++;
	}
}

void	init_struct_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->numb_of_philo)
	{
		//aqui dentro iremos iniciar a struc dos philos TBM, pois vamos guardar cada philo, ja iniciado
		//em seu devido index do array de philos
		info->philo[i].id = i + 1; //começa em 1 e vai até n, diferente do index q começa em 0 e vai ate n - 1
		info->philo[i].meals = 0; //ao iniciar ninguem comeu ainda. Por isso inicia em 0
		info->philo[i].last_meal_time = info->time_start; //assim o monitor n irá confundir o deley entre o inicio do programa e a criaçao do philo, com tempo sem comer
		info->philo[i].is_dead = 0; //assim como a flag do stop, só muda quando o philo morrer. Iniciando em 0
		info->philo[i].info = info;
		info->philo[i].left_fork = &info->forks[i]; //indicamos de qual garfo esse philo é dono
		info->philo[i].right_fork = &info->forks[(i + 1) % info->numb_of_philo]; //indicamos qual garfo esse philo pegará emprestado
// o % garante q nunca passaremos um garfo numa pos invalida, pela "mesa" ser circular, caso esse seja o ultimo philo, ele deve pegar o garfo do primeiro, ou seja, do fork[0];
		if (pthread_mutex_init(&info->philo[i].philo_lock, NULL) != 0) //cada philo terá seu proprio mutex, entao precisamos cria-los dentro do looping
		{
			printf("Error: Mutex: Philo initialization failed.\n");
			mutex_destroy(info, 2, i);
			return ;			
		}	
		i++;
	}
}

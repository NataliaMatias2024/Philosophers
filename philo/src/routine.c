/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:23:52 by namatias          #+#    #+#             */
/*   Updated: 2026/03/23 16:29:29 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static void take_a_fork(t_philo *philo);
static void eating(t_philo *philo);
static void	sleeping(t_philo *philo);
static void	thinking(t_philo *philo);

//para o SO aceitar a funçao como uma thread temos que usar esse molde de ponteiro generico
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg; //aqui informamos, "Oh! esse ponteiro genérico é uma struct do tipo t_philo"
	while (keep_running(philo->info) == 0) //enquanto ninguem morrer nem atingir o numero minimo de refeições 
	{									  //n podemos comparar o info->stop direto com o zero pois	
		thinking(philo);				 //temos q protege-lo de data race, por isso usamos uma funçao auxiliar
		take_a_fork(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL); //encerrando o looping se encerra o programa.
}

static void	thinking(t_philo *philo)
{
	if (keep_running(philo->info) == 0)
	{
		print_action(philo, 4);
		//custom_usleep(100, philo->info); //como saber qual valor usar? //TODO: testar tempos diferentes e ver se ninguem morre
	}
}

static void take_a_fork(t_philo *philo)
{
	if (philo->id % 2 == 0 && keep_running(philo->info) == 0) //se for um philo com id par e ninguem tiver morrido
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, 1);
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, 1);
	}
	else if (philo->id % 2 != 0 && keep_running(philo->info) == 0) //se for um philo com id impar e ninguem tiver morrido
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, 1);
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, 1);
	}
	//todo mutex lock tem que ser unlock. Porem minhas funçoes de pegar o garfo e comer ficaram separadas
	//entao quem dara o unlock nos garfos sera a funçao eating
}

static void eating(t_philo *philo)
{
//Verificamos se ninguem morreu ou a rotina foi encerrada antes de iniciar a ação de comer
	if (keep_running(philo->info) != 0)
	{
		//caso a rotina tenha sido encerrrada apenas damos unlock da take_a_fork e retornamos
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	//chegando aqui iniciamos a açao de comer e atualizaçao das variaveis ligadas a ela
//imprimimos primeiro depois liberamos os garfos, garantindo que nenhum philo irá atropelar ela
	print_action(philo, 2); 
	pthread_mutex_lock(&philo->philo_lock);
	philo->last_meal_time = current_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->philo_lock);
//deve ficar fora da proteçao do mutex para n travar o monitor enquanto esse philo esta comendo	
	custom_usleep(philo->info->time_to_eat, philo->info);
//Liberamos os garfos foram lockados la no take_a_fork
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

static void	sleeping(t_philo *philo)
{
//Verificamos se o programa ainda esta rodando
	if (keep_running(philo->info) == 0)
	{
		print_action(philo, 3); //indicamos oq nossa threat irá fazer por baixo dos panos
		custom_usleep(philo->info->time_to_sleep, philo->info); //avança o tempo
	}
}

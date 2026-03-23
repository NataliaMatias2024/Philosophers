/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:23:52 by namatias          #+#    #+#             */
/*   Updated: 2026/03/23 02:29:31 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//para o SO aceitar a funçao como uma thread temos que usar esse molde de ponteiro generico
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg; //aqui informamos, "Oh! esse ponteiro genérico é uma struct do tipo t_philo"
	while (keep_running(philo->info) == 0) //enquanto ninguem morrer nem atingir o numero minimo de refeições 
	{									  //n podemos comparar o info->stop direto com o zero pois	
		thinking(philo);				 //temos q protege-lo de data race, por isso usamos uma funçao auxiliar
		take_a_fork(philo);
		eatting(philo);
		sleeping(philo);
	}
	return (NULL); //encerrando o looping se encerra o programa.
}



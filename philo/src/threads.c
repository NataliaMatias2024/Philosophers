/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:39:00 by namatias          #+#    #+#             */
/*   Updated: 2026/03/23 20:56:40 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static void	thread_error(t_info *info, int error_i);

void	threads_philo_create(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->numb_of_philo)
	{
		//ao criar a thread é retorna 0 no sucesso, entao se retornar qualquer outra coisa deu erro!!
		if (pthread_create(&info->philo[i].thread_id, NULL, &routine,
				&info->philo[i]) != 0)
		{
			thread_error(info, i);
			return ;
		}
		i++;
	}
}

void	thread_wait(t_info *info, int error_i)
{
	int	i;

	i = 0;
//Essa funçao obriga a main esperar as threads seguirem a rodina definada e finalizarem para só entao encerrar
//Comportamento parecido com o waitpid nos processos filhos (lógico q com definiçoes e fluxos diferentes)
	while (i < info->numb_of_philo && i < error_i)
	{
		pthread_join(info->philo[i].thread_id, NULL);
		i++;
	}
}

static void	thread_error(t_info *info, int error_i)
{
	printf("Error: Creating philo threads\n");
//Independende de onde ocorreu o erro as threads ja criadas precisam ser avisadas para pararem a rona
	pthread_mutex_lock(&info->death_lock);
	info->stop = 1;
	pthread_mutex_unlock(&info->death_lock);
//depois precisamos esperar que as threads ja criadas finalizem correntamente seus processos pulando para a ultiam linha da rotina
	thread_wait(info, error_i);
//E só entao td deve ser destruido
	mutex_destroy(info, 2, info->numb_of_philo);
}

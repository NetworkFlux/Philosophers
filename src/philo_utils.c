/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:45:47 by npinheir          #+#    #+#             */
/*   Updated: 2021/12/07 12:49:26 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(unsigned int time_in_ms, t_philo *phils)
{
	unsigned long	start;

	start = ft_actual_time();
	while (1)
	{
		if (ft_actual_time() - start >= time_in_ms)
			break ;
		usleep(phils->ru->nb_phil * 2);
	}
}

void	ft_print_status(char *str, t_philo *phils)
{
	unsigned int	time;

	time = 0;
	time = ft_actual_time() - phils->ru->start_time;
	if (time <= 2147483647 && !ft_death(phils, 0))
	{
		printf("%d ", time);
		printf("Philo %d %s", phils->id, str);
	}
}

unsigned int	ft_actual_time(void)
{
	unsigned int	time;
	struct timeval	current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

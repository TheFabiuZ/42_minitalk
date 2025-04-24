/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:04:54 by famirant          #+#    #+#             */
/*   Updated: 2023/03/01 15:36:00 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_build_char(int signal_i, unsigned char *c, int i)
{
	*c <<= 1;
	if (signal_i == SIGUSR2)
		*c += 1;
	if (i > 7)
	{
		if (!(*c))
			write(1, "\n", 1);
		else
			write(1, &(*c), 1);
	}
}

void	ft_interpreter(int signal_i, siginfo_t *sigact)
{
	static int				i = 0;
	static unsigned char	c = 0;

	i++;
	ft_build_char(signal_i, &c, i);
	if (i > 7)
	{
		i = 0;
		if (!c)
		{
			kill(sigact->si_pid, SIGUSR2);
			return ;
		}
		c = 0;
	}
}

void	ft_received(int signal_i, siginfo_t *sigact, void *context)
{
	(void)context;
	ft_interpreter(signal_i, sigact);
	kill(sigact->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sigact;

	ft_printf("server pid: %d\n", getpid());
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_received;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		;
	return (0);
}

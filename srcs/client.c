/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:35:01 by famirant          #+#    #+#             */
/*   Updated: 2023/03/01 16:13:19 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_bool	g_server_busy = TRUE;

void	ft_signal_received(int signal)
{
	(void)signal;
	ft_printf("\033[1;38;5;76mReceived a response by the server!\033[0m\n");
	exit(0);
}

void	ft_server_ready(int signal)
{
	(void)signal;
	g_server_busy = FALSE;
}

void	ft_send_bits(unsigned int pid, char *str)
{
	int		signo;
	int		bit;
	int		i;

	i = 0;
	while (g_server_busy)
		if (++i > 500000)
			exit (22);
	bit = 7;
	while (*(++str - 1))
	{
		while (--bit >= 0)
		{
			signo = SIGUSR1;
			if ((*(str - 1) >> bit) & 0x01)
				signo = SIGUSR2;
			g_server_busy = TRUE;
			kill(pid, signo);
			while (g_server_busy)
				;
		}
		bit = 8;
	}
}

void	ft_communicate(unsigned int pid, char *str)
{
	int		signo;
	int		bit;

	signal(SIGUSR2, &ft_signal_received);
	signal(SIGUSR1, &ft_server_ready);
	bit = 8;
	signo = SIGUSR1;
	if ((*str >> bit) & 0x01)
		signo = SIGUSR2;
	g_server_busy = TRUE;
	if (kill(pid, signo))
		exit (22);
	ft_send_bits(pid, str);
	bit = -1;
	while (++bit < 8)
	{
		g_server_busy = TRUE;
		kill(pid, SIGUSR1);
		while (g_server_busy)
			;
	}
	sleep(5);
	ft_printf("\033[31mTIMED OUT\033[0m\n");
}

int	main(int argc, char **argv)
{
	if (argc - 3)
		return (0);
	ft_communicate(ft_atoi(argv[1]), argv[2]);
	return (0);
}

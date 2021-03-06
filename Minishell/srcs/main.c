/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:21:04 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/08/24 17:03:01 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_hello(void)
{
	printf("\033[34m");
	printf(
		"\n███╗░░░███╗██╗███╗░░██╗██╗░██████╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░\n");
	printf(
		"████╗░████║██║████╗░██║██║██╔════╝██║░░██║██╔════╝██║░░░░░██║░░░░░\n");
	printf(
		"██╔████╔██║██║██╔██╗██║██║╚█████╗░███████║█████╗░░██║░░░░░██║░░░░░\n");
	printf(
		"██║╚██╔╝██║██║██║╚████║██║░╚═══██╗██╔══██║██╔══╝░░██║░░░░░██║░░░░░\n");
	printf(
		"██║░╚═╝░██║██║██║░╚███║██║██████╔╝██║░░██║███████╗███████╗███████╗\n");
	printf(
		"╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝\n\n");
	printf("\033[0m");
}

void	init_env(t_all *data, int argc, char **argv, char **env)
{
	int	i;

	(void)argc;
	(void)argv;
	i = -1;
	while (env[++i])
		ft_lstadd_back(&(data->env), ft_lstnew(ft_strdup(env[i])));
	data->fd_std[0] = dup(0);
	data->fd_std[1] = dup(1);
}

void	print_args(t_all data)
{
	t_list	*tmp;

	tmp = data.args;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_all	data;
	char	*input;

	ft_hello();
	init_env(&data, argc, argv, env);
	while (1)
	{
		input = readline("\001\033[34m\002minishell> \001\033[37m\002");
		if (!input)
			exit(0);
		add_history(input);
		if (parser(input, &data))
			return (1);
		executor(&data);
		//print_args(data);
		ft_lstclear(&(data.args), &free);
		free(input);
	}
	return (0);
}

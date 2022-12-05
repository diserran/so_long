/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:16 by diserran          #+#    #+#             */
/*   Updated: 2022/12/05 23:20:07 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = map_checker(argv[1]);
		printf("puntero listas %p\n", map);
		t_map	*curr = map;
		while (curr != NULL)
		{
			printf("linea: %p\n", curr->next);
			curr = curr->next;
		}
	}
	else
		write(2, "Not enough arguments!\n", 23);
	return (0);
}

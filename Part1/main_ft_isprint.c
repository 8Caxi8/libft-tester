/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:03:39 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 14:25:42 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#define GREEN "\033[92m"
#define GREY  "\033[90m"
#define BLACK_ON_GREEN "\033[1;30;102m"
#define WHITE_ON_RED "\033[1;37;41m"
#define ITALIC_BLUE "\033[3;34m"
#define RED "\033[91m"
#define RESET "\033[0m"

int	main()
{
	int		a;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_isprint";
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	a = 32;
	if (isprint(a) - ft_isprint(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i,  a, isprint(a), ft_isprint(a));
	i++;

	///////////Test 2///////////
	a = 31;
	if (isprint(a) - ft_isprint(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
	i++;

	///////////Test 3///////////
	a = 255;
	if (isprint(a) - ft_isprint(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
	i++;

	///////////Test 4///////////
	a = 126;
	if (isprint(a) - ft_isprint(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
	i++;

	///////////Test 5///////////
	a = 127;
	if (isprint(a) - ft_isprint(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isprint(a), ft_isprint(a));
	i++;

	///////////Test 6///////////
	a = 0;
	if (isprint(a) - ft_isprint(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n",i,  a, isprint(a), ft_isprint(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n",i, a, isprint(a), ft_isprint(a));
	i++;

	///////////RESULT///////////
	if (success == i)
		printf(BLACK_ON_GREEN " PASS " RESET ITALIC_BLUE " %s" RESET "\n\n", function);
	else
		printf(WHITE_ON_RED " FAIL " RESET ITALIC_BLUE " %s" RESET "\n\n", function);

	///////////RESULTS_LOGS///////////
	write(fd, function, strlen(function));
	write(fd, " ", 1);
	if (success / i == 1)
		write(fd, "OK :D\n", 6);
	else
		write(fd, "KO :(\n", 6);
	close (fd);
	return (0);
}

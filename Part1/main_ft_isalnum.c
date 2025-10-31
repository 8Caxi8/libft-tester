/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:54:50 by caxi              #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#define GREEN "\033[92m"
#define YELLOW "\033[93m"
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
	char	*function = "ft_isalnum";
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	a = '5';
	if (isalnum(a) - ft_isalnum(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else if (ft_isalnum(a) != 0)
	{
		printf(YELLOW "✓ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i,  a, isalnum(a), ft_isalnum(a));
	i++;

	///////////Test 2///////////
	a = 'c';
	if (isalnum(a) - ft_isalnum(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else if (ft_isalnum(a) != 0)
	{
		printf(YELLOW "✓ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
	i++;

	///////////Test 3///////////
	a = 255;
	if (isalnum(a) - ft_isalnum(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else if (ft_isalnum(a) == 0)
	{
		printf(YELLOW "✓ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
	i++;

	///////////Test 4///////////
	a = 0;
	if (isalnum(a) - ft_isalnum(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else if (ft_isalnum(a) == 0)
	{
		printf(YELLOW "✓ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
	i++;

	///////////Test 5///////////
	a = '-';
	if (isalnum(a) - ft_isalnum(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else if (ft_isalnum(a) == 0)
	{
		printf(YELLOW "✓ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
	i++;

	///////////Test 6///////////
	a = '~';
	if (isalnum(a) - ft_isalnum(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %d. Original: %d My own: %d" RESET "\n",i,  a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else if (ft_isalnum(a) == 0)
	{
		printf(YELLOW "✓ [%d] Testing for %d. Original: %d My own: %d" RESET "\n", i, a, isalnum(a), ft_isalnum(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %d. Original: %d My own: %d" RESET "\n",i, a, isalnum(a), ft_isalnum(a));
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
		write(fd, "OK :D 1\n", 8);
	else
		write(fd, "KO :( 0\n", 8);
	close (fd);
	return (0);
}
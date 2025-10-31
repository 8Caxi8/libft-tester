/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:37:24 by caxi              #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <setjmp.h>

#define GREEN "\033[92m"
#define GREY  "\033[90m"
#define BLACK_ON_GREEN "\033[1;30;102m"
#define WHITE_ON_RED "\033[1;37;41m"
#define ITALIC_BLUE "\033[3;34m"
#define RED "\033[91m"
#define RESET "\033[0m"

static sigjmp_buf jump_buffer;

void segfault_handler(int sig)
{
    (void) sig;
    siglongjmp(jump_buffer, 1);
}

int	main()
{
	char	*a;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_atoi";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	a = "\t -554521";
	if (atoi(a) - ft_atoi(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for \"\\t -554521\". Original: %d My own: %d" RESET "\n", i, atoi(a), ft_atoi(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for \"\\t -554521\". Original: %d My own: %d" RESET "\n", i, atoi(a), ft_atoi(a));
	i++;

	///////////Test 2///////////
	a = "\r\n +-4";
	if (atoi(a) - ft_atoi(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for \"\\r\\n +-4\". Original: %d My own: %d" RESET "\n", i, atoi(a), ft_atoi(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for \"\\r\\n +-4\". Original: %d My own: %d" RESET "\n", i, atoi(a), ft_atoi(a));
	i++;

	///////////Test 3///////////
	a = "-2147483648";
	if (atoi(a) - ft_atoi(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Original: %d My own: %d" RESET "\n", i, a, atoi(a), ft_atoi(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Original: %d My own: %d" RESET "\n", i, a, atoi(a), ft_atoi(a));
	i++;

	///////////Test 4///////////
	a = "2147483647";
	if (atoi(a) - ft_atoi(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Original: %d My own: %d" RESET "\n", i, a, atoi(a), ft_atoi(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Original: %d My own: %d" RESET "\n", i, a, atoi(a), ft_atoi(a));
	i++;

	///////////Test 5///////////
	a = "\f\t\v -512345f412";
	if (atoi(a) - ft_atoi(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for \"\\f\\t\\v -512345f412\". Original: %d My own: %d" RESET "\n",i, atoi(a), ft_atoi(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for \"\\f\\t\\v -512345f412\". Original: %d My own: %d" RESET "\n",i, atoi(a), ft_atoi(a));
	i++;

	///////////Test 6///////////
	a = "";
	if (atoi(a) - ft_atoi(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Original: %d My own: %d" RESET "\n",i,  a, atoi(a), ft_atoi(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Original: %d My own: %d" RESET "\n",i, a, atoi(a), ft_atoi(a));
	i++;

	///////////Test 7///////////
	a = "\b 45";
	if (atoi(a) - ft_atoi(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for \"\\b 45\". Original: %d My own: %d" RESET "\n",i, atoi(a), ft_atoi(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for \"\\b 45\". Original: %d My own: %d" RESET "\n",i, atoi(a), ft_atoi(a));
	i++;

	///////////Test 8///////////
	a = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		ft_atoi(a);
        printf(RED "✗ [%d] Testing for \"%s\". Original: <<seg fault>> My own: %d" RESET "\n", i, a, ft_atoi(a));
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, a);
		success++;
    }
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:08:00 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 09:01:36 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <limits.h>
#include <bsd/string.h>
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
	size_t	n;
	char	*little;
	char	*big;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_strnstr";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	little = ", c";
	big = "Olaa, como vais?";
	n = 20;
	if (ft_strnstr(big, little, n))
	{
		if (strcmp(strnstr(big, little, n), ft_strnstr(big, little, n)) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, big, little, n, strnstr(big, little, n), ft_strnstr(big, little, n));
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, big, little, n, strnstr(big, little, n), ft_strnstr(big, little, n));
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: (null)" RESET "\n", i, big, little, n, strnstr(big, little, n));
	i++;

	///////////Test 2///////////
	little = "O";
	big = "Olaa, como vais?";
	n = 20;
	if (ft_strnstr(big, little, n))
	{
		if (strcmp(strnstr(big, little, n), ft_strnstr(big, little, n)) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, big, little, n, strnstr(big, little, n), ft_strnstr(big, little, n));
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, big, little, n, strnstr(big, little, n), ft_strnstr(big, little, n));
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: (null)" RESET "\n", i, big, little, n, strnstr(big, little, n));
	i++;

	///////////Test 3///////////
	little = "?";
	big = "Olaa, como vais?";
	n = 20;
	if (ft_strnstr(big, little, n))
	{
		if (strcmp(strnstr(big, little, n), ft_strnstr(big, little, n)) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, big, little, n, strnstr(big, little, n), ft_strnstr(big, little, n));
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, big, little, n, strnstr(big, little, n), ft_strnstr(big, little, n));
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: (null)" RESET "\n", i, big, little, n, strnstr(big, little, n));
	i++;

	///////////Test 4///////////
	little = "";
	big = "Olaa, como vais?";
	n = 20;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		if (ft_strnstr(big, little, n))
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: (null) My own: (null)" RESET "\n", i, big, little, n);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: (null)" RESET "\n", i, big, little, n, strnstr(big, little, n));
	}
	else
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: <<seg fault>>" RESET "\n", i, big, little, n, strnstr(big, little, n));
	i++;

	///////////Test 5///////////
	little = ", ";
	big = "Olaa, como vais?";
	n = 4;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		if (!ft_strnstr(big, little, n))
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: (null) My own: (null)" RESET "\n", i, big, little, n);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: (null) My own: \"%s\"" RESET "\n", i, big, little, n, ft_strnstr(big, little, n));
	}
	else
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: <<seg fault>>" RESET "\n", i, big, little, n, strnstr(big, little, n));
	i++;

	///////////Test 6///////////
	little = ", ";
	big = "Olaa, como vais?";
	n = 0;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		if (!ft_strnstr(big, little, n))
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: (null) My own: (null)" RESET "\n", i, big, little, n);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: (null) My own: \"%s\"" RESET "\n", i, big, little, n, ft_strnstr(big, little, n));
	}
	else
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: \"%s\" My own: <<seg fault>>" RESET "\n", i, big, little, n, strnstr(big, little, n));
	i++;
	
	///////////Test 7///////////
	little = NULL;
	big = "olaaa";
	n = 5;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		ft_strnstr(big, little, n);
        printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: %s" RESET "\n", i, big, little, n, ft_strnstr(big, little, n));
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, big, little, n);
		success++;
    }
	i++;

	///////////Test 8///////////
	little = "Olaaa";
	big = NULL;
	n = 5;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		ft_strnstr(big, little, n);
        printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: %s" RESET "\n", i, big, little, n, ft_strnstr(big, little, n));
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, big, little, n);
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
		write(fd, "OK :D\n", 6);
	else
		write(fd, "KO :(\n", 6);
	close (fd);
	return (0);
}

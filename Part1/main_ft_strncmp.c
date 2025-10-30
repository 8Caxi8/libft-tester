/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:36:10 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 09:01:36 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <limits.h>
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
	size_t 	n;
	char	*s1;
	char	*s2;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_strncmp";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	s1 = "olaaaa";
	s2 = "Olaa, como vais?";
	n = 5;
	if (strncmp(s1, s2, n) == ft_strncmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	i++;

	///////////Test 2///////////
	s1 = "Olaaaa";
	s2 = "Olaa, como vais?";
	n = 50;
	if (strncmp(s1, s2, n) == ft_strncmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	i++;

	///////////Test 3///////////
	s1 = "olaaaa";
	s2 = "olaaaa";
	n = 50;
	if (strncmp(s1, s2, n) == ft_strncmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	i++;

	///////////Test 4///////////
	s1 = "";
	s2 = "";
	n = 5;
	if (strncmp(s1, s2, n) == ft_strncmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	i++;

	///////////Test 5///////////
	s1 = "olaaaa";
	s2 = "";
	n = 5;
	if (strncmp(s1, s2, n) == ft_strncmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	i++;

	///////////Test 6///////////
	s1 = "";
	s2 = "O";
	n = 5;
	if (strncmp(s1, s2, n) == ft_strncmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	i++;
	
	///////////Test 6///////////
	s1 = "Olaa";
	s2 = "Ossd";
	n = 0;
	if (strncmp(s1, s2, n) == ft_strncmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, s1, s2, n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	i++;
	
	///////////Test 7///////////
	n = 3;
	s1 = NULL;
	s2 = "Olaa";
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		ft_strncmp(s1, s2, n);
        printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: %d" RESET "\n", i, s1, s2, n, ft_strncmp(s1, s2, n));
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, s1, s2, n);
		success++;
    }
	i++;
	
	///////////Test 8///////////
	n = 3;
	s1 = "Olaa";
	s2 = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		ft_strncmp(s1, s2, n);
        printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: %d" RESET "\n", i, s1, s2, n, ft_strncmp(s1, s2, n));
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, s1, s2, n);
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
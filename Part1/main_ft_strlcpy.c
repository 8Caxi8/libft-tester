/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:51:46 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 09:01:36 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
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
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_strlcpy";
	const char	*s;
	char		d1[1024];
	char		d2[1024];
	char		*d3;
	size_t		n;
	size_t		n1;
	size_t		n2;
	
	d3 = NULL;
	signal(SIGSEGV, segfault_handler);
	
	fd = open("res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	s = "Olaaaa, tudo bem?";
	n = strlen(s) + 1;
	n1 = strlcpy(d1, s, n);
	n2 = ft_strlcpy(d2, s, n);
	
	if (memcmp(d1, d2, n) == 0 && n1 == n2)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %zu). ", i, s, n);
		printf("Original: (\"%s\", %lu) ", d1, n1);
		printf("My own: (\"%s\", %lu)", d2, n2);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (\"%s\", %zu). ", i, s, n);
		printf("Original: (\"%s\", %lu) ", d1, n1);
		printf("My own: (\"%s\", %lu)", d2, n2);
		printf(RESET "\n");
		printf(RESET "\n");
	}
	i++;

	///////////Test 2///////////
	s = "Olaaaa, tudo bem?";
	n = 5;
	n1 = strlcpy(d1, s, n);
	n2 = ft_strlcpy(d2, s, n);
	
	if (memcmp(d1, d2, n) == 0 && n1 == n2)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %zu). ", i, s, n);
		printf("Original: (\"%s\", %lu) ", d1, n1);
		printf("My own: (\"%s\", %lu)", d2, n2);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (\"%s\", %zu). ", i, s, n);
		printf("Original: (\"%s\", %lu) ", d1, n1);
		printf("My own: (\"%s\", %lu)", d2, n2);
		printf(RESET "\n");
		printf(RESET "\n");
	}
	i++;

	///////////Test 3///////////
	s = "Olaaaa";
	n = 0;
	n1 = strlcpy(d1, s, n);
	n2 = ft_strlcpy(d2, s, n);
	
	if (memcmp(d1, d2, n) == 0 && n1 == n2)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %zu). ", i, s, n);
		printf("Original: (\"%s\", %lu) ", d1, n1);
		printf("My own: (\"%s\", %lu)", d2, n2);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (\"%s\", %zu). ", i, s, n);
		printf("Original: (\"%s\", %lu) ", d1, n1);
		printf("My own: (\"%s\", %lu)", d2, n2);
		printf(RESET "\n");
		printf(RESET "\n");
	}
	i++;

	///////////Test 4///////////
	s = "Olaaaa";
	n = 1;
	n1 = strlcpy(d1, s, n);
	n2 = ft_strlcpy(d2, s, n);
	
	if (memcmp(d1, d2, n) == 0 && n1 == n2)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %zu). ", i, s, n);
		printf("Original: (\"%s\", %lu) ", d1, n1);
		printf("My own: (\"%s\", %lu)", d2, n2);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (\"%s\", %zu). ", i, s, n);
		printf("Original: (\"%s\", %lu) ", d1, n1);
		printf("My own: (\"%s\", %lu)", d2, n2);
		printf(RESET "\n");
		printf(RESET "\n");
	}
	i++;

	///////////Test 5///////////
	n = 5;
	s = "Olaa";
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		n1 = ft_strlcpy(d3, s, n);
        printf(RED "✗ [%d] Testing for dest = NULL. Original: <<seg fault>> My own: (\"%s\",%lu)" RESET "\n", i, d3, n1);
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for dest = NULL . Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i);
		success++;
    }
	i++;

	///////////Test 6///////////
	n = 5;
	s = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		n1 = ft_strlcpy(d1, s, n);
        printf(RED "✗ [%d] Testing for src = NULL. Original: <<seg fault>> My own: (\"%s\",%lu)" RESET "\n", i, d1, n1);
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for src = NULL . Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i);
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

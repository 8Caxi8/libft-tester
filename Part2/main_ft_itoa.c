/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:07:45 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 09:01:33 by caxi             ###   ########.fr       */
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
	int				n;
	char			*exp;
	char			*sub;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_itoa";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	n = 50;
	exp = "50";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_itoa(n);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: (null)" RESET "\n", i, n, exp);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, n, exp);
	i++;
  
	///////////Test 1///////////
	n = -50;
	exp = "-50";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_itoa(n);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: (null)" RESET "\n", i, n, exp);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, n, exp);
	i++;

	///////////Test 1///////////
	n = 5;
	exp = "5";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_itoa(n);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: (null)" RESET "\n", i, n, exp);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, n, exp);
	i++;

	///////////Test 1///////////
	n = 0;
	exp = "0";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_itoa(n);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: (null)" RESET "\n", i, n, exp);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, n, exp);
	i++;

	///////////Test 1///////////
	n = -1;
	exp = "-1";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_itoa(n);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: (null)" RESET "\n", i, n, exp);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, n, exp);
	i++;

	///////////Test 1///////////
	n = INT_MAX;
	exp = "2147483647";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_itoa(n);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: (null)" RESET "\n", i, n, exp);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, n, exp);
	i++;
	
	///////////Test 1///////////
	n = INT_MIN;
	exp = "-2147483648";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_itoa(n);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: (null)" RESET "\n", i, n, exp);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, n, exp);
	i++;

	///////////Test 1///////////
	n = -524;
	exp = "-524";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_itoa(n);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, n, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: (null)" RESET "\n", i, n, exp);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, n, exp);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:13:15 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
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
	t_list			*new;
	int				expi;
	int				subi;
	char			*exp;
	char			*sub;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_strjoin";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	sub = "Ola ,, como ??";
	exp = "Ola ,, como ??";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = ft_lstnew(sub);
		if (new)
		{
			if (strcmp(new->content, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, exp, exp, (char *)new->content);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, exp, exp, (char *)new->content);
			free(new);
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp, exp);
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp, exp);
	i++;
  
	///////////Test 1///////////
	sub = "";
	exp = "";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = ft_lstnew(sub);
		if (new)
		{
			if (strcmp(new->content, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, exp, exp, (char *)new->content);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, exp, exp, (char *)new->content);
			free(new);
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp, exp);
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp, exp);
	i++;

	///////////Test 1///////////
	sub = "42";
	exp = "42";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = ft_lstnew(sub);
		if (new)
		{
			if (strcmp(new->content, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, exp, exp, (char *)new->content);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, exp, exp, (char *)new->content);
			free(new);
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp, exp);
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp, exp);
	i++;

	///////////Test 1///////////
	subi = 42;
	expi = 42;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = ft_lstnew(&sub);
		if (new)
		{
			if (subi == expi)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: %d My own: %d" RESET "\n", i, expi, expi, *(int *)new->content);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for %d. Expected: %d My own: %d" RESET "\n", i, expi, expi, *(int *)new->content);
			free(new);
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: %d My own: (null)" RESET "\n", i, expi, expi);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: %d My own: <<seg fault>>" RESET "\n", i, expi, expi);
	i++;

	///////////Test 1///////////
	sub = NULL;
	exp = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = ft_lstnew(sub);
		if (new)
		{
			if (new->content == NULL)
			{
				printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, exp, exp, (char *)new->content);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, exp, exp, (char *)new->content);
			free(new);
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp, exp);
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp, exp);
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

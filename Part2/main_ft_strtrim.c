/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:23:40 by caxi              #+#    #+#             */
/*   Updated: 2025/10/31 16:02:03 by dansimoe         ###   ########.fr       */
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
#define YELLOW "\033[93m"
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
	char			*s1;
	char			*set;
	char			*exp;
	char			*sub;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_strtrim";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	s1 = "  ,  ,Ola ,, como,  ,  ";
	set = "  ,";
	exp = "Ola ,, como";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_strtrim(s1, set);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: (null)" RESET "\n", i, s1, set, exp);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, s1, set, exp);
	i++;
  
	///////////Test 1///////////
	s1 = "  , Ola ,, como,  ,  ";
	set = " ";
	exp = ", Ola ,, como,  ,";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_strtrim(s1, set);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: (null)" RESET "\n", i, s1, set, exp);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, s1, set, exp);
	i++;

	///////////Test 1///////////
	s1 = "  ,  ,Ola ,, como,  ,  ";
	set = "";
	exp = "  ,  ,Ola ,, como,  ,  ";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_strtrim(s1, set);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: (null)" RESET "\n", i, s1, set, exp);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, s1, set, exp);
	i++;

	///////////Test 1///////////
	s1 = "  , ";
	set = "  , abcd";
	exp = "";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_strtrim(s1, set);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: (null)" RESET "\n", i, s1, set, exp);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, s1, set, exp);
	i++;

	///////////Test 1///////////
	s1 = "Ola ,, comosdds  a ";
	set = " a  sdds";
	exp = "Ola ,, como";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_strtrim(s1, set);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			free(sub);
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: (null)" RESET "\n", i, s1, set, exp);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, s1, set, exp);
	i++;

	///////////Test 1///////////
	s1 = "Ola ,, comosdds  a ";
	set = NULL;
	exp = "Ola ,, comosdds  a ";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_strtrim(s1, set);
		if (sub)
		{
			if (strcmp(sub, exp) == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
				success++;
			}
			else
				printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			free(sub);
		}
		else
		{
			printf(YELLOW "✓ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			success++;
		}
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, s1, set, exp);
	i++;
	
	///////////Test 1///////////
	s1 = NULL;
	set = NULL;
	exp = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_strtrim(s1, set);
		if (!sub)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, s1, set, exp);
	i++;

	///////////Test 1///////////
	s1 = NULL;
	set = "  Ola ";
	exp = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_strtrim(s1, set);
		if (!sub)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s1, set, exp, sub);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\"). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, s1, set, exp);
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

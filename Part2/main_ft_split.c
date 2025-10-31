/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:37:46 by caxi              #+#    #+#             */
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
	char			*s1;
	char			s2;
	char			**exp;
	char			**sub;
	int				j;
	int				t;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_split";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	s1 = "Ola como vais ??";
	s2 = ' ';
	exp = malloc(4 * 8);
	exp[0] = "Ola";
	exp[1] = "como";
	exp[2] = "vais";
	exp[3] = "??";
	exp[4] = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_split(s1, s2);
		if (sub)
		{
			t = 0;
			j = -1;
			while (sub[++j])
				t += strcmp(exp[j], sub[j]);
			if (!t)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for (\"%s\", '%c').", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
			}
			free(sub);
		}
		else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: (null)");
		}
	}
	else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: <<seg fault>>");
		}
	i++;
	free(exp);
 
	///////////Test 1///////////
	s1 = "    Ola   como  vais ??";
	s2 = ' ';
	exp = malloc(5 * 8);
	exp[0] = "Ola";
	exp[1] = "como";
	exp[2] = "vais";
	exp[3] = "??";
	exp[4] = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_split(s1, s2);
		if (sub)
		{
			t = 0;
			j = -1;
			while (sub[++j])
				t += strcmp(exp[j], sub[j]);
			if (!t)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for (\"%s\", '%c').", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
			}
			free(sub);
		}
		else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: (null)");
		}
	}
	else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: <<seg fault>>");
		}
	i++;
	free(exp);

	///////////Test 1///////////
	s1 = "  Ola   como  vais ??    ";
	s2 = ' ';
	exp = malloc(5 * 8);
	exp[0] = "Ola";
	exp[1] = "como";
	exp[2] = "vais";
	exp[3] = "??";
	exp[4] = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_split(s1, s2);
		if (sub)
		{
			t = 0;
			j = -1;
			while (sub[++j])
				t += strcmp(exp[j], sub[j]);
			if (!t)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for (\"%s\", '%c').", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
			}
			free(sub);
		}
		else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: (null)");
		}
	}
	else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: <<seg fault>>");
		}
	i++;
	free(exp);

	///////////Test 1///////////
	s1 = "Ola";
	s2 = ' ';
	exp = malloc(2 * 8);
	exp[0] = "Ola";
	exp[1] = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_split(s1, s2);
		if (sub)
		{
			t = 0;
			j = -1;
			while (sub[++j])
				t += strcmp(exp[j], sub[j]);
			if (!t)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for (\"%s\", '%c').", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
			}
			free(sub);
		}
		else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: (null)");
		}
	}
	else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: <<seg fault>>");
		}
	i++;
	free(exp);

	///////////Test 1///////////
	s1 = "....Ola .. ..,";
	s2 = '.';
	exp = malloc(4 * 8);
	exp[0] = "Ola ";
	exp[1] = " ";
	exp[2] = ",";
	exp[3] = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_split(s1, s2);
		if (sub)
		{
			t = 0;
			j = -1;
			while (sub[++j])
				t += strcmp(exp[j], sub[j]);
			if (!t)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for (\"%s\", '%c').", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
			}
			free(sub);
		}
		else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: (null)");
		}
	}
	else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: <<seg fault>>");
		}
	i++;
	free(exp);
	
	/* ///////////Test 1///////////
	s1 = NULL;
	s2 = ' ';
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_split(s1, s2);
		if (!sub)
		{
			t = 0;
			j = -1;
			while (sub[++j])
				t += strcmp(exp[j], sub[j]);
			if (!t)
			{
				printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for (\"%s\", '%c').", i, s1, s2);
				printf("Expected: ");
				j = -1;
				while (exp[++j])
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				while (sub[++j])
				{
					printf("\\\"%s\"", sub[j]);
					free(sub[j]);
				}
				printf(RESET "\n");
			}
			free(sub);
		}
		else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: (null)");
		}
	}
	else
		{
			printf(RED "✗ [%d] Testing for (\"%s\", '%c'). ", i, s1, s2);
			printf("Expected: ");
			j = -1;
			while (exp[++j])
				printf("\\\"%s\"", exp[j]);
			printf(" My own: <<seg fault>>");
		}
	i++;
	free(exp); */
	
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

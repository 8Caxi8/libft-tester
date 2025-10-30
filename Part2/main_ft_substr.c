/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:00:21 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 13:07:49 by dansimoe         ###   ########.fr       */
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
	size_t			len;
	unsigned int	start;
	char			*s;
	char			*exp;
	char			*sub;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_substr";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	s = "Ola como vais?";
	exp = "como";
	start = 4;
	len = 4;
	sub = ft_substr(s, start, len);
	if (sub)
	{
		if (strcmp(sub, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: (null)" RESET "\n", i, s, start, len, exp);
	i++;
	free(sub);
 
	///////////Test 1///////////
	s = "Ola como vais?";
	exp = "Ola como ";
	start = 0;
	len = 9;
	sub = ft_substr(s, start, len);
	if (sub)
	{
		if (strcmp(sub, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: (null)" RESET "\n", i, s, start, len, exp);
	i++;
	free(sub);

	///////////Test 1///////////
	s = "Ola como vais?";
	exp = "Ola como vais?";
	start = 0;
	len = 20;
	sub = ft_substr(s, start, len);
	if (sub)
	{
		if (strcmp(sub, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: (null)" RESET "\n", i, s, start, len, exp);
	i++;
	free(sub);

	///////////Test 1///////////
	s = "Ola como vais?";
	exp = "vais?";
	start = 9;
	len = 20;
	sub = ft_substr(s, start, len);
	if (sub)
	{
		if (strcmp(sub, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: (null)" RESET "\n", i, s, start, len, exp);
	i++;
	free(sub);

	///////////Test 1///////////
	s = "Ola como vais?";
	exp = "";
	start = 6;
	len = 0;
	sub = ft_substr(s, start, len);
	if (sub)
	{
		if (strcmp(sub, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: (null)" RESET "\n", i, s, start, len, exp);
	i++;
	free(sub);

	///////////Test 1///////////
	s = "Ola como vais?";
	exp = "";
	start = 30;
	len = 9;
	sub = ft_substr(s, start, len);
	if (sub)
	{
		if (strcmp(sub, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: \"%s\"" RESET "\n", i, s, start, len, exp, sub);
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: \"%s\" My own: (null)" RESET "\n", i, s, start, len, exp);
	i++;
	free(sub);
	
	///////////Test 7///////////
	s = NULL;
	start = 2;
	len = 9;
	sub = ft_substr(s, start, len);
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		sub = ft_substr(s, start, len);
		if (!sub)
		{
        	printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d, %lu). Original: (null) My own: (null)" RESET "\n", i, s, start, len);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: (null) My own: \"%s\"" RESET "\n", i, s, start, len, sub);
	}
	else 
		printf(RED "✗ [%d] Testing for (\"%s\", %d, %lu). Expected: (null) My own: <<seg fault>>" RESET "\n", i, s, start, len);
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

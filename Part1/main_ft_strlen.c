/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:06:39 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 09:01:36 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
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
	char	*a;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_strlen";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	a = "";
	if (strlen(a) - ft_strlen(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %s. Original: %zu My own: %zu" RESET "\n", i, a, strlen(a), ft_strlen(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %s. Original: %zu My own: %zu" RESET "\n", i,  a, strlen(a), ft_strlen(a));
	i++;

	///////////Test 2///////////
	a = "42!!";
	if (strlen(a) - ft_strlen(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %s. Original: %zu My own: %zu" RESET "\n", i, a, strlen(a), ft_strlen(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %s. Original: %zu My own: %zu" RESET "\n", i, a, strlen(a), ft_strlen(a));
	i++;

	///////////Test 3///////////
	a = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0) 
        printf(RED "✗ [%d] Testing for %s. Original: <<seg fault>> My own: %zu" RESET "\n", i, a, ft_strlen(a));
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for %s. Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, a);
		success++;
    }
	i++;

	///////////Test 4///////////
	a = "\t\0P";
	if (strlen(a) - ft_strlen(a) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for %s. Original: %zu My own: %zu" RESET "\n", i, a, strlen(a), ft_strlen(a));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for %s. Original: %zu My own: %zu" RESET "\n", i, a, strlen(a), ft_strlen(a));
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

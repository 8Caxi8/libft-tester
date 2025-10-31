/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:57:02 by caxi              #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
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
	int		c;
	char	*s;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_strchr";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	c = 'c';
	s = "Olaa, como vais?";
	if (strcmp(strchr(s, c), ft_strchr(s, c)) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %c). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %c). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
	i++;

	///////////Test 2///////////
	c = 'O';
	s = "Olaa, como vais?";
	if (strcmp(strchr(s, c), ft_strchr(s, c)) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %c). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %c). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
	i++;

	///////////Test 3///////////
	c = 0;
	s = "Olaa, como vais?";
	if (strcmp(strchr(s, c), ft_strchr(s, c)) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %c). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
	i++;

	///////////Test 5///////////
	c = 'c' - 255;
	s = "Olaa, como vais?";
	if(ft_strchr(s, c) == NULL)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %d). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %d). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
	i++;

	///////////Test 6///////////
	c = 'c' + 256;
	s = "Olaa, como vais?";
	if (ft_strchr(s, c) != NULL)
	{
		if (strcmp(strchr(s, c), ft_strchr(s, c)) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %c). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
			success++;
		}
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %c). Original: \"%s\" My own: \"%s\"" RESET "\n", i, s, c, strchr(s, c), ft_strchr(s, c));
	i++;
	
	///////////Test 7///////////
	c = 3;
	s = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		ft_strchr(s, c);
        printf(RED "✗ [%d] Testing for %s. Original: <<seg fault>> My own: %s" RESET "\n", i, s, ft_strchr(s, c));
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for %s. Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, s);
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

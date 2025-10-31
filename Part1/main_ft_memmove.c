/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:47:41 by caxi              #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
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
	size_t	n;
	int		success = 0;
	int		j;
	int		i = 0;
	int		fd;
	char	*function = "ft_memmove";
	const char	*t0 = "Tudo bem? Ola";
	const char	*t3 = NULL;
	int			t4[3] = {0, 2, INT_MAX};
	char	*a = malloc(1024);
	char	*b = malloc(1024);

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	n = 7;
	b = strcpy(b,t0);
	a = strcpy(a,t0);
	ft_memmove(b+5, b, n);
	memmove(a+5, a, n);
	
	if (memcmp(a, b, n) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%s, (str + 5, str), %zu). ", i, t0, n);
		printf("Original: %s ", a);
		printf("My own: %s", b);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (%s, (str + 5, str), %zu). ", i, t0, n);
		printf("Original: %s ", a);
		printf("My own: %s", b);
		printf(RESET "\n");
	}
	i++;

	///////////Test 2///////////
	n = 3;
	b = strcpy(b,t0);
	a = strcpy(a,t0);
	ft_memmove(b, b + 5, n);
	memmove(a, a + 5, n);
	
	if (memcmp(a, b, n) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%s, (str, str + 5), %zu). ", i, t0, n);
		printf("Original: %s ", a);
		printf("My own: %s", b);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (%s, (str, str + 5), %zu). ", i, t0, n);
		printf("Original: %s ", a);
		printf("My own: %s", b);
		printf(RESET "\n");
	}
	i++;

	///////////Test 3///////////
	n = 7;
	b = strcpy(b,t0);
	a = strcpy(a,t0);
	ft_memmove(b + 2, b, n);
	memmove(a + 2, a, n);
	
	if (memcmp(a, b, n) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%s, (str + 2, str), %zu). ", i, t0, n);
		printf("Original: %s ", a);
		printf("My own: %s", b);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (%s, (str + 2, str), %zu). ", i, t0, n);
		printf("Original: %s ", a);
		printf("My own: %s", b);
		printf(RESET "\n");
	}
	i++;

	///////////Test 4///////////
	n = 6;
	memcpy(b, t4, 3 * 4);
	memcpy(a, t4, 3 * 4);
	ft_memmove(b, b + 4, n);
	memmove(a, a + 4, n);
	
	if (memcmp(a, b, 3*4) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for ({%d, %d, %d}, (str, str + 4), %zu). ", i, t4[0], t4[1], t4[2], n);
		printf("Original: ");
		j = -1;
		while (++j < 3)
			printf("/%d", ((int *)a)[j]);
		printf(" My own: ");
		j = -1;
		while (++j < 3)
			printf("/%d", ((int *)b)[j]);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for ({%d, %d, %d}, (str, str + 4), %zu). ", i, t4[0], t4[1], t4[2], n);
		printf("Original: ");
		j = -1;
		while (++j < 3)
			printf("/%d", (int)a[j]);
		printf(" My own: ");
		j = -1;
		while (++j < 3)
			printf("/%d", (int)b[j]);
		printf(RESET "\n");
	}
	i++;

	///////////Test 5///////////
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		b = (char *)ft_memmove(NULL, t0, n);
        printf(RED "✗ [%d] Testing for %s. Original: <<seg fault>> My own: %s" RESET "\n", i, t3, b);
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for %s. Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, t3);
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
	free(a);
	free(b);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:21:24 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 13:07:49 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <limits.h>
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
	size_t		j;
	int		i = 0;
	int		fd;
	char	*function = "ft_bzero";
	const char	*t1 = "Olaaaa";
	const char	*t2 = "";
	const char	*t3 = NULL;
	int			t4[3] = {INT_MIN, INT_MAX, 3};
	char	*a = malloc(1024);
	char	*b = malloc(1100);

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	n = 5;
	ft_bzero(strcpy(b,t1), n);
	bzero(strcpy(a,t1), n);
	
	if (memcmp(a, b, n) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%s, %zu). ", i, t1, n);
		printf("Original: ");
		j = -1;
		while (++j < strlen(t1))
			printf("/%d", a[j]);
		printf(" My own: ");
		j = -1;
		while (++j < strlen(t1))
			printf("/%d", b[j]);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (%s, %zu). ", i, t1, n);
		printf("Original: ");
		j = -1;
		while (++j < strlen(t1))
			printf("/%d", a[j]);
		printf(" My own: ");
		j = -1;
		while (++j < strlen(t1))
			printf("/%d", b[j]);
		printf(RESET "\n");
	}
	i++;

	///////////Test 2///////////
	n = strlen(t1) + 1;
	ft_bzero(strcpy(b,t1), strlen(t1) + 1);
	bzero(strcpy(a,t1), strlen(t1) + 1);
	
	if (memcmp(a, b, n) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%s, %zu). ", i, t1, n);
		printf("Original: ");
		j = -1;
		while (++j < strlen(t1) + 1)
			printf("/%d", a[j]);
		printf(" My own: ");
		j = -1;
		while (++j < strlen(t1) + 1)
			printf("/%d", b[j]);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (%s, %zu). ", i, t1, n);
		printf("Original: ");
		j = -1;
		while (++j < strlen(t1) + 1)
			printf("/%d", a[j]);
		printf(" My own: ");
		j = -1;
		while (++j < strlen(t1) + 1)
			printf("/%d", b[j]);
		printf(RESET "\n");
	}
	i++;

	///////////Test 3///////////
	n = 1;
	ft_bzero(strcpy(b,t2), n);
	bzero(strcpy(a,t2), n);
	
	if (memcmp(a, b, n) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%s, %zu). ", i, t2, n);
		printf("Original: ");
		j = -1;
		while (++j < n)
			printf("/%d", a[j]);
		printf(" My own: ");
		j = -1;
		while (++j < n)
			printf("/%d", b[j]);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (%s, %zu). ", i, t2, n);
		printf("Original: ");
		j = -1;
		while (++j < n)
			printf("/%d", a[j]);
		printf(" My own: ");
		j = -1;
		while (++j < n)
			printf("/%d", b[j]);
		printf(RESET "\n");
	}
	i++;

	///////////Test 4///////////
	n = 6;
	b = memcpy(b, t4, 3 * 4);
	a = memcpy(a, t4, 3 * 4);
	ft_bzero(strcpy(b,(char *)t4), n);
	bzero(strcpy(a,(char *)t4), n);
	
	if (memcmp(a, b, n) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for ({%d, %d, %d}, %zu). ", i, t4[0], t4[1], t4[2], n);
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
		printf(RED "✗ [%d] Testing for ({%d, %d, %d}, %zu). ", i, t4[0], t4[1], t4[2], n);
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
	n = 6;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		ft_bzero(NULL, n);
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
		write(fd, "OK :D\n", 6);
	else
		write(fd, "KO :(\n", 6);
	close (fd);
	free(a);
	free(b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:53:01 by caxi              #+#    #+#             */
/*   Updated: 2025/10/30 13:07:49 by dansimoe         ###   ########.fr       */
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
	int		j;
	size_t	n;
	void	*t = malloc(1024);
	void	*s1;
	void	*s2;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_memchr";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1//////////
	c = 'c';
	strcpy(t, "Olaaa, como vao?");
	n = strlen(t) + 1;
	s1 = memchr(t, c, n);
	s2 = ft_memchr(t, c, n);
	if (s1 != NULL && s2 != NULL)
	{
		if (memcmp(s1, s2, n) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %c, %lu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, (char *)t, (char)c, n, (char *)s1, (char *)s2);
			success++;
		}
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", %c, %lu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, (char *)t, (char)c, n, (char *)s1, (char *)s2);
	i++;
	
	 ///////////Test 2///////////
	c = -29;
	((int *)t)[0] = INT_MAX;
	((int *)t)[1] = 254862;
	((int *)t)[2] = 256;
	n = 6;
	s1 = memchr(t, c, n);
	s2 = ft_memchr(t, c, n);
	if (s1 != NULL && s2 != NULL)
	{
		if (memcmp(s1, s2, n) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for ({%d, %d, %d}, %d, %zu). ", i, ((int *)t)[0], ((int *)t)[1], ((int *)t)[2], c, n);
			printf("Original: ");
			j = -1;
			while (++j < 6)
			printf("/%d", ((char *)s1)[j]);
			printf(" My own: ");
			j = -1;
			while (++j < 6)
				printf("/%d", ((char *)s2)[j]);
			printf(RESET "\n");
			success++;
		}
	}
	else
	{
		printf(RED "✗ [%d] Testing for ({%d,%d,%d}, %c, %lu). ", i, ((int *)t)[0], ((int *)t)[1], ((int *)t)[2], (char)c, n);
		printf("Original: ");
			j = -1;
			while (++j < 6)
			printf("/%d", ((char *)s1)[j]);
			if (s2 == NULL)
			{
				printf(" My own: (null)" RESET "\n");
			}
			else
			{
			printf(" My own: ");
			j = -1;
			while (++j < 6)
				printf("/%d", ((char *)s2)[j]);
			printf(RESET "\n");
			}
	}
	i++;
	
	///////////Test 3///////////
	c = -28;
	((int *)t)[0] = INT_MAX;
	((int *)t)[1] = 254862;
	((int *)t)[2] = 256;
	n = 8;
	s1 = memchr(t, c, n);
	s2 = ft_memchr(t, c, n);
	if (s1 == NULL)
	{
		printf(GREEN "✓" GREY " [%d] Testing for ({%d, %d, %d}, %d, %zu). Original: (null) My own: (null)" RESET "\n", i, ((int *)t)[0], ((int *)t)[1], ((int *)t)[2], c, n);
		success++;
	}
	else
	{
		printf(RED "✗ [%d] Testing for ({%d,%d,%d}, %c, %lu). Original: {%d,%d,%d} My own: {%d,%d,%d}" RESET "\n", i, ((int *)t)[0], ((int *)t)[1], ((int *)t)[2], (char)c, n, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2]);
		printf("Original: (null)");
		printf(" My own: ");
		j = -1;
		while (++j < 6)
			printf("/%d", ((char *)s2)[j]);
		printf(RESET "\n");
	}
	i++;
	
	///////////Test 7///////////
	c = 'c';
	s1 = NULL;
	n = 5;
	if (sigsetjmp(jump_buffer, 1) == 0) 
	{
		ft_memchr(s1, c, n);
        printf(RED "✗ [%d] Testing for (\"%s\", %c, %lu). Original: <<seg fault>> My own: %s" RESET "\n", i, (char *)s1, (char)c, n, (char *)ft_memchr(s1, c, n));
	}
	else 
	{
        printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", %c, %lu). Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, (char *)s1, (char)c, n);
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
	free(t);
	return (0);
}

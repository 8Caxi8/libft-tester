/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:05:53 by caxi              #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
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
	size_t	size;
	size_t	nmemb;
	int		success = 0;
	size_t		j;
	int		i = 0;
	int		fd;
	char	*function = "ft_calloc";
	void	*s1;
	void	*s2;

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	size = 5;
	nmemb = 2;
	s1 = calloc(nmemb, size);
	j = -1;
	while (++j < 5)
	{
		s2 = malloc(size * nmemb);
		s2 = memset(s2, 43, size * nmemb);
		free(s2);
	}
	s2 = ft_calloc(nmemb, size);
	
	if (memcmp(s1, s2, nmemb * size) == 0)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%zu, %zu). ", i, nmemb, size);
		printf("Original: ");
		j = -1;
		while (++j < 2)
			printf("/%d", ((char *)s1)[j]);
		printf(" My own: ");
		j = -1;
		while (++j < 2)
			printf("/%d", ((char *)s2)[j]);
		printf(RESET "\n");
		success++;
	}
	else
	{		
		printf(RED "✗ [%d] Testing for (%zu, %zu). ", i, nmemb, size);
		printf("Original: ");
		j = -1;
		while (++j < 2)
			printf("/%d", ((char *)s1)[j]);
		printf(" My own: ");
		j = -1;
		while (++j < size * nmemb)
			printf("/%d", ((char *)s2)[j]);
		printf(RESET "\n");
	}
	free(s1);
	free(s2);
	i++;
 
	///////////Test 1///////////
	size = (SIZE_MAX / 16) + 1;
	nmemb = 32;
	s1 = calloc(nmemb, size);
	s2 = ft_calloc(nmemb, size);
	if (!s2)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%zu, %zu). Original: \"%s\" My own: \"%s\"" RESET "\n", i, nmemb, size, (char *)s1, (char *)s2);
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (%zu, %zu). Original: \"%s\" My own: \"(not null)\"" RESET "\n", i, nmemb, size, (char *)s1);
	i++;
	free(s1);
	free(s2);

	///////////Test 3///////////
	size = 0;
	nmemb = 2;
	s1 = calloc(nmemb, size);
	s2 = ft_calloc(nmemb, size);
	if (s2)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%zu, %zu). Original: (0) My own: (0)" RESET "\n", i, nmemb, size);
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (%zu, %zu). Original: (0) My own: \"%s\"" RESET "\n", i, nmemb, size, (char *)s2);
	i++;
	free(s1);
	free(s2);

	///////////Test 3///////////
	size = 1;
	nmemb = 0;
	s1 = calloc(nmemb, size);
	s2 = ft_calloc(nmemb, size);
	if (s2)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%zu, %zu). Original: (0) My own: (0)" RESET "\n", i, nmemb, size);
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (%zu, %zu). Original: (0) My own: \"%s\"" RESET "\n", i, nmemb, size, (char *)s2);
	i++;
	free(s1);
	free(s2);

	///////////Test 3///////////
	size = 0;
	nmemb = 0;
	s1 = calloc(nmemb, size);
	s2 = ft_calloc(nmemb, size);
	if (s2)
	{
		printf(GREEN "✓" GREY " [%d] Testing for (%zu, %zu). Original: (0) My own: (0)" RESET "\n", i, nmemb, size);
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (%zu, %zu). Original: (0) My own: \"%s\"" RESET "\n", i, nmemb, size, (char *)s2);
	i++;
	free(s1);
	free(s2);

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:37:44 by caxi              #+#    #+#             */
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
#define GREY "\033[90m"
#define BLACK_ON_GREEN "\033[1;30;102m"
#define WHITE_ON_RED "\033[1;37;41m"
#define ITALIC_BLUE "\033[3;34m"
#define RED "\033[91m"
#define RESET "\033[0m"

static sigjmp_buf jump_buffer;

void segfault_handler(int sig)
{
	(void)sig;
	siglongjmp(jump_buffer, 1);
}

int main()
{
	size_t n;
	void *s1 = malloc(1024);
	void *s2 = malloc(1024);
	void *s3 = NULL;
	int success = 0;
	int i = 0;
	int fd;
	char *function = "ft_memcmp";

	signal(SIGSEGV, segfault_handler);

	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}

	///////////Test 1//////////
	s1 = memcpy(s1, "Olaa!", 6);
	s2 = memcpy(s2, "Ola", 4);
	n = 4;
	if (memcmp(s1, s2, n) == ft_memcmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, (char *)s1, (char *)s2, n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, (char *)s1, (char *)s2, n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
	i++;

	///////////Test 2///////////
	((int *)s1)[0] = INT_MAX;
	((int *)s1)[1] = 254862;
	((int *)s1)[2] = 256;
	((int *)s2)[0] = INT_MAX;
	((int *)s2)[1] = 254862;
	((int *)s2)[2] = 256;
	n = 12;
	if (memcmp(s1, s2, n) == ft_memcmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for ({%d,%d,%d}, {%d,%d,%d}, %lu). Original: %d My own: %d" RESET "\n", i, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2], n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for ({%d,%d,%d}, {%d,%d,%d}, %lu). Original: %d My own: %d" RESET "\n", i, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2], n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
	i++;

	///////////Test 3///////////
	((int *)s1)[0] = INT_MAX;
	((int *)s1)[1] = 254862;
	((int *)s1)[2] = 256;
	((int *)s2)[0] = INT_MAX;
	((int *)s2)[1] = 254862;
	((int *)s2)[2] = 254;
	n = 12;
	if (memcmp(s1, s2, n) == ft_memcmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for ({%d,%d,%d}, {%d,%d,%d}, %lu). Original: %d My own: %d" RESET "\n", i, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2], n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for ({%d,%d,%d}, {%d,%d,%d}, %lu). Original: %d My own: %d" RESET "\n", i, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2], n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
	i++;

	///////////Test 3///////////
	((int *)s1)[0] = INT_MAX;
	((int *)s1)[1] = 254862;
	((int *)s1)[2] = 256;
	((int *)s2)[0] = INT_MAX;
	((int *)s2)[1] = 254862;
	((int *)s2)[2] = 254;
	n = 1;
	if (memcmp(s1, s2, n) == ft_memcmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for ({%d,%d,%d}, {%d,%d,%d}, %lu). Original: %d My own: %d" RESET "\n", i, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2], n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for ({%d,%d,%d}, {%d,%d,%d}, %lu). Original: %d My own: %d" RESET "\n", i, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2], n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
	i++;

	///////////Test 3///////////
	((int *)s1)[0] = INT_MAX;
	((int *)s1)[1] = 254862;
	((int *)s1)[2] = 256;
	((int *)s2)[0] = INT_MAX;
	((int *)s2)[1] = 254862;
	((int *)s2)[2] = 254;
	n = 0;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_memcmp(s1, s2, n);
		printf(GREEN "✓" GREY " [%d] Testing for ({%d,%d,%d}, {%d,%d,%d}, %lu). Original: %d My own: %d" RESET "\n", i, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2], n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
		success++;
	}
	else
	{
		printf(RED "✗ [%d] Testing for ({%d,%d,%d}, {%d,%d,%d}, %lu). Original: %d My own: <<seg fault>>" RESET "\n", i, ((int *)s1)[0], ((int *)s1)[1], ((int *)s1)[2], ((int *)s2)[0], ((int *)s2)[1], ((int *)s2)[2], n, memcmp(s1, s2, n));
	}
	i++;

	///////////Test 5///////////
	s1 = memcpy(s1, "", 1);
	s2 = memcpy(s2, "", 1);
	n = 1;
	if (memcmp(s1, s2, n) == ft_memcmp(s1, s2, n))
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, (char *)s1, (char *)s2, n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: %d My own: %d" RESET "\n", i, (char *)s1, (char *)s2, n, memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
	i++;

	///////////Test 6///////////
	s1 = memcpy(s1, "", 1);
	n = 5;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_memcmp(s1, s3, n);
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: %d" RESET "\n", i, (char *)s1, (char *)s3, n, ft_memcmp(s1, s2, n));
	}
	else
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, (char *)s1, (char *)s3, n);
		success++;
	}
	i++;

	///////////Test 7///////////
	s2 = memcpy(s2, "", 1);
	n = 5;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_memcmp(s3, s2, n);
		printf(RED "✗ [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: %d" RESET "\n", i, (char *)s3, (char *)s2, n, ft_memcmp(s1, s2, n));
	}
	else
	{
		printf(GREEN "✓" GREY " [%d] Testing for (\"%s\", \"%s\", %lu). Original: <<seg fault>> My own: <<seg fault>>" RESET "\n", i, (char *)s3, (char *)s2, n);
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
	close(fd);
	return (0);
}

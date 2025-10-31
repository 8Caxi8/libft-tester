/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:45:29 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <setjmp.h>

#define GREEN "\033[92m"
#define GREY  "\033[90m"
#define BLACK_ON_GREEN "\033[1;30;102m"
#define WHITE_ON_RED "\033[1;37;41m"
#define ITALIC_BLUE "\033[3;34m"
#define RED "\033[91m"
#define RESET "\033[0m"
#define BUF_LEN 1024

static sigjmp_buf jump_buffer;

void segfault_handler(int sig)
{
    (void) sig;
    siglongjmp(jump_buffer, 1);
}

int	main()
{
	int		fdt;
	int		nbr;
	char	buffer[BUF_LEN];
	char	*exp;
	int		len;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_putnbr_fd";
	
	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	nbr = -2;
	exp = "-2";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		fdt = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		ft_putnbr_fd(nbr, fdt);
		close (fdt);
		fdt = open("test.txt", O_RDONLY);
		len = read(fdt, buffer, BUF_LEN);
		buffer[len] = 0;
		if (strcmp(buffer, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
		close(fdt);
		unlink("test.txt");
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, nbr, exp);
	i++;
 
	///////////Test 1///////////
	nbr = 0;
	exp = "0";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		fdt = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		ft_putnbr_fd(nbr, fdt);
		close (fdt);
		fdt = open("test.txt", O_RDONLY);
		len = read(fdt, buffer, BUF_LEN);
		buffer[len] = 0;
		if (strcmp(buffer, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
		close(fdt);
		unlink("test.txt");
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, nbr, exp);
	i++;

	///////////Test 1///////////
	nbr = 6;
	exp = "6";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		fdt = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		ft_putnbr_fd(nbr, fdt);
		close (fdt);
		fdt = open("test.txt", O_RDONLY);
		len = read(fdt, buffer, BUF_LEN);
		buffer[len] = 0;
		if (strcmp(buffer, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
		close(fdt);
		unlink("test.txt");
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, nbr, exp);
	i++;

	///////////Test 1///////////
	nbr = INT_MAX;
	exp = "2147483647";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		fdt = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		ft_putnbr_fd(nbr, fdt);
		close (fdt);
		fdt = open("test.txt", O_RDONLY);
		len = read(fdt, buffer, BUF_LEN);
		buffer[len] = 0;
		if (strcmp(buffer, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
		close(fdt);
		unlink("test.txt");
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, nbr, exp);
	i++;

	///////////Test 1///////////
	nbr = INT_MIN;
	exp = "-2147483648";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		fdt = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		ft_putnbr_fd(nbr, fdt);
		close (fdt);
		fdt = open("test.txt", O_RDONLY);
		len = read(fdt, buffer, BUF_LEN);
		buffer[len] = 0;
		if (strcmp(buffer, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: \"%s\"" RESET "\n", i, nbr, exp, buffer);
		close(fdt);
		unlink("test.txt");
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, nbr, exp);
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
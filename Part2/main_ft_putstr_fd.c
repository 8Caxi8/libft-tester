/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:44:41 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/30 13:07:49 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
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
	char	*c;
	char	buffer[BUF_LEN];
	char	*exp;
	int		len;
	int		success = 0;
	int		i = 0;
	int		fd;
	char	*function = "ft_putstr_fd";
	
	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	c = "Ola!!";
	exp = "Ola!!";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		fdt = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		ft_putstr_fd(c, fdt);
		close (fdt);
		fdt = open("test.txt", O_RDONLY);
		len = read(fdt, buffer, BUF_LEN);
		buffer[len] = 0;
		if (strcmp(buffer, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, c, exp, buffer);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, c, exp, buffer);
		close(fdt);
		unlink("test.txt");
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, c, exp);
	i++;
 
	///////////Test 1///////////
	c = "";
	exp = "";
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		fdt = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		ft_putstr_fd(c, fdt);
		close (fdt);
		fdt = open("test.txt", O_RDONLY);
		len = read(fdt, buffer, BUF_LEN);
		buffer[len] = 0;
		if (strcmp(buffer, exp) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, c, exp, buffer);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"%s\"" RESET "\n", i, c, exp, buffer);
		close(fdt);
		unlink("test.txt");
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, c, exp);
	i++;

	///////////Test 1///////////
	c = NULL;
	exp = NULL;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		fdt = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		ft_putstr_fd(c, fdt);
		close (fdt);
		fdt = open("test.txt", O_RDONLY);
		len = read(fdt, buffer, BUF_LEN);
		if (len == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for \"%s\". Expected: \"len = 0\" My own: \"len = %d\"" RESET "\n", i, c, len);
			success++;
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"len = 0\" My own: \"len = %d\"" RESET "\n", i, c, len);
		close(fdt);
		unlink("test.txt");
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"len = 0\" My own: <<seg fault>>" RESET "\n", i, c);
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
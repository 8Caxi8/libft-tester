/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:22:17 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/30 19:56:31 by dansimoe         ###   ########.fr       */
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
t_list	*lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list); 
}

int	main()
{
	t_list			*header;
	t_list			*second;
	t_list			*third;
	int				size;
	int				expi;
	//int				expi[4];
	//int				subi[4];
	int				t;
	int				j;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_lstsize";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	char	exp[4][1024] = {"ola", "tudo", "bem", "contigo?"};
	char	sub[4][1024] = {"ola", "tudo", "bem", "contigo?"};
	header = lstnew(sub[0]);
	second = lstnew(sub[1]);
	third = lstnew(sub[2]);
	header->next = second;
	second->next = third;
	expi = 3;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		size = ft_lstsize(header);
		if (size == expi)
		{
			printf(GREEN "✓" GREY " [%d] ", i);
			printf("Testing for: ");
			j =-1;
			while (++j < 3)
				printf("->\"%s\"", exp[j]);
			printf(" Expected: %d My own: %d" RESET "\n", expi, size);
			success++;
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: ");
			j =-1;
			while (++j < 3)
				printf("->\"%s\"", exp[j]);
			printf(" Expected: %d My own: %d" RESET "\n", expi, size);
		}
	}
	else
	{
		printf(RED "✗ [%d] ", i);
		printf("Testing for: ");		
		j =-1;
		while (++j < 3)
			printf("->\"%s\"", exp[j]);
		printf(" Expected: %d My own: <<seg fault>>" RESET "\n", expi);
	}
	i++;
  
	///////////Test 1///////////
	header = lstnew(sub[0]);
	expi = 1;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		size = ft_lstsize(header);
		if (size == expi)
		{
			printf(GREEN "✓" GREY " [%d] ", i);
			printf("Testing for: ");
			j =-1;
			while (++j < 1)
				printf("->\"%s\"", exp[j]);
			printf(" Expected: %d My own: %d" RESET "\n", expi, size);
			success++;
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: ");
			j =-1;
			while (++j < 1)
				printf("->\"%s\"", exp[j]);
			printf(" Expected: %d My own: %d" RESET "\n", expi, size);
		}
	}
	else
	{
		printf(RED "✗ [%d] ", i);
		printf("Testing for: ");		
		j =-1;
		while (++j < 1)
			printf("->\"%s\"", exp[j]);
		printf(" Expected: %d My own: <<seg fault>>" RESET "\n", expi);
	}
	i++;

	///////////Test 1///////////
	header = lstnew(NULL);
	second = lstnew(NULL);
	header->next = second;
	expi = 2;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		size = ft_lstsize(header);
		if (size == expi)
		{
			printf(GREEN "✓" GREY " [%d] ", i);
			printf("Testing for: ->\"(null)\"->\"(null)\"");
			printf(" Expected: %d My own: %d" RESET "\n", expi, size);
			success++;
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: ->\"(null)\"->\"(null)\"");
			printf(" Expected: %d My own: %d" RESET "\n", expi, size);
		}
	}
	else
	{
		printf(RED "✗ [%d] ", i);
		printf("Testing for: ->\"(null)\"->\"(null)\"");
		printf(" Expected: %d My own: <<seg fault>>" RESET "\n", expi);
	}
	i++;

	///////////Test 1///////////
	expi = 0;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		size = ft_lstsize(NULL);
		if (size == expi)
		{
			printf(GREEN "✓" GREY " [%d] ", i);
			printf("Testing for: (null)");
			printf(" Expected: %d My own: %d" RESET "\n", expi, size);
			success++;
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: (null)");
			printf(" Expected: %d My own: %d" RESET "\n", expi, size);
		}
	}
	else
	{
		printf(RED "✗ [%d] ", i);
		printf("Testing for: (null)");
		printf(" Expected: %d My own: <<seg fault>>" RESET "\n", expi);
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
	return (0);
}
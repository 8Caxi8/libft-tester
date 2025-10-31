/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:57:29 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <bsd/string.h>
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
	t_list			*new;
	t_list			*sub;
	char			*exp;
	//int				expi[4];
	//int				subi[4];
	int				j;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_lstlast";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	exp = "contigo?";
	char	s[4][1024] = {"ola", "tudo", "bem", "contigo?"};
	header = lstnew(s[0]);
	second = lstnew(s[1]);
	third = lstnew(s[2]);
	new = lstnew(s[3]);
	header->next = second;
	second->next = third;
	third->next = new;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_lstlast(header);
		if (sub)
		{
			if (strcmp(sub->content,new->content)== 0)
			{
				printf(GREEN "✓" GREY " [%d] ", i);
				printf("Testing for: ");
				j =-1;
				while (++j < 4)
					printf("->\"%s\"", s[j]);
				printf("Expected: \"%s\" My own: \"%s\"", (char *)new->content, (char *)sub->content);
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] ", i);
				printf("Testing for: ");
				j =-1;
				while (++j < 4)
					printf("->\"%s\"", s[j]);
				printf("Expected: \"%s\" My own: \"%s\"", (char *)new->content, (char *)sub->content);
				printf(RESET "\n");
			}
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: ");
			j =-1;
			while (++j < 4)
				printf("->\"%s\"", s[j]);
			printf("Expected: \"%s\" My own: \"%s\"", (char *)new->content, (char *)sub->content);
			printf(RESET "\n");
		}
	}
	else
	{
		printf(RED "✗ [%d] ", i);
		printf("Testing for: ");
		j =-1;
		while (++j < 4)
			printf("->\"%s\"", s[j]);
		printf("Expected: \"%s\" My own: <<seg fault>>", (char *)new->content);
		printf(RESET "\n");
	}
	i++;

	///////////Test 1///////////
	exp = "contigo?";
	size_t	s1[3] = {0, 42, SIZE_MAX};
	header = lstnew(s[0]);
	second = lstnew(s[1]);
	third = lstnew(s[2]);
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_lstlast(header);
		if (sub)
		{
			if (*(size_t *)sub->content == *(size_t *)third->content)
			{
				printf(GREEN "✓" GREY " [%d] ", i);
				printf("Testing for: ");
				j =-1;
				while (++j < 3)
					printf("->%zu", s1[j]);
				printf("Expected: %zu My own: %zu", *(size_t *)third->content, *(size_t *)sub->content);
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] ", i);
				printf("Testing for: ");
				j =-1;
				while (++j < 3)
					printf("->%zu", s1[j]);
				printf("Expected: %zu My own: %zu", *(size_t *)third->content, *(size_t *)sub->content);
				printf(RESET "\n");
			}
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: ");
				j =-1;
				while (++j < 3)
					printf("->%zu", s1[j]);
				printf("Expected: %zu My own: %zu", *(size_t *)third->content, *(size_t *)sub->content);
				printf(RESET "\n");
		}
	}
	else
	{
		printf(RED "✗ [%d] ", i);
		printf("Testing for: ");
		j =-1;
		while (++j < 3)
			printf("->%zu", s1[j]);
		printf("Expected: %zu My own: <<seg fault>>", *(size_t *)third->content);
		printf(RESET "\n");
	}
	i++;

	///////////Test 1///////////
	exp = "contigo?";
	char	s2[4][1024] = {"ola", "tudo", "bem", "contigo?"};
	header = lstnew(s[3]);
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_lstlast(header);
		if (sub)
		{
			if (strcmp(sub->content,new->content)== 0)
			{
				printf(GREEN "✓" GREY " [%d] ", i);
				printf("Testing for: ");
				printf("->\"%s\"", s2[3]);
				printf("Expected: \"%s\" My own: \"%s\"", (char *)header->content, (char *)sub->content);
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] ", i);
				printf("Testing for: ");
				printf("->\"%s\"", s2[3]);
				printf("Expected: \"%s\" My own: \"%s\"", (char *)header->content, (char *)sub->content);
				printf(RESET "\n");
			}
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: ");
			printf("->\"%s\"", s2[3]);
			printf("Expected: \"%s\" My own: \"%s\"", (char *)header->content, (char *)sub->content);
			printf(RESET "\n");
		}
	}
	else
	{
		printf(RED "✗ [%d] ", i);
		printf("Testing for: ");
		printf("->\"%s\"", s2[3]);
		printf("Expected: \"%s\" My own: <<seg fault>>", (char *)header->content);
		printf(RESET "\n");
	}
	i++;
	
	///////////Test 1///////////
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		sub = ft_lstlast(NULL);
		if (!sub)
		{
			printf(GREEN "✓" GREY " [%d] ", i);
			printf("Testing for: ");
			printf("(null)");
			printf("Expected: (null) My own: (null)");
			printf(RESET "\n");
			success++;
			
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: ");
			printf("(null)");
			printf("Expected: \"(null)\" My own: \"%s\"", (char *)sub->content);
			printf(RESET "\n");
		}
	}
	else
	{
		printf(RED "✗ [%d] ", i);
		printf("Testing for: ");
		printf("(null)");
		printf("Expected: \"(null)\" My own: <<seg fault>>");
		printf(RESET "\n");
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

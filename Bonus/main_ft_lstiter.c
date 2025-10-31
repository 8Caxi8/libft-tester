/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:39:54 by dansimoe          #+#    #+#             */
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

void	rot13(void *str)
{
	char	*s = (char *)str;
	
	while (*(char *)s != 0)
	{
		if ((*(char *)s >= 'a' && *(char *)s <= 'm') || (*(char *)s >= 'A' && *(char *)s <= 'M'))
			*(char *)s += 13;
		else if ((*(char *)s >= 'n' && *(char *)s <= 'z') || (*(char *)s >= 'N' && *(char *)s <= 'Z'))
			*(char *)s -= 13;
		s++;
	}
}

void	sum1(void *i)
{
	(*(int *)i)++;
}

int	main()
{
	t_list			*header;
	t_list			*second;
	t_list			*third;
	t_list			*temp;
	//int				expi[4];
	//int				subi[4];
	int				t;
	int				j;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_lstiter";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	header = lstnew(ft_strdup("Olaa"));
	second = lstnew(ft_strdup("tudo"));
	third = lstnew(ft_strdup("bem"));
	char	s[3][1024] = {"Olaa", "tudo", "bem"};
	char	exp[3][1024] = {"Bynn", "ghqb", "orz"};
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstiter(header, &rot13);
		if (header)
		{
			t = 0;
			j = -1;
			temp = header;
			while (temp)
			{
				t += strcmp(temp->content, exp[++j]);
				temp = temp->next;
			}
			if (t == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for ", i);
				j =-1;
				while (++j < 3)
					printf("->\"%s\"", s[j]);
				printf(" Expected: ");
				j =-1;
				while (++j < 3)
					printf("->\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("->\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for ", i);
				j =-1;
				while (++j < 3)
					printf("->\"%s\"", s[j]);
				printf(" Expected: ");
				j = -1;
				while (++j < 3)
					printf("->\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("->\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
			}
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp[0], exp[0]);
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp[0], exp[0]);
	i++;

	///////////Test 1///////////
	header = lstnew(ft_strdup("Olaa"));
	second = lstnew(ft_strdup("tudo"));
	third = lstnew(ft_strdup("bem"));
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstiter(NULL, NULL);
		printf(GREEN "✓" GREY " [%d] ", i);
		printf("Testing for: header = (null) and f = (null)");
		printf(" Expected: ");
		j =-1;
		while (++j < 3)
			printf("->\"%s\"", exp[j]);
		printf(" My own: ");
		j = -1;
		temp = header;
		while (temp)
		{
			printf("->\"%s\"", (char *)temp->content);
			temp = temp->next;
			free(header);
			header = temp;
		}
		printf(RESET "\n");
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for lst = (Null) and f = (null). My own: <<seg fault>>" RESET "\n", i);
	i++;

	///////////Test 1///////////
	header = lstnew(ft_strdup("Olaa"));
	second = lstnew(ft_strdup("tudo"));
	third = lstnew(ft_strdup("bem"));
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstiter(header, NULL);
		if (header)
		{
			t = 0;
			j = -1;
			temp = header;
			while (temp)
			{
				t += strcmp(temp->content, s[++j]);
				temp = temp->next;
			}
			if (t == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for f = (null) and ", i);
				j =-1;
				while (++j < 3)
					printf("->\"%s\"", s[j]);
				printf(" Expected: ");
				j =-1;
				while (++j < 3)
					printf("->\"%s\"", s[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("->\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for f = (null) and ", i);
				j =-1;
				while (++j < 3)
					printf("->\"%s\"", s[j]);
				printf(" Expected: ");
				j = -1;
				while (++j < 3)
					printf("->\"%s\"", s[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("->\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
			}
		}
		else
			printf(RED "✗ [%d] Testing for f = (null). Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp[0]);
	}
	else
		printf(RED "✗ [%d] Testing for f = (null). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp[0]);
	i++;

	///////////Test 1///////////
	int	num[3] = {42, 0, -1};
	header = lstnew(&num[0]);
	second = lstnew(&num[1]);
	third = lstnew(&num[2]);
	int	s1[3] = {42, 0, -1};
	int	exp1[3] = {43, 1, 0};
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstiter(header, &sum1);
		if (header)
		{
			t = 0;
			j = -1;
			temp = header;
			while (temp)
			{
				if (*(int *)temp->content != exp1[++j])
					t ++;
				temp = temp->next;
			}
			if (t == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for ", i);
				j =-1;
				while (++j < 3)
					printf("->%d", s1[j]);
				printf(" Expected: ");
				j =-1;
				while (++j < 3)
					printf("->%d", exp1[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("->%d", *(int *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for ", i);
				j =-1;
				while (++j < 3)
					printf("->%d", s1[j]);
				printf(" Expected: ");
				j = -1;
				while (++j < 3)
					printf("->%d", exp1[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("->%d", *(int *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
			}
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: %d My own: \"(null)\"" RESET "\n", i, exp1[0], exp1[0]);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: %d My own: <<seg fault>>" RESET "\n", i, exp1[0], exp1[0]);
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

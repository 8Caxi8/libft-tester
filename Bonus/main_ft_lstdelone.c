/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:50:51 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/30 21:22:04 by dansimoe         ###   ########.fr       */
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

void del(void *s)
{
	s = NULL;
}

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
	t_list			*temp;
	t_list			*new;
	//int				expi[4];
	//int				subi[4];
	int				t;
	int				j;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_lstdelone";

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
	new = lstnew(sub[3]);
	header->next = second;
	second->next = third;
	third->next = new;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstdelone(third, &del);
		second->next = NULL;
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
			printf(GREEN "✓" GREY " [%d] ", i);
			printf("Testing for: ");
			j =-1;
			while (++j < 2)
				printf("->\"%s\"", exp[j]);
			printf("Expected: ");
			j =-1;
			while (++j < 2)
				printf("\\\"%s\"", exp[j]);
			printf(" My own: ");
			j = -1;
			temp = header;
			while (temp)
			{
				printf("\\\"%s\"", (char *)temp->content);
				temp = temp->next;
				free(header);
				header = temp;
			}
			printf(RESET "\n");
			success++;
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: ");
			j =-1;
			while (++j < 2)
				printf("->\"%s\"", exp[j]);
			printf("Expected: ");
			j = -1;
			while (++j < 2)
				printf("\\\"%s\"", exp[j]);
			printf(" My own: ");
			j = -1;
			temp = header;
			while (temp)
			{
				printf("\\\"%s\"", (char *)temp->content);
				temp = temp->next;
				free(header);
				header = temp;
			}
			printf(RESET "\n");
		}
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp[0], exp[0]);
	i++;
  
	///////////Test 1///////////
	header = lstnew(sub[0]);
	second = lstnew(sub[1]);
	third = lstnew(sub[2]);
	new = lstnew(sub[3]);
	header->next = second;
	second->next = third;
	third->next = new;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstdelone(third, NULL);
		if (strcmp(third->content,"bem") == 0)
		{
			printf(GREEN "✓" GREY " [%d] ", i);
			printf("Testing for: del = (null) ");
			printf("Expected: ");
			j =-1;
			while (++j < 4)
				printf("\\\"%s\"", exp[j]);
			printf(" My own: ");
			j = -1;
			temp = header;
			while (temp)
			{
				printf("\\\"%s\"", (char *)temp->content);
				temp = temp->next;
				free(header);
				header = temp;
			}
			printf(RESET "\n");
			success++;
		}
		else
		{
			printf(RED "✗ [%d] ", i);
			printf("Testing for: del = (null) ");
			printf("Expected: ");
			j = -1;
			while (++j < 4)
				printf("\\\"%s\"", exp[j]);
			printf(" My own: ");
			j = -1;
			temp = header;
			while (temp)
			{
				printf("\\\"%s\"", (char *)temp->content);
				temp = temp->next;
				free(header);
				header = temp;
			}
			printf(RESET "\n");
		}
	}
	else
		printf(RED "✗ [%d] Testing for del = (null). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp[0]);
	i++;

	///////////Test 1///////////
	header = lstnew(sub[0]);
	second = lstnew(sub[1]);
	third = lstnew(sub[2]);
	new = lstnew(sub[3]);
	header->next = second;
	second->next = third;
	third->next = new;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstdelone(NULL, NULL);
		printf(GREEN "✓" GREY " [%d] ", i);
		printf("Testing for: del = (null) ");
		printf("Expected: ");
		j =-1;
		while (++j < 4)
			printf("\\\"%s\"", exp[j]);
		printf(" My own: ");
		j = -1;
		temp = header;
		while (temp)
		{
			printf("\\\"%s\"", (char *)temp->content);
			temp = temp->next;
			free(header);
			header = temp;
		}
		printf(RESET "\n");
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for del = (null). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp[0]);
	i++;

	///////////Test 1///////////
	header = lstnew(sub[0]);
	second = lstnew(sub[1]);
	third = lstnew(sub[2]);
	new = lstnew(sub[3]);
	header->next = second;
	second->next = third;
	third->next = new;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstdelone(NULL, &del);
		printf(GREEN "✓" GREY " [%d] ", i);
		printf("Testing for: del = (null) ");
		printf("Expected: ");
		j =-1;
		while (++j < 4)
			printf("\\\"%s\"", exp[j]);
		printf(" My own: ");
		j = -1;
		temp = header;
		while (temp)
		{
			printf("\\\"%s\"", (char *)temp->content);
			temp = temp->next;
			free(header);
			header = temp;
		}
		printf(RESET "\n");
		success++;
	}
	else
		printf(RED "✗ [%d] Testing for del = (null). Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp[0]);
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